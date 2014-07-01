#include <RSA.h>

vector<ZZ> RSA::cipher(const string& message, const ZZ& cipherKey, const ZZ& n)
{
	RSA rsa(20);
	ZZ C;
	size_t length = message.length();
	int blockSize = rsa.calcBlockSize(n);
	string numericMessage = rsa.convertNumeric(message, blockSize);
	if(DEBUG)
	{
		cout << "*** DEBUG: rsaCipher()..." << endl;
		cout << "*** DEBUG: N: " << n << "..." << endl;
		cout << "*** DEBUG: block size: " << blockSize << "..." << endl;
		cout << "*** DEBUG: numeric: [" << numericMessage << "]..." << endl;
		cout << "!";
	}
	ZZ i;
		cout << ".";
	vector<ZZ> ciphered;

		cout << ".";
	for(i=to_ZZ(0) ; i<to_ZZ(length) ; i+=n)
	{
		cout << ".";
		string block = numericMessage.substr(to_int(i),blockSize);
		ZZ zblock = s_to_ZZ(block);
		C = bigPower(zblock, cipherKey, n);
		ciphered.push_back(C);
	}
	cout << "-";


	return ciphered;
}
