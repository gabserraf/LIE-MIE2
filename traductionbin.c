/*
 * INCLUDES
 */

#include "liste.h"
/*
 * DEFINE
 */

#define T_MAX 512

/*
 * DECLARATIONS
 */

char* bin2hex (char bin[T_MAX]);
char* dec2bin (int dec, int nbBits);
int hex2dec (char hex[T_MAX]);
void translateLine (char line[T_MAX]);
void translateFile ();

/*
 * FUNCS
 */

char* bin2hex (char bin[T_MAX]) {

	int i = 0;
	char *tab = malloc(sizeof(char) * 9);
	for (i = 0; i < 32; i += 4){
		char binNumber[5] = {bin[i], bin[i+1], bin[i+2], bin[i+3], '\0'};
		if (strcmp(binNumber, "0000") == 0) tab[i/4] = '0';
		if (strcmp(binNumber, "0001") == 0) tab[i/4] = '1';
		if (strcmp(binNumber, "0010") == 0) tab[i/4] = '2';
		if (strcmp(binNumber, "0011") == 0) tab[i/4] = '3';
		if (strcmp(binNumber, "0100") == 0) tab[i/4] = '4';
		if (strcmp(binNumber, "0101") == 0) tab[i/4] = '5';
		if (strcmp(binNumber, "0110") == 0) tab[i/4] = '6';
		if (strcmp(binNumber, "0111") == 0) tab[i/4] = '7';
		if (strcmp(binNumber, "1000") == 0) tab[i/4] = '8';
		if (strcmp(binNumber, "1001") == 0) tab[i/4] = '9';
		if (strcmp(binNumber, "1010") == 0) tab[i/4] = 'A';
		if (strcmp(binNumber, "1011") == 0) tab[i/4] = 'B';
		if (strcmp(binNumber, "1100") == 0) tab[i/4] = 'C';
		if (strcmp(binNumber, "1101") == 0) tab[i/4] = 'D';
		if (strcmp(binNumber, "1110") == 0) tab[i/4] = 'E';
		if (strcmp(binNumber, "1111") == 0) tab[i/4] = 'F';
	}

	tab[8] = '\0';

	return tab;

}

char* dec2bin (int dec, int nbBits) {

	/*
	 * variables
	 */

	char binaryNumb[20] = "";
	int j = 0;

	/*
	 * code
	 */

	for (int i = nbBits-1; i >= 0; i--, j++) {
		if (dec >= pow(2, i)) {
			binaryNumb[j] = '1';
			dec -= pow(2, i);
		} else {
			binaryNumb[j] = '0';
		}
	}

	binaryNumb[nbBits] = 0;

	/*
	 * end & return
	 */

	return strdup(binaryNumb);

}

int hex2dec (char hex[T_MAX]) {
	
	/*
	 * variables
	 */

	int dec = 0;

	/*
	 * code
	 */

	for (int i = strlen(hex)-1; i >= 0; i--) {

		if (hex[i] == 'A') dec += 10*pow(16, strlen(hex)-1-i);
		else if (hex[i] == 'B') dec += 11*pow(16, strlen(hex)-1-i);
		else if (hex[i] == 'C') dec += 12*pow(16, strlen(hex)-1-i);
		else if (hex[i] == 'D') dec += 13*pow(16, strlen(hex)-1-i);
		else if (hex[i] == 'E') dec += 14*pow(16, strlen(hex)-1-i);
		else if (hex[i] == 'F') dec += 15*pow(16, strlen(hex)-1-i);
		else {
			dec += atoi(&hex[i])*pow(16, strlen(hex)-1-i);
		}

	}

	/*
	 * end & return
	 */

	return dec;

}

void translateLine (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;
	int lineType;

	/*
	 * translate
	 */

	token = strtok(line, " ,\n");

	if (strcmp(token, "OR") == 0) {
		strcat(newLine, dec2bin(0, 5));
		lineType = 1;
	} else if (strcmp(token, "XOR") == 0) {
		strcat(newLine, dec2bin(1, 5));
		lineType = 1;
	} else if (strcmp(token, "AND") == 0) {
		strcat(newLine, dec2bin(2, 5));
		lineType = 1;
	} else if (strcmp(token, "ADD") == 0) {
		strcat(newLine, dec2bin(3, 5));
		lineType = 1;
	} else if (strcmp(token, "SUB") == 0) {
		strcat(newLine, dec2bin(4, 5));
		lineType = 1;
	} else if (strcmp(token, "MUL") == 0) {
		strcat(newLine, dec2bin(5, 5));
		lineType = 1;
	} else if (strcmp(token, "DIV") == 0) {
		strcat(newLine, dec2bin(6, 5));
		lineType = 1;
	} else if (strcmp(token, "SHR") == 0) {
		strcat(newLine, dec2bin(7, 5));
		lineType = 1;
	} else if (strcmp(token, "LDB") == 0) {
		strcat(newLine, dec2bin(8, 5));
		lineType = 2;
	} else if (strcmp(token, "LDH") == 0) {
		strcat(newLine, dec2bin(9, 5));
		lineType = 2;
	} else if (strcmp(token, "LDW") == 0) {
		strcat(newLine, dec2bin(10, 5));
		lineType = 2;
	} else if (strcmp(token, "STB") == 0) {
		strcat(newLine, dec2bin(11, 5));
		lineType = 3;
	} else if (strcmp(token, "STH") == 0) {
		strcat(newLine, dec2bin(12, 5));
		lineType = 3;
	} else if (strcmp(token, "STW") == 0) {
		strcat(newLine, dec2bin(13, 5));
		lineType = 3;
	} else if (strcmp(token, "JMP") == 0) {
		strcat(newLine, dec2bin(20, 5));
		lineType = 4;
	} else if (strcmp(token, "JZS") == 0) {
		strcat(newLine, dec2bin(21, 5));
		lineType = 4;
	} else if (strcmp(token, "JZC") == 0) {
		strcat(newLine, dec2bin(22, 5));
		lineType = 4;
	} else if (strcmp(token, "JCS") == 0) {
		strcat(newLine, dec2bin(23, 5));
		lineType = 4;
	} else if (strcmp(token, "JCC") == 0) {
		strcat(newLine, dec2bin(24, 5));
		lineType = 4;
	} else if (strcmp(token, "JNS") == 0) {
		strcat(newLine, dec2bin(25, 5));
		lineType = 4;
	} else if (strcmp(token, "JNC") == 0) {
		strcat(newLine, dec2bin(26, 5));
		lineType = 4;
	} else if (strcmp(token, "IN") == 0) {
		strcat(newLine, dec2bin(28, 5));
		lineType = 5;
	} else if (strcmp(token, "OUT") == 0) {
		strcat(newLine, dec2bin(29, 5));
		lineType = 5;
	} else if (strcmp(token, "RND") == 0) {
		strcat(newLine, dec2bin(30, 5));
		lineType = 1;
	} else if (strcmp(token, "HLT") == 0) {
		strcat(newLine, dec2bin(31, 5));
		lineType = 6;
	}

	if (lineType == 1) {
		
		for (int k = 0; k < 2; k++) {
			token = strtok(NULL, " ,\n");
			for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(token), 5));
		}
		
		token = strtok(NULL, " ,\n");

		if (token[0] == 'R') {
			strcat(newLine, "0");
			for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(token), 16));
		} else if (token[0] == '#') {
			strcat(newLine, "1");
			if (token[1] == 'h') {
				for (int i = 2; i < strlen(token); i++) token[i-2] = token[i];
				token[strlen(token)-2] = '\0';
				strcat(newLine, dec2bin(hex2dec(token), 16));
			} else {
				for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
				token[strlen(token)-1] = '\0';
				strcat(newLine, dec2bin(atoi(token), 16));
			}
		}

	} else if (lineType == 2) {

		
		for (int k = 0; k < 2; k++) {
			token = strtok(NULL, " ,()\n");
			for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(token), 5));
		}


		token = strtok(NULL, " ,()\n");

		if (token[0] == 'R') {
			strcat(newLine, "0");
			for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(token), 16));
		} else if (token[0] == '#') {
			strcat(newLine, "1");
			if (token[1] == 'h') {
				for (int i = 2; i < strlen(token); i++) token[i-2] = token[i];
				token[strlen(token)-2] = '\0';
				strcat(newLine, dec2bin(hex2dec(token), 16));
			} else {
				for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
				token[strlen(token)-1] = '\0';
				strcat(newLine, dec2bin(atoi(token), 16));
			}
		}

	} else if (lineType == 3) {

		token = strtok(NULL, " ,()\n");
		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';
		strcat(newLine, dec2bin(atoi(token),5));
		char tmp[T_MAX] = "";
		token = strtok(NULL, " ,()\n");
		strcpy(tmp,token);
		token = strtok(NULL, " ,()\n");
		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';
		strcat(newLine, dec2bin(atoi(token), 5));

		if (tmp[0] == 'R') {
			strcat(newLine, "0");
			for (int i = 1; i < strlen(tmp); i++) tmp[i-1] = tmp[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(tmp), 16));
		} else if (tmp[0] == '#') {
			strcat(newLine, "1");
			if (tmp[1] == 'h') {
				for (int i = 2; i < strlen(tmp); i++) tmp[i-2] = tmp[i];
				tmp[strlen(tmp)-2] = '\0';
				strcat(newLine, dec2bin(hex2dec(tmp), 16));
			} else {
				for (int i = 1; i < strlen(tmp); i++) tmp[i-1] = tmp[i];
				tmp[strlen(tmp)-1] = '\0';
				strcat(newLine, dec2bin(atoi(tmp), 16));
			}
		}

	} else if (lineType == 4) {
		strcat(newLine, "0000000000");
		token = strtok(NULL, " ,\n");
		if (token[0] == 'R') {
			strcat(newLine, "0");
			for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
			token[strlen(token)-1] = '\0';
			strcat(newLine, dec2bin(atoi(token), 16));
		} else if (token[0] == '#') {
			strcat(newLine, "1");
			if (token[1] == 'h') {
				for (int i = 2; i < strlen(token); i++) token[i-2] = token[i];
				token[strlen(token)-2] = '\0';
				strcat(newLine, dec2bin(hex2dec(token), 16));
			} else {
				for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
				token[strlen(token)-1] = '\0';
				strcat(newLine, dec2bin(atoi(token), 16));
			}
		}
	} else if (lineType == 5) {
		token = strtok(NULL, " ,\n");
		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';
		strcat(newLine, dec2bin(atoi(token), 5));
		strcat(newLine, "0000000000000000000000");
	} else if (lineType == 6) {
		strcat(newLine, "000000000000000000000000000");
	}

	strcat(newLine, "\n");

	/*
	 * end
	 */

	strcpy(line, newLine);

}

void translateFile () {

	/*
	 * variables
	 */

	FILE * file;
	FILE * newFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	/*
	 * translate
	 */

	file = fopen("fileWithoutLabels.txt", "r");
	newFile = fopen("binFile.txt", "w");

	while ((read = getline(&line, &len, file)) != -1) {
		translateLine(line);
		fputs(line, newFile);
	}

	/*
	 * end
	 */

	fclose(file);
	fclose(newFile);

}

/****** MAIN ******/

//int main(void) {
	//translateFile();
	//return 0;
//}