/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
 */

void proprifyLine (char line[T_MAX]) {

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
		strcat(newLine, token);
		token = strtok(NULL, " \t");
		if (token != NULL) {
			if (token[0] == ',') {
				strcat(newLine, ",");
				if (strlen(token) > 1) {
					for (int i = 1; i < strlen(token); i++) token[i-1] = token[i];
					token[strlen(token)-1] = '\0';
				} else {
					token = strtok(NULL, " \t");
				}
			}
		}
		strcat(newLine, " ");
	}

	newLine[strlen(newLine)-1] = '\0';

	/*
	 * end
	 */

	strcpy(line, newLine);

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