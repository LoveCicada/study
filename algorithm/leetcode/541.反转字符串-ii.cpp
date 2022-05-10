/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
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
    }
};
// @lc code=end

