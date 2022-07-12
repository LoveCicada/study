
#include <iostream>
#include "decorator3.h"
using namespace std;

int main(int argc, char **argv)
{
	FileStream* pFs = new FileStream();
	pFs->Read();
	cout << endl;

	CryptoStream* pCs = new CryptoStream(pFs);
	pCs->Read();
	cout << endl;

	BufferedStream* pBs = new BufferedStream(pFs);
	pBs->Read();
	cout << endl;

	BufferedStream* pBs2 = new BufferedStream(pCs);
	pBs2->Read();
	cout << endl;

	return 0;
}

/*
@result
	./bin/main 
	FileStream: Read
	
	DecoratorStream : DecoratorStream
	CryptoStream : CryptoStream
	FileStream: Read
	
	DecoratorStream : DecoratorStream
	BufferedStream : BufferedStream
	FileStream: Read
	
	DecoratorStream : DecoratorStream
	BufferedStream : BufferedStream
	FileStream: Read
*/