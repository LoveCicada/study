#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    char record[26] = {0};
    int n = 26;
    for (int i = 0; i < s.size(); i++) {
        record[s[i] - 'a']++; 
    }

    for (int j = 0; j < t.size(); j++) {
        record[t[j] - 'a']--;
    }

    for (int k = 0; k < n; k++) {
        if(record[k] != 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "ace";
    string t = "cea";

    string r;
    bool bAnagram = isAnagram(s, t);
    r = bAnagram ? "true" : "false";
    cout << s << " and " << t << " is: " << r << endl;

    string s2 = "acf";
    string t2 = "cea";
    bAnagram = isAnagram(s2, t2);
    r = bAnagram ? "true" : "false";
    cout << s2 << " and " << t2 << " is: " << r << endl;

    return 0;
}

/**
 * @result 
    ace and cea is: true
    acf and cea is: false
 */