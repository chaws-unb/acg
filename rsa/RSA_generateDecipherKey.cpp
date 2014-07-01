#include <RSA.h>

ZZ RSA::generateDecipherKey(const ZZ& cipherKey, const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateDecipherKey()..." << endl;

	ZZ phi = totient(p, q);
	return xgcd(cipherKey, phi);
}
