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

/* detectError */

int detectErrorHexaFromChar (char p);
int detectErrorHexaFromLine (char token[T_MAX]);
int detectErrorDecFromChar (char p);
int detectErrorDecFromLine (char token[T_MAX]);
int detectErrorFromRegister (char token[T_MAX]);
int detectLabelErrorFromLine (char line[T_MAX]);
int detectSyntaxErrorFromLine (char line[T_MAX]);
void detectLabelErrorFromFile (char filename[T_MAX], int* n);
int command2lineType (char* command);

/* proprifyFile */

int proprifyTokenWithComma (char * token, char newLine[T_MAX]);
int proprifyTokenWithOpen (char * token, char newLine[T_MAX]);
int proprifyTokenWithClose (char * token, char newLine[T_MAX]);
void proprifyLineWithComma (char line[T_MAX]);
void proprifyLineWithOpen (char line[T_MAX]);
void proprifyLineWithClose (char line[T_MAX]);
void proprifyLine (char line[T_MAX]);
void proprifyFile (char filename[T_MAX]);

/* label */

int nbLinesPerFile (char filename[T_MAX]);
void extractlabel (char line[T_MAX], char label[T_MAX]);
void changeLabelFromLine (char line[T_MAX], int labelAdress);
void removeLabelFromLine (char line[T_MAX]);
void removeLabelsFromFile ();

/* translate2binary */

char* bin2hex (char bin[T_MAX]);
char* dec2bin (int dec, int nbBits);
int hex2dec (char hex[T_MAX]);
void translateLine (char line[T_MAX]);
void translateFile ();

/* translate2hexa */

void putSpace (char line[T_MAX]);
void translateFileBin2Hexa ();

/*
 * END
 */

#endif