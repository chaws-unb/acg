#include <RSA.h>

#include <sstream>

using namespace std;

string RSA::decipher(const vector<ZZ> &cipheredMessage, const ZZ& decipherKey, const ZZ& n)
{
	RSA rsa(20);
	if(DEBUG)
		cout << "*** DEBUG: rsaDecipher()..." << endl;


	stringstream numericSS;
	string message;
	int i,size;
	int blockSize = rsa.calcBlockSize(n);
	ZZ block;
	string stringBlock;
	for(i=0,size=int(cipheredMessage.size()) ; i < n ; i++)
	{
		block = rsa.bigPower(cipheredMessage[i],decipherKey,n);
		stringBlock = ZZ_to_s(block);
		numericSS << stringBlock;

		if(DEBUG)
			cout << "{" << stringBlock << "}" << endl;

	}

	return rsa.convertString(numericSS.str());
}
