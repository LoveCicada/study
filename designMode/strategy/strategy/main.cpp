
#include <iostream>
#include "strategy.h"
using namespace std;

int main(int argc, char **argv)
{
	
	{
		Strategy* p = new CNStrategy();
		SalesOrder so(p);
		so.Calc();
	}

	return 0;
}

/*
@result
	./bin/main 
	Strategy
	CNStrategy
	SalesOrder
	Do
	~CNStrategy
	~Strategy
	~SalesOrder
*/