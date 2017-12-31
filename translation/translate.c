/*
 * INCLUDES
 */

#include "lib.h"

/*
 * FUNCS
 */

/** 
 * TODO (comment)
 */
void putSpace(char line[T_MAX]) {
	
	/*
	 * variables
	 */

	char LineCopy[T_MAX] = "";
	int counter = 0;
	int index = 0;

	/*
	 * code
	 */

	for (int i = 0; i < strlen(line); i++) {
		LineCopy[index] = line[i];
		counter++;
		index++;
		if (counter == 2) {
			LineCopy[index] = ' ';
			counter = 0;
			index++;
		}
	}

	/*
	 * end
	 */

	strcpy(line, LineCopy);

}

/** 
 * TODO (comment)
 */
void translateSToken(char newLine[T_MAX], char* token) {

	if (token[0] == 'R') {
		strcat(newLine, "0");
		shift(token, 1);
		strcat(newLine, dec2bin(atoi(token), 16, 0));
	} else if (token[0] == '#') {
		strcat(newLine, "1");
		shift(token, 1);
		if (token[0] == 'h') {
			shift(token, 1);
			strcat(newLine, dec2bin(hex2dec(token), 16, 1));
		} else {
			strcat(newLine, dec2bin(atoi(token), 16, 1));
		}
	}

}

/** 
 * TODO (comment)
 */
void translateLine2Bin(char line[T_MAX]) {

	/*
	 * variables
	 */


	char * token = NULL;
	char newLine[T_MAX] = "";
	char tmp[T_MAX] = "";
	int lineType;

	/*
	 * translate
	 */

	token = strtok(line, " ,\r\n");

	if (token == NULL) return;

	if (strcmp(token, "OR") == 0) strcat(newLine, dec2bin(0, 5, 0));
	else if (strcmp(token, "XOR") == 0) strcat(newLine, dec2bin(1, 5, 0));
	else if (strcmp(token, "AND") == 0) strcat(newLine, dec2bin(2, 5, 0));
	else if (strcmp(token, "ADD") == 0) strcat(newLine, dec2bin(3, 5, 0));
	else if (strcmp(token, "SUB") == 0) strcat(newLine, dec2bin(4, 5, 0));
	else if (strcmp(token, "MUL") == 0) strcat(newLine, dec2bin(5, 5, 0));
	else if (strcmp(token, "DIV") == 0) strcat(newLine, dec2bin(6, 5, 0));
	else if (strcmp(token, "SHR") == 0) strcat(newLine, dec2bin(7, 5, 0));
	else if (strcmp(token, "LDB") == 0) strcat(newLine, dec2bin(8, 5, 0));
	else if (strcmp(token, "LDH") == 0) strcat(newLine, dec2bin(9, 5, 0));
	else if (strcmp(token, "LDW") == 0) strcat(newLine, dec2bin(10, 5, 0));
	else if (strcmp(token, "STB") == 0) strcat(newLine, dec2bin(11, 5, 0));
	else if (strcmp(token, "STH") == 0) strcat(newLine, dec2bin(12, 5, 0));
	else if (strcmp(token, "STW") == 0) strcat(newLine, dec2bin(13, 5, 0));
	else if (strcmp(token, "JMP") == 0) strcat(newLine, dec2bin(20, 5, 0));
	else if (strcmp(token, "JZS") == 0) strcat(newLine, dec2bin(21, 5, 0));
	else if (strcmp(token, "JZC") == 0) strcat(newLine, dec2bin(22, 5, 0));
	else if (strcmp(token, "JCS") == 0) strcat(newLine, dec2bin(23, 5, 0));
	else if (strcmp(token, "JCC") == 0) strcat(newLine, dec2bin(24, 5, 0));
	else if (strcmp(token, "JNS") == 0) strcat(newLine, dec2bin(25, 5, 0));
	else if (strcmp(token, "JNC") == 0) strcat(newLine, dec2bin(26, 5, 0));
	else if (strcmp(token, "IN") == 0) strcat(newLine, dec2bin(28, 5, 0));
	else if (strcmp(token, "OUT") == 0) strcat(newLine, dec2bin(29, 5, 0));
	else if (strcmp(token, "RND") == 0) strcat(newLine, dec2bin(30, 5, 0));
	else if (strcmp(token, "HLT") == 0) strcat(newLine, dec2bin(31, 5, 0));

	lineType = command2lineType(token);

	if (lineType == 1) {
		
		/* token 1 & 2 --> Rd, Rn */

		for (int k = 0; k < 2; k++) {
			token = strtok(NULL, " ,\r\n");
			shift(token, 1);
			strcat(newLine, dec2bin(atoi(token), 5, 0));
		}
		
		/* token 3 --> S */

		token = strtok(NULL, " ,\r\n");
		translateSToken(newLine, token);


	} else if (lineType == 2) {
		
		/* token 1 & 2 --> Rd, Rn */

		for (int k = 0; k < 2; k++) {
			token = strtok(NULL, " ,()\r\n");
			shift(token, 1);
			strcat(newLine, dec2bin(atoi(token), 5, 0));
		}

		/* token 3 --> S */

		token = strtok(NULL, " ,()\r\n");
		translateSToken(newLine, token);

	} else if (lineType == 3) {

		/* token 1 --> Rd */

		token = strtok(NULL, " ,()\r\n");

		shift(token, 1);
		strcat(newLine, dec2bin(atoi(token), 5, 0));
		
		/* token 2 --> S */

		token = strtok(NULL, " ,()\r\n");
		strcpy(tmp, token);
		
		/* token 3 --> Rn */

		token = strtok(NULL, " ,()\r\n");
		
		shift(token, 1);
		strcat(newLine, dec2bin(atoi(token), 5, 0));

		/* end token 2 --> S */

		translateSToken(newLine, tmp);

	} else if (lineType == 4) {
		
		strcat(newLine, "0000000000");

		/* token 1 --> S */

		token = strtok(NULL, " \r\n");
		translateSToken(newLine, token);

	} else if (lineType == 5) {
		
		/* token 1 --> Rd */

		token = strtok(NULL, " \r\n");
		shift(token, 1);
		strcat(newLine, dec2bin(atoi(token), 5, 0));

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

/** 
 * TODO (comment)
 */
void translateFile2Bin() {

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

	if (file == NULL) {
		printf("FAILURE: File doesn't exist (fileWithoutLabels.txt)");
		exit(0);
	}

	while ((read = getline(&line, &len, file)) != -1) {
		translateLine2Bin(line);
		fputs(line, newFile);
	}

	/*
	 * end
	 */

	fclose(file);
	fclose(newFile);

}

/** 
 * TODO (comment)
 */
void translateFileBin2Hexa() {

	/*
	 * variables
	 */

	FILE* file;
	FILE* newFile;
	size_t len = 0;
	ssize_t read;
	char * line = NULL;
	char * newLine = NULL;
	char* token = NULL;

	/*
	 * translate
	 */

	file = fopen("binFile.txt", "r");
	newFile = fopen("../hexaFile.txt", "w");

	if (file == NULL) {
		printf("FAILURE: File doesn't exist (binFile.txt)");
		exit(0);
	}

	while ((read = getline(&line, &len, file)) != -1) {
		token = strtok(line, " \t\r\n");
		if (token != NULL) {
			newLine = bin2hex(line);
			putSpace(newLine);
			strcat(newLine, "\n");
			fputs(newLine, newFile);
		}
	}


	/*
	 * end
	 */

	fclose(file);
	fclose(newFile);

}

/** 
 * TODO (comment)
 */
void translate(char filename[T_MAX]) {

	proprifyFile(filename);
	removeLabelsFromFile();
	
	if (detectErrorFromFile()) {
		remove("proprifiedFile.txt");
		remove("fileWithoutLabels.txt");
		exit(0);
	}

	translateFile2Bin();
	translateFileBin2Hexa();
	
	remove("proprifiedFile.txt");
	remove("fileWithoutLabels.txt");
	remove("binFile.txt");
	
}

/****** MAIN *******/

int main (int argc, char* argv[]) {
	
	char filename[T_MAX] = "../testFile.txt";

	if (argc < 2) {
		printf("FAILURE: filename is required");
		exit(0);
	}

	strcpy(filename, argv[1]);
	translate(filename);

	return 0;

}
