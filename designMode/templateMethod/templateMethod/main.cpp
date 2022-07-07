
#include <iostream>
#include "templateMethod.h"
using namespace std;

int main(int argc, char **argv)
{

	Library* pLib = new Application();
	pLib->Run();
	delete pLib;

	return 0;
}

/*
@result
	./bin/main
	Library
	Application
	Run
	Step1
	Step2
	Step3
	Step4
	Step5
	~Application
	~Library
*/