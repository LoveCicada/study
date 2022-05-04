/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 使用vector定义一个二维数组
        vector<vector<int>> res(n, vector<int>(n, 0));
        // 定义每循环一个圈的起始位置
        int startX = 0, startY = 0;
        // 每个圈循环几次，例如n为奇数3，那么loop=1只是循环一圈，
        // 矩阵中间的值需要单独处理
        int loop = n/2;
        // 矩阵中间的位置，例如：n为3，中间的位置就是(1,1)，n为5，中间位置为(2,2)
        int mid = n/2;
        // 用来给矩阵中每一个空格赋值
        int count = 1;
        // 每一圈循环，需要控制每一条边遍历的长度
        int offset = 1;
        int i, j;
        while(loop--){
            i = startX;
            j = startY;

            // 下面开始的四个for循环是模拟转了一圈
            // 模拟填充上行(从左到右)(左闭右开)
            // --->
            for( j = startY; j < startY + n - offset; j++ ){
                res[startX][j] = count++;
            }

            // 模拟填充右列(从上到下)(左闭右开)
            //       |
            //       |
            //      \ /
            //       .
            for( i = startX; i < startX + n - offset; i++ ){
                res[i][j] = count++;
            }

            // 模拟填充下行(从右到左)(左闭右开)
            // <---
            for( ; j > startY; j-- ){
                res[i][j] = count++;
            }

            // 模拟填充左列从下到上(左闭右开)
            //       .
            //      / \
            //       |
            //       |
            for( ; i > startX; i-- ){
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1，
            // 例如：第一圈起始位置是(0,0)，第二圈起始位置是(1,1)
            startX++;
            startY++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 2;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if(n % 2){
            res[mid][mid] = count;
        }

        return res;
    }
};
// @lc code=end

