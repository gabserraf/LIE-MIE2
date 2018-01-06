#ifndef LIB_H
#define LIB_H

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

/* auxiliaries */

void shift (char * token, int number);
int nbLinesPerFile (char filename[T_MAX]);
int command2lineType (char* command);
char* bin2hex (char bin[T_MAX]);
char* hex2bin (char hex[T_MAX]);
char* dec2bin (int dec, int nbBits, int a2);
int hex2dec (char hex[T_MAX]);

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

void extractlabel (char line[T_MAX], char label[T_MAX]);
void changeLabelFromLine (char line[T_MAX], int labelAdress);
void removeLabelFromLine (char line[T_MAX]);
void removeLabelsFromFile ();

/* detectError */

int detectErrorHexaFromChar (char p);
int detectErrorHexaFromLine (char token[T_MAX]);
int detectErrorDecFromChar (char p);
int detectErrorDecFromLine (char token[T_MAX]);
int detectErrorFromRegister (char token[T_MAX]);
int detectLabelErrorFromLine (char line[T_MAX]);
int detectSyntaxErrorFromLine (char line[T_MAX]);
void detectLabelErrorFromFile (char filename[T_MAX], int* n);
int detectErrorFromFile ();

/* translate the file to hexa */

void putSpace (char line[T_MAX]);
void translateSToken(char newLine[T_MAX], char* token);
void translateLine2Bin (char line[T_MAX]);
void translateFile2Bin ();
void translateFileBin2Hexa ();
void translate (char filename[T_MAX]);

/*
 * END
 */

#endif