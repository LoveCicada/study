
#include <iostream>
#include "callback.h"
using namespace std;


int main(int argc, char **argv)
{
	CCallback cb;
	CDo cd;
	cd.SetCallback(&cb);
	cd.Do();
	return 0;
}

/**
 * @result 
 * 	./bin/main
	Do
	OnCall
 */