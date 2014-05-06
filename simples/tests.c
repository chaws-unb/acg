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
void test_breaker();
void runAllTests();
int key = 0x10;
int keyTransposition = 0xCDF86BDB;
const char * plainText = "O modo de seguuranca e util para solucionar problemas com programas e drivers que talvez nao iniciem corretamente ou que podem impedir que o Windows seja iniciado corretamente Se um problema nao se repetir quando o computador for iniciado no modo de seguuranca voce podera eliminar as configuracoes padrao e os drivers de dispositivo basicos como as possiveis causas Se um programa dispositivo ou driver instalado recentemente impedir a execucao correta do Windows voce podera iniciar o computador no modo de seguranca e em seguida remover o programa que esta causando o problema Qualquer usuario independente do tipo de uso do computador pode ser um alvo maravilhoso para os 454785 maliciosos desenvolvedores de pragas virtuais principalmente porque cada equipamento infectado tem a capacidade de infectar uma quantidade absurda de outros computadores sem o conhecimento do proprietario Voce sabia que pode pegar  um virus somente por acessar sites infectados Basta que sua maquina nao esteja protegida devidamente ou que voce esteja utilizando softwares desatualizados Coisa serias";
size_t length;

/**
 *	Please, add the new tests to this method
 */
void runAllTests()
{
	test_substitutionCipher();
	test_transpositionCipher();
	test_productCipher();
	test_breaker();
}

/**
 *	Test if the substitution cipher is working
 */
void test_substitutionCipher()
{
	char * cipheredText 	= substitutionCipher(plainText, length, key);
	char * decipheredText 	= substitutionDecipher(cipheredText, length, key);

	printf("*** Test: substitutionCipher() ***\n");
	printf("Plain text is     : %s\n", plainText);
	printf("Ciphered text is  : %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: substitutionCipher() ***\n\n");
}

/**
 *	Test if the substitution cipher is working
 */
void test_transpositionCipher()
{
	char * cipheredText 	= transpositionCipher(plainText, length, keyTransposition);
	char * decipheredText 	= transpositionDecipher(cipheredText, length, keyTransposition);

	printf("*** Test: transpositionCipher() ***\n");
	printf("Plain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: transpositionCipher() ***\n\n");
}

/**
 *	Test if the substitution cipher is working
 */
void test_productCipher()
{
	char * cipheredText 	= productCipher(plainText, length, key);
	char * decipheredText 	= productDecipher(cipheredText, length, key);

	printf("*** Test: productCipher() ***\n");
	printf("Plain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: productCipher() ***\n\n");
}

/**
 *	Test the breaker
 */
void test_breaker()
{
	char * substitutionCipheredText = substitutionCipher(plainText, length, key);
	char * productCipheredText 		= productCipher(plainText, length, key);
	char * productBroken 			= breaker_bf(productCipheredText, length);

	printf("*** Test: breaker() ***\n");
	printf("Plain text is:      	%s\n", plainText);
	printf("Substitution text is:   %s\n", substitutionCipheredText);
	printf("Broken is: 				%s\n", productBroken);
	printf("*** End of Test: productCipher() ***\n");
}

int main()
{
	length = strlen(plainText);
	runAllTests();
	return 0;
}
