/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
 */

/**
 * détecte si un char est bien hexadecimal
 * @params p, le char a tester (char)
 * @return 1 s'il y a une erreur, 0 sinon
 */
int detectErrorHexaFromChar (char p) {
	
	if (detectErrorDecFromChar(p) == 0) return 0;

	else if (p == 'a' || p == 'A' || p == 'b' || p == 'B' || p == 'c' || p == 'C' || p == 'd' || p == 'D' || p == 'e' || p == 'E' || p == 'f' || p == 'F')
		return 0;

	return 1;

}

int detectErrorHexaFromLine (char token[T_MAX]) {
	

	for (int i = 2; i < strlen(token); i++) token[i-2] = token[i];
	token[strlen(token)-2] = '\0';

	if (strlen(token) > 4) return 1;

	if (strlen(token) == 0) return 1;

	for (int i = 0; i < strlen(token); i++) {
		if (detectErrorHexaFromChar(token[i])) return 1;
	}

	return 0;

}

int detectErrorDecFromChar (char p) {
	
	for (int i = 0; i < 10; i++) {
		char c = i + '0';
		if (p == c) return 0;
	}

	return 1;

}

int detectErrorDecFromLine (char token[T_MAX]) {
	
	for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
	token[strlen(token)-1] = '\0';

	if (strlen(token) == 0) return 1;

	for (int i = 0; i < strlen(token); i++) {
		if (detectErrorDecFromChar(token[i])) return 1;
	}

	return atoi(token) > 65535;

}

int detectErrorFromRegister (char token[T_MAX]) {
	
	if (token[0] != 'R') return 1;
	
	if (strlen(token) < 2) return 1;

	for (int i = 0; i < strlen(token); i++) token[i-1] = token[i];
	token[strlen(token)-1] = '\0';

	for (int i = 0; i < 32; i++) {
		char s[3];
		sprintf(s, "%d", i);
		if (strcmp(token, s) == 0) return 0;
	}

	return 1;

}

int detectLabelErrorFromLine (char line[T_MAX]) {
	
	char label[T_MAX] = "";
	extractlabel(line, label);
	
	if (strstr(label, " ")) return 1;
	
	return 0;
}

/*
void detectLabelErrorFromFile (char filename[T_MAX], int* n) {



	FILE * fileCopy;
	char listIndex[nbLinesPerFile(filename)][T_MAX];
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char label[T_MAX];
	int lineCounter = 0;
	int counter = 0;




	fileCopy = fopen(filename, "r");
	if (fileCopy == NULL) {
		*n = -2;
		return;
	}
	while ((read = getline(&line, &len, fileCopy)) != -1) {
		label[0] = '\0';
		counter++;
		if (detectLabelErrorFromLine(line) == 1) {
			*n = counter;
			return;
		}
		extractlabel(line, label);
		strcpy(listIndex[lineCounter], label);
		lineCounter++;
	}

	fclose(fileCopy);

	int i = 0;
	while (strcmp(listIndex[i], "\0") != 0) {
		printf("%s\n", listIndex[i]);
		i++;
	}


	fileCopy = fopen(filename, "r");
	line = NULL;
	len = 0;
	int i = 0;
	counter = 0;
	*n = 0;
	char* token = NULL;



	while ((read = getline(&line, &len, fileCopy)) != -1) {
		token = strtok(line, "                                                         \t");
		counter++;
		if( strcmp(token, "JMP") == 0 || strcmp(token, "JZS") == 0 || strcmp(token, "JZC") == 0 || strcmp(token, "JCS") == 0 || strcmp(token, "JCC") == 0 || strcmp(token, "JNS") == 0 || strcmp(token, "JNC") == 0) {
			token = strtok(NULL, "                                                    \t");
			printf("token %s",token);
			i = 0;
			while (strcmp(listIndex[i], "\0") != 0 ) {
				printf("list index %s",listIndex[i]);
				if (strcmp(listIndex[i], token) == 0) {
					*n = 1;
				}
				i++;
			}
		}
		if (n == 0) {
			*n = counter;
			return;
		}
	}
	fclose(fileCopy); 

}
*/


int command2lineType (char* command) {
	if (strcmp(command, "OR") == 0) return 1;
	else if (strcmp(command, "XOR") == 0) return 1;
	else if (strcmp(command, "AND") == 0) return 1;
	else if (strcmp(command, "ADD") == 0) return 1;
	else if (strcmp(command, "SUB") == 0) return 1;
	else if (strcmp(command, "MUL") == 0) return 1;
	else if (strcmp(command, "DIV") == 0) return 1;
	else if (strcmp(command, "SHR") == 0) return 1;
	else if (strcmp(command, "LDB") == 0) return 2;
	else if (strcmp(command, "LDH") == 0) return 2;
	else if (strcmp(command, "LDW") == 0) return 2;
	else if (strcmp(command, "STB") == 0) return 3;
	else if (strcmp(command, "STH") == 0) return 3;
	else if (strcmp(command, "STW") == 0) return 3;
	else if (strcmp(command, "JMP") == 0) return 4;
	else if (strcmp(command, "JZS") == 0) return 4;
	else if (strcmp(command, "JZC") == 0) return 4;
	else if (strcmp(command, "JCS") == 0) return 4;
	else if (strcmp(command, "JCC") == 0) return 4;
	else if (strcmp(command, "JNS") == 0) return 4;
	else if (strcmp(command, "JNC") == 0) return 4;
	else if (strcmp(command, "IN") == 0) return 5;
	else if (strcmp(command, "OUT") == 0) return 5;
	else if (strcmp(command, "RND") == 0) return 1;
	else if (strcmp(command, "HLT") == 0) return 6;
	else return 0;
}



int detectSyntaxErrorFromLine (char line[T_MAX]) {	
	
	/*
	 * variables
	 */
	
	char * token = NULL;
	int lineType;

	/*
	 * code
	 */

	proprifyLine(line);

	token = strtok(line, " \n");
	lineType = command2lineType(token);

	if (lineType == 0) return 1;

	if (lineType == 1) {
		
		for (int i = 0; i < 2; i++) {
			token = strtok(NULL, " ");
			if (token == NULL) return 1;
			if (token[strlen(token)-1] != ',') return 1;
			token[strlen(token)-1] = '\0';
			if (detectErrorFromRegister(token)) return 1;
		}

		token = strtok(NULL, " ");
		if (token == NULL) return 1;
		if (token[0] == 'R') {
			if (detectErrorFromRegister(token)) return 1;
		} else if (token[0] == '#') {
			if (strlen(token) < 2) return 1;
			if (token[1] == 'h') {
				if (detectErrorHexaFromLine(token)) return 1;
			} else {
				if (detectErrorDecFromLine(token)) return 1;
			}
		} else {
			return 1;
		}

		token = strtok(NULL, " ");
		return token != NULL;

	}

	if (lineType == 2) {
		// TODO
	}

	if (lineType == 3) {
		// TODO
	}

	if (lineType == 4) {

		token = strtok(NULL, " ");
		if (token == NULL) return 1;
		if (token[0] == 'R') {
			if (detectErrorFromRegister(token)) return 1;
		} else if (token[0] == '#') {
			if (strlen(token) < 2) return 1;
			if (token[1] == 'h') {
				if (detectErrorHexaFromLine(token)) return 1; 
			} else {
				if (detectErrorDecFromLine(token)) return 1;
			}
		} else {
			return 1;
		}

		token = strtok(NULL, " ");
		return token != NULL;

	}

	if (lineType == 5) {
		
		token = strtok(NULL, " ");
		if (token == NULL) return 1;
		if (token[strlen(token)-1] != ',') return 1;
		token[strlen(token)-1] = '\0';
		if (detectErrorFromRegister(token)) return 1;

		token = strtok(NULL, " ");
		return token != NULL;

	}

	if (lineType == 6) {

		token = strtok(NULL, " ");
		return token != NULL;

	}

	/*
	 * end
	 */

	return 1;

}


/******** MAIN ********/

int main(void) {
	char p[T_MAX] = "JMP #h22\0";
	//char token[T_MAX] = "#h2\0";
	//printf("%d\n", detectErrorHexaFromLine(token));
	printf("%d", detectSyntaxErrorFromLine(p));
	return 0;
}