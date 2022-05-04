/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    //! 左闭右闭
    int search(vector<int>& nums, int target) {
        int left = 0;
        //! 定义target在左闭右闭的区间, 即[left, right]
        int right = nums.size() - 1;
        //! 当left == right, [left, right]区间依然有效, 所以使用<=
        while(left <= right) {
            //! 防止溢出, 等同于(left+right)/2
            int middle = left + (right - left) / 2;
            if(target < nums[middle]) {
                //! target在[left, middle-1]
                right = middle - 1;
            }else if(target > nums[middle]) {
                //! target在[middle+1, right]
                left = middle + 1;
            }else {
                //! target == nums[middle]
                return middle;
            }
        }

        //! not found
        return -1;
    } 
};
// @lc code=end

