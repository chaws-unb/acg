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

RSA rsa(500);

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

	ZZ bigPrime1;
	ZZ bigPrime2;
	ZZ bigPrime3;
	ZZ bigPrime4;
	ZZ bigPrime5;
	ZZ bigPrime6;
	ZZ bigPrime7;
	ZZ bigPrime8;
	ZZ bigPrime9;
	ZZ bigPrime10;

	bigPrime1 = rsa.getBigPrime();
	bigPrime2 = rsa.getBigPrime();
	bigPrime3 = rsa.getBigPrime();
	bigPrime4 = rsa.getBigPrime();
	bigPrime5 = rsa.getBigPrime();
	bigPrime6 = rsa.getBigPrime();
	bigPrime7 = rsa.getBigPrime();
	bigPrime8 = rsa.getBigPrime();
	bigPrime9 = rsa.getBigPrime();
	bigPrime10 = rsa.getBigPrime();

	cout << "The big 10 primes for " << rsa.numberOfBits << " bits are: " << endl;
	cout << "1: " << bigPrime1 << endl;
	cout << "2: " << bigPrime2 << endl;
	cout << "3: " << bigPrime3 << endl;
	cout << "4: " << bigPrime4 << endl;
	cout << "5: " << bigPrime5 << endl;
	cout << "6: " << bigPrime6 << endl;
	cout << "7: " << bigPrime7 << endl;
	cout << "8: " << bigPrime8 << endl;
	cout << "9: " << bigPrime9 << endl;
	cout << "10: " << bigPrime10 << endl;

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
	phi = (bigNumber1 - 1) * (bigNumber2 - 1);

	resultXGCD = rsa.xgcd(to_ZZ(7), phi, to_ZZ(1));

	cout << "XGCD(" << bigNumber1 << ", " << bigNumber2 << ") = " << resultXGCD << endl;

	cout << "****** End-Test: xgcd() ******" << endl << endl;
}

void test_generateCipherKey()
{
	cout << "****** Test: generateCipherKey() ******" << endl;

	ZZ p, q, cipherKey;

	p = rsa.getBigPrime();
	q = rsa.getBigPrime();
	cipherKey 	= rsa.generateCipherKey(p, q);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;

	cout << "****** End-Test: generateCipherKey() ******" << endl << endl;
}

void test_generateDecipherKey()
{
	cout << "****** Test: generateDecipherKey() ******" << endl;

	ZZ p, q, cipherKey, decipherKey;

	// p =  to_ZZ(3);
	// q =  to_ZZ(5);
	p = rsa.getBigPrime();
	q = rsa.getBigPrime();
	
	cipherKey 	= rsa.generateCipherKey(p, q);
	decipherKey = rsa.generateDecipherKey(cipherKey, p, q);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			 << p << endl;
	cout << "q = " 			 << q << endl;
	cout << "cipherKey = "   << cipherKey << endl;
	cout << "decipherKey = " << decipherKey << endl;

	cout << "****** End-Test: generateDecipherKey() ******" << endl << endl;
}

void test_rsaCipher()
{
	cout << "****** Test: rsaCipher() ******" << endl;

	ZZ p, q, cipherKey, n;
	string message, ciphered;

	p = rsa.getBigPrime();
	q = rsa.getBigPrime();
	n = p * q;
	cipherKey 	= rsa.generateCipherKey(p, q);
	message 	= "This is my cool message with random senseless stuff";
	ciphered	= rsa.cipher(message, cipherKey, n);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< n << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;
	cout << "message = " 	<< message << endl;
	cout << "ciphered = " 	<< ciphered << endl;

	cout << "****** End-Test: rsaCipher() ******" << endl << endl;
}

void test_rsaDecipher()
{
	cout << "****** Test: rsaDecipher() ******" << endl;

	ZZ p, q, cipherKey, decipherKey, n;
	string message, ciphered, deciphered;

	p 			= rsa.getBigPrime();
	q 			= rsa.getBigPrime();
	n			= p * q;
	cipherKey 	= rsa.generateCipherKey(p, q);
	decipherKey = rsa.generateDecipherKey(cipherKey, p, q);
	message 	= "This is my cool message with random senseless stuff";
	ciphered	= rsa.cipher(message, cipherKey, n);
	deciphered	= rsa.decipher(ciphered, decipherKey, n);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< n << endl;
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
