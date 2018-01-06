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

#define T_MAX 512

/*
 * REGISTERS
 */

int registres[35];

/*
 * MEMORY
 */

char memory[65536][2];

/*
 * FUNCS
 */

/* auxiliaries */

void shift (char * token, int number);
char* bin2hex (char bin[T_MAX]);
char* dec2bin (int dec, int nbBits, int a2);
int hex2dec (char hex[T_MAX]);

/* execution */

void initializeMemory(char filename[T_MAX], char memory[65536][2]);
void initializeRegisters(int registres[35]);
void extractCommand(char line[T_MAX], char command[4]);
int extractFirstRegister(char line[T_MAX]);
int extractSecondRegister(char line[T_MAX]);
int extractImm(char line[T_MAX]);
int extractS(char line[T_MAX]);
void display(int registres[35], int PC);
void executeOR(int registres[35], int reg1, int reg2, int imm, int S);
void execute(char filename[T_MAX], int registres[35], char memory[65536][2]);

/*
 * END
 */

#endif
