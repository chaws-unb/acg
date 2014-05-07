#include <RSA.h>

ZZ RSA::generateCipherKey(const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateCipherKey()..." << endl;
	
	ZZ cipherKey = to_ZZ(1);
	return cipherKey;
}
