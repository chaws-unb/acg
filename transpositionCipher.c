#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * keyColumnGenerator(int key){
	static int r[8];
	int i = 0;
	int j = 0;
	int value = 0;
	for(; i < BLOCK_SIZE; i++){
		value = abs(key % BLOCK_SIZE);
		key = key >> 4;
		int ok;
		do {
			ok = 1;
			j = 0;
			for(;j<i; j++){
				if(r[j] == value){
					value += 1 % BLOCK_SIZE;
					ok = 0;
					break;
				}
			}
		} while (!ok);
		r[i] = value;
	}

	return r;
}

char * transpositionCipher(const char * plainText, size_t length, int key)
{
	if(!plainText)
		return NULL;

	int tam = length + length % BLOCK_SIZE + 1;
	char * cipheredText = (char *)malloc(sizeof(char) * tam);
	cipheredText[tam - 1] = '\0';
	int rows = ((int)length / BLOCK_SIZE) + (((int)length % BLOCK_SIZE) ? 1 : 0);
	char * text = (char *)malloc(rows*BLOCK_SIZE);
	int *keyColumn;

	keyColumn = keyColumnGenerator(key);
	int keyIndex = 0;

	int i = 0,j = 0, pi = 0;
	for(;i < BLOCK_SIZE; i++){
		for(;j < rows; j++){
			pi = j * BLOCK_SIZE + *(keyColumn + i);
			cipheredText[i * rows + j] = pi < length ? plainText[pi] : '!';
		}
	 j = 0;
	}

	return cipheredText;
}

char * transpositionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	char * plainText = (char *)malloc(sizeof(char) * length + 1);
	plainText[length] = '\0';
	int rows = ((int)length / BLOCK_SIZE) + (((int)length % BLOCK_SIZE) ? 1 : 0);
	char * text = (char *)malloc(rows*BLOCK_SIZE);
	int *keyColumn;

	keyColumn = keyColumnGenerator(key);
	int i = 0,j = 0, pi = 0;
	for(;i < BLOCK_SIZE; i++){
		for(;j < rows; j++){
			pi = j * BLOCK_SIZE + *(keyColumn + i);
			if( pi < length){
				plainText[pi] = cipheredText[i * rows + j];
			}
			
		}
	 j = 0;
	}
	// for (i=length-BLOCK_SIZE; i<length; i++) {
	// 	printf("I: %i, C: %c\n",i, plainText[i] );
	// 	if (plainText[i] == '!') {
	// 		plainText[i] = '\0';
	// 	}
	// }

	return plainText;
}