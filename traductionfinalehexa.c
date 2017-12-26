#include "liste.h"

/*
 * DECLARATIONS
 */

void PutSpace (char line[T_MAX]);
void TranslateFileBin2Hexa ();

/*
 * FUNCS
 */


void PutSpace (char line[T_MAX]) {
	char LineCopy[T_MAX] = "";
	int counter = 0;
	int index = 0;

	for (int i = 0; i < strlen(line); i++) {
		LineCopy[index] = line[i];
		counter++;
		index++;
		if (counter == 2) {
			LineCopy[index] = ' ';
			counter = 0;
			index++;
		}
	}

	strcpy(line, LineCopy);
}

void TranslateFileBin2Hexa () {

	/*
	 * variables
	 */

	FILE* file;
	FILE* newFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char* newLine = NULL ;
	char LineJump[] = "\n";


	/*
	 * translating
	 */

	file = fopen("binFile.txt", "r");
	newFile = fopen("hexaFile.txt", "w");

	while ((read = getline(&line, &len, file)) != -1) {
		newLine = bin2hex(line);
		PutSpace(newLine);
		fputs(newLine, newFile);
		fputs(LineJump,newFile);
	}


	/*
	 * end
	 */


	fclose(file);
	fclose(newFile);
}




/****** MAIN ******/

int main(void) {
	TranslateFileBin2Hexa("binFile.txt");
	return 0;
}


