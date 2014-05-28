#include <RSA.h>
ZZ mod(const ZZ& number1, const ZZ& number2)
{
	ZZ r = number1%number2;

	if((r*number2)<0)
	{
		return (r + number2);
	}
	return r;

}

ZZ RSA::xgcd(const ZZ& e, const ZZ& et, const ZZ& x)
{
	ZZ r = mod(et,e);

	if(r==0)
	{
		return mod((x/e),(et/e));
	}

	return (xgcd(r,e,-x) * et+x) / (mod(e,et));
}
