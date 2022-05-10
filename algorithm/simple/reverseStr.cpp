
/**
 * @file intersection.cpp
 * @author your name (you@domain.com)
 * @brief 两个数组的交集 intersection of two arrays
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string reverseStr(string s, int k) {
    for(int i=0; i <s.size(); i+=(2*k)) {
        // 1.每隔2k个字符的前k个字符进行反转
        // 2.剩余字符小于2k但大于或等于k个, 则反转前k个字符
        if(i + k <= s.size()){
            reverse(s.begin() + i , s.begin() + i + k);
            continue;
        }

        // 3.如果剩余字符少于k个, 则将剩余字符全部反转
        reverse(s.begin() + i, s.begin() + s.size());
    }

    return s;
}

template<class T>
void printArray(const vector<T>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    string src = "asdfghjkl";
    cout << "src = " << src << endl;
    int k = 3;
    string dst = reverseStr(src, k);
    cout << "dst = " << dst << endl;

    return 0;
}
/**
 * @result 
    src = asdfghjkl
    dst = dsafghlkj
 */