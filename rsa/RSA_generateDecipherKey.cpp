#include <RSA.h>

ZZ RSA::generateDecipherKey(const ZZ& cipherKey, const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateDecipherKey()..." << endl;
	
	ZZ decipherKey = to_ZZ(1);
	return decipherKey;
}
