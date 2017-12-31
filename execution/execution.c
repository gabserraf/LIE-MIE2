/*
 * INCLUDES
 */

#include "lib.h"

/*
 * FUNCS
 */

void fillMemoryFromFile(char filename[T_MAX]) {

	/*
	* variables
	*/

	FILE* file = NULL;
	char* line = NULL;
	char* token = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int numberLine = 0;

	/*
	 * code
	 */

	file = fopen("../hexaFile.txt", "r");

	if (file == NULL) {
		printf("FAILURE: File doesn't exist (../hexaFile.txt)");
		exit(0);
	}

	while ((read = getline(&line, &len, file)) != -1) {

		token = strtok(line, " \r\n");

		while (token != NULL) {
			strcpy(memory[numberLine], token);
			token(NULL, " \r\n");
		}

		numberLine++;

	}

}

void extractCommand(char char1, char char2, char command[4]) {

	if (char2 == '0' || char2 == '1' || char2 == '2' || char2 == '3' || char2 == '4' || char2 == '5' || char2 == '6' || char2 == '7') {

		if (char1 == '0') strcpy(command, "OR");
		if (char1 == '1') strcpy(command, "AND");
		if (char1 == '2') strcpy(command, "SUB");
		if (char1 == '3') strcpy(command, "DIV");
		if (char1 == '4') strcpy(command, "LDB");
		if (char1 == '5') strcpy(command, "LDW");
		if (char1 == '6') strcpy(command, "STH");
		if (char1 == 'A') strcpy(command, "JMP");
		if (char1 == 'B') strcpy(command, "JZC");
		if (char1 == 'C') strcpy(command, "JCC");
		if (char1 == 'D') strcpy(command, "JNC");
		if (char1 == 'E') strcpy(command, "IN");
		if (char1 == 'F') strcpy(command, "RND");

	} else {

		if (char1 == '0') strcpy(command, "XOR");
		if (char1 == '1') strcpy(command, "ADD");
		if (char1 == '2') strcpy(command, "MUL");
		if (char1 == '3') strcpy(command, "SHR");
		if (char1 == '4') strcpy(command, "LDH");
		if (char1 == '5') strcpy(command, "STB");
		if (char1 == '6') strcpy(command, "STW");
		if (char1 == 'A') strcpy(command, "JZS");
		if (char1 == 'B') strcpy(command, "JCS");
		if (char1 == 'C') strcpy(command, "JNS");
		if (char1 == 'E') strcpy(command, "OUT");
		if (char1 == 'F') strcpy(command, "HLT");

	}

	command[strlen(command)-1] = '\0';

}

void extractFirstRegister(char char1, char char2, int* reg) {

	if (char2 == '0' || char2 == '1' || char2 == '2' || char2 == '3') {

		if (char1 == '0' || char1 == '8') reg = R0;
		if (char1 == '1' || char1 == '9') reg = R4;
		if (char1 == '2' || char1 == 'A') reg = R8;
		if (char1 == '3' || char1 == 'B') reg = R12;
		if (char1 == '4' || char1 == 'C') reg = R16;
		if (char1 == '5' || char1 == 'D') reg = R20;
		if (char1 == '6' || char1 == 'E') reg = R24;
		if (char1 == '7' || char1 == 'F') reg = R28;

	} else if (char2 == '4' || char2 == '5' || char2 == '6' || char2 == '7') {

		if (char1 == '0' || char1 == '8') reg = R1;
		if (char1 == '1' || char1 == '9') reg = R5;
		if (char1 == '2' || char1 == 'A') reg = R9;
		if (char1 == '3' || char1 == 'B') reg = R13;
		if (char1 == '4' || char1 == 'C') reg = R17;
		if (char1 == '5' || char1 == 'D') reg = R21;
		if (char1 == '6' || char1 == 'E') reg = R25;
		if (char1 == '7' || char1 == 'F') reg = R29;

	} else if (char2 == '8' || char2 == '9' || char2 == 'A' || char2 == 'B') {

		if (char1 == '0' || char1 == '8') reg = R2;
		if (char1 == '1' || char1 == '9') reg = R6;
		if (char1 == '2' || char1 == 'A') reg = R10;
		if (char1 == '3' || char1 == 'B') reg = R14;
		if (char1 == '4' || char1 == 'C') reg = R18;
		if (char1 == '5' || char1 == 'D') reg = R22;
		if (char1 == '6' || char1 == 'E') reg = R26;
		if (char1 == '7' || char1 == 'F') reg = R30;

	} else {

		if (char1 == '0' || char1 == '8') reg = R3;
		if (char1 == '1' || char1 == '9') reg = R7;
		if (char1 == '2' || char1 == 'A') reg = R11;
		if (char1 == '3' || char1 == 'B') reg = R15;
		if (char1 == '4' || char1 == 'C') reg = R19;
		if (char1 == '5' || char1 == 'D') reg = R23;
		if (char1 == '6' || char1 == 'E') reg = R27;
		if (char1 == '7' || char1 == 'F') reg = R31;

	}

}