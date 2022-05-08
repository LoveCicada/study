/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        char letter[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            letter[s[i] - 'a']++;
        }
        
        for(int j = 0; j < t.size(); j++) {
            letter[t[j] - 'a']--;
        }

        for(int k = 0; k < 26; k++) {
            if(letter[k] !=0 ){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

