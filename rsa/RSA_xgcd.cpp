#include <RSA.h>

pair<ZZ, pair<ZZ, ZZ> > extendedEuclid(ZZ a, ZZ b) 
{
    ZZ x = ZZ_1, y = ZZ_0;
    ZZ xLast = ZZ_0, yLast = ZZ_1;
    ZZ q, r, m, n;
    while(a != ZZ_0) 
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
ZZ modInverse(ZZ a, ZZ m) 
{
    return (extendedEuclid(a,m).second.first + m) % m;
}

ZZ RSA::xgcd(const ZZ& e, const ZZ& phi)
{
	return modInverse(e, phi);
}
