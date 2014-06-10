#include <RSA.h>

ZZ RSA::bigPower(const ZZ& base, const ZZ& bigPow)
{
	if(DEBUG)
		cout << "*** DEBUG: bigPower()..." << endl;

	if(bigPow == ZZ_0)
		return ZZ_1;

	ZZ result;
	ZZ i;
	for(i = ZZ_0, result = ZZ_1; i < bigPow; i++)
		result *= base;

	return result;
}
