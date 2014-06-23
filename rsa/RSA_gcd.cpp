#include <RSA.h>

ZZ RSA::gcd(const ZZ& number1, const ZZ& number2)
{
	if(DEBUG)
	 	cout << "*** DEBUG: gcd()..." << endl;

	ZZ big, small;

	if(number1 < number2)
	{
		big   = number2;
		small = number1;
	}
	else
	{
		big   = number1;
		small = number2;
	}

	ZZ modulus;
	while(small != 0)
	{
		modulus = big;
		big = small;
		small = modulus % small;
	}

	return big;
}
