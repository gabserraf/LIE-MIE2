/*
 * INCLUDES
 */

#include "liste.h"

/*
 * FUNCS
 */

void putSpace (char line[T_MAX]) {
	
	/*
	 * variables
	 */

	char LineCopy[T_MAX] = "";
	int counter = 0;
	int index = 0;

	/*
	 * code
	 */

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

	/*
	 * end
	 */

	strcpy(line, LineCopy);

}

void translateFileBin2Hexa () {

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
	 * translate
	 */

	file = fopen("binFile.txt", "r");
	newFile = fopen("hexaFile.txt", "w");

	while ((read = getline(&line, &len, file)) != -1) {
		newLine = bin2hex(line);
		putSpace(newLine);
		fputs(newLine, newFile);
		fputs(LineJump,newFile);
	}


	/*
	 * end
	 */

	fclose(file);
	fclose(newFile);

}
