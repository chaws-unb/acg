#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *	Make GCC stop complaining
 */
void test_substitutionCipher();
void test_transpositionCipher();
void test_productCipher();
void runAllTests();

/**
 *	Please, add the new tests to this method
 */
void runAllTests()
{
	test_substitutionCipher();
	//test_transpositionCipher();
	//test_productCipher();
}

/**
 *	Test if the substitution cipher is working
 */
void test_substitutionCipher()
{
	printf("*** Test: substitutionCipher() ***\n");

	int key = 0x01010101;
	const char * plainText = "This is my cool stuffed text with words computador and seguranca";
	size_t length = strlen(plainText);
	char * cipheredText = substitutionCipher(plainText, length, key);
	char * decipheredText = substitutionDecipher(cipheredText, length, key);

	printf("\nPlain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: substitutionCipher() ***\n");
}

/**
 *	Test if the substitution cipher is working
 */
void test_transpositionCipher()
{
	printf("*** Test: transpositionCipher() ***\n");

	int key = 0xBABAD0;
	const char * plainText = "This is my cool stuffed text with words computador and seguranca";
	size_t length = strlen(plainText);
	char * cipheredText = transpositionCipher(plainText, length, key);
	char * decipheredText = transpositionDecipher(cipheredText, length, key);

	printf("\nPlain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: transpositionCipher() ***\n");
}

/**
 *	Test if the substitution cipher is working
 */
void test_productCipher()
{
	printf("*** Test: productCipher() ***\n");

	int key = 0xBABAD0;
	const char * plainText = "This is my cool stuffed text with words computador and seguranca";
	size_t length = strlen(plainText);
	char * cipheredText = productCipher(plainText, length, key);
	char * decipheredText = productDecipher(cipheredText, length, key);

	printf("\nPlain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: productCipher() ***\n");
}

int main()
{
	runAllTests();
	return 0;
}
