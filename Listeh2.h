#ifndef LISTE_H2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define R0 0
#define T_MAX 512

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

int* C = NULL;
int* Z = NULL;
int* N = NULL;
int* PC = NULL;

char memory[65536][4];

void shift(char * token, int number);
char* bin2hex (char bin[T_MAX]);
char* hex2bin (char hex[T_MAX]);
char* dec2bin (int dec, int nbBits, int a2);
int bin2dec (char bin[T_MAX]);
int hex2dec (char hex[T_MAX]);
void readLineFromHexaFile (char line[T_MAX]);
void ConvertHexaFileToBin (char filename[T_MAX]);



















#endif




