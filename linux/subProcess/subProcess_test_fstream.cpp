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

    std::streambuf *psbuf, *backup;
    std::ofstream file("test.txt");
    backup = std::cout.rdbuf();
    psbuf = file.rdbuf();
    std::cout.rdbuf(psbuf);
    std::cout << "This is written to the file ";
    std::cout.rdbuf(backup);
    file.close();

    //std::cout << cmd.stdout().rdbuf();

#if 0
    cout << "--------------------------" << std::endl;
    std::string str1;
    cmd.stdout() >> str1;
    cout << str1 << endl;

#else
    // std::string buf;
    // std::getline(cmd.stdout(), buf);
    // cout << "--------------------------" << std::endl;
    // cout << "buf len: " << buf.size() << endl;
    // cout << buf << endl;

    // cout << "--------------------------" << std::endl;
    // std::cout << cmd.stdout().rdbuf();

    //!
    std::string buf;
    std::string totalBuf;
    std::vector<std::string> strings;
    int nCount = 0;
    while(std::getline(cmd.stdout(), buf))
    {
        cout << "nCount: " << ++nCount << endl;
        //cout << buf << endl;
        strings.push_back(buf);
    }

    // cout << "--------------------------" << std::endl;
    // cout << "buf len: " << buf.size() << endl;
    // cout << buf << endl;

    // cout << "--------------------------" << std::endl;
    // std::cout << cmd.stdout().rdbuf();

    cout << "---------- totalbuf ----------------" << std::endl;
    for(const auto& str : strings)
    {
        cout << str << endl;
    }

#endif

    return 0;
}