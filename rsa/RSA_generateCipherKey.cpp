#include <RSA.h>

ZZ RSA::generateCipherKey(const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateCipherKey()..." << endl;

	ZZ phi = totient(p, q);
	ZZ cipherKey = ZZ_1;
    
	ZZ e = ZZ_1;

	e = (to_ZZ(rand()) % (phi - ZZ_1)) + ZZ_2;


	while(gcd(e, phi) != ZZ_1)
	{
		e = to_ZZ(rand()) % (phi - ZZ_1) + ZZ_2;
	}
	
	cipherKey = e;
	return cipherKey;
}
