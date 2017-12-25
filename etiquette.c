#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_MAX 512

// int detectLabelError (char ligne[T_MAX]);
void extractlabel (char ligne[T_MAX], char label[T_MAX]);
int nbLinesPerFile (char filename[T_MAX]);
void removeLabelsFromFile (char filename[T_MAX]);
void removeLabelFromLine (char line[T_MAX]) ;

/*
int detectLabelError (char ligne[T_MAX]) {
	char* label = extractlabel(ligne);
	if (label != NULL) {
		if (strstr(label, " ")) {
			return 1;
		}
		return 0;
	}
	return 0;
}
*/

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

void removeLabelsFromFile (char filename[T_MAX]) {

	/*
	 * variables
	 */

	FILE * file;
	FILE * newFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int lineCounter = 0;
	char listIndex[nbLinesPerFile(filename)][T_MAX];
	char label[T_MAX];

	/*
	 * store labels
	 */

	file = fopen(filename, "r");
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
	file = fopen(filename, "r");
	// char * tmp = NULL;
	// int i;

	while ((read = getline(&line, &len, file)) != -1) {
		removeLabelFromLine(line);
		/*
		if (line[0] == 'J') {
			tmp = strtok(line, " ");
			tmp = strtok(NULL, " ");
			if (ContainsLabel(listIndex,tmp) != -1) {
				i = ContainsLabel(listIndex,tmp);
				i = i*4;
				ChangeLabelFromLine(line,tmp,i);
				fputs(line,NewFile);
			}
		} else fputs(line,NewFile);
		*/
		fputs(line, newFile);
	}
	

	/*
	 * end
	 */

	if (line) free(line);
	fclose(newFile);
	fclose(file);

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
	while (line[i] == ' ' || line[i] == '\t') {
		i++;
	}
	while (line[i] != '\0') {
		newLine[j] = line[i];
		j++;
		i++;
	}
	newLine[j] = '\0';
	strcpy(line, newLine);

}



int main(void) {
	removeLabelsFromFile("testFile.txt");
	return 0;
}