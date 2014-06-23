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
	a = e;
	b = et;

	while(a != ZZ_0)
	{
		q = b / a;
		r = b % a;
		m = x - (u * q);
		n = y - (v * q);
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}

	if(x < ZZ_0)
		x *= -ZZ_1;

	cout << "x = " << x << endl;

	return b;

/*
	ZZ rest = mod(et, e);

	if(rest == 0)
		return mod((x / e), (et / e));

	return (xgcd(rest, e, -x) * et + x) / (mod(e, et));
	*/
}
