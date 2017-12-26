#ifndef LISTE_H
#define LISTE_H

/*
 * INCLUDES
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

/*
 * DEFINE
 */

#define T_MAX 512

/*
 * DECLARATIONS
 */

char*	bin2hex (char bin[T_MAX]);
char*	dec2bin (int dec, int nbBits);
int		hex2dec (char hex[T_MAX]);
void 	translateLine (char line[T_MAX]);
void 	translateFile ();
int 	nbLinesPerFile (char filename[T_MAX]);
void 	proprifyLine(char line[T_MAX]);
void 	proprifyFile (char filename[T_MAX]);
void 	extractlabel (char line[T_MAX], char label[T_MAX]);
void 	removeLabelFromLine (char line[T_MAX]);
void 	changeLabelFromLine (char line[T_MAX], int labelAdress);
void 	removeLabelsFromFile ();
void 	putSpace (char line[T_MAX]);
void 	translateFileBin2Hexa ();

/*
 * END
 */

#endif