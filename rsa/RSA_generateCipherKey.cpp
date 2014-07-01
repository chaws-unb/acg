#include <RSA.h>

ZZ RSA::generateCipherKey(const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateCipherKey()..." << endl;

	ZZ phi = totient(p, q);
	ZZ e;

	e = (bigRandom(this->numberOfBits / 2) % phi) + ZZ_1;
	if(e > ZZ_2 && !bit(e, 0))
		e--;

	while(gcd(e, phi) != ZZ_1)
		e--;
	
	return e;
}
