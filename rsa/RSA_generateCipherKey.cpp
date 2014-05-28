#include <RSA.h>

ZZ RSA::generateCipherKey(const ZZ& p, const ZZ& q)
{
	if(DEBUG)
		cout << "*** DEBUG: generateCipherKey()..." << endl;
	
	ZZ n = p * q;

	ZZ phi = this->totient(n);
	ZZ cipherKey = to_ZZ(1);
    
	ZZ e = to_ZZ(1);

	e = (to_ZZ(rand()) % (phi - to_ZZ(1))) + to_ZZ(2);


	while(this->gcd(e, (phi)) != to_ZZ(1)){
		e = to_ZZ(rand()) % (phi - to_ZZ(1)) + to_ZZ(2);
	}
	cipherKey = e;
	return cipherKey;
}
