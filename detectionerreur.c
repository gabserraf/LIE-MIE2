#include "liste.h"

/*
 * DECLARATIONS
 */

int detectLabelErrorFromLine (char line[T_MAX]);
void detectLabelErrorFromFile (char filename[T_MAX], int* n);
int detectErrorFromLine (char line[T_MAX]);
int detectErrorHexaFromChar (char p);
int detectErrorFromHexa (char token[T_MAX]);
int detectErrorFromRegister (char token[T_MAX]);

/*
 * FUNCS
 */

int detectErrorHexaFromChar (char p) {
	if (p == '0') return 0;
	if (p == '1') return 0;
	if (p == '2') return 0;
	if (p == '3') return 0;
	if (p == '4') return 0;
	if (p == '5') return 0;
	if (p == '6') return 0;
	if (p == '7') return 0;
	if (p == '8') return 0;
	if (p == '9') return 0;
	if (p == 'a' || p == 'A') return 0;
	if (p == 'b' || p == 'B') return 0;
	if (p == 'c' || p == 'C') return 0;
	if (p == 'd' || p == 'D') return 0;
	if (p == 'e' || p == 'E') return 0;
	if (p == 'f' || p == 'F') return 0;
	return 1;
}

int detectErrorFromHexa (char token[T_MAX]) {
	if (strlen(token) > 4) return 1;
	for (int i = 0; i < strlen(token); i++) {
		if (detectErrorHexaFromChar(token[i]) == 1) return 1;
	}
	return 0;
}

int detectErrorFromRegister (char token[T_MAX]) {
	if (strcmp(token, "0") == 0) return 0;
	if (strcmp(token, "1") == 0) return 0;
	if (strcmp(token, "2") == 0) return 0;
	if (strcmp(token, "3") == 0) return 0;
	if (strcmp(token, "4") == 0) return 0;
	if (strcmp(token, "5") == 0) return 0;
	if (strcmp(token, "6") == 0) return 0;
	if (strcmp(token, "7") == 0) return 0;
	if (strcmp(token, "8") == 0) return 0;
	if (strcmp(token, "9") == 0) return 0;
	if (strcmp(token, "10") == 0) return 0;
	if (strcmp(token, "11") == 0) return 0;
	if (strcmp(token, "12") == 0) return 0;
	if (strcmp(token, "13") == 0) return 0;
	if (strcmp(token, "14") == 0) return 0;
	if (strcmp(token, "15") == 0) return 0;
	if (strcmp(token, "16") == 0) return 0;
	if (strcmp(token, "17") == 0) return 0;
	if (strcmp(token, "18") == 0) return 0;
	if (strcmp(token, "19") == 0) return 0;
	if (strcmp(token, "20") == 0) return 0;
	if (strcmp(token, "21") == 0) return 0;
	if (strcmp(token, "22") == 0) return 0;
	if (strcmp(token, "23") == 0) return 0;
	if (strcmp(token, "24") == 0) return 0;
	if (strcmp(token, "25") == 0) return 0;
	if (strcmp(token, "26") == 0) return 0;
	if (strcmp(token, "27") == 0) return 0;
	if (strcmp(token, "28") == 0) return 0;
	if (strcmp(token, "29") == 0) return 0;
	if (strcmp(token, "30") == 0) return 0;
	if (strcmp(token, "31") == 0) return 0;
	return 1;
}

int detectLabelErrorFromLine (char line[T_MAX]) {
	if (strstr(line, " :")) {
		return 1;
	}
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
		printf("%s\n",listIndex[i]);
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

} */

int detectErrorFromLine (char line[T_MAX]) {
	if (detectLabelErrorFromLine(line) == 1) return 1;
	proprifyFile(line);
	char* token = NULL;
	token = strtok(line, " \n");
	int lineType;


	if (strcmp(token, "OR") == 0) lineType = 1;
	else if (strcmp(token, "XOR") == 0) lineType = 1;
	else if (strcmp(token, "AND") == 0) lineType = 1;
	else if (strcmp(token, "ADD") == 0) lineType = 1;
	else if (strcmp(token, "SUB") == 0) lineType = 1;
	else if (strcmp(token, "MUL") == 0) lineType = 1;
	else if (strcmp(token, "DIV") == 0) lineType = 1;
	else if (strcmp(token, "SHR") == 0) lineType = 1;
	else if (strcmp(token, "LDB") == 0) lineType = 2;
	else if (strcmp(token, "LDH") == 0) lineType = 2;
	else if (strcmp(token, "LDW") == 0) lineType = 2;
	else if (strcmp(token, "STB") == 0) lineType = 3;
	else if (strcmp(token, "STH") == 0) lineType = 3;
	else if (strcmp(token, "STW") == 0) lineType = 3;
	else if (strcmp(token, "JMP") == 0) lineType = 4;
	else if (strcmp(token, "JZS") == 0) lineType = 4;
	else if (strcmp(token, "JZC") == 0) lineType = 4;
	else if (strcmp(token, "JCS") == 0) lineType = 4;
	else if (strcmp(token, "JCC") == 0) lineType = 4;
	else if (strcmp(token, "JNS") == 0) lineType = 4;
	else if (strcmp(token, "JNC") == 0) lineType = 4;
	else if (strcmp(token, "IN") == 0) lineType = 5;
	else if (strcmp(token, "OUT") == 0) lineType = 5;
	else if (strcmp(token, "RND") == 0) lineType = 1;
	else if (strcmp(token, "HLT") == 0) lineType = 6;
	else return 1;

	

	if (lineType == 1) {
		if (token[0] != 'R') return 1;
		token = strtok(NULL, " R,\n");
		printf("%s\n", token);
		if (detectErrorFromRegister(token) == 0) {
			token = strtok(NULL, " R,\n#");
			if (detectErrorFromRegister(token) == 0) {
				token = strtok(NULL, " R,#h\n");
				return detectErrorFromRegister(token);
			}
		}
	}





	if (lineType == 4) {
		token = strtok(NULL, " \n");
		if (token[0] == 'R') {
			if (detectErrorFromRegister(token) == 1) return 1;
			token = strtok(NULL, " \n");
			if (token != NULL) return 1;
			else return 0;
		} else if (token[0] == '#') {
			if (token[1] == 'h') {
				if (strlen(token) > 6) return 1;
				else {
					int count = 0;
					for (int i = 2; i < strlen(token); i++) {
						if (detectErrorHexaFromChar(token[i]) == 1) return 1;
					}
					token = strtok(NULL, " \n");
					if (token != NULL) return 1;
					else return 0;
				}
			}
			else {
				token = strtok(NULL, " \n");
				if (token != NULL) return 1;
				return 0;
			}
		}else return 1;
	}



	if (lineType == 5) {
		token = strtok(NULL, " R\n");
		if (detectErrorFromRegister(token) == 1) return 1;
		token = strtok(NULL, " \n");
		if (token != NULL) return 1;
		return 0;
	}


	if (lineType == 6) {
		if (token == NULL) return 0;
	}
	return 1;
}


/******** MAIN ********/

int main(void) {
	char p[] = "    JZS      #h7   ";
	int i = detectErrorFromLine(p);
	printf("%d",i);

	return 0;
}