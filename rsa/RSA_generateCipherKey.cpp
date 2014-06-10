#include <RSA.h>

ZZ RSA::generateCipherKey(const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateCipherKey()..." << endl;

	ZZ phi = totient(p, q);
	ZZ e;

	e = (bigRandom(phi, ZZ_1) % (phi - ZZ_1)) + ZZ_2;

	while(gcd(e, phi) != ZZ_1)
		e = (bigRandom(phi, ZZ_1) % (phi - ZZ_1)) + ZZ_2;
	
	return e;
}
