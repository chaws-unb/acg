#include <RSA.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ZZ RSA::bigRandom(unsigned short numberOfBits)
{
	if(numberOfBits == 0)
		numberOfBits = this->numberOfBits;

	// Create a big number with 'numberOfBits' bits
	ZZ returned = ZZ_1 << numberOfBits;

	char buffer[4];
	int value = 0;
	for(int i = 0; i < numberOfBits; i++)
	{
		FILE * output = popen("free | grep 'cache:' | sed 's/.*\\([0-9][0-9][0-9][0-9]\\)$/\\1/'", "r");
		if(fgets(buffer, 4, output) != NULL)
			memcpy(&value, buffer, 4);
		else
			value = 124354645;
	    pclose(output);

		if(value & 1)
			SetBit(returned, i);
	}

	return returned;
}
