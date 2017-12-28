#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int myAtoi(char *str);
char* dec2bin (int dec, int nbBits);
char * ConversionEnC2(char* nombreNegatif,int nbreDeBits);


// fonctions utilisées 

int myAtoi(char *str) {

    int val = 0;
    int index = 0;
    int positif = 1;
    char c;

    if (str[0] == '-') {
        positif = -1;
        index++;
    } else if (str[0] == '+') index++;
    while (isdigit(c = str[index++])) val = 10*val + c - '0';
    return val*positif;
}

char* dec2bin (int dec, int nbBits) {

  /*
   * variables
   */

  char binaryNumb[20] = "";
  int j = 0;

  /*
   * code
   */

  for (int i = nbBits-1; i >= 0; i--, j++) {
    if (dec >= pow(2, i)) {
      binaryNumb[j] = '1';
      dec -= pow(2, i);
    } else {
      binaryNumb[j] = '0';
    }
  }

  binaryNumb[nbBits] = 0;

  /*
   * end & return
   */

  return strdup(binaryNumb);

}

/** 
 * TODO (comment)
 */


// fonction convertir en C2

char * ConversionEnC2 (char* nombreNegatif, int nbreDeBits) {
  nombreNegatif++;
  int i = myAtoi(nombreNegatif); //fonction de Haya
  char buf[100000] = "";

	char* tmp = dec2bin(16,i);  //fonction de Haya

	char* un = "1";
	char * zero = "0";

	//printf("tmp :%s\n", tmp);
	int nombreDeChiffre = 0;

	while (*tmp) {

		if (*tmp == '1') {
			strcat(buf, zero); // ca doit etre dans une bibliotheque, pcq pas fonction de Haya 
		} else {
			strcat(buf, un);  // ca doit etre dans une bibliotheque, pcq pas fonction de Haya 
		}
		tmp++;
		nombreDeChiffre++;
	}

	//printf("buf :%s\n", buf);
	//printf("nombreDeChiffre : %d\n", nombreDeChiffre);
  
  nombreNegatif = strdup(buf);   // ca doit etre dans une bibliotheque, pcq pas fonction de Haya 
  //printf("n :%s\n", nombreNegatif);

  //int retenu=0;
  nombreDeChiffre--;

    if (nombreNegatif[nombreDeChiffre] == '0') {

       nombreNegatif[nombreDeChiffre] = '1';
    }
    else {
         //retenu=1;
         nombreNegatif[nombreDeChiffre]='0';
         nombreDeChiffre--;
         do {
              if (nombreNegatif[nombreDeChiffre] == '0') {
                  nombreNegatif[nombreDeChiffre] = '1';
                  break;
              }
               else {
                  // retenu=1;
                  nombreNegatif[nombreDeChiffre] = '0';
              }
           nombreDeChiffre--;
        } while (nombreDeChiffre) ;
    }
    return strdup(nombreNegatif);
}


int main (void) {
  char p[] = "-2";
  char* tmp = ConversionEnC2(p, 3);
  printf("%s", tmp);
  return 0;
}