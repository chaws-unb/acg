#include <RSA.h>

ZZ RSA::generateDecipherKey(const ZZ& cipherKey, const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateDecipherKey()..." << endl;

	ZZ phi = this->totient(p, q); 
	ZZ decipherKey = ((ZZ_1 / cipherKey) % phi);
	return decipherKey;
}
