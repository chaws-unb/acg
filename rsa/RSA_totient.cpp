#include <RSA.h>

ZZ RSA::totient(const ZZ& n)
{
	// Base case
	if(n < ZZ_2)
		return ZZ_0;

	// Lehmer's conjecture
	if(isPrime(n))
		return to_ZZ(n - 1);

	// Even number?
	if((n & ZZ_1) == ZZ_0) 
	{
		ZZ m = to_ZZ(n >> 1);// AQUIIIIIIIIIIIIIIIII
		return ((m & ZZ_1) != ZZ_0) ? this->totient(m) : this->totient(m) << 1 ;
	}

	// For all primes
	PrimeSeq primeSequence; 
	for(ZZ tempPrime = conv<ZZ>(primeSequence.next()); tempPrime <= n; tempPrime = primeSequence.next())
	{
		if(n % tempPrime  != ZZ_0) 
			continue;

		// totient is multiplicative
		ZZ o = n / tempPrime;

		ZZ d = gcd(tempPrime, o);
		return d == 1 ? 
			 (totient(tempPrime) * totient(o)) : 
			((totient(tempPrime) * totient(o) * d) / totient(d));
	}

	return ZZ_0;
}