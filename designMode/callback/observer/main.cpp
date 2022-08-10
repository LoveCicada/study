
#include <iostream>
#include "callback.h"
using namespace std;


int main(int argc, char **argv)
{
	ObserverImp obs;
	Module d(&obs);
	d.OnFuncString("callback test");
	return 0;
}

/**
 * @result 
 * 	./bin/main
	OnFuncString
	OnCall: callback test
 */