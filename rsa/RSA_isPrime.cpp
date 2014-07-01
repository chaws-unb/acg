#include <RSA.h>

// Miller-Rabin test
bool MRTest(const ZZ& n, const ZZ& x)
{
	RSA rsa(20);
	ZZ m, y, z;
	long j, k;

	if(x == 0) 
		return false;

	// compute m, k such that n-1 = 2^k * m, m odd:

	k = 1;
	m = n / 2;
	while(m % 2 == 0) 
	{
		k++;
		m /= 2;
	}

	//z = PowerMod(x, m, n); // z = x^m % n
	z = rsa.bigPower(x, m, n); // z = x^m % n AQUIIIIIIIIIIIII
	if(z == 1) 
		return false;

	j = 0;
	do 
	{
		y = z;
		z = (y * y) % n; 
		j++;
	} while (j < k && z != 1);

	return z != 1 || y != n - 1;
}

bool RSA::isPrime(const ZZ& prime, long t)
{

  if (prime <= 1) 
		return false;

	// First, just try out the division by the first 2000 primes
	// Source: http://www.shoup.net/ntl/doc/tour-ex1.html
	PrimeSeq primeSequence; 
	long tempPrime;

	tempPrime = primeSequence.next();
	while(tempPrime && tempPrime < 2000) 
	{
		if((prime % tempPrime) == 0) 
			return prime == tempPrime;
		tempPrime = primeSequence.next();
	}

	// Not it's time for real prime testing
	ZZ x;
	long i;

	for(i = 0; i < t; i++) 
	{
		x = bigRandom(prime, ZZ_0); // random number between 0 and n-1

		if (MRTest(prime, x)) 
			return false;
	}

	return true;
}
