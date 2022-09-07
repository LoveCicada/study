
#include <iostream>
#include "subprocess.hpp"
using namespace std;

int main(int argc, char* argv[])
{
#if 0
    std::vector<std::string> vs;
    vs.push_back("1.py");
    subprocess::popen cmd("python3", vs);
#else
    subprocess::popen cmd("subProcess_test2", {});
    std::cout << cmd.stdout().rdbuf();
#endif

    return 0;

}