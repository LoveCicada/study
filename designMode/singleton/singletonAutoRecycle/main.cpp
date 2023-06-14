
#include <iostream>
#include "singletonAutoRecycle.h"
using namespace std;

int main(int argc, char **argv)
{
    Singleton::Get();

    return 0;
}