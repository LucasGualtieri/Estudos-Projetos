#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// clear && gcc userInput.c -o userInput && ./userInput

#define STR_MAX_LEN 80
#define INVALID 0

typedef char* String;

String readString(String str);
int readInt(String str);
float readFloat(String str);

#endif