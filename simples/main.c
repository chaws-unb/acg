#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

/**
 *	Options to control program flow
 */
int DECIPHER_BRUTE = 1, 
	DECIPHER_KEY = 2,
	DECIPHER_SUB = 3,
	CIPHER_KEY = 4;

static void printWrongArgList()
{
	printf("Bad choice of arguments.\n"
		   "Please run `acg help` for more details\n");
}

static void printHelp()
{
	printf("\nHelp for ACG:\n"
	"acg [c|d] <key|s>? (c)ipher or (d)ecipher [with the key]\n"
	"               a string passed through STDIN (<4096)\n"
	"  - c: Cipher a text using substitution,\n"
	"       transposition and product ciphering.\n"
	"       The key is required.\n"
	"  - d: Decipher a ciphered text using\n"
	"       the key [if passed] or cryptanalysis[s|t].\n"
	"       The key is optional.\n"
	"  - If key is not passed there're three extra options:\n"
	"	  - <empty>: If nothing is passed, uses\n"
	"       brute-force to find out the transposition order\n"
	"       followed by a brute-force/cryptanalysis to find\n"
	"       out the inverted substitution table.\n"
	"	  - s: considering the input as a simple substitution\n"
	"       output uses brute-force/cryptanalysis to find\n"
	"       out the inverted substitution table.\n"
	"  	  - The output will be a likely plain text with dots '.'\n"
	"  	    in places where was not possible to guess the right letter.\n"
	"- key: A 32-bit key used to cipher the plain text\n"
	"  	    in the hexadecimal format FFFFFFFF.\n\n");
}

static void printAlphabet()
{
	int i;
	for(i = 0; i < ALPHABET_LENGTH; i++)
		printf(" %c", alphabet[i]);
	printf("\n");
}

char * work(char option, char * buffer, size_t length, unsigned int key)
{
	char * output;
	switch((int)option)
	{
		case 1/*DECIPHER_BRUTE*/: return breaker_bf(buffer, length);
		case 3/*DECIPHER_SUB*/:   return breaker_s(buffer, length);
		case 2/*DECIPHER_KEY*/:   return decipher(buffer, length, key);
		case 4/*CIPHER_KEY*/:     return cipher(buffer, length, key);
	}
}

int main(int argc, char *argv[])
{
	unsigned int key = 0;
	char buffer[BUFFER_SIZE] = {0};
	size_t length = 0;;

	char option = 0;

	if(argc == 2)
	{
		// User needs help
		if(!strncmp(argv[1], "help", 4))
			printHelp();
		// break through brute force
		else if(!strncmp(argv[1], "d", 1))
			option = DECIPHER_BRUTE; 
		else
		{
			printWrongArgList();
			return 1;
		}
	}

	if (argc != 3) 
    {
        printWrongArgList();
        return 2;
    }

    // From now on, argc = 3

    // User needs to decipher 
    if(!strncmp(argv[1], "d", 1))
    {
    	// Using brute-force considering the input is output
    	// from simple substitution
    	if(!strncmp(argv[2], "s", 1))
    	{
    		option = DECIPHER_SUB;
    	}
    	else 
    	{
    		// Try to convert the hexadecimal to 
    		key = strtol(argv[2], NULL, 16);
    		if(key == 0 && errno == EINVAL)
    		{
    			// Failed
    			printf("Key '%s' is not in the specified format\n", argv[2]);
    			printWrongArgList();
    			return 3;
    		}
    		option = DECIPHER_KEY;
    	} 
    }

    // User needs to cipher
    else if(!strncmp(argv[1], "c", 1))
    {
    	// Try to convert the hexadecimal to 
		key = strtol(argv[2], NULL, 16);
		if(key == 0 && errno == EINVAL)
		{
			// Failed
			printf("Key '%s' is not in the specified format\n", argv[2]);
			printWrongArgList();
			return 4;
		}
		option = CIPHER_KEY;
    }

    // User does not know what he/she is doing
    else
    {
    	printWrongArgList();
    	return 5;
    }

    // Read the text from STDIN until EOF
    if(fgets(buffer, BUFFER_SIZE, stdin) == NULL)
    {
    	printf("Something wrong happened while reading the string...\n");
    	return 6;
    }

    length = strlen(buffer) - 1;
    buffer[length] = '\0'; // Remove \n from the end

    // Check if the values match the specified ones
    if(compareToAlphabet(buffer, length))
    {
    	printf("The string entered does not match our alphabet...\n");
    	printf("Please, enter only characters like the ones below:\n");
    	printAlphabet();
    	return 7;	
    }

	if(DEBUG)
	{
		printf("String read \"%s\"\n", buffer);
	}

	char * output = work(option, buffer, length, key);
	printf("%s", output);

	return 0;
}