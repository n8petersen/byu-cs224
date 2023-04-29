#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BAD_NUMBER_ARGS 1

/**
 * Parses the command line.
 *
 * argc: the number of items on the command line (and length of the
 *       argv array) including the executable
 * argv: the array of arguments as strings (char* array)
 * bits: the integer value is set to TRUE if bits output indicated
 *       outherwise FALSE for hex output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *bits) {
  if (argc > 2) {
    printf("Usage: %s [-b|-bits]\n", argv[0]);
    exit(BAD_NUMBER_ARGS);
  }

  if (argc == 2 &&
      (strcmp(argv[1], "-b") == 0 || strcmp(argv[1], "-bits") == 0)) {
    *bits = TRUE;
  } else {
    *bits = FALSE;
  }

  return stdin;
}

/**
 * Writes data to stdout in hexadecimal.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsHex(unsigned char *data, size_t size) {
  // printf("TODO 1: printDataAsHex (2)");
  printf(" ");

  for (int i = 0; i < 16; i++) { // will always fill a space of 16 bytes, so we use 16 rather than
    if (i < size) {
      printf("%02x", data[i]);  // print the hex data
    } 
    else { 
      printf("  "); 
    } // otherwise print some spaces to fill the gap

    if (i % 2 == 1 && i < 15) { // if we're at an odd number, but not the end
      printf(" ");
    }
  }
}

/**
 * Writes data to stdout as characters.
 *
 * See myxxd.md for details.
 *
 * data: an array of no more than 16 characters
 * size: the size of the array
 **/
void printDataAsChars(unsigned char *data, size_t size) {
  // printf("TODO 2: printDataAsChars (3)");

  for (int i = 0; i < size; i++) {
    if (data[i] >= 0x20 && data[i] <= 0x7e) { // check that the value is in a the proper range for printable characters 
      printf("%c", data[i]);
    }
    else {
      printf(".");  // If not a valid printable character, print a '.' instead.
    }
  }
}

void printDataAsBinary(unsigned char *data, size_t size) {
  // printf("TODO 3: readAndPrintInputAsBits");
  printf(" ");

  // Follow same pattern as the hex, but we have to convert it to binary
  // and space it a little bit differently.

  unsigned char bitstring[8]; // a bit string is 8 bits long

  // Overall loop for the 6 bitstrings per line
  for (int i = 0; i < 6; i++) { 
    int x = data[i];

    // Inner loop for writing the individual bits into each string
    for (int j = 0; j < 8; j++) {
      if (x % 2 == 1) {
        bitstring[7 - j] = 1; // Set the right-most bit first, moving left with each iteration.
      }
      else {
        bitstring[7 - j] = 0;
      }
      x = x / 2; 
    }

    // Prints the bitstring to the current line, 
    if (i < size) { // if we're not at the end of the input
      for (int k = 0; k < 8; k++) { // 8 bits in each bitstring
        printf("%d", bitstring[k]);
      }
    }
    else { // if we are the end of the input
      printf("        "); // print padding to finish the line
    }
    if (i < 5) { // if we're not at the end of the line
      printf(" "); // print a space to seperate the bitstrings
    }
  }
}

void readAndPrintInputAsHex(FILE *input) {
  unsigned char data[16];
  int numBytesRead = fread(data, 1, 16, input);
  unsigned int offset = 0;
  while (numBytesRead != 0) {
    printf("%08x:", offset);
    offset += numBytesRead;
    printDataAsHex(data, numBytesRead);
    printf("  ");
    printDataAsChars(data, numBytesRead);
    printf("\n");
    numBytesRead = fread(data, 1, 16, input);
  }
}

/**
 * Bits output for xxd.
 *
 * See myxxd.md for details.
 *
 * input: input stream
 **/
void readAndPrintInputAsBits(FILE *input) {
  unsigned char data[6];
  int numBytesRead = fread(data, 1, 6, input);
  unsigned int offset = 0;
  while (numBytesRead != 0) {
    printf("%08x:", offset);
    offset += numBytesRead;
    printDataAsBinary(data, numBytesRead);
    printf("  ");
    printDataAsChars(data, numBytesRead);
    printf("\n");
    numBytesRead = fread(data, 1, 6, input);
  }
}

int main(int argc, char **argv) {
  int bits = FALSE;
  FILE *input = parseCommandLine(argc, argv, &bits);

  if (bits == FALSE) {
    readAndPrintInputAsHex(input);
  } else {
    readAndPrintInputAsBits(input);
  }
  return 0;
}
