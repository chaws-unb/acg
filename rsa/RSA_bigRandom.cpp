#include <RSA.h>
#include <stdlib.h>

ZZ RSA::bigRandom(const ZZ& n, const ZZ& seed, unsigned short numberOfBits)
{
	//return RandomBnd(n);
	if(!numberOfBits)
		numberOfBits = this->numberOfBits;

	// Create a big number with 'numberOfBits' bits
	ZZ returned = ZZ_1 << numberOfBits;

	unsigned char t;

	int i;

	for(i = 0; (i + 8) < numberOfBits;)
	{
		t = rand() % 255;
		//cout << "t = " << (int)t << endl;
		t += 2;

		// Set the bits
		if(t & 1)   SetBit(returned, i++);
		if(t & 2)   SetBit(returned, i++);
		if(t & 4)   SetBit(returned, i++);
		if(t & 8)   SetBit(returned, i++);
		if(t & 16)  SetBit(returned, i++);
		if(t & 32)  SetBit(returned, i++);
		if(t & 64)  SetBit(returned, i++);
		if(t & 128) SetBit(returned, i++);
	}

	// Continue setting until numberOfBits
	for(; i < numberOfBits; i++)
	{
		t = rand() % 2;
		if(t) SetBit(returned, i);
	}

	return returned;
}
