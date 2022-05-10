
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
#include <unordered_map>

using namespace std;

void reverseString(vector<char>& s) {
    for (size_t i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
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
    char array[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> v(array, array + sizeof(array)/sizeof(array[0]));
    printArray(v);
    reverseString(v);
    printArray(v);

    return 0;
}
/**
 * @result 
 
 */