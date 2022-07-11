
#include <iostream>
using namespace std;

class Father
{
public:
    virtual int add(int l = 10, int r = 20)
    {
        cout << "Father: " << __func__ << endl;
        return l + r;
    }
};

class Son : public Father
{
public:
    virtual int add(int l = 11, int r = 22)
    {
        cout << "Son: " << __func__ << endl;
        return l + r;
    }
};

int main()
{
    Father* pF = new Son();
    int ret = pF->add();
    cout << "ret = " << ret << endl;

    ret = pF->add(33, 44);
    cout << "ret = " << ret << endl;

    delete pF;

    return 0;
}