#include <RSA.h>

ZZ RSA::generateDecipherKey(const ZZ& cipherKey, const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateDecipherKey()..." << endl;
	
	ZZ n = p * q;

	ZZ phi = this->totient(n); 
	ZZ decipherKey = ((to_ZZ(1)/cipherKey) % phi);
	return decipherKey;
}
