#include <RSA.h>
#include <iostream>

using namespace std;

/**
 *	Make G++ stop complaining
 */
void runAllTests();
void test_getBigPrime();
void test_gcd();
void test_xgcd();
void test_generateCipherKey();
void test_generateDecipherKey();
void test_rsaCipher();
void test_rsaDecipher();

RSA rsa;

/**
 *	Please, add the new tests to this method
 */
void runAllTests()
{
	test_getBigPrime();
	test_gcd();
	test_xgcd();
	test_generateCipherKey();
	test_generateDecipherKey();
	test_rsaCipher();
	test_rsaDecipher();
}

void test_getBigPrime()
{
	cout << "****** Test: getBigPrime() ******" << endl;

	unsigned short numberOfBits = 2;
	ZZ bigPrime;

	bigPrime = rsa.getBigPrime(numberOfBits);

	cout << "The big prime for " << numberOfBits << " bits is " << bigPrime << endl;

	cout << "****** End-Test: getBigPrime() ******" << endl << endl;
}

void test_gcd()
{
	cout << "****** Test: gcd() ******" << endl;

	ZZ bigNumber1, bigNumber2, resultGCD;

	bigNumber1 = to_ZZ(1160718174);
	bigNumber2 = to_ZZ(316258250);

	resultGCD = rsa.gcd(bigNumber1, bigNumber2);

	cout << "GCD(" << bigNumber1 << ", " << bigNumber2 << ") = " << resultGCD << endl;

	cout << "****** End-Test: gcd() ******" << endl << endl;
}

void test_xgcd()
{
	cout << "****** Test: xgcd() ******" << endl;

	ZZ bigNumber1, bigNumber2, resultXGCD, phi;

	bigNumber1 = to_ZZ(17);
	bigNumber2 = to_ZZ(11);
	phi = (bigNumber1-1) * (bigNumber2-1);

	resultXGCD = rsa.xgcd(to_ZZ(7), phi, to_ZZ(1));

	cout << "XGCD(" << bigNumber1 << ", " << bigNumber2 << ") = " << resultXGCD << endl;

	cout << "****** End-Test: xgcd() ******" << endl << endl;
}

void test_generateCipherKey()
{
	cout << "****** Test: generateCipherKey() ******" << endl;

	unsigned short numberOfBits = 4;
	ZZ p, q, cipherKey;

	//p 			= rsa.getBigPrime(numberOfBits);
	p =  to_ZZ(3);
	
	//q 			= rsa.getBigPrime(numberOfBits);
	q =  to_ZZ(5);
	cipherKey 	= rsa.generateCipherKey(p, q);

	cout << "Number of bits for key generation: " << numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;

	cout << "****** End-Test: generateCipherKey() ******" << endl << endl;
}

void test_generateDecipherKey()
{
	cout << "****** Test: generateDecipherKey() ******" << endl;

	unsigned short numberOfBits = 4;
	ZZ p, q, cipherKey, decipherKey;

	//p 			= rsa.getBigPrime(numberOfBits);
	p =  to_ZZ(3);
	
	//q 			= rsa.getBigPrime(numberOfBits);
	q =  to_ZZ(5);
	cipherKey 	= rsa.generateCipherKey(p, q);
	decipherKey = rsa.generateDecipherKey(cipherKey, p, q);

	cout << "Number of bits for key generation: " << numberOfBits << endl;
	cout << "p = " 			 << p << endl;
	cout << "q = " 			 << q << endl;
	cout << "cipherKey = "   << cipherKey << endl;
	cout << "decipherKey = " << decipherKey << endl;

	cout << "****** End-Test: generateDecipherKey() ******" << endl << endl;
}

void test_rsaCipher()
{
	cout << "****** Test: rsaCipher() ******" << endl;

	unsigned short numberOfBits = 4;
	ZZ p, q, cipherKey, modN;
	string message, ciphered;

	p 			= rsa.getBigPrime(numberOfBits);
	q 			= rsa.getBigPrime(numberOfBits);
	modN		= to_ZZ(7);
	cipherKey 	= rsa.generateCipherKey(p, q);
	message 	= "This is my cool message with random senseless stuff";
	ciphered	= rsa.cipher(message, cipherKey, modN);

	cout << "Number of bits for key generation: " << numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< modN << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;
	cout << "message = " 	<< message << endl;
	cout << "ciphered = " 	<< ciphered << endl;

	cout << "****** End-Test: rsaCipher() ******" << endl << endl;
}

void test_rsaDecipher()
{
	cout << "****** Test: rsaDecipher() ******" << endl;

	unsigned short numberOfBits = 4;
	ZZ p, q, cipherKey, decipherKey, modN;
	string message, ciphered, deciphered;

	p 			= rsa.getBigPrime(numberOfBits);
	q 			= rsa.getBigPrime(numberOfBits);
	modN		= to_ZZ(7);
	cipherKey 	= rsa.generateCipherKey(p, q);
	decipherKey = rsa.generateDecipherKey(cipherKey, p, q);
	message 	= "This is my cool message with random senseless stuff";
	ciphered	= rsa.cipher(message, cipherKey, modN);
	deciphered	= rsa.decipher(ciphered, decipherKey, modN);

	cout << "Number of bits for key generation: " << numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< modN << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;
	cout << "decipherKey = "<< decipherKey << endl;
	cout << "message = " 	<< message << endl;
	cout << "ciphered = " 	<< ciphered << endl;
	cout << "deciphered = " 	<< deciphered << endl;

	cout << "****** End-Test: rsaDecipher() ******" << endl << endl;
}


int main()
{
	cout << "Testing" << endl;
	runAllTests();
	return 0;
}
