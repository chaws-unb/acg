#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern const char alphabet[];

char * transpositionCipher(const char * plainText, size_t length, int key)
{
	if(!plainText)
		return NULL;

	int cipherIndex = 0, blockIndex = 0, newPosition = 0, addValueToCipherIndex = 0;
	int i = 0;
	char newBlock[BLOCK_SIZE];
	int resto = ((int) length) % BLOCK_SIZE;
	int size = (int) length + resto;
	char * cipheredText = (char *)malloc(sizeof(char) * size);
	char * plainTextInt = (char *)malloc(sizeof(char) * size);
	memcpy(plainTextInt, plainText, (int)length);

	for(; cipherIndex <= size; cipherIndex+=BLOCK_SIZE)
	{
		
		for(; blockIndex < BLOCK_SIZE; blockIndex++){
			newPosition = (blockIndex ^ key) % BLOCK_SIZE;
			newBlock[newPosition] = plainTextInt[cipherIndex + blockIndex];			
		}

		for(; addValueToCipherIndex < BLOCK_SIZE; addValueToCipherIndex++){
			cipheredText[cipherIndex + addValueToCipherIndex] = newBlock[addValueToCipherIndex];
		}

		blockIndex = 0;
		addValueToCipherIndex = 0;
	}


	return cipheredText;
}

char * transpositionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	int decipherIndex = 0, blockIndex = 0, newPosition = 0, addValueToDecipherIndex = 0;
	int i = 0;
	int j = 0;
	char newBlock[BLOCK_SIZE];
	char * plainText = (char *)malloc(sizeof(char) * length);

	for(; decipherIndex < length; decipherIndex+=BLOCK_SIZE)
	{
		
		for(; blockIndex < BLOCK_SIZE; blockIndex++){
			newPosition = (blockIndex ^ key) % BLOCK_SIZE;
			newBlock[newPosition] = cipheredText[decipherIndex + blockIndex];			
		}

		for(; addValueToDecipherIndex < BLOCK_SIZE; addValueToDecipherIndex++){
			plainText[decipherIndex + addValueToDecipherIndex] = newBlock[addValueToDecipherIndex];
		}

		blockIndex = 0;
		addValueToDecipherIndex = 0;
	}

		return plainText;
	
}