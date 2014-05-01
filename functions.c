#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char alphabet[] = {
	' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y','X','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','x','z'
};

char compareToAlphabet(const char * string, size_t length)
{
	if(string == NULL)
		return 1;
	int i, j, found;
	for(i = 0; i < length; i++)
	{
		for(found = j = 0; !found && j < ALPHABET_LENGTH; j++)
			if(string[i] == alphabet[j])
				found = 1;

		if(!found)
			return 1;
	}
	return 0;
}

char * cipher(const char * plainText, size_t length, int key)
{
	return productCipher(plainText, length, key);
}

char * decipher(const char * cipheredText, size_t length, int key)
{
	return productDecipher(cipheredText, length, key);
}

static char * applyCombination(const char * cipheredText, size_t length, char * combination)
{

}

char * breaker_bf(char * cipheredText, size_t length)
{
	// Will store an array of ~40k position, 
	// each position contains a different combination of 8 chars
	char * possibleCombinations;

	// Stores one simple combination
	char combination[BLOCK_SIZE]; 

	// Number of combinations
	int combinations = 8 * 7 * 6 * 5 * 4 * 3 * 2, i;

	// Will store the cipheredText with a specific combination applied
	char * textCombined = NULL;

	// Will store a likely to be plain text, returned after a breaker_s on textCombined
	char * likelyPlain = NULL;

	// Generate it only once
	possibleCombinations = crackTransposition();

	for(i = 0; i < combinations; i++)
	{
		// Copy one combination
		memcpy(combination, possibleCombinations + (i * BLOCK_SIZE), BLOCK_SIZE);

		// mix chars
		textCombined = applyCombination(cipheredText, length, combination);

		// Test if something comes from this text
		likelyPlain = breaker_s(textCombined, length);
		if(likelyPlain != NULL)
			return likelyPlain;
	}
}

char * breaker_s(char * cipheredText, size_t length)
{
	return crackSubstitution(cipheredText, length);
}