#ifndef LIB_H

/*
 * INCLUDES
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*
 * DEFINE
 */

#define R0 0
#define T_MAX 512

/*
 * GLOBAL REGISTERS
 */

int* R1 = NULL;
int* R2 = NULL;
int* R3 = NULL;
int* R4 = NULL;
int* R4 = NULL;
int* R5 = NULL;
int* R6 = NULL;
int* R7 = NULL;
int* R8 = NULL;
int* R9 = NULL;
int* R10 = NULL;
int* R11 = NULL;
int* R12 = NULL;
int* R13 = NULL;
int* R14 = NULL;
int* R15 = NULL;
int* R16 = NULL;
int* R17 = NULL;
int* R18 = NULL;
int* R19 = NULL;
int* R20 = NULL;
int* R21 = NULL;
int* R22 = NULL;
int* R23 = NULL;
int* R24 = NULL;
int* R25 = NULL;
int* R26 = NULL;
int* R27 = NULL;
int* R28 = NULL;
int* R29 = NULL;
int* R30 = NULL;
int* R31 = NULL;

/*
 * OTHER REGISTERS
 */

int* C = NULL;
int* Z = NULL;
int* N = NULL;
int* PC = NULL;

char memory[65536][2];

/*
 * FUNCS
 */

/* auxiliaries */

void shift(char * token, int number);

/* execution */

void fillMemoryFromFile(char filename[T_MAX]);
void extractCommand(char char1, char char2, char command[4]);
void extractFirstRegister(char char1, char char2, int register);

/*
 * END
 */

#endif
