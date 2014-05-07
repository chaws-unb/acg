#include <RSA.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

inline bool file_exists(const string& filename)
{
	ifstream f(filename.c_str());
    if (f.good()) 
    {
        f.close();
        return true;
    } 
    else 
    {
        f.close();
        return false;
    }    
}

inline string file_get_contents(const string& filename)
{
	ifstream ifs(filename.c_str());
  	string content( (istreambuf_iterator<char>(ifs)),
                    (istreambuf_iterator<char>()));
  	return content;
}

inline void file_set_contents(const string& filename, const string& content)
{
	ofstream myfile;
	myfile.open(filename.c_str());
	myfile << content.c_str();
	myfile.close();
}

static void printWrongArgList()
{
	cout << "Bad choice of arguments.\n"
		   "Please run `rsa help` for more details" << endl;
}

static void printHelp()
{
	cout << "\nHelp for RSA:\n"
	"rsa [c|d] <message|ciphered>TextFile <cipher|decipher>KeyFile \n"
	"		(c)ipher or (d)ecipher [with the key]\n"
	"  - c: Cipher messageTextFile file using RSA ciphering,\n"
	"       and the cipherKey from cipherKeyFile file.\n"
	"  - d: Decipher a cipheredTextFile file using RSA\n"
	"       and the decipherKeyFile file.\n" << endl;
}

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		// User needs help
		if(!strncmp(argv[1], "help", 4))
		{
			printHelp();
			return 0;
		}
		else
		{
			printWrongArgList();
			return 1;
		}
	}

	if(argc != 3)
	{
		printWrongArgList();
		return 1;
	}

	bool cipherOrDecipher = true; // true - cipher, false - decipher
	if(!strncmp(argv[1], "c", 1))
		cipherOrDecipher = true;
	else if(!strncmp(argv[1], "d", 1))
		cipherOrDecipher = false; 
	else
	{
		printWrongArgList();
		return 1;
	}

	string messageFile, keyFile, outFile;
	if(!file_exists(messageFile) || !file_exists(keyFile))
	{
		cout << "Both " << messageFile << " and " << keyFile << " must exist! Aborting..." << endl;
		return 1;
	}

	RSA rsa;
	string output, input;
	ZZ key;

	input = file_get_contents(messageFile);
	key = to_ZZ(1);
	output = (cipherOrDecipher ? rsa.cipher(input, key) : rsa.decipher(input, key));

	file_set_contents(keyFile, output);

	return 0;
}