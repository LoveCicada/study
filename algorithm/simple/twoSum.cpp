
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
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++){
        auto itor = um.find(target - nums[i]);
        if(itor != um.end()){
            return {itor->second, i};
        }
        um.insert(pair<int, int>(nums[i], i));
    }
    return {};
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
    int array[] = {2, 7, 11, 15};
    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    printArray(v);

    int target = 9;
    vector<int> vs;
    vs = twoSum(v, target);
    printArray(vs);

    return 0;
}
/**
 * @result 
 *  1 2 3 4 5 6 7 
    3 4 
 */