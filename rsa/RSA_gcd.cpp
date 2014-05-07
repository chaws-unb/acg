#include <RSA.h>

ZZ RSA::gcd(const ZZ& number1, const ZZ& number2)
{
	if(DEBUG)
		cout << "*** DEBUG: gcd()..." << endl;

	if(number2 == 0)
		return number1;

	ZZ r;
	r = number1 % number2;
	
	ZZ result = this->gcd(number2, r);
	return result;
}
