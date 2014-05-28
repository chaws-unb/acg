#include <RSA.h>

ZZ  RSA::totient(const ZZ& n)
{
  vector<ZZ> primes;

  primes.push_back(to_ZZ(2));
  primes.push_back(to_ZZ(3));
  primes.push_back(to_ZZ(5));
  primes.push_back(to_ZZ(7));
  primes.push_back(to_ZZ(11));
  primes.push_back(to_ZZ(13));
  primes.push_back(to_ZZ(17));
  primes.push_back(to_ZZ(19));
  primes.push_back(to_ZZ(23));
  primes.push_back(to_ZZ(29));
  primes.push_back(to_ZZ(31));
  primes.push_back(to_ZZ(37));
  primes.push_back(to_ZZ(41));
  primes.push_back(to_ZZ(43));

  // Base case
  if ( n < to_ZZ(2) )
    return to_ZZ(0);
 
  // Lehmer's conjecture
  if (isPrime(n))
    return to_ZZ(n-1);
 
  // Even number?
  if ( (n & to_ZZ(1)) == to_ZZ(0) ) {
    ZZ m = to_ZZ(n >> 1);
    return ((m & to_ZZ(1)) != to_ZZ(0)) ? this->totient(m) : this->totient(m)<<1 ;
  }
 
  // For all primes ...
  for ( std::vector<ZZ>::iterator p = primes.begin(); p != primes.end() && *p <= n; ++p )
  {
    ZZ m = *p;
    if ( n % m  != to_ZZ(0)) continue;
 
    // totient is multiplicative
    ZZ o = n/m;

    ZZ d = gcd(m, o);
    return d==1? this->totient(m)*this->totient(o) : this->totient(m)*this->totient(o)*d/this->totient(d);
  }

  return to_ZZ(0);
}