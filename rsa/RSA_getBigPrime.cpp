#include <RSA.h>

ZZ RSA::getBigPrime(unsigned short numberOfBits)
{
	if(DEBUG)
		cout << "*** DEBUG: getBigPrime()..." << endl;
	
	// Big number if numberOfBits bits
	ZZ bigNumber = ZZ_1;
	bigNumber <<= numberOfBits;

	// Generate a random number between 0 and x
	ZZ prime = RandomBnd(bigNumber); 

	// Force it to be odd not divisible by 5
	if(bit(prime, 0) == 0)
		prime--;

	if(DEBUG)
		cout << "*** DEBUG: Big random number is " << prime << endl;
//return prime;
	ZZ two = ZZ_2;
	while(prime > two && !isPrime(prime))
		prime -= two;

	return prime;
}
