/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
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

		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';

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
			for (int i = counter; i < strlen(token); i++) token[i-counter] = token[i];
			token[strlen(token)-counter] = '\0';
		} else {
			return 1;
		}

	}

	return 0;

}

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

		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';

	} else {
		
		while (token[counter] != '(') {
			midToken[counter] = token[counter];
			counter++;
		}
		
		strcat(newLine, midToken);
		strcat(newLine, " ");

		if (counter < strlen(token)) {
			for (int i = counter; i < strlen(token); i++) token[i-counter] = token[i];
			token[strlen(token)-counter] = '\0';
		} else {
			return 1;
		}

	}

	return 0;

}

int proprifyTokenWithClose (char * token, char newLine[T_MAX]) {

	if (token[0] == ')' && strlen(token) > 1) {

		newLine[strlen(newLine)-1] = ')';

		for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
		token[strlen(token)-1] = '\0';

	} else {

		strcat(newLine, token);
		return 1;

	}

	return 0;

}

void proprifyLineWithComma (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t");

	while (token != NULL) {

		if (strstr(token, ",")) {
			if (proprifyTokenWithComma(token, newLine)) token = strtok(NULL, " \t");;
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

void proprifyLineWithOpen (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t");

	while (token != NULL) {

		if (strstr(token, "(")) {
			if (proprifyTokenWithOpen(token, newLine)) token = strtok(NULL, " \t");;
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

void proprifyLineWithClose (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;

	/*
	 * code
	 */

	token = strtok(line, " \t");

	while (token != NULL) {

		if (strstr(token, ")")) {
			if (proprifyTokenWithClose(token, newLine)) token = strtok(NULL, " \t");;
		} else {
			strcat(newLine, token);
			strcat(newLine, " ");
			token = strtok(NULL, " \t");
		}

	}

	/*
	 * end
	 */

	newLine[strlen(newLine)] = '\0';
	strcpy(line, newLine);

}

void proprifyLine (char line[T_MAX]) {

	proprifyLineWithOpen(line);
	proprifyLineWithClose(line);
	proprifyLineWithComma(line);

}


void proprifyFile (char filename[T_MAX]) {

	/*
	 * variables
	 */

	FILE * file;
	FILE * newFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	/*
	 * code
	 */
	
	file = fopen(filename, "r");
	newFile = fopen("proprifiedFile.txt", "w");

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
