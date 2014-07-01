#include <RSA.h>
#include <sstream>

using namespace std;

int RSA::calcBlockSize(const ZZ& n)
{
	ZZ comparator = to_ZZ(1);
	int i=1;
	while(comparator<=n)
	{
		comparator*=2;
		i++;
	}
	return (1 + (int)((i-1)/8));
}

string RSA::convertNumeric(const string& message, int blockSize)
{
	size_t length = message.length();
	int i;
	stringstream ss;
	for(i = 0; i < length; i++)
	{
		if(message[i]<10)
			ss << "00";
		else if(message[i]<100)
			ss << '0';
		ss << int(message[i]);
	}

	while((ss.str().length())%blockSize != 0)
		ss << '0';

	return ss.str();
}

ZZ RSA::s_to_ZZ(string str)
{
	ZZ value = to_ZZ(0);
	for(int i=(str.length()-1) ; i>0 ; i++)
	{
		value *= 10;
		value += to_ZZ(str[i]);
	}
	return value;
}


