#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

#define BAD_NUMBER_ARGS 1
#define BAD_OPTION 2
#define FSEEK_ERROR 3
#define FREAD_ERROR 4
#define MALLOC_ERROR 5
#define FWRITE_ERROR 6

/**
 * Parses the command line.
 *
 * argc:      the number of items on the command line (and length of the
 *            argv array) including the executable
 * argv:      the array of arguments as strings (char* array)
 * grayscale: the integer value is set to TRUE if grayscale output indicated
 *            outherwise FALSE for threshold output
 *
 * returns the input file pointer (FILE*)
 **/
FILE *parseCommandLine(int argc, char **argv, int *isGrayscale) {
  if (argc > 2) {
    fprintf(stderr, "Usage: %s [-g]\n", argv[0]);
    exit(BAD_NUMBER_ARGS);
  }

  if (argc == 2) {
    if (strcmp(argv[1], "-g") == 0) {
      *isGrayscale = TRUE;

    } else if (strcmp(argv[1], "-s") == 0) {
      // set isscale here

    } else {
      fprintf(stderr, "Unknown option: '%s'\n", argv[1]);
      fprintf(stderr, "Usage: %s [-g]\n", argv[0]);
      exit(BAD_OPTION);  
    }
  }

  return stdin;
}

unsigned getFileSizeInBytes(FILE* stream) {
  unsigned fileSizeInBytes = 0;
  
  rewind(stream);
  if (fseek(stream, 0L, SEEK_END) != 0) {
    exit(FSEEK_ERROR);
  }
  fileSizeInBytes = ftell(stream);

  return fileSizeInBytes;
}

void getBmpFileAsBytes(unsigned char* ptr, unsigned fileSizeInBytes, FILE* stream) {
  rewind(stream);
  if (fread(ptr, fileSizeInBytes, 1, stream) != 1) {
#ifdef DEBUG
    printf("feof() = %x\n", feof(stream));
    printf("ferror() = %x\n", ferror(stream));
#endif
    exit(FREAD_ERROR);
  }
}

unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red) {
  // printf("TODO unsigned char getAverageIntensity(unsigned char blue, unsigned char green, unsigned char red)\n");
  int sum = 0;
  char avg = 0;
  sum = sum + (int)blue;
  sum = sum + (int)green;
  sum = sum + (int)red;

  // sum = (unsigned char) sum; // breaks things
  
  avg = (sum / 3);
  unsigned char intensity = avg;
  return intensity;
}

void applyGrayscaleToPixel(unsigned char* pixel) {
  // printf("TODO void applyGrayscaleToPixel(unsigned char* pixel)\n");
  unsigned char intensity = getAverageIntensity(*pixel, *(pixel + 1), *(pixel + 2));

  *pixel = intensity;
  *(pixel + 1) = intensity;
  *(pixel + 2) = intensity;
}

void applyThresholdToPixel(unsigned char* pixel) {
  // printf("TODO void applyThresholdToPixel(unsigned char* pixel)\n");
  unsigned char intensity = getAverageIntensity(*pixel, *(pixel + 1), *(pixel + 2));
  int threshold = 0;

  if (intensity >= 128) {
    threshold = 0xff;
  } else {
    threshold = 0x00;
  }

  *pixel = threshold;
  *(pixel + 1) = threshold;
  *(pixel + 2) = threshold;
}

void applyFilterToPixel(unsigned char* pixel, int isGrayscale) {
  // printf("TODO void applyFilterToPixel(unsigned char* pixel, int isGrayscale)\n");
  if (isGrayscale) {
    applyGrayscaleToPixel(pixel);
  } else {
    applyThresholdToPixel(pixel);
  }
}

void applyFilterToRow(unsigned char* row, int width, int isGrayscale) {
  // printf("TODO void applyFilterToRow(unsigned char* row, int width, int isGrayscale)\n");
  for (unsigned int i = 0; i < (width * 3); i += 3) {
    applyFilterToPixel(row + i, isGrayscale);
  }
}

void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale) {
  int padding = 0;
  // printf("TODO compute the required amount of padding from the image width");

  int widthBytes = width * 3;
  padding = width % 4;

  int totalWidthBytes = widthBytes + padding;

  for (unsigned int i = 0; i < height; i++) {
    applyFilterToRow(pixelArray + (i * totalWidthBytes), width, isGrayscale);
  }

#ifdef DEBUG
  printf("padding = %d\n", padding);
#endif  
  
  // printf("TODO void applyFilterToPixelArray(unsigned char* pixelArray, int width, int height, int isGrayscale)\n");

}

void parseHeaderAndApplyFilter(unsigned char* bmpFileAsBytes, int isGrayscale) {
  int offsetFirstBytePixelArray = 0;
  int width = 0;
  int height = 0;
  unsigned char* pixelArray = NULL;

  // printf("TODO set offsetFirstBytePixelArray\n");
  // printf("TODO set width\n");
  // printf("TODO set height\n");
  // printf("TODO set the pixelArray to the start of the pixel array\n");

  offsetFirstBytePixelArray = * (int *)(bmpFileAsBytes + 10);
  width = * (int *)(bmpFileAsBytes + 18);
  height = * (int *)(bmpFileAsBytes + 22);
  pixelArray = bmpFileAsBytes + offsetFirstBytePixelArray;

#ifdef DEBUG
  printf("offsetFirstBytePixelArray = %u\n", offsetFirstBytePixelArray);
  printf("width = %u\n", width);
  printf("height = %u\n", height);
  printf("pixelArray = %p\n", pixelArray);
#endif

  applyFilterToPixelArray(pixelArray, width, height, isGrayscale);
}

int main(int argc, char **argv) {
  int grayscale = FALSE;
  unsigned fileSizeInBytes = 0;
  unsigned char* bmpFileAsBytes = NULL;
  FILE *stream = NULL;
  
  stream = parseCommandLine(argc, argv, &grayscale);
  fileSizeInBytes = getFileSizeInBytes(stream);

#ifdef DEBUG
  printf("fileSizeInBytes = %u\n", fileSizeInBytes);
#endif

  bmpFileAsBytes = (unsigned char *)malloc(fileSizeInBytes);
  if (bmpFileAsBytes == NULL) {
    exit(MALLOC_ERROR);
  }
  getBmpFileAsBytes(bmpFileAsBytes, fileSizeInBytes, stream);

  parseHeaderAndApplyFilter(bmpFileAsBytes, grayscale);

#ifndef DEBUG
  if (fwrite(bmpFileAsBytes, fileSizeInBytes, 1, stdout) != 1) {
    exit(FWRITE_ERROR);
  }
#endif

  free(bmpFileAsBytes);
  return 0;
}
