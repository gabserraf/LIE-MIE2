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