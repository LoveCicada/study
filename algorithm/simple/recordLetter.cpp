#include <iostream>
#include <vector>

using namespace std;

void solution(const vector<char>& a)
{
    int record[26] = {0};
    for(int i = 0; i < a.size(); i++){
        record[a[i] - 'a']++;
    }

    char result;
    int max_count = 0;

    for(int j = 0; j < 26; j++){
        if(record[j] > max_count) {
            max_count = record[j];
            result = j + 'a';
        }
    }

    cout << "出现最多的字母是: " << result
         <<  ", 出现的次数: " << max_count << endl;
}

int main()
{
    char a[] = {'a', 'b', 'c', 'd', 'c', 'f', 'g', 'c', 'i', 'j'};
    cout << "sizeof(a) is: " << sizeof(a) << endl;
    cout << "length of a is: " << sizeof(a)/sizeof(a[0]) << endl;
    vector<char> va(a, a + sizeof(a)/sizeof(a[0]));
    solution(va);

    return 0;
}

/**
 * @result 
 *  sizeof(a) is: 10
    length of a is: 10
    出现最多的字母是: c, 出现的次数: 3
 */