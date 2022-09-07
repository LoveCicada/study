/**
 * @file subProcess_test_fstream.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * @see https://github.com/tsaarni/cpp-subprocess
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "subprocess.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    std::vector<std::string> vs;
    vs.push_back("1.py");
    subprocess::popen cmd("python3", vs);
    cmd.close();

    std::vector<std::string> vss;
    cmd.getResults(vss);
    cmd.printResults(vss);

    return 0;
}