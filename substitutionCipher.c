#include <functions.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TABLE(i) (tableOfSubstitutionChars[alphabet[(i)]])
#define CHAR(c) (tableAlphabetIndex[(c)])
#define FORWARD 1
#define BACKWARD 0

extern const char alphabet[];

/**
 *	Stores forwards substitution
 */
static char tableOfSubstitutionChars[LAST_ASCII_CHAR_INDEX] = {0};

/** 
 *	Stores backwards substitution
 */	
static char tableOfSubstitutionCharsInv[LAST_ASCII_CHAR_INDEX] = {0};

/**
 *	Stores customized ASCII indexes
 */
static char tableAlphabetIndex[LAST_ASCII_CHAR_INDEX] = {0};

/** 
 *	Stores characteres that need to shift (because of key bit)
 */
static char charsNeededToMove[ALPHABET_LENGTH] = {0};	

static void checkTableOfSubstitutionChars()
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
				printf("%s\n", "lala");
			}
		}
		else
			printf("No reference for %c\n", 'c');
	}
}

static void printTables()
{
	// DEBUGing
	if(DEBUG)
	{
		int i;
		printf("\n*** DEBUG: Substitution table:");
		printf("\n*** DEBUG: Alphabet:");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", alphabet[i]);

		printf("\n*** DEBUG: SubTable:");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", TABLE(i));

		printf("\n*** DEBUG: InvTable:");
		for(i = 0; i < ALPHABET_LENGTH; i++)
			printf("%c ", tableOfSubstitutionCharsInv[alphabet[i]]);
		printf("\n");
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

static unsigned char getByte(int key, int ith)
{
	return (isLittleEndian() ?
		* (((char *)(&key)) + (ith % sizeof(int))):
		* (((char *)(&key)) + ((DOUBLE_KEY_SIZE - ith) % sizeof(int)))
	);
}

static void passWhereKeyBitIs1(int key)
{
	unsigned char byte;
	int byteIndex, bitIndex, alphIndex, zeroIndex = 0;
	char leftOrRight = 0; // 0 - L, 1 - R
	char substituteChar;
	// Now, pass all posititions where key bit == 1
	for(byteIndex = 0; byteIndex < DOUBLE_KEY_SIZE; byteIndex++)
	{
		alphIndex = byteIndex * 8;
		byte = getByte(key, byteIndex);
		for(bitIndex = 0; bitIndex < 8 && alphIndex < ALPHABET_LENGTH; bitIndex++, alphIndex++)
		{
//printf("Passing where bit == 1, alphIndex = %i\n", alphIndex);
			if(byte & (1 << bitIndex))
			{
				TABLE(alphIndex) = alphabet[alphIndex];
				//printf("TABLE(alphIndex) = %c\n", alphabet[alphIndex]);
			}
			else
			{
				//printf("TABLE(alphIndex) = -\n");
				TABLE(alphIndex) = '-';
				charsNeededToMove[zeroIndex++] = alphIndex + 1;
			}
		}
	}
}

static void shiftPosition(char alphIndex, char * lastLeft, char * lastRight, char * leftOrRight)
{
	char oldChar;
	char subsIndex;
	char ll, lr, lor;

	ll  = *lastLeft;
	lr  = *lastRight;
	lor = *leftOrRight;
	oldChar = alphabet[alphIndex];
	//printf("Finding a new position for %c\n", oldChar);

	// Right
	if(lor)
	{
		while(TABLE(--lr) != '-' && lr >= 0)
			;//printf("R: lr = %i, TABLE(lr) = %c\n", lr, TABLE(lr));
		subsIndex = lr;
	}
	// Left
	else
	{
		while(TABLE(++ll) != '-' && ll < ALPHABET_LENGTH)
			;//printf("L: ll = %i, TABLE(ll) = %c\n", ll, TABLE(ll));
		subsIndex = ll;
	}
	//printf("New position is %c\n", alphabet[subsIndex]);

	lor = oldChar & 1;

	TABLE(subsIndex) = oldChar;

	*lastLeft 	= ll;
	*lastRight 	= lr;
	*leftOrRight= lor;
}

static void crazilyShift()
{	
	char alphIndex, lastLeft, lastRight, leftOrRight;

	// Helps to find next left or right
	lastRight = ALPHABET_LENGTH;
	lastLeft = -1;
	leftOrRight = 0;

	// Let the duty begin
	for(alphIndex = strlen(charsNeededToMove) - 1; alphIndex >= 0; alphIndex--)
		shiftPosition(charsNeededToMove[alphIndex] - 1, &lastLeft, &lastRight, &leftOrRight);
}

static char initTableOfSubstitutionChars(int key)
{
	// Copy the same characters where the key bit == 1
	passWhereKeyBitIs1(key);

	// Make a kinda crazy shift
	crazilyShift();

	// Create the inverted and alphabet index tables
	int i;
	for(i = 0; i < ALPHABET_LENGTH; i++)
	{
		//printf("For TABLE(i) %c=>%c \n", alphabet[i], TABLE(i));
		tableOfSubstitutionCharsInv[TABLE(i)] = alphabet[i];

		// Finally build the alphabet index, to ease calculations
		tableAlphabetIndex[alphabet[i]] = i;
	}

	printTables();
	return 1;
}

static char * substitute(const char * plainText, size_t length, int key, char forwardOrBackward)
{
	// Make sure substitution table is ok
	static int oldKey = 0;
	if(oldKey != key)
	{
		initTableOfSubstitutionChars(key);
		oldKey = key;
	}

	int cipherIndex = 0;
	char * cipheredText = (char *)malloc(sizeof(char) * length);
	char newChar, oldChar;

	for(; cipherIndex < length; cipherIndex++)
	{
		oldChar = plainText[cipherIndex];
		if(forwardOrBackward)
		{
			newChar = tableOfSubstitutionChars[oldChar];
			//printf("[%c] => %c\n", oldChar, newChar);
			//printf("(CHAR(new) + key %% ALPHABET_LENGTH = %i\n", abs(CHAR(newChar) + key) % ALPHABET_LENGTH);
			//cipheredText[cipherIndex] = alphabet[abs((CHAR(newChar) + key) % ALPHABET_LENGTH)];
			cipheredText[cipherIndex] = newChar;
			//printf("ciphered %c\n", cipheredText[cipherIndex]);
		}
		else
		{
			//printf("Received %c\n", oldChar);
			//printf("(CHAR(oldChar) - key %% ALPHABET_LENGTH = %i\n", abs(CHAR(oldChar) - key) % ALPHABET_LENGTH);
			//newChar = alphabet[abs((CHAR(oldChar) - key) % ALPHABET_LENGTH)];	
			//printf("new char %c\n", newChar);
			//cipheredText[cipherIndex] = tableOfSubstitutionCharsInv[newChar];
			//printf("Plain %c\n", cipheredText[cipherIndex]);
			cipheredText[cipherIndex] = tableOfSubstitutionCharsInv[oldChar];
		}
	}
	return cipheredText;
}

char * substitutionCipher(const char * plainText, size_t length, int key)
{
	if(!plainText)
		return;

	char * cipheredText = substitute(plainText, length, key, FORWARD);

	return cipheredText;
}

char * substitutionDecipher(const char * cipheredText, size_t length, int key)
{
	if(!cipheredText)
		return NULL;

	char * plainText = substitute(cipheredText, length, key, BACKWARD);

	return plainText;
}