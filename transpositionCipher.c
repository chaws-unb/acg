#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char * transpositionCipher(const char * plainText, size_t length, int key)
{
	if(!plainText)
		return NULL;

	char * cipheredText = (char *)malloc(sizeof(char) * length);
	int rows = ((int)length / BLOCK_SIZE) + (((int)length % BLOCK_SIZE) ? 1 : 0);
	char * text = (char *)malloc(rows*BLOCK_SIZE);
	//Idéia é transformar a chave em um vetor do estilo:
	int keyColumn[BLOCK_SIZE] = {4,2,0,7,5,1,6,3};
	int i = 0,j = 0, pi = 0;
	for(;i < rows; i++){
		for(;j < BLOCK_SIZE; j++){
			text[i * BLOCK_SIZE + j] = plainText[pi] == '\0' ? ' ' : plainText[pi++];
			printf("%c", text[i * BLOCK_SIZE + j]);
			if( j == 7){
				printf("\n");
			}
		}
	 j = 0;
	}

	int indexI = 0, indexJ = 0, ci = 0;
	for(; indexI < BLOCK_SIZE ; indexI++){
		for(;indexJ < rows ; indexJ++){
			cipheredText[ci++] = text[indexJ * BLOCK_SIZE + keyColumn[indexI]];
		}
		indexJ = 0;
	}

	return cipheredText;
}

char * transpositionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	char * plainText = (char *)malloc(sizeof(char) * length);
	int rows = ((int)length / BLOCK_SIZE) + (((int)length % BLOCK_SIZE) ? 1 : 0);
	char * text = (char *)malloc(rows*BLOCK_SIZE);
	//Idéia é transformar a chave em um vetor do estilo:
	int keyColumn[BLOCK_SIZE] = {4,2,0,7,5,1,6,3};
	int i = 0,j = 0, pi = 0;
	printf("----------------------DECIPHER--------------------\n");
	for(;i < BLOCK_SIZE; i++){
		for(;j < rows; j++){
			text[j * BLOCK_SIZE + i] = cipheredText[pi] == '\0' ? ' ' : cipheredText[pi++];
		}
	 j = 0;
	}
	int k = 0, l=0;
	for(; k < rows; k++){
		for(;l< BLOCK_SIZE; l++){
			printf("%c", text[k*BLOCK_SIZE+l]);
			if(l == 7){
				printf("\n");
			}
		}
		l=0;
	}

	int indexI = 0, indexJ = 0, ci = 0;
	for(; indexI < rows ; indexI++){
		for(;indexJ < BLOCK_SIZE ; indexJ++){
			plainText[ci++] = text[indexI * BLOCK_SIZE + keyColumn[indexJ]];
		}
		indexJ = 0;
	}

	return plainText;
}