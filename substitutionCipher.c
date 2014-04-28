#include <functions.h>
#include <stdlib.h>
#include <stdio.h>

extern const char alphabet[];
static char tableOfSubstitutionChars[LAST_ASCII_CHAR_INDEX] = {0};
static char tableOfSubstitutionCharsInverted[LAST_ASCII_CHAR_INDEX] = {0};

void checkTableOfSubstitutionChars()
{
	printf("Checking tableOfSubstitutionChars\n");
	char * table = tableOfSubstitutionChars;
	int i, j;
	for(i = 0; i < ALPHABET_LENGTH; i++)
	{
		if(table[alphabet[i]])
		{
			for(j = 0; j < ALPHABET_LENGTH; j++)
			{
				printf("\n" );
			}
		}
		else
			printf("No reference for \n" );
	}
}

void printTables()
{
	// DEBUGing
	if(DEBUG)
	{
		int i;
		printf("\n*** DEBUG: Substitution table:");
		printf("\n*** DEBUG: ");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", alphabet[i]);

		printf("\n*** DEBUG: ");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", tableOfSubstitutionChars[alphabet[i]]);

		printf("\n*** DEBUG: ");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", tableOfSubstitutionCharsInverted[tableOfSubstitutionChars[alphabet[i]]]);
	}
}

// 1 - Little endian
// 0 - Big endian
static char isLittleEndian()
{
	static char endianess = -1;
	if(endianess != -1)
		return endianess;
	int number = 1;
	endianess = (*((char *)(&number)) & 1);
	return endianess;
}

static void crazilyShift(int key)
{	
	char * table = tableOfSubstitutionChars;
	unsigned char doubleKey[DOUBLE_KEY_SIZE] = {0};
	unsigned char byte;
	int sizeofInt = sizeof(int);
	int newIndex = 0;
	int i, j;

	// Init the table
	//for(i = 0; i < ALPHABET_LENGTH; i++)
		//table[alphabet[i]] = alphabet[i];

	// Goes through number of bytes of the key
	for(i = 0; i < DOUBLE_KEY_SIZE; i++)
	{
		byte = (isLittleEndian() ?
				* (((char *)(&key)) + (i % sizeof(int))):
				* (((char *)(&key)) + ((DOUBLE_KEY_SIZE - i) % sizeof(int)))
			   );
		printf("byte = %X\n", byte);

		// Just copies the chars where the key has 1 as bit
		for(j = 0; j < 8 && (i * 8 + j) < ALPHABET_LENGTH; j++)
		{
			// bit == 1
			if(byte & (1 << j)) 
			{
				table[alphabet[i * 8 + j]] = alphabet[i * 8 + j];
			}
		}
		doubleKey[i] = byte;
	}

	printTables();
	
	// Now, move the rest
	for(i = 0; i < DOUBLE_KEY_SIZE; i++)
	{
		// Just copies the chars where the key has 1 as bit
		for(j = 0; j < 8 && (i * 8 + j) < ALPHABET_LENGTH; j++)
		{
			// bit == 0
			if((doubleKey[i] & (1 << j)) == 0)
			{
				newIndex = i * 8 + j;
				char oldChar = alphabet[newIndex];
			INC_NEW_INDEX:
				newIndex++;
				newIndex %= ALPHABET_LENGTH;
				// Check if that position is already in use
				if(table[alphabet[newIndex]])
					goto INC_NEW_INDEX;

				table[alphabet[newIndex]] = oldChar;
				printf("\nSetou %c na posicao %i['%c']\n", alphabet[i * 8 + j], alphabet[i * 8 + j], alphabet[i * 8 + j]);
			}
		}
	}

	printTables();
}

static char initTableOfSubstitutionChars(int key)
{
	char * table = tableOfSubstitutionChars;
	char * invTable = tableOfSubstitutionCharsInverted;
	unsigned char cipherChar;
	char plainChar;

	int i;

	crazilyShift(key);

	for(i = 0; i < ALPHABET_LENGTH; i++)
	{
		plainChar = table[alphabet[i]];
		cipherChar = alphabet[((unsigned char)(plainChar + key)) % ALPHABET_LENGTH];
		printf("plainChar = %c, cipherChar = %c\n", plainChar, cipherChar);

		if(DEBUG)
		{
			//printf("\n*** DEBUG: [i=%i] plainChar = %c, cipherChar = %i", i, plainChar, cipherChar);
		}

		// Finally set the substitution table
		table[plainChar] = cipherChar;
	}

	printTables();

	return 1;
}

char * substitutionCipher(const char * plainText, size_t length, int key)
{
	// Make sure substitution table is ok
	static char tableInitialized = 0;	
	if(!tableInitialized)
		tableInitialized = initTableOfSubstitutionChars(key);

	if(!plainText)
		return;

	int cipherIndex = 0;
	char * cipheredText = (char *)malloc(sizeof(char) * length);

	for(; cipherIndex < length; cipherIndex++)
	{
		char oldChar = plainText[cipherIndex];
		char newChar = tableOfSubstitutionChars[oldChar];
		cipheredText[cipherIndex] = newChar;
	}

	return cipheredText;
}

char * substitutionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;



	return NULL;
}