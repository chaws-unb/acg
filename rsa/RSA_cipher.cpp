#include <RSA.h>

vector<ZZ> RSA::cipher(const string& message, const ZZ& cipherKey, const ZZ& n)
{
	RSA rsa(20);
	ZZ C;
	size_t length = message.length();
	int blockSize = rsa.calcBlockSize(n);
	string numericMessage = rsa.convertNumeric(message, blockSize);
	cout << "." << endl;
	cout << numericMessage << endl;
	if(DEBUG)
		cout << "*** DEBUG: rsaCipher()..." << endl;

	cout << "String format size: " << length << endl;
	cout << "Numeric format size: " << numericMessage.length() << endl;



	ZZ i;
	vector<ZZ> ciphered;

	for(i=to_ZZ(0) ; i<to_ZZ(length) ; i+=n)
	{
		string block = numericMessage.substr(to_int(i),blockSize);
		ZZ zblock = s_to_ZZ(block);
		C = bigPower(zblock, cipherKey, n);
		ciphered.push_back(C);
	}


	return ciphered;
}
