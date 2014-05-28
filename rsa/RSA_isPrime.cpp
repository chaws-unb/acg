#include <RSA.h>

bool RSA::isPrime(const ZZ& n)
{

  long i;
	
	for (i=2; i<n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	
	return true;
}
