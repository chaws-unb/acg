#ifndef RSA_H
#define RSA_H
#define DEBUG 1
#include <NTL/ZZ.h>
#include <string>
#include <stdlib.h>
#include <vector>

/**
 *	Some defines because of ZZ
 */
#define ZZ_0 to_ZZ(0)
#define ZZ_1 to_ZZ(1)
#define ZZ_2 to_ZZ(2)

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
	 *	Number of working bits for numbers in this RSA workspace
	 */
	unsigned short numberOfBits;
	RSA(unsigned short numberOfBits);

	/**
	 *	Return a [very big] prime of the 'numberOfBits' bits
	 */
	ZZ getBigPrime(unsigned short numberOfBits = 0);

	/**
	 *	Return GCD (MDC in pt-BR) of two [very big] numbers
	 */
	ZZ gcd(const ZZ& number1, const ZZ& number2);

	/**
	 *	Return the Extend Euclides of an e number and
	 *	your Euler totient;
	 */
	ZZ xgcd(const ZZ& e, const ZZ& et, ZZ& x);

	/**
	 *	Check to see if a number is a prime
	 *	t = number of Miller-Rabin tests
	 */
	bool isPrime(const ZZ& prime, long t = 10);

	/**
	 *	Generates big random number
	 */
	ZZ bigRandom(const ZZ& n, const ZZ& seed, unsigned short numberOfBits = 0);

	/**
	 *	Power of ZZ
	 */
	ZZ bigPower(const ZZ& base, const ZZ& exp, const ZZ& n);

	/**
	 * 	Totient function
	 *	If q is passed, n is considered to be p
	 *	otherwise, n is considered to be p*q
	 */
	ZZ totient(const ZZ& n, const ZZ& q = ZZ_0);

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
	vector<ZZ> cipher(const string& message, const ZZ& cipherKey, const ZZ& n);

	/**
	 *	Cipher 'message' with 'cipherKey' and 'modN'
	 */
	string decipher(const vector<ZZ> &cipheredMessage, const ZZ& decipherKey, const ZZ& n);
};

#endif

