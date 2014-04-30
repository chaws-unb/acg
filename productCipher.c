#include <functions.h>
#include <stdlib.h>
#include <stdio.h>

char * productCipher(const char * plainText, size_t length, int key)
{
	if(!plainText)
		return NULL;

	char * subsCiphered = substitutionCipher(plainText, length, key);
	char * transCiphered = transpositionCipher(subsCiphered, length, key);

	return transCiphered;
}

char * productDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	char * transDeciphered = transpositionDecipher(cipheredText, length, key);
	char * subsDeciphered = substitutionDecipher(transDeciphered, length, key);

	return subsDeciphered;
}