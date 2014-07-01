#include <RSA.h>

vector<ZZ> RSA::cipher(const string& message, const ZZ& cipherKey, const ZZ& n)
{
	if(DEBUG)
		cout << "*** DEBUG: rsaCipher()..." << endl;

	size_t length = message.length();
	int i;
	vector<ZZ> ciphered;
	ZZ C;
	for(i = 0; i < length; i++)
	{
		C = bigPower(conv<ZZ>(message[i]), cipherKey, n);
		ciphered.push_back(C);
	}

	return ciphered;
}
