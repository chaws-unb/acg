#include <RSA.h>

ZZ RSA::bigPower(const ZZ& base, const ZZ& exp, const ZZ& n)
{
	if(DEBUG)
		cout << "*** DEBUG: bigPower()..." << endl;

    ZZ result;
    ZZ temp = base;
	ZZ temp_power = exp;
    for(result = 1; temp_power != ZZ_0; temp_power = temp_power >> 1)
    {
        if ((temp_power & ZZ_1) == ZZ_1)
            result = ((result % n) * (temp % n)) % n;
        temp = ((temp % n) * (temp % n)) % n;
    }

    return result;
}
