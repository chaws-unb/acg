#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_COMBINATIONS 8 * 7 * 6 * 5 * 4 * 3 * 2
#define COMBINATIONS_FILE "combinations.txt"

int * keyColumnGenerator(int key){
	int * columnKey = (int *)malloc(sizeof(int) * BLOCK_SIZE);
	int columnIndex = 0;
	int checkIndex = 0;
	int value = 0;
	for(; columnIndex < BLOCK_SIZE; columnIndex++){
		value = abs(key % BLOCK_SIZE);
		key = key >> 4;
		int ok;
		do {
			ok = 1;
			checkIndex = 0;
			for(;checkIndex < columnIndex; checkIndex++){
				if(columnKey[checkIndex] == value){
					value = (value + 1) % BLOCK_SIZE;
					ok = 0;
					break;
				}
			}
		} while (!ok);
		columnKey[columnIndex] = value;
	}

	return columnKey;
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

	int columnIndex = 0,rowsIndex = 0, pi = 0;
	for(;columnIndex < BLOCK_SIZE; columnIndex++){
		for(;rowsIndex < rows; rowsIndex++){
			pi = rowsIndex * BLOCK_SIZE + *(keyColumn + columnIndex);
			cipheredText[columnIndex * rows + rowsIndex] = pi < length ? plainText[pi] : '0';
		}
	 rowsIndex = 0;
	}

	return cipheredText;
}

char * transpositionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	char * plainText = (char *)malloc(sizeof(char) * length + 1);
	plainText[length + 1] = '\0';
	int rows = ((int)length / BLOCK_SIZE) +	 (((int)length % BLOCK_SIZE) ? 1 : 0);
	char * text = (char *)malloc(rows*BLOCK_SIZE);
	int *keyColumn;

	keyColumn = keyColumnGenerator(key);

	int columnIndex = 0,rowsIndex = 0, pi = 0;
	for(;columnIndex < BLOCK_SIZE; columnIndex++){
		for(;rowsIndex < rows; rowsIndex++){
			pi = rowsIndex * BLOCK_SIZE + *(keyColumn + columnIndex);
			if( pi < length){
				plainText[pi] = cipheredText[columnIndex * rows + rowsIndex];
			}
			
		}
	 rowsIndex = 0;
	}
  int padIndex;
  for (padIndex=length-BLOCK_SIZE; padIndex < length; padIndex++){
    if(plainText[padIndex] == '0'){
      plainText[padIndex] = '\0';
    }
  }

	return plainText;
}

char * crackTransposition()
{
	static char initTable = 0;
	static char * table = NULL;
	if(initTable)
		return table;

	// Read the combinations from a file
	FILE * file = fopen(COMBINATIONS_FILE, "r");
	if(!file)
	{
		printf("Combinations file not found!\n");
		return NULL;
	}

	table = (char *)malloc(sizeof(char) * MAX_COMBINATIONS * BLOCK_SIZE);

	// Generate the combinationsTable
	int i, j;
	for(i = 0; i < MAX_COMBINATIONS; i++, getc(file) /* remove \n */)
		for(j = 0; j < BLOCK_SIZE; j++)
			table[i * BLOCK_SIZE + j] = getc(file) - '0'; // from numbers 0 - 7, not character

	initTable = 1;
	fclose(file);

	return table;
}
