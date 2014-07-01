#include <RSA.h>

ZZ RSA::getBigPrime(unsigned short numberOfBits)
{
	if(DEBUG)
		cout << "*** DEBUG: getBigPrime()..." << endl;

	if(numberOfBits == 0)
		numberOfBits = this->numberOfBits / 4;

	cout << "Number of bits: " << numberOfBits << endl;
	
	// Big number if numberOfBits bits
	ZZ bigNumber = ZZ_1 << numberOfBits;

	// Generate a random number between 0 and x
	ZZ prime = bigRandom(numberOfBits); 

	// Force it to be odd not divisible by 5
	if(bit(prime, 0) == 0)
		prime--;

	if(DEBUG)
		cout << "*** DEBUG: Big random number is " << prime << endl;
	
	while(prime > ZZ_2 && !isPrime(prime))
		prime -= ZZ_2;

	return prime;
}
