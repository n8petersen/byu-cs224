#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

const int MAX_MEM_SIZE  = (1 << 13);



void doMoveFetch() { // FetchStage Helper function for the RRMOVQ / CMOVXX distinction

}



void fetchStage(int *icode, int *ifun, int *rA, int *rB, wordType *valC, wordType *valP) {
  // printf("fetchStage\n"); // used for debugging
  wordType currentPC = getPC();
  byteType opcode = getByteFromMemory(currentPC);

  int icode_copy = (opcode >> 4) & 0xf;
  int ifun_copy = opcode & 0xf;

  // printf("   currentPC: %lx %x\n   icode: %x\n   ifun: %x\n", currentPC, opcode, icode_copy, ifun_copy); // used for debugging

  *icode = icode_copy;
  *ifun = ifun_copy;
  
  // Increment the PC the right amount, based on opcode
  if (*icode == HALT || *icode == NOP || *icode == RET) {
    *valP = currentPC + 1;
  }
  else if (*icode == RRMOVQ /* || *icode == CMOVXX */) {
    byteType regArgs = getByteFromMemory(currentPC + 1);
    *rA = (regArgs >> 4) & 0xf;
    *rB = regArgs & 0xf;
    *valP = currentPC + 2;
  }
  else if (*icode == OPQ) {
  byteType regArgs = getByteFromMemory(currentPC + 1);
  *rA = (regArgs >> 4) & 0xf;
  *rB = regArgs & 0xf;
  *valP = currentPC + 2;
  }
  else if (*icode == IRMOVQ || *icode == RMMOVQ || *icode == MRMOVQ) {
    byteType regArgs = getByteFromMemory(currentPC + 1);
    *rA = (regArgs >> 4) & 0xf;
    *rB = regArgs & 0xf;
    *valC = getWordFromMemory(currentPC + 2);
    *valP = currentPC + 10;
  }
  else if (*icode == JXX || *icode == CALL) {
    *valC = getWordFromMemory(currentPC + 1);
    *valP = currentPC + 9;
  }
  else if (*icode == PUSHQ || *icode == POPQ) {
    byteType regArgs = getByteFromMemory(currentPC + 1);
    *rA = (regArgs >> 4) & 0xf;
    *rB = regArgs & 0xf;
    *valP = currentPC + 2;
  }
  else {
    printf("ERROR: INVALID CODE IN FETCH STAGE! Incrementing PC by 1 byte.\n");
    *valP = currentPC + 1;
  }

}

void decodeStage(int icode, int rA, int rB, wordType *valA, wordType *valB) {
//  printf("decodeStage\n");

  if (icode == RRMOVQ /* || icode == CMOVXX */) {
    *valA = getRegister(rA);
  }
  else if (icode == RMMOVQ || icode == OPQ) {
    *valA = getRegister(rA);
    *valB = getRegister(rB);
  }
  else if (icode == MRMOVQ) {
    *valB = getRegister(rB);
  }
  else if (icode == CALL) {
    *valB = getRegister(RSP);
  }
  else if (icode == RET || icode == POPQ) {
    *valA = getRegister(RSP);
    *valB = getRegister(RSP);
  }
  else if (icode == PUSHQ) {
    *valA = getRegister(rA);
    *valB = getRegister(RSP);
  }
  else if (icode == NOP || icode == HALT || icode == IRMOVQ || icode == JXX) {
    // Do nothing
  }
  else {
    printf("ERROR: INVALID CODE IN DECODE STAGE! Nothing performed.\n");
  }
}

void executeStage(int icode, int ifun, wordType valA, wordType valB, wordType valC, wordType *valE, bool *Cnd) {
  // printf("executeStage\n");

  if (icode == RRMOVQ /* || icode == CMOVXX */) {
    *valE = valA;
    if (ifun != UCND) {
      *Cnd = Cond(ifun);
    }
    
  }
  else if (icode == IRMOVQ) {
    *valE = 0 + valC;
  }
  else if (icode == RMMOVQ || icode == MRMOVQ) {
    *valE = valB + valC;
  }
  else if (icode == OPQ) {

    // Reset condition flags
    bool sf = FALSE;
    bool zf = FALSE;
    bool of = FALSE;

    // This depends on the operation, which is encoded in the ifun (instruction function)
    // Operations are: ADD, SUB, AND, XOR.
    // valE will become the result of the operation.
    // Overflow flag is dependent on the operation, so it will be evaluated per operation
    if (ifun == ADD) {
      *valE = valB + valA;

      // Check for OF on ADD
      if (((valA < 0) == (valB < 0)) && ((*valE < 0) != (valA < 0))) {
        of = TRUE;
      }
    }
    else if (ifun == SUB) {
      *valE = valB - valA;

      // Check for OF on SUB
      if (((valA < 0) != (valB < 0)) && ((*valE < 0) == (valA < 0))) {
        of = TRUE;
      }
    }
    else if (ifun == AND) {
      *valE = valB & valA;
      // OF can't occur on AND
    }
    else if (ifun == XOR) {
      *valE = valB ^ valA;
      // OF can't occur on XOR
    }

    // After operation, we have to set the condition flags for ZF or SF
    if (*valE < 0) {
      sf = TRUE;
    }
    if (*valE == 0) {
      zf = TRUE;
    }
    setFlags(sf, zf, of);
  
  }
  else if (icode == JXX) {
    *Cnd = Cond(ifun);
  }
  else if (icode == CALL || icode == PUSHQ) {
    *valE = valB + (-8);
  }
  else if (icode == RET || icode == POPQ) {
    *valE = valB + 8;
  }
  else if (icode == HALT || icode == NOP) {
    // Do nothing
  }
  else {
    printf("ERROR: INVALID CODE IN EXECUTE STAGE! Nothing performed.\n");
  }
}

void memoryStage(int icode, wordType valA, wordType valP, wordType valE, wordType *valM) {
  // printf("memoryStage\n");

  if (icode == RMMOVQ) {
    setWordInMemory(valE, valA);
  }
  else if (icode == MRMOVQ) {
    *valM = getWordFromMemory(valE);
  }
  else if (icode == CALL) {
    setWordInMemory(valE, valP);
  }
  else if (icode == RET) {
    *valM = getWordFromMemory(valA);
  }
  else if (icode == PUSHQ) {
    setWordInMemory(valE, valA);
  }
  else if (icode == POPQ) {
    *valM = getWordFromMemory(valA);
  }
  else if (icode == HALT || icode == NOP || icode == RRMOVQ  /* || icode == CMOVXX */ || icode == IRMOVQ || icode == OPQ || icode == JXX) { 
    // Do nothing
  }
  else {
      printf("ERROR: INVALID CODE IN MEMORY STAGE! Nothing performed.\n");
  }
}

void writebackStage(int icode, int ifun, int rA, int rB, wordType valE, wordType valM, bool Cnd) {
//  printf("writebackStage\n");

  if (icode == RRMOVQ /* || icode == CMOVXX */) {
    
    if (ifun != UCND) { // icode == CMOVXX
      if (Cnd) {
        setRegister(rB, valE);
      }
      else {
        // Do nothing
      }
    }
    else if (ifun == UCND) { // icode == RRMOVQ
      setRegister(rB, valE);
    }

  }
  else if (icode == IRMOVQ || icode == OPQ) {
    setRegister(rB, valE);
  }
  else if (icode == MRMOVQ) {
    setRegister(rA, valM);
  }
  else if (icode == CALL || icode == RET || icode == PUSHQ) {
    setRegister(RSP, valE);
  }
  else if (icode == POPQ) {
    setRegister(RSP, valE);
    setRegister(rA, valM);
  }
  else if (icode == HALT || icode == NOP || icode == RMMOVQ || icode == JXX) { 
    // Do nothing
  }
  else {
    printf("ERROR: INVALID CODE IN WRITE-BACK STAGE! Nothing performed.\n");
  }
}

void pcUpdateStage(int icode, wordType valC, wordType valP, bool Cnd, wordType valM) {
  // printf("pcUpdateStage\n");

  if (icode == HALT) {
    setPC(valP);
    setStatus(STAT_HLT);
  }
  else if (icode == NOP || icode == RRMOVQ /* || icode == CMOVXX */ || icode == IRMOVQ || icode == RMMOVQ ||
     icode == MRMOVQ || icode == OPQ|| icode == PUSHQ || icode == POPQ) {
    setPC(valP);
  }
  else if (icode == JXX) {
    wordType set = (Cnd ? valC : valP);
    setPC(set);
  }
  else if (icode == CALL) {
    setPC(valC);
  }
  else if (icode == RET) {
    setPC(valM);
  }
  else {
    printf("ERROR: INVALID CODE IN PC-UPDATE STAGE! PC set to valP.\n");
    setPC(valP);
  }
}

void stepMachine(int stepMode) {
  /* FETCH STAGE */
  int icode = 0, ifun = 0;
  int rA = 0, rB = 0;
  wordType valC = 0;
  wordType valP = 0;
 
  /* DECODE STAGE */
  wordType valA = 0;
  wordType valB = 0;

  /* EXECUTE STAGE */
  wordType valE = 0;
  bool Cnd = 0;

  /* MEMORY STAGE */
  wordType valM = 0;

  fetchStage(&icode, &ifun, &rA, &rB, &valC, &valP);
  applyStageStepMode(stepMode, "Fetch", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);

  decodeStage(icode, rA, rB, &valA, &valB);
  applyStageStepMode(stepMode, "Decode", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);
  
  executeStage(icode, ifun, valA, valB, valC, &valE, &Cnd);
  applyStageStepMode(stepMode, "Execute", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);
  
  memoryStage(icode, valA, valP, valE, &valM);
  applyStageStepMode(stepMode, "Memory", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);
  
  writebackStage(icode, ifun, rA, rB, valE, valM, Cnd);
  applyStageStepMode(stepMode, "Writeback", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);
  
  pcUpdateStage(icode, valC, valP, Cnd, valM);
  applyStageStepMode(stepMode, "PC update", icode, ifun, rA, rB, valC, valP, valA, valB, valE, Cnd, valM);

  incrementCycleCounter();
}

// #define DEBUG
/** 
 * main
 * */
int main(int argc, char **argv) {
  int stepMode = 0;
  FILE *input = parseCommandLine(argc, argv, &stepMode);

  initializeMemory(MAX_MEM_SIZE);
  initializeRegisters();
  loadMemory(input);

  applyStepMode(stepMode);
  while (getStatus() != STAT_HLT) {
    stepMachine(stepMode);
    applyStepMode(stepMode);
#ifdef DEBUG
    printMachineState();
    printf("\n");
#endif
  }
  printMachineState();
  return 0;
}