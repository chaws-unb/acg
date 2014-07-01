#include <RSA.h>

string RSA::decipher(const vector<ZZ> &cipheredMessage, const ZZ& decipherKey, const ZZ& n)
{
//	RSA rsa(20);
//	if(DEBUG)
//		cout << "*** DEBUG: rsaDecipher()..." << endl;
//
//	size_t length = cipheredMessage.length();
//	int blockSize = calcBlockSize(n);
//
//
//
//
//	length = cipheredMessage.size();
//	string message;
//	int i;
//	ZZ M;
//	for(i = 0; i < length; i++)
//	{
//		M = rsa.bigPower(to_ZZ(cipheredMessage[i]), decipherKey, n);
//		if(DEBUG)
//			;//cout << "[" << cipheredMessage[i] << "] = " << M << endl;
//
//		message.push_back((char)trunc_long(M, 8));
//	}
//
//	return message;
}
