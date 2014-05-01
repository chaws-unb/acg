#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

#define DEBUG 0
#define LAST_ASCII_CHAR_INDEX 123
#define BLOCK_SIZE 8
#define DOUBLE_KEY_SIZE 2 * sizeof(int)

// The size of this alphabet, with uper, lower cases, numbers and space
#define ALPHABET_LENGTH 63
const char alphabet[ALPHABET_LENGTH];

/**
 *	Make sure the string entered is the same as the ones specified
 *	for alphabet
 *	Return 0 if it's ok, 1 if there's at least one invalid character
 */
char compareToAlphabet(const char * string, size_t length);

/**
 *	Cipher the plain text using a substitution cipher
 */
char *   substitutionCipher(const char * plainText, size_t length, int key);
char * substitutionDecipher(const char * cipheredText, size_t length, int key);
char * 	  crackSubstitution(char * cipheredText, size_t length);

/**
 *	Cipher the plain text using a transposition cipher
 */
char *   transpositionCipher(const char * plainText, size_t length, int key);
char * transpositionDecipher(const char * cipheredText, size_t length, int key);
char *    crackTransposition(); // Actually, generates all possible combinations and return an array with it

/**
 *	Cipher the plain text using a product cipher
 *	Actually it uses previous cipher algorithms combined
 */
char *   productCipher(const char * plainText, size_t length, int key);
char * productDecipher(const char * cipheredText, size_t length, int key);

/**
 *	Cipher any text using the cipher functions above
 */
char * cipher(const char * plainText, size_t length, int key);

/**
 *	This is the hardest function, you gotta receive a ciphered text
 *	and decipher it!!!
 *	How: I don't know!
 */
char * decipher(const char * cipheredText, size_t length, int key);

/**
 *	Breaker functions:
 *	Tries to break a ciphered text using brute-force to generate
 *	positions likely to be correct and send each one to breaker_s
 */
char * breaker_bf(char * cipheredText, size_t length);

/**
 *	Breaker functions:
 *	Tries to find patterns with words computador and seguranca
 *	to make guesses about the substitution table
 */
char * breaker_s(char * cipheredText, size_t length);

#endif