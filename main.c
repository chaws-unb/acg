#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

static void printHelp()
{
	printf("\nHelp for ACG:\n"
	"- [c|d] <key>: (c)ipher or (d)ecipher [with the key]\n"
	"               a string passed through STDIN\n"
	"  - c: Cipher a text using substitution,\n"
	"       transposition and product ciphering.\n"
	"  - d: Decipher a ciphered text using\n"
	"       cryptanalysis technics.\n"
	"- key: A 32-bit key used to cipher the plain text.\n\n");
}

static void printAlphabet()
{
	int i;
	for(i = 0; i < ALPHABET_LENGTH; i++)
		printf(" %c", alphabet[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	if(argc == 2 && !strncmp(argv[1], "help", 4))
	{
		printHelp();
		return 0;
	}
	if ( argc != 3 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf("\nUsage: %s [c|d] <key>\n\n", argv[0]);
        return 0;
    }

    // Read the text from STDIN until EOF
    char buffer[BUFFER_SIZE];
    if(fgets(buffer, BUFFER_SIZE, stdin) == NULL)
    {
    	printf("Something wrong happened while reading the string...\n");
    	return 1;
    }

    size_t length = strlen(buffer) - 1;
    // Remove \n from the end
    buffer[length] = '\0';

    // Check if the values match the specified ones
    if(compareToAlphabet(buffer, length))
    {
    	printf("The string entered does not match our alphabet...\n");
    	printf("Please, enter only characters like the ones below:\n");
    	printAlphabet();
    	return 1;	
    }

	if(DEBUG)
	{
		printf("String read \"%s\"\n", buffer);
	}

	char * cipheredText = cipher(buffer, length, 0XFACADA);
	printf("%s", cipheredText);

	return 0;
}