/*
 * INCLUDES
 */

#include "lib.h"

/*
 * FUNCS
 */

/** 
 * TODO (comment)
 */
void shift(char * token, int number) {

	for (int i = number; i < strlen(token); i++) token[i-number] = token[i];
	token[strlen(token)-number] = '\0';

}

/** 
 * TODO (comment)
 */
char* bin2hex (char bin[T_MAX]) {

	/*
	 * variables
	 */

	char * hex = malloc(sizeof(char) * (strlen(bin)/4+1));

	/*
	 * translate
	 */

	for (int i = 0; i < strlen(bin); i += 4){
		char binNumber[5] = {bin[i], bin[i+1], bin[i+2], bin[i+3], '\0'};
		if (strcmp(binNumber, "0000") == 0) hex[i/4] = '0';
		if (strcmp(binNumber, "0001") == 0) hex[i/4] = '1';
		if (strcmp(binNumber, "0010") == 0) hex[i/4] = '2';
		if (strcmp(binNumber, "0011") == 0) hex[i/4] = '3';
		if (strcmp(binNumber, "0100") == 0) hex[i/4] = '4';
		if (strcmp(binNumber, "0101") == 0) hex[i/4] = '5';
		if (strcmp(binNumber, "0110") == 0) hex[i/4] = '6';
		if (strcmp(binNumber, "0111") == 0) hex[i/4] = '7';
		if (strcmp(binNumber, "1000") == 0) hex[i/4] = '8';
		if (strcmp(binNumber, "1001") == 0) hex[i/4] = '9';
		if (strcmp(binNumber, "1010") == 0) hex[i/4] = 'A';
		if (strcmp(binNumber, "1011") == 0) hex[i/4] = 'B';
		if (strcmp(binNumber, "1100") == 0) hex[i/4] = 'C';
		if (strcmp(binNumber, "1101") == 0) hex[i/4] = 'D';
		if (strcmp(binNumber, "1110") == 0) hex[i/4] = 'E';
		if (strcmp(binNumber, "1111") == 0) hex[i/4] = 'F';
	}

	/*
	 * end & return
	 */

	hex[strlen(bin)/4] = '\0';
	return hex;

}

/**
 * TODO (comment)
 */
char* hex2bin (char hex[T_MAX]) {

	/*
	 * variables
	 */

	char * bin = malloc(sizeof(char) * (strlen(hex)*4+1));

	/*
	 * translate
	 */

	for (int i = 0; i < strlen(hex); i++) {
		if (hex[i] == '0') strcat(bin, "0000");
		if (hex[i] == '1') strcat(bin, "0001");
		if (hex[i] == '2') strcat(bin, "0010");
		if (hex[i] == '3') strcat(bin, "0011");
		if (hex[i] == '4') strcat(bin, "0100");
		if (hex[i] == '5') strcat(bin, "0101");
		if (hex[i] == '6') strcat(bin, "0110");
		if (hex[i] == '7') strcat(bin, "0111");
		if (hex[i] == '8') strcat(bin, "1000");
		if (hex[i] == '9') strcat(bin, "1001");
		if (hex[i] == 'A' || hex[i] == 'a') strcat(bin, "1010");
		if (hex[i] == 'B' || hex[i] == 'b') strcat(bin, "1011");
		if (hex[i] == 'C' || hex[i] == 'c') strcat(bin, "1100");
		if (hex[i] == 'D' || hex[i] == 'd') strcat(bin, "1101");
		if (hex[i] == 'E' || hex[i] == 'e') strcat(bin, "1110");
		if (hex[i] == 'F' || hex[i] == 'f') strcat(bin, "1111");
	}

	/*
	 * end & return
	 */

	bin[strlen(hex)*4] = '\0';
	return bin;

}

/** 
 * TODO (comment)
 */
char* dec2bin (int dec, int nbBits, int a2) {

	/*
	 * variables
	 */

	char bin[T_MAX] = "";
	char * newBin = NULL;

	/*
	 * code
	 */

	if (a2 == 0) {
		newBin = dec2bin (dec, nbBits+1, 1);
		shift(newBin, 1);
		return newBin;
	}

	if (dec >= pow(2, nbBits-1) || dec < -1*pow(2, nbBits-1)) {
		printf("FAILURE: Could not convert into binary, bits number is insufficient\n");
		return NULL;
	}

	if (dec >= 0) {

		bin[0] = '0';

		for (int i = nbBits-2; i >= 0; i--) {
			if (dec >= pow(2, i)) {
				bin[nbBits-1-i] = '1';
				dec -= pow(2, i);
			} else {
				bin[nbBits-1-i] = '0';
			}
		}

	} else {

		bin[0] = '0';

		dec = abs(dec) - 1;

		for (int i = nbBits-2; i >= 0; i--) {
			if (dec >= pow(2, i)) {
				bin[nbBits-1-i] = '1';
				dec -= pow(2, i);
			} else {
				bin[nbBits-1-i] = '0';
			}
		}

		for (int i = 0; i < strlen(bin); i++) bin[i] = (bin[i] == '0') ? '1' : '0';

	}

	/*
	 * end & return
	 */

	bin[nbBits] = '\0';
	return strdup(bin);

}

/** 
 * TODO (comment)
 */
int bin2dec (char bin[T_MAX]) {

	/*
	 * variables
	 */

	int dec = 0;

	/*
	 * translate
	 */

	if (bin[0] == '0') {
		
		for (int i = strlen(bin)-1; i >= 0; i--) {
			dec += (bin[i] == '1') ? pow(2, strlen(bin)-1-i) : 0;
		}

	} else {
		
		for (int i = 0; i < strlen(bin); i++) bin[i] = (bin[i] == '0') ? '1' : '0';
		dec = -1* (bin2dec(bin) + 1);

	}

	/*
	 * end & return
	 */

	return dec;

}

/** 
 * TODO (comment)
 */
int hex2dec (char hex[T_MAX]) {

	return bin2dec(hex2bin(hex));

}