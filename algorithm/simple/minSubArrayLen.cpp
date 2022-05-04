
#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(vector<int>& v, int value) {
    int result = INT32_MAX;
    int sum = 0;    //滑动窗口的数值之和
    int i = 0;      //滑动窗口的起始位置
    int subLength = 0;//滑动窗口的长度

    for( int j = 0; j < v.size(); j++ ){
        sum += v[j];
        // 每次更新i(起始位置)并不断比较子数组是否符合条件
        while(sum >= value){
            //获取子数组的长度
            subLength = (j - i + 1);
            result = result < subLength ? result : subLength;
            //不断变更i(子数组的起始位置)
            sum -= v[i++];
        }
        
    }

    return result == INT32_MAX ? 0 : result;
}

void printArray(const vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    int array[] = {2, 3, 1, 2, 4, 3};
    int val = 7;
    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    printArray(v);
    int len = minSubArrayLen(v, val);
    printArray(v);
    cout << "len = " << len << endl;
    return 0;
}