/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (size_t i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }
};
// @lc code=end

