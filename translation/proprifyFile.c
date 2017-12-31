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
int proprifyTokenWithComma (char * token, char newLine[T_MAX]) {

	/*
	 * variables
	 */

	char midToken[T_MAX] = "";
	int counter = 0;

	/*
	 * code
	 */

	if (strcmp(token, ",") == 0) {

		newLine[strlen(newLine)-1] = ',';
		strcat(newLine, " ");

		return 1;

	} else if (token[0] == ',') {

		newLine[strlen(newLine)-1] = ',';
		strcat(newLine, " ");

		shift(token, 1);

	} else {
		
		while (token[counter] != ',') {
			midToken[counter] = token[counter];
			counter++;
		}
		
		midToken[counter] = ',';
		midToken[counter+1] = '\0';
		counter++;
		
		strcat(newLine, midToken);
		strcat(newLine, " ");

		if (counter < strlen(token)) {
			shift(token, counter);
		} else {
			return 1;
		}

	}

	return 0;

}

/** 
 * TODO (comment)
 */
int proprifyTokenWithOpen (char * token, char newLine[T_MAX]) {

	/*
	 * variables
	 */

	char midToken[T_MAX] = "";
	int counter = 0;

	/*
	 * code
	 */

	if (strcmp(token, "(") == 0) {
		
		strcat(newLine, token);
		return 1;

	} else if (token[0] == '(') {

		strcat(newLine, "(");

		shift(token, 1);

	} else {
		
		while (token[counter] != '(') {
			midToken[counter] = token[counter];
			counter++;
		}
		
		strcat(newLine, midToken);
		strcat(newLine, " ");

		if (counter < strlen(token)) {
			shift(token, counter);
		} else {
			return 1;
		}

	}

	return 0;

}

/** 
 * TODO (comment)
 */
int proprifyTokenWithClose (char * token, char newLine[T_MAX]) {

	/*
	 * variables
	 */

	char midToken[T_MAX] = "";
	int counter = 0;

	/*
	 * code
	 */

	if (strcmp(token, ")") == 0) {

		newLine[strlen(newLine)-1] = ')';
		strcat(newLine, " ");

		return 1;

	} else if (token[0] == ')') {

		newLine[strlen(newLine)-1] = ')';
		strcat(newLine, " ");

		shift(token, 1);

	} else {

		while (token[counter] != ')') {
			midToken[counter] = token[counter];
			counter++;
		}
		
		midToken[counter] = ')';
		midToken[counter+1] = '\0';
		counter++;
		
		strcat(newLine, midToken);
		strcat(newLine, " ");

		if (counter < strlen(token)) {
			shift(token, counter);
		} else {
			return 1;
		}

	}

	return 0;

}

/** 
 * TODO (comment)
 */
void proprifyLineWithComma (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t\r\n");

	while (token != NULL) {

		if (strstr(token, ",")) {
			if (proprifyTokenWithComma(token, newLine)) token = strtok(NULL, " \t\r\n");;
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t\r\n");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

/** 
 * TODO (comment)
 */
void proprifyLineWithOpen (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t\r\n");

	while (token != NULL) {

		if (strstr(token, "(")) {
			if (proprifyTokenWithOpen(token, newLine)) token = strtok(NULL, " \t\r\n");;
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t\r\n");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

/** 
 * TODO (comment)
 */
void proprifyLineWithClose (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t\r\n");

	while (token != NULL) {

		if (strstr(token, ")")) {
			if (proprifyTokenWithClose(token, newLine)) token = strtok(NULL, " \t\r\n");
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t\r\n");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

/** 
 * TODO (comment)
 */
void proprifyLine (char line[T_MAX]) {

	proprifyLineWithOpen(line);
	proprifyLineWithClose(line);
	proprifyLineWithComma(line);
	strcat(line, "\n");

}

/** 
 * TODO (comment)
 */
void proprifyFile (char filename[T_MAX]) {

	/*
	 * variables
	 */

	FILE * file = NULL;
	FILE * newFile = NULL;
	char * line = NULL;
	size_t len = 0;
	ssize_t read = 0;

	/*
	 * code
	 */
	

	file = fopen(filename, "r");
	newFile = fopen("proprifiedFile.txt", "w");

	if (file == NULL) {
		printf("FAILURE: File doesn't exist (%s)", filename);
		exit(0);
	}

	while ((read = getline(&line, &len, file)) != -1) {
		proprifyLine(line);
		fputs(line, newFile);
	}

	/*
	 * end
	 */

	fclose(file);
	fclose(newFile);

}
