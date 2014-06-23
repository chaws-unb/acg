#include <RSA.h>

string RSA::decipher(const vector<ZZ> &cipheredMessage, const ZZ& decipherKey, const ZZ& n)
{
	if(DEBUG)
		cout << "*** DEBUG: rsaDecipher()..." << endl;

	size_t length = cipheredMessage.size();
	string message;
	int i;
	ZZ M;
	for(i = 0; i < length; i++)
	{
		M = bigPower(cipheredMessage[i], decipherKey, n);
		if(DEBUG)
			;//cout << "[" << cipheredMessage[i] << "] = " << M << endl;

		message.push_back((char)trunc_long(M, 8));
	}

	return message;
}
