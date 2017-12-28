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

/** 
 * TODO (comment)
 */
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

/** 
 * TODO (comment)
 */
int detectErrorDecFromChar (char p) {
	
	for (int i = 0; i < 10; i++) {
		char c = i + '0';
		if (p == c) return 0;
	}

	return 1;

}

/** 
 * TODO (comment)
 */
int detectErrorDecFromLine (char token[T_MAX]) {
	
	shift(token, 1);

	if (strlen(token) == 0) return 1;

	if (token[0] == '-') shift(token, 1);

	for (int i = 0; i < strlen(token); i++) {
		if (detectErrorDecFromChar(token[i])) return 1;
	}

	return atoi(token) > 32767;

}

/** 
 * TODO (comment)
 */
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

/** 
 * TODO (comment)
 */
int detectLabelErrorFromLine (char line[T_MAX]) {
	
	char label[T_MAX] = "";
	extractlabel(line, label);
	
	if (strstr(label, " ")) return 1;
	
	return 0;
	
}

/** 
 * TODO (comment)
 */
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
		
		/* token 1 & 2 --> Rd, Rn */

		for (int i = 0; i < 2; i++) {
			
			token = strtok(NULL, " \r\n");
			if (token == NULL) return 1;

			if (token[strlen(token)-1] != ',') return 1;
			token[strlen(token)-1] = '\0';
			if (detectErrorFromRegister(token)) return 1;

		}

		/* token 3 --> S */

		token = strtok(NULL, " \r\n");
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

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	if (lineType == 2) {
		
		/* token 1 --> Rd, */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (token[strlen(token)-1] != ',') return 1;
		token[strlen(token)-1] = '\0';
		if (detectErrorFromRegister(token)) return 1;

		/* token 2 --> (Rn) */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (token[0] != '(' || token[strlen(token)-1] != ')') return 1;

		token[strlen(token)-1] = '\0';
		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';

		if (detectErrorFromRegister(token)) return 1;

		/* token 3 --> S */

		token = strtok(NULL, " \r\n");
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

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	if (lineType == 3) {

		/* token 1 --> (Rd) */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (token[0] != '(' || token[strlen(token)-1] != ')') return 1;

		token[strlen(token)-1] = '\0';
		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';

		if (detectErrorFromRegister(token)) return 1;

		/* token 2 --> S, */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (token[strlen(token)-1] != ',') return 1;
		token[strlen(token)-1] = '\0';

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

		/* token 3 --> Rn */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (detectErrorFromRegister(token)) return 1;

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	if (lineType == 4) {

		/* token 1 --> S */

		token = strtok(NULL, " \r\n");
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

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	if (lineType == 5) {
		
		/* token 1 --> Rd */

		token = strtok(NULL, " \r\n");
		if (token == NULL) return 1;

		if (detectErrorFromRegister(token)) return 1;

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	if (lineType == 6) {

		/* end */

		token = strtok(NULL, " \r\n");
		return token != NULL;

	}

	/*
	 * end
	 */

	return 1;

}

/** 
 * TODO (comment)
 */
int detectErrorFromFile () {
	
	/*
	 * variables
	 */

	FILE * proprifiedFile = NULL;
	FILE * withoutLabelFile = NULL;
	char * line = NULL;
	size_t len = 0;
	ssize_t read = 0;
	int lineCounter = 0;
	int error = 0;

	/*
	 * detection error - proprifed
	 */

	proprifiedFile = fopen("proprifiedFile.txt", "r");
	
	if (proprifiedFile == NULL) {
		printf("FAILURE");
		return 1;
	}

	while ((read = getline(&line, &len, proprifiedFile)) != -1) {
		lineCounter++;
		if (detectLabelErrorFromLine(line)) {
			printf("Label error on Line %d\n", lineCounter);
			error = 1;
		}
	}

	fclose(proprifiedFile);

	/*
	 * detection error - withoutLabel
	 */

	line = NULL;
	len = 0;
	read = 0;
	lineCounter = 0;

	withoutLabelFile = fopen("fileWithoutLabels.txt", "r");
	if (withoutLabelFile == NULL) {
		printf("FAILURE");
		return 1;
	}

	while ((read = getline(&line, &len, withoutLabelFile)) != -1) {
		lineCounter++;
		if (detectSyntaxErrorFromLine(line)) {
			printf("Syntax error on Line %d\n", lineCounter);
			error = 1;
		}
	}

	fclose(withoutLabelFile);

	/*
	 * end
	 */

	return error;

}