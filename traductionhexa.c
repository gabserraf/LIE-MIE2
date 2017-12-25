#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define T_MIN 16
#define T_MAX 512

char* HexaConverter (char bin[32]);
char * recupererNombreBinaire(int nbrBits,int nbrAconvertir);


char* HexaConverter (char bin[32]) {

	int i = 0;
	char *tab = malloc(sizeof(char) * 9);
	for (i = 0; i < 32; i += 4){
		char binNumber[5] = {bin[i], bin[i+1], bin[i+2], bin[i+3], '\0'};
		if (strcmp(binNumber, "0000") == 0) tab[i/4] = '0';
		if (strcmp(binNumber, "0001") == 0) tab[i/4] = '1';
		if (strcmp(binNumber, "0010") == 0) tab[i/4] = '2';
		if (strcmp(binNumber, "0011") == 0) tab[i/4] = '3';
		if (strcmp(binNumber, "0100") == 0) tab[i/4] = '4';
		if (strcmp(binNumber, "0101") == 0) tab[i/4] = '5';
		if (strcmp(binNumber, "0110") == 0) tab[i/4] = '6';
		if (strcmp(binNumber, "0111") == 0) tab[i/4] = '7';
		if (strcmp(binNumber, "1000") == 0) tab[i/4] = '8';
		if (strcmp(binNumber, "1001") == 0) tab[i/4] = '9';
		if (strcmp(binNumber, "1010") == 0) tab[i/4] = 'A';
		if (strcmp(binNumber, "1011") == 0) tab[i/4] = 'B';
		if (strcmp(binNumber, "1100") == 0) tab[i/4] = 'C';
		if (strcmp(binNumber, "1101") == 0) tab[i/4] = 'D';
		if (strcmp(binNumber, "1110") == 0) tab[i/4] = 'E';
		if (strcmp(binNumber, "1111") == 0) tab[i/4] = 'F';
	}

	tab[8] = '\0';

	return tab;

}

char * recupererNombreBinaire(int nbrBits,int nbrAconvertir){

	int bits[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
	int i = 0;
  	char nbrBinaire[20] = "";
	int j = 0;

  	for (i = nbrBits-1 ; i >= 0; i--, j++) {
       if(bits[i] <= nbrAconvertir) {
		nbrBinaire[j] = '1';
        nbrAconvertir -= bits[i];
       }
       else
       {
		nbrBinaire[j]='0';
       }
 	}
	printf("%s\n", nbrBinaire);
	nbrBinaire[nbrBits]  = 0;
  	return strdup(nbrBinaire);
}

int main(void) {
	char* p = recupererNombreBinaire(5,28);
	printf("%s",p);
	printf("%d",strlen(p));
	free(p);
	return 0;
}