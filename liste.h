#ifndef LISTE_H
#define LISTE_H



#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#define T_MAX 512

char* bin2hex (char bin[T_MAX]);
char* dec2bin (int dec, int nbBits);
int hex2dec (char hex[T_MAX]);
void translateLine (char line[T_MAX]);
void translateFile ();
int nbLinesPerFile (char filename[T_MAX]);
void proprifyLine(char line[T_MAX]);
void proprifyFile (char filename[T_MAX]);
void extractlabel (char ligne[T_MAX], char label[T_MAX]);
void removeLabelFromLine (char line[T_MAX]);
void changeLabelFromLine (char line[T_MAX], int labelAdress);
void removeLabelsFromFile ();
void PutSpace (char line[T_MAX]);
void TranslateFileBin2Hexa ();





#endif