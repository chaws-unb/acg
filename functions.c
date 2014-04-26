#include <functions.h>
#include <stdlib.h>
#include <stdio.h>

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
	char * ciphered = productCipher(plainText, length, key);
	return ciphered;
}

char * decipher(const char * cipheredText, size_t length, int key)
{
	return NULL;
}