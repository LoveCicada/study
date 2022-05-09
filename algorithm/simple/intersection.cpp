
/**
 * @file intersection.cpp
 * @author your name (you@domain.com)
 * @brief 两个数组的交集 intersection of two arrays
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> result_set;
    unordered_set<int> nums_set(nums1.begin(), nums1.end());

    for(int num: nums2){
        // 发现nums2的元素在nums_set中出现过
        if(nums_set.find(num) != nums_set.end()) {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}

void printArray(const vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    int array[] = {1, 2, 2, 4, 5, 6, 7};
    int array2[] = {0, 1, 2, 3, 4, 5, 6};

    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    vector<int> v2(array2, array2 + sizeof(array2)/sizeof(array2[0]));

    printArray(v);
    printArray(v2);

    vector<int> vs;
    vs = intersection(v, v2);
    printArray(vs);

    return 0;
}
/**
 * @result 
 *  1 2 2 4 5 6 7 
    0 1 2 3 4 5 6 
    6 5 4 2 1 
 */