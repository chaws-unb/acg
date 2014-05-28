#ifndef RSA_H
#define RSA_H
#define DEBUG 1
#include <NTL/ZZ.h>
#include <string>
#include <stdlib.h>
#include <vector>

/**
 *	Required for use of NTL
 */
using namespace NTL;
using namespace std;

/**
 *	Responsible for generating RSA keys and ciphering
 */
class RSA
{

public:

	/**
	 *	Return a [very big] prime of the 'numberOfBits' bits
	 */
	ZZ getBigPrime(unsigned short numberOfBits);

	/**
	 *	Return GCD (MDC in pt-BR) of two [very big] numbers
	 */
	ZZ gcd(const ZZ& number1, const ZZ& number2);

	/**
	* Check to see if a number is a prime
	**/
	bool isPrime(const ZZ& n);

	/**
	*Totient function
	**/

	ZZ totient(const ZZ& n);
	/**
	 *	Return a random key crafted by the use of 'p' and 'q' from RSA algorithm
	 */
	ZZ generateCipherKey(const ZZ& p, const ZZ& q);

	/**
	 *	Return a random key crafted by the use cipherKey and 'p' and 'q' from RSA algorithm
	 */
	ZZ generateDecipherKey(const ZZ& cipherKey, const ZZ& p, const ZZ& q);

	/**
	 *	Cipher 'message' with 'cipherKey' and 'modN'
	 */
	string cipher(const string& message, const ZZ& cipherKey, const ZZ& modN = to_ZZ(1));

	/**
	 *	Cipher 'message' with 'cipherKey' and 'modN'
	 */
	string decipher(const string& cipheredMessage, const ZZ& decipherKey, const ZZ& modN = to_ZZ(1));
};

#endif