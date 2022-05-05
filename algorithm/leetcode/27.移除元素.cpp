/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIdx = 0;
        int fastIdx = 0;
        for(fastIdx = 0; fastIdx < nums.size(); fastIdx++){
            if(nums[fastIdx] != val){
                nums[slowIdx++] = nums[fastIdx];
            }
        }
        return slowIdx;
    }
};
// @lc code=end

