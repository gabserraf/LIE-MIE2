/*
 * INCLUDES
 */

#include "lib.h"

/*
 * FUNCS
 */

/********** INIT **********/

/** 
 * TODO (comment)
 */
void initializeMemory(char filename[T_MAX], char memory[65536][3]) {

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
		for (int i = 0; i < 4; i++) {
			strcpy(memory[numberLine], token);
			memory[numberLine][3] = '\0';
			token = strtok(NULL, " \r\n");
			numberLine++;
		}

	}

	/*
	 * end
	 */

	fclose(file);

}

/** 
 * TODO (comment)
 */
void initializeRegisters(int registres[36]) {

	for (int i = 0; i < 36; i++) registres[i] = 0;

}

/********** EXTRACT **********/

/** 
 * TODO (comment)
 */
void extractCommand(char line[T_MAX], char command[4]) {

	char char1 = line[0];
	char char2 = line[1];

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

	command[strlen(command)] = '\0';

}

/** 
 * TODO (comment)
 */
int extractFirstRegister(char line[T_MAX]) {

	char char1 = line[1];
	char char2 = line[2];

	if (char2 == '0' || char2 == '1' || char2 == '2' || char2 == '3') {

		if (char1 == '0' || char1 == '8') return 0;
		if (char1 == '1' || char1 == '9') return 4;
		if (char1 == '2' || char1 == 'A') return 8;
		if (char1 == '3' || char1 == 'B') return 12;
		if (char1 == '4' || char1 == 'C') return 16;
		if (char1 == '5' || char1 == 'D') return 20;
		if (char1 == '6' || char1 == 'E') return 24;
		if (char1 == '7' || char1 == 'F') return 28;

	} else if (char2 == '4' || char2 == '5' || char2 == '6' || char2 == '7') {

		if (char1 == '0' || char1 == '8') return 1;
		if (char1 == '1' || char1 == '9') return 5;
		if (char1 == '2' || char1 == 'A') return 9;
		if (char1 == '3' || char1 == 'B') return 13;
		if (char1 == '4' || char1 == 'C') return 17;
		if (char1 == '5' || char1 == 'D') return 21;
		if (char1 == '6' || char1 == 'E') return 25;
		if (char1 == '7' || char1 == 'F') return 29;

	} else if (char2 == '8' || char2 == '9' || char2 == 'A' || char2 == 'B') {

		if (char1 == '0' || char1 == '8') return 2;
		if (char1 == '1' || char1 == '9') return 6;
		if (char1 == '2' || char1 == 'A') return 10;
		if (char1 == '3' || char1 == 'B') return 14;
		if (char1 == '4' || char1 == 'C') return 18;
		if (char1 == '5' || char1 == 'D') return 22;
		if (char1 == '6' || char1 == 'E') return 26;
		if (char1 == '7' || char1 == 'F') return 30;

	} else {

		if (char1 == '0' || char1 == '8') return 3;
		if (char1 == '1' || char1 == '9') return 7;
		if (char1 == '2' || char1 == 'A') return 11;
		if (char1 == '3' || char1 == 'B') return 15;
		if (char1 == '4' || char1 == 'C') return 19;
		if (char1 == '5' || char1 == 'D') return 23;
		if (char1 == '6' || char1 == 'E') return 27;
		if (char1 == '7' || char1 == 'F') return 31;

	}

	return 0;

}

/** 
 * TODO (comment)
 */
int extractSecondRegister(char line[T_MAX]) {

	char char1 = line[2];
	char char2 = line[3];

	if (char1 == '0' || char1 == '4' || char1 == '8' || char1 == 'C') {

		if (char2 == '0' || char2 == '1') return 0;
		if (char2 == '2' || char2 == '3') return 1;
		if (char2 == '4' || char2 == '5') return 2;
		if (char2 == '6' || char2 == '7') return 3;
		if (char2 == '8' || char2 == '9') return 4;
		if (char2 == 'A' || char2 == 'B') return 5;
		if (char2 == 'C' || char2 == 'D') return 6;
		if (char2 == 'E' || char2 == 'F') return 7;

	} else if (char1 == '1' || char1 == '5' || char1 == '9' || char1 == 'D') {

		if (char2 == '0' || char2 == '1') return 8;
		if (char2 == '2' || char2 == '3') return 9;
		if (char2 == '4' || char2 == '5') return 10;
		if (char2 == '6' || char2 == '7') return 11;
		if (char2 == '8' || char2 == '9') return 12;
		if (char2 == 'A' || char2 == 'B') return 13;
		if (char2 == 'C' || char2 == 'D') return 14;
		if (char2 == 'E' || char2 == 'F') return 15;

	} else if (char1 == '2' || char1 == '6' || char1 == 'A' || char1 == 'E') {

		if (char2 == '0' || char2 == '1') return 16;
		if (char2 == '2' || char2 == '3') return 17;
		if (char2 == '4' || char2 == '5') return 18;
		if (char2 == '6' || char2 == '7') return 19;
		if (char2 == '8' || char2 == '9') return 20;
		if (char2 == 'A' || char2 == 'B') return 21;
		if (char2 == 'C' || char2 == 'D') return 22;
		if (char2 == 'E' || char2 == 'F') return 23;

	} else {

		if (char2 == '0' || char2 == '1') return 24;
		if (char2 == '2' || char2 == '3') return 25;
		if (char2 == '4' || char2 == '5') return 26;
		if (char2 == '6' || char2 == '7') return 27;
		if (char2 == '8' || char2 == '9') return 28;
		if (char2 == 'A' || char2 == 'B') return 29;
		if (char2 == 'C' || char2 == 'D') return 30;
		if (char2 == 'E' || char2 == 'F') return 31;

	}

	return 0;

}

/** 
 * TODO (comment)
 */
int extractImm(char line[T_MAX]) {

	char char1 = line[3];

	if (char1 == '0' || char1 == '2' || char1 == '4' || char1 == '6' || char1 == '8' || char1 == 'A' || char1 == 'C' || char1 == 'E')
		return 0;

	return 1;

}

/** 
 * TODO (comment)
 */
int extractS(char line[T_MAX]) {

	shift(line, 4);
	return hex2dec(line);

}

/********** EXECUTE **********/

/** 
 * TODO (comment)
 */
void display(int registres[36]) {

	printf("# ---- START DISPLAY ---- #\n");

	for (int i = 0; i < 36; i++) {
		if (i <= 31) printf("R%d: %s (%d)\n", i, dec2bin(registres[i], 32, 1), registres[i]);
		if (i == 32) printf("C: %d\n", registres[i]);
		if (i == 33) printf("N: %d\n", registres[i]);
		if (i == 34) printf("Z: %d\n", registres[i]);
		if (i == 35) printf("PC: %d\n", registres[i]);
	}

	printf("# ==== END ==== #\n");

}

/** 
 * TODO (comment)
 */
void updateRegister(int registres[36], int result, int reg) {

	registres[32] = (result > 2147483647 || result < -2147483648) ? 1 : 0;


	result = (result > 2147483647) ? 2147483647 : result;
	result = (result < -2147483648) ? -2147483648 : result;

	registres[33] = dec2bin(result, 32, 1)[0] - 48;
	registres[34] = (result == 0) ? 1 : 0;
	registres[35] += 4;

	if (reg != 0) {
		registres[reg] = result;
	}

}

/** 
 * TODO (comment)
 */
void executeOR(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	
	result = registres[reg2] | S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeXOR(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = registres[reg2] ^ S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeAND(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = registres[reg2] & S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeADD(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = registres[reg2] + S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeSUB(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = registres[reg2] - S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeMUL(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char binR[T_MAX] = "";
	char binS[T_MAX] = "";

	strcpy(binR, dec2bin(registres[reg2], 32, 1));
	shift(binR, 16);
	strcpy(binS, dec2bin(S, 32, 1));
	shift(binS, 16);
	result = bin2dec(binR) * bin2dec(binS);

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeDIV(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = registres[reg2] / S;

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeSHR(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char* binR = NULL;

	if (S >= 0) result = registres[reg2] >> S;
	if (S < 0) result = registres[reg2] << S;

	updateRegister(registres, result, reg1);

	binR = dec2bin(registres[reg2], 32, 1);
	if (S < 0) registres[32] = binR[abs(S)-1] - 48;
	if (S > 0) registres[32] = binR[32-S] - 48;

}

/** 
 * TODO (comment)
 */
void executeLDB(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char binR[T_MAX] = "";

	if (registres[reg2]+S >= 0 && registres[reg2]+S <= 31) {

		strcpy(binR, dec2bin(registres[registres[reg2]+S], 32, 1));
		shift(binR, 24);
		result = bin2dec(binR);

		registres[reg1] = result;

		updateRegister(registres, result, reg1);

	} else {
		printf("FAILURE: LDB Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeLDH(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char binR[T_MAX] = "";

	if (registres[reg2]+S >= 0 && registres[reg2]+S <= 31) {

		strcpy(binR, dec2bin(registres[registres[reg2]+S], 32, 1));
		shift(binR, 16);
		result = bin2dec(binR);

		registres[reg1] = result;

		updateRegister(registres, result, reg1);

	} else {
		printf("FAILURE: LDH Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeLDW(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	if (registres[reg2]+S >= 0 && registres[reg2]+S <= 31) {

		result = registres[registres[reg2]+S];
		registres[reg1] = result;

		updateRegister(registres, result, reg1);

	} else {
		printf("FAILURE: LDW Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeSTB(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char binR[T_MAX] = "";

	if (registres[reg1]+S >= 0 && registres[reg1]+S <= 31) {

		strcpy(binR, dec2bin(registres[reg2], 32, 1));
		shift(binR, 24);
		result = bin2dec(binR);

		registres[registres[reg1]+S] = result;

		updateRegister(registres, result, 0);

	} else {
		printf("FAILURE: STB Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeSTH(int registres[36], int reg1, int reg2, int S) {

	int result = 0;
	char binR[T_MAX] = "";

	if (registres[reg1]+S >= 0 && registres[reg1]+S <= 31) {

		strcpy(binR, dec2bin(registres[reg2], 32, 1));
		shift(binR, 16);
		result = bin2dec(binR);

		registres[registres[reg1]+S] = result;

		updateRegister(registres, result, 0);

	} else {
		printf("FAILURE: STH Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeSTW(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	if (registres[reg1]+S >= 0 && registres[reg1]+S <= 31) {

		result = registres[registres[reg1]+S];
		registres[reg2] = result;

		updateRegister(registres, result, reg1);

	} else {
		printf("FAILURE: STW Greater than 32");
		exit(0);
	}

}

/** 
 * TODO (comment)
 */
void executeJ(int registres[36], int S, char command[4]) {

	if (strcmp(command, "JMP") == 0) {
		registres[35] = S;
	} else if (strcmp(command, "JZS") == 0) {
		if (registres[34]) registres[35] = S;
		else registres[35] += 4;
	} else if (strcmp(command, "JZC") == 0) {
		if (!registres[34]) registres[35] = S;
		else registres[35] += 4;
	} else if (strcmp(command, "JCS") == 0) {
		if (registres[32]) registres[35] = S;
		else registres[35] += 4;
	} else if (strcmp(command, "JCC") == 0) {
		if (!registres[32]) registres[35] = S;
		else registres[35] += 4;
	} else if (strcmp(command, "JNS") == 0) {
		if (registres[33]) registres[35] = S;
		else registres[35] += 4;
	} else if (strcmp(command, "JNC") == 0) {
		if (!registres[33]) registres[35] = S;
		else registres[35] += 4;
	}

}

/** 
 * TODO (comment)
 */
void executeIN(int registres[36], int reg1) {

	int result = 0;

	printf("Entrez une valeur :\n");
	scanf("%d", &result);

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeOUT(int registres[36], int reg1) {

	int result = 0;

	result = registres[reg1];
	printf("%d\n", result);

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void executeRND(int registres[36], int reg1, int reg2, int S) {

	int result = 0;

	result = rand()%(S - registres[reg2]) + registres[reg2];

	updateRegister(registres, result, reg1);

}

/** 
 * TODO (comment)
 */
void execute(char filename[T_MAX], int registres[36], char memory[65536][3]) {

	/*
	 * variables
	 */

	char line[T_MAX] = "";
	char command[4] = "";
	int reg1 = 0;
	int reg2 = 0;
	int imm = 0;
	int S = 0;

	/*
	 * execution
	 */

	srand(time(NULL));
	initializeMemory(filename, memory);
	initializeRegisters(registres);

	while (strcmp(command, "HLT") != 0) {

		strcpy(line, "");
		for (int i = 0; i < 4; i++) strcat(line, memory[registres[35]+i]);
		line[strlen(line)] = '\0';
		
		extractCommand(line, command);
		reg1 = extractFirstRegister(line);
		reg2 = extractSecondRegister(line);
		imm = extractImm(line);
		S = imm ? extractS(line) : registres[extractS(line)];

		if (strcmp(command, "OR") == 0) executeOR(registres, reg1, reg2, S);
		if (strcmp(command, "XOR") == 0) executeXOR(registres, reg1, reg2, S);
		if (strcmp(command, "AND") == 0) executeAND(registres, reg1, reg2, S);
		if (strcmp(command, "ADD") == 0) executeADD(registres, reg1, reg2, S);
		if (strcmp(command, "SUB") == 0) executeSUB(registres, reg1, reg2, S);
		if (strcmp(command, "MUL") == 0) executeMUL(registres, reg1, reg2, S);
		if (strcmp(command, "DIV") == 0) executeDIV(registres, reg1, reg2, S);
		if (strcmp(command, "SHR") == 0) executeSHR(registres, reg1, reg2, S);
		if (strcmp(command, "LDB") == 0) executeLDB(registres, reg1, reg2, S);
		if (strcmp(command, "LDH") == 0) executeLDH(registres, reg1, reg2, S);
		if (strcmp(command, "LDW") == 0) executeLDW(registres, reg1, reg2, S);
		if (strcmp(command, "STB") == 0) executeSTB(registres, reg1, reg2, S);
		if (strcmp(command, "STH") == 0) executeSTH(registres, reg1, reg2, S);
		if (strcmp(command, "STW") == 0) executeSTW(registres, reg1, reg2, S);
		if (command[0] == 'J') executeJ(registres, S, command);
		if (strcmp(command, "IN") == 0) executeIN(registres, reg1);
		if (strcmp(command, "OUT") == 0) executeOUT(registres, reg1);
		if (strcmp(command, "RND") == 0) executeRND(registres, reg1, reg2, S);

		display(registres);

	}

}

/********** MAIN **********/

int main (int argc, char* argv[]) {

	char filename[T_MAX] = "../testFile.txt";

	if (argc < 2) {
		printf("FAILURE: filename is required");
		exit(0);
	}

	strcpy(filename, argv[1]);
	execute(filename, registres, memory);

	return 0;

}