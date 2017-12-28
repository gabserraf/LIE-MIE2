/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
 */

/** 
 * TODO (comment)
 */
void extractlabel (char line[T_MAX], char label[T_MAX]) {
	
	if (strstr(line, ":")) {
		int counter = 0;	
		while (line[counter] != ':') {
			label[counter] = line[counter];
			counter++;
		}
		label[counter] = '\0';
	}

}

/** 
 * TODO (comment)
 */
void changeLabelFromLine (char line[T_MAX], int labelAdress) {

	/*
	 * variables
	 */

	char newLine[T_MAX] = "";
	char * token = NULL;
	char adresse[T_MAX] = " #\0";
	char strLabelAdr[T_MAX];

	/*
	 * code
	 */

	token = strtok(line, " \r\n");
	sprintf(strLabelAdr, "%d", labelAdress);
	strcat(adresse, strLabelAdr);
	strcat(adresse, "\n");
	strcat(newLine, token);
	strcat(newLine, adresse);

	/*
	 * end
	 */

	strcpy(line, newLine);

}

/** 
 * TODO (comment)
 */
void removeLabelFromLine (char line[T_MAX]) {
	
	/*
	 * variables
	 */

	int counter = 0;

	/*
	 * code
	 */

	if (strstr(line, ":")) {
		while (line[counter] != ':') {
			counter++;
		}
		counter++;
	}

	while (line[counter] == ' ') {
		counter++;
	}

	/*
	 * end
	 */

	shift(line, counter);

}

/** 
 * TODO (comment)
 */
void removeLabelsFromFile () {

	/*
	 * variables
	 */

	FILE * file;
	FILE * newFile;
	char * token = NULL;
	char * line = NULL;
	char listIndex[nbLinesPerFile("proprifiedFile.txt")][T_MAX];
	char label[T_MAX];
	char copyLine[T_MAX];
	int lineCounter = 0;
	int labelAdress;
	size_t len = 0;
	ssize_t read;

	/*
	 * store labels
	 */

	file = fopen("proprifiedFile.txt", "r");

	if (file == NULL) {
		printf("FAILURE: File doesn't exist (proprifiedFile.txt)");
		exit(0);
	}

	while ((read = getline(&line, &len, file)) != -1) {
		label[0] = '\0';
		extractlabel(line, label);
		strcpy(listIndex[lineCounter], label);
		lineCounter++;
	}

	fclose(file);

	/*
	 * create new file
	 */

	newFile = fopen("fileWithoutLabels.txt", "w");
	file = fopen("proprifiedFile.txt", "r");

	while ((read = getline(&line, &len, file)) != -1) {

		removeLabelFromLine(line);

		strcpy(copyLine, line);

		labelAdress = -1;
		
		if (line[0] == 'J') {

			token = strtok(line, " \r\n");
			token = strtok(NULL, " \r\n");

			for (int i = 0; i < lineCounter; i++) {
				if (strcmp(listIndex[i], token) == 0) labelAdress = 4*i;
			}

			if (labelAdress != -1) changeLabelFromLine(line, labelAdress);

		}

		if (labelAdress != -1) fputs(line, newFile);
		else fputs(copyLine, newFile);

	}

	/*
	 * end
	 */

	if (line) free(line);
	fclose(newFile);
	fclose(file);

}