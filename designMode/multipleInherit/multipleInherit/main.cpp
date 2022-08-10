
#include <iostream>
#include "multipleInherit.h"
using namespace std;


int main(int argc, char **argv)
{
	Son s;
	s.Process();
	return 0;
}

/**
 * @result 
 * 	./bin/main
 * 	Process 
	Handle
	Do1
	Handle
	Do2
	Handle
	Do3
 */