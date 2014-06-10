#include <RSA.h>

string RSA::cipher(const string& message, const ZZ& cipherKey, const ZZ& n)
{
	if(DEBUG)
		cout << "*** DEBUG: rsaCipher()..." << endl;

	size_t length = message.length();
	int i;
	for(i = 0; i < length; i++)
		cout << "[" << message[i] << "] = " << bigPower(conv<ZZ>(message[i]), cipherKey, n) << endl;

	return "";
}
