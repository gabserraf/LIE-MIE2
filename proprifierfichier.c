/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
 */

void removeCompressement (char newLine[T_MAX]) {

	char tmp[T_MAX] = "";
	int i = 0;
	int index;
	int j = 0;


	
	/*if ( (newLine[strlen(newLine)-1] != 'B' || newLine[strlen(newLine)-1] != 'H' || newLine[strlen(newLine)-1] != 'W') && strlen(newLine) >= 4) {
		while (newLine[i] != 'B' || newLine[i] != 'H' || newLine[i] != 'W') {
			i++;
		}
		index = ++i;
		while(newLine[i] != '\0') {
			tmp[j] = newLine[i]; 
			i++;
			j++;
		}
		tmp[j] = '\0';
		newLine[index] = '\0';
		strcat(newLine, " ");
		strcat(newLine, tmp);
	}
	i = 0;
	j = 0;
	strcpy(tmp,"");
	while (newLine[i] != ',') i++;
	index = ++i;
	if (newLine[index] != ' ') {
		while (newLine[i] != '\0') {
			tmp[j] = newLine[i];
			j++;
			i++;
		}
		newLine[index] = '\0';
		strcat(newLine, " ");
		strcat(newLine, tmp);
	} */

	i = 0;
	j = 0;
	strcpy(tmp, "");
	while (newLine[i] != ',') {
		i++;
	}
	index = ++i;
	if (newLine[index] != ' ') {
		while (newLine[i] != '\0') {
			tmp[j] = newLine[i];
			j++;
			i++;
		}
		newLine[index]  = '\0';
		strcat(newLine, " ");
		strcat(newLine, tmp);
	}

	

}


void proprifyLine (char line[T_MAX]) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;
	//int dejaentre = 0;
	int dejaentre1 = 0;

	/*
	 * code
	 */

	token = strtok(line, " \t");



	while (token != NULL) {
		strcat(newLine, token);
		/*if  (strstr(newLine, "ST") && dejaentre != 1 ) {
			dejaentre++;
			removeCompressement(newLine);
		} */
		if  ( strstr(newLine, "LD") && dejaentre1 != 1 )  {
			dejaentre1++;
			removeCompressement(newLine);
		}
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
			} if (newLine[strlen(newLine)-1] == '(') {
				newLine[strlen(newLine)-1] = ' ';
				strcat(newLine, "(");
				strcat(newLine, token);
				token = strtok(NULL, " \t");
				strcat(newLine, " ");

			} if (token[0] == '(') {
				if (strlen(token) == 1) {
					strcat(newLine, " ");
					strcat(newLine, "(");
					token = strtok(NULL, " \t");
					strcat(newLine, token);
					token = strtok(NULL, " \t");
				}
			} if (token[0] == ')') {
				if (strlen(token) == 1) {
					if (newLine[strlen(newLine)-1] != ' ' ) strcat(newLine, ")");
					else newLine[strlen(newLine)-1] = ')';
				} else strcat(newLine, token);
				token = strtok(NULL, " \t");
			} 		
		}
		if (newLine[strlen(newLine)-1] != ' ' && newLine[strlen(newLine)-1] != ')') strcat(newLine, " ");
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