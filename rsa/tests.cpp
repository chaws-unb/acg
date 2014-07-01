#include <RSA.h>
#include <iostream>


/**
	***** Values for RSA *****

ok	Pick primes: try to generate primes with 150 digits
		- generate p and q
ok	Calculare n and phi(n):
		- n = p * q
		- phi(n) = (p - 1) * (q - 1)
	Choose e:  random value between 2 and phi(n)
	Find d: d*e = 1 mod(phi(n))

	***** Encoding *****
ok	c = m ** e (mod n)

	***** Decoding *****
ok	m = c ** d (mod n)
 */

using namespace std;

/**
 *	Make G++ stop complaining
 */
void runAllTests();
void test_simple();
void test_getBigPrime();
void test_gcd();
void test_xgcd();
void test_generateCipherKey();
void test_generateDecipherKey();
void test_rsaCipher();
void test_rsaDecipher();

RSA rsa(20);

/**
 *	Please, add the new tests to this method
 */
void runAllTests()
{
	test_simple();
	/*
	test_getBigPrime();
	test_gcd();
	test_xgcd();
	test_generateCipherKey();
	test_generateDecipherKey();
	test_rsaCipher();
	test_rsaDecipher();
	*/
}

void test_simple()
{
	cout << "****** Test: simple() ******" << endl;
	/*
	 * p = 7669
	 * q = 10711
	 * n = 82142659
	 * phi = 82124280
	 * k = 1806734161 (e*d)
	 * e = 47
	 * d = 48830653
	 */

	ZZ p, q, e, d, n, phi, e_generated, d_generated, p_generated, q_generated;
	string message, deciphered, deciphered_generated;
	vector<ZZ> ciphered, ciphered_generated;

	p 			= conv<ZZ>(7669);
	q 			= conv<ZZ>(10711);
	n			= p * q;
	phi			= rsa.totient(p, q);
	e 			= conv<ZZ>(37);
	d 			= conv<ZZ>(48830653);

	// Generate both keys
	p_generated = rsa.getBigPrime();
	q_generated = rsa.getBigPrime();
	e_generated = rsa.generateCipherKey(p_generated, q_generated);
	d_generated = rsa.generateDecipherKey(e_generated, p_generated, q_generated);

	message 	= "NO WAY";
	ciphered	= rsa.cipher(message, e, n);
	deciphered	= rsa.decipher(ciphered, d, n);
	ciphered_generated 	 = rsa.cipher(message, e_generated, n);
	deciphered_generated = rsa.decipher(ciphered_generated, d_generated, n);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< n << endl;
	cout << "phi = " 			<< phi << endl;
	cout << "cipherKey = " 	<< e << endl;
	cout << "decipherKey = "<< d << endl;
	cout << "generated cipherKey = " 	<< e_generated << endl;
	cout << "generated decipherKey = "<< d_generated << endl;
	cout << "message = " 	<< message << endl;

	cout << "ciphered = ";
	for(int i = 0; i < ciphered.size(); i++)
		cout <<"\t["<< i <<"]"<< ciphered[i] << ", " << endl;
	cout << "generated ciphered = ";
	for(int i = 0; i < ciphered_generated.size(); i++)
		cout <<"\t["<< i <<"]"<< ciphered_generated[i] << ", " << endl;

	cout << "deciphered = " << deciphered << endl;
	cout << "generated deciphered = " << deciphered_generated << endl;

	cout << "****** End-Test: simple() ******" << endl << endl;
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

	ZZ bigNumber1, bigNumber2, resultXGCD, phi, x;

	bigNumber1 = to_ZZ(1160718174);
	bigNumber2 = to_ZZ(316258250);
	phi = (bigNumber1 - 1) * (bigNumber2 - 1);

	resultXGCD = rsa.xgcd(bigNumber1, bigNumber2, x);

	cout << "XGCD(" << bigNumber1 << ", " << bigNumber2 << ") = " << resultXGCD << endl;
	cout << "X = " << x << endl;

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
	string message;
	vector<ZZ> ciphered;

	p = to_ZZ(37);
	q = to_ZZ(23);
	n = p * q;
	// e=5, d=317, n=851
	cipherKey 	= 5;
	message 	= "This is my cool message with random senseless stuff";
	ciphered	= rsa.cipher(message, cipherKey, n);

	cout << "Number of bits for key generation: " << rsa.numberOfBits << endl;
	cout << "p = " 			<< p << endl;
	cout << "q = " 			<< q << endl;
	cout << "n = " 			<< n << endl;
	cout << "cipherKey = " 	<< cipherKey << endl;
	cout << "message = " 	<< message << endl;
	//cout << "ciphered = " 	<< ciphered << endl;

	cout << "****** End-Test: rsaCipher() ******" << endl << endl;
}

void test_rsaDecipher()
{
	cout << "****** Test: rsaDecipher() ******" << endl;

	ZZ p, q, cipherKey, decipherKey, n;
	string message, deciphered;
	vector<ZZ> ciphered;

	// n = 82142659
	p = to_ZZ(7669);
	q = to_ZZ(10711);
	n = p * q;
	cipherKey 	= 37;

	decipherKey = 48830653;
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
	//cout << "ciphered = " 	<< ciphered << endl;
	cout << "deciphered = " 	<< deciphered << endl;

	cout << "****** End-Test: rsaDecipher() ******" << endl << endl;
}

int main()
{
	cout << "Testing" << endl;
	runAllTests();
	return 0;
}
