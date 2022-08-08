
#include <iostream>
#include "callback.h"
using namespace std;


int main(int argc, char **argv)
{
	PrintString ps;
	auto pFunc = std::bind(&PrintString::PrintStr, &ps, std::placeholders::_1);
	Module d(pFunc);
	d.OnFuncString("callback test");
	return 0;
}

/**
 * @result 
 * 	./bin/main 
	OnFuncString
	PrintStr: callback test
 */