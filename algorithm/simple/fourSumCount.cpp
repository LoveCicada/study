
/**
 * @file intersection.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

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

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    // key: a+b的数值
    // value: a+b数值出现的次数
    // 遍历A、B数组, 统计两个数组元素之和及出现的次数, 并放到map中
    unordered_map<int, int> um;
    for(int a: nums1) {
        for(int b: nums2) {
            um[a+b]++;
        }
    }
    
    // 统计a++c+d=0 出现的次数
    int count = 0;

    // a+b = 0 - (c + d);

    // 在遍历C、D数组时, 如果0-(c+d)在map中出现过
    // 就统计map中key对应的value, 即两数之和出现的次数
    for(int c: nums3){
        for(int d: nums4) {
            if(um.find(0 - (c + d)) != um.end()){
                count += um[0 - (c + d)];
            }
        }
    }

    return count;
}

void printArray(const vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    //int array[] = {1, 2, 3, 4, 5, 6, 7};
    int array[] = {1, 2};
    int array2[] = {-2, -1};
    int array3[] = {-1, 2};
    int array4[] = {0, 2};

    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    vector<int> v2(array2, array2 + sizeof(array2)/sizeof(array2[0]));
    vector<int> v3(array3, array3 + sizeof(array3)/sizeof(array3[0]));
    vector<int> v4(array4, array4 + sizeof(array4)/sizeof(array4[0]));

    printArray(v);
    printArray(v2);
    printArray(v3);
    printArray(v4);

    int val = fourSumCount(v, v2, v3, v4);
    cout << "val: " << val << endl;

    return 0;
}
/**
 * @result 
    1 2 
    val: 2
 */