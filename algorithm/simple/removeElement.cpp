
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& v, int value) {
    int slowIdx = 0;
    int fastIdx = 0;

    for(fastIdx = 0; fastIdx < v.size(); fastIdx++) {
        if(v[fastIdx] != value){
            v[slowIdx++] = v[fastIdx];
        }
    }

    return slowIdx;
}

void printArray(const vector<int>& v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    int array[] = {0, 1, 2, 2, 4, 2, 6};
    int val = 2;
    vector<int> v(array, array + sizeof(array)/sizeof(array[0]));
    printArray(v);
    int len = removeElement(v, val);
    printArray(v);
    cout << "len = " << len << endl;
    return 0;
}