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

int nbLinesPerFile (char filename[T_MAX]);
void extractlabel (char ligne[T_MAX], char label[T_MAX]);
void removeLabelFromLine (char line[T_MAX]);
void changeLabelFromLine (char line[T_MAX], int labelAdress);
void removeLabelsFromFile ();

/*
 * FUNCS
 */

int nbLinesPerFile (char filename[T_MAX]) {

	/*
	 * variables
	 */

	FILE * file;
	char * line = NULL;
	int lineCounter = 0;
	size_t len = 0;
	ssize_t read;

	/*
	 * code
	 */

	file = fopen(filename, "r");
	if (file == NULL) {
		printf("FAILURE");
		return 0;
	}

	while ((read = getline(&line, &len, file)) != -1) {
		lineCounter++;
	}

	/*
	 * end & return
	 */

	fclose(file);
	if (line) free(line);

	return lineCounter;

}


void extractlabel (char ligne[T_MAX], char label[T_MAX]) {
	
	if (strstr (ligne,":")) {
		int counter = 0;	
		while (ligne[counter] != ':') {
			label[counter] = ligne[counter];
			counter++;
		}
		label[counter] = '\0';
	}

}

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

	token = strtok(line, " ");
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

void removeLabelFromLine (char line[T_MAX]) {
	
	/*
	 * variables
	 */

	int i = 0;
	int j = 0;
	char newLine[T_MAX];

	/*
	 * code
	 */

	if (strstr(line, ":")) {
		while (line[i] != ':') {
			i++;
		}
		i++;
	}
	while (line[i] == ' ') {
		i++;
	}
	while (line[i] != '\0') {
		newLine[j] = line[i];
		j++;
		i++;
	}
	newLine[j] = '\0';

	/*
	 * code
	 */

	strcpy(line, newLine);

}

void removeLabelsFromFile () {

	/*
	 * variables
	 */

	FILE * file;
	FILE * newFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int lineCounter = 0;
	char listIndex[nbLinesPerFile("proprifiedFile.txt")][T_MAX];
	char label[T_MAX];
	char * token = NULL;
	int labelAdress;

	/*
	 * store labels
	 */

	file = fopen("proprifiedFile.txt", "r");
	if (file == NULL) {
		printf("FAILURE");
		return ;
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
		
		labelAdress = -1;
		
		if (line[0] == 'J') {

			token = strtok(line, " \n");
			token = strtok(NULL, " \n");

			for (int i = 0; i < lineCounter; i++) {
				if (strcmp(listIndex[i], token) == 0) labelAdress = 4*i;
			}

			if (labelAdress != -1) {
				changeLabelFromLine(line, labelAdress);
			}

		}

		fputs(line, newFile);

	}
	

	/*
	 * end
	 */

	if (line) free(line);
	fclose(newFile);
	fclose(file);

}

/****** MAIN ******/

int main(void) {
	proprifyFile("testFile.txt");
	removeLabelsFromFile();
	return 0;
} 