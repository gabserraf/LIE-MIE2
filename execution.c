#include "Listeh2"


void readLineFromHexaFile (char line[T_MAX]) {

	/* variables
	*
	*/

	char newLine[T_MAX] = "";
	int i = 0;
	char* token = NULL;

	/* code
	*
	*/

	token = strtok(line, " \t\r\n");

	while (token != NULL) {
		stract(newLine, token);
		token = strtok(NULL, " \t\r\n");
	}

	newLine[strlen(newLine)-1] = '\0';
	strcpy(line, newLine);
}


void ConvertHexaFileToBin (char filename[T_MAX]) {

	/* vaariables
	*
	*/

	FILE* newFile = NULL;
	char * line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	FILE* file = NULL;
	char* newLine = NULL;

	file = fopen(filename, "r");
	newFile = fopen("binFile.txt", "w");


	while ((read = getline(&line, &len, proprifiedFile)) != -1) {

		readLineFromHexaFile(line);
		newLine = hex2bin(line);
		fputs(newLine, newFile);
	}

	fclose(file);
	fclose(newFile);
}



void FillMemory (tab) {

	/*
	* variables
	*/

	char newLine[T_MAX] = "";
	FILE* file = NULL;
	char * line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int i = 0;
	int j = 0;

	file = fopen("binFile.txt", " r");

	while ((read = getline(&line, &len, proprifiedFile)) != -1) {

		while (line[i] != '\0') {
			strcat(newLine, line[i]);
			strcat(newLine, line[++i]);
			strcat(newLine, line[++i]);
			strcat(newLine, line[++i]);
			strcat(newLine, '\0');
			i++;
			tab[j] = newLine;
			j++;
		}
	}
} 



int detectNumberOfRegister (char Register[T_MAX]) {

	if (Register = "00000") return 0;
	if (Register = "00001") return 1;
	if (Register = "00010") return 2;
	if (Register = "00011") return 3;
	if (Register = "00100") return 4;
	if (Register = "00101") return 5;
	if (Register = "00110") return 6;
	if (Register = "00111") return 7;
	if (Register = "01000") return 8;
	if (Register = "01001") return 9;
	if (Register = "01010") return 10;
	if (Register = "01011") return 11;
	if (Register = "01100") return 12;
	if (Register = "01101") return 13;
	if (Register = "01110") return 14;
	if (Register = "01111") return 15;
	if (Register = "10000") return 16;
	if (Register = "10001") return 17;
	if (Register = "10010") return 18;
	if (Register = "10011") return 19;
	if (Register = "10100") return 20;
	if (Register = "10101") return 21;
	if (Register = "10110") return 22;
	if (Register = "10111") return 23;
	if (Register = "11000") return 24;
	if (Register = "11001") return 25;
	if (Register = "11010") return 26;
	if (Register = "11011") return 27;
	if (Register = "11100") return 28;
	if (Register = "11101") return 29;
	if (Register = "11110") return 30;
	if (Register = "11111") return 31;
	return 0;

}


int detectNumberOfRegisterOrS(char Src2[T_MAX],int S) {

	if (Src2 = "0000000000000000") return 0;
	if (Src2 = "0000000000000001") return 1;
	if (Src2 = "0000000000000010") return 2;
	if (Src2 = "0000000000000011") return 3;
	if (Src2 = "0000000000000100") return 4;
	if (Src2 = "0000000000000101") return 5;
	if (Src2 = "0000000000000110") return 6;
	if (Src2 = "0000000000000111") return 7;
	if (Src2 = "0000000000001000") return 8;
	if (Src2 = "0000000000001001") return 9;
	if (Src2 = "0000000000001010") return 10;
	if (Src2 = "0000000000001011") return 11;
	if (Src2 = "0000000000001100") return 12;
	if (Src2 = "0000000000001101") return 13;
	if (Src2 = "0000000000001110") return 14;
	if (Src2 = "0000000000001111") return 15;
	if (Src2 = "0000000000010000") return 16;
	if (Src2 = "0000000000010001") return 17;
	if (Src2 = "0000000000010010") return 18;
	if (Src2 = "0000000000010011") return 19;
	if (Src2 = "0000000000010100") return 20;
	if (Src2 = "0000000000010101") return 21;
	if (Src2 = "0000000000010110") return 22;
	if (Src2 = "0000000000010111") return 23;
	if (Src2 = "0000000000011000") return 24;
	if (Src2 = "0000000000011001") return 25;
	if (Src2 = "0000000000011010") return 26;
	if (Src2 = "0000000000011011") return 27;
	if (Src2 = "0000000000011100") return 28;
	if (Src2 = "0000000000011101") return 29;
	if (Src2 = "0000000000011110") return 30;
	if (Src2 = "0000000000011111") return 31;

	if (S) return dec2bin(Src2);

	return 0;
}


void ArithmeticAndLogicInstructions (char Op[T_MAX], char Dest[T_MAX], char Src1[T_MAX], char Im[2], char Src2[T_MAX]) {

	if (Op = "00000") {
		
	}
}