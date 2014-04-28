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
int key = 0x10;
const char * plainText = "O modo de seguranca e util para solucionar problemas com programas e drivers que talvez nao iniciem corretamente ou que podem impedir que o Windows seja iniciado corretamente Se um problema nao se repetir quando o computador for iniciado no modo de seguranca voce podera eliminar as configuracoes padrao e os drivers de dispositivo basicos como as possiveis causas Se um programa dispositivo ou driver instalado recentemente impedir a execucao correta do Windows voce podera iniciar o computador no modo de seguranca e em seguida remover o programa que esta causando o problema Qualquer usuario independente do tipo de uso do computador pode ser um alvo maravilhoso para os 454785 maliciosos desenvolvedores de pragas virtuais principalmente porque cada equipamento infectado tem a capacidade de infectar uma quantidade absurda de outros computadores sem o conhecimento do proprietario Voce sabia que pode pegar  um virus somente por acessar sites infectados Basta que sua maquina nao esteja protegida devidamente ou que voce esteja utilizando softwares desatualizados Coisa serias";
size_t length;

/**
 *	Please, add the new tests to this method
 */
void runAllTests()
{
	test_substitutionCipher();
	test_transpositionCipher();
	test_productCipher();
}

/**
 *	Test if the substitution cipher is working
 */
void test_substitutionCipher()
{
	printf("*** Test: substitutionCipher() ***\n");

	char * cipheredText = substitutionCipher(plainText, length, key);
	char * decipheredText = substitutionDecipher(cipheredText, length, key);
	char * analysis = crackSubstitution(cipheredText, length);

	printf("\nPlain text is     : %s\n", plainText);
	printf("Ciphered text is  : %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("Broken text is    : %s\n", analysis);
	printf("*** End of Test: substitutionCipher() ***\n");
}

/**
 *	Test if the substitution cipher is working
 */
void test_transpositionCipher()
{
	printf("*** Test: transpositionCipher() ***\n");

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

	char * cipheredText = productCipher(plainText, length, key);
	char * decipheredText = productDecipher(cipheredText, length, key);

	printf("\nPlain text is:      %s\n", plainText);
	printf("Ciphered text is:   %s\n", cipheredText);
	printf("Deciphered text is: %s\n", decipheredText);
	printf("*** End of Test: productCipher() ***\n");
}

int main()
{
	length = strlen(plainText);
	runAllTests();
	return 0;
}
