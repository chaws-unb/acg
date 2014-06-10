#include <RSA.h>

ZZ mod(const ZZ& number1, const ZZ& number2)
{
	ZZ r = number1 % number2;
	if((r * number2) < 0)
		return (r + number2);
	return r;

}

ZZ RSA::xgcd(const ZZ& e, const ZZ& et, ZZ& x)
{
	// Iterative
	ZZ y = ZZ_1, u = ZZ_1, v = ZZ_0;
	ZZ a, b, q, r, m, n;

	// Forces a > b
	if(e < et)
	{
		a = et;
		b = e;
	}
	else
	{
		a = e;
		b = et;
	}

	while(b != ZZ_0)
	{
		q = a / b;
		r = a % b;
		m = x - (u * q);
		n = y - (v * q);
		a = b;
		b = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}
	return a;

/*
	ZZ rest = mod(et, e);

	if(rest == 0)
		return mod((x / e), (et / e));

	return (xgcd(rest, e, -x) * et + x) / (mod(e, et));
	*/
}
