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

int registres[36];

/*
 * MEMORY
 */

char memory[65536][3];

/*
 * FUNCS
 */

/* auxiliaries */

void shift (char * token, int number);
char* bin2hex (char bin[T_MAX]);
char* hex2bin (char hex[T_MAX]);
char* dec2bin (int dec, int nbBits, int a2);
int bin2dec (char bin[T_MAX]);
int hex2dec (char hex[T_MAX]);

/* execution */

void initializeMemory(char filename[T_MAX], char memory[65536][3]);
void initializeRegisters(int registres[36]);
void extractCommand(char line[T_MAX], char command[4]);
int extractFirstRegister(char line[T_MAX]);
int extractSecondRegister(char line[T_MAX]);
int extractImm(char line[T_MAX]);
int extractS(char line[T_MAX]);
void display(int registres[36]);
void executeOR(int registres[36], int reg1, int reg2, int S);
void executeXOR(int registres[36], int reg1, int reg2, int S);
void executeAND(int registres[36], int reg1, int reg2, int S);
void executeADD(int registres[36], int reg1, int reg2, int S);
void executeSUB(int registres[36], int reg1, int reg2, int S);
void executeMUL(int registres[36], int reg1, int reg2, int S);
void executeDIV(int registres[36], int reg1, int reg2, int S);
void executeSHR(int registres[36], int reg1, int reg2, int S);
void executeLDB(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeLDH(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeLDW(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeSTB(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeSTH(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeSTW(int registres[36], char memory[65536][3], int reg1, int reg2, int S);
void executeIN(int registres[36], int reg1);
void executeOUT(int registres[36], int reg1);
void executeRND(int registres[36], int reg1, int reg2, int S);
void execute(char filename[T_MAX], int registres[36], char memory[65536][3]);

/*
 * END
 */

#endif
