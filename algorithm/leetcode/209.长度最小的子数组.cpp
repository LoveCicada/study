/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int i = 0;  //起点位置
        int j = 0;  //终点位置
        int sum = 0;//字串和
        int subLength = 0;//滑动窗口长度
        for(j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while(sum >= target) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++];
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};
// @lc code=end

