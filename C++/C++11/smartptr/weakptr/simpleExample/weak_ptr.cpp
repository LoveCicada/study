#include <iostream>
#include <memory>
#include <string>
using namespace std;

void Check(weak_ptr<int>& wp)
{
    //转化为shared_ptr<int>
    shared_ptr<int> sp = wp.lock();
    if(sp != nullptr)
        cout << "still " << *sp << endl;
    else
        cout << "pointer is invalid." << endl;    
}

void test()
{
    shared_ptr<int> sp1(new int(22));
    shared_ptr<int> sp2 = sp1;
    //指向shared_ptr<int>所指对象
    weak_ptr<int> wp = sp1;

    cout << *sp1 << endl;   //22
    cout << *sp2 << endl;   //22
    Check(wp);              //still 22

    sp1.reset();
    //cout << *sp1 << endl;   //invalid
    cout << *sp2 << endl;   //22
    Check(wp);              //still 22

    sp2.reset();
    //cout << *sp1 << endl;   //invalid
    //cout << *sp2 << endl;   //invalid
    Check(wp);              //invalid
}

void test2()
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1);
    weak_ptr<int> wp(sp2);
    //输出和wp同指向的sharped_ptr类型指针的数量
    cout << "wp.use_count() = " << wp.use_count() <<endl;   //2
    //释放 sp2
    sp2.reset();
    cout << wp.use_count() << endl; //1
    //借助lock函数，返回一个和wp同指向的shared_ptr类型指针，获取其存储的数据
    cout << "*(wp.lock()) = " << *(wp.lock()) << endl;
    string str = !wp.expired() ? "wp未过期 " : "wp过期无效了";
    cout << str << endl;

    sp1.reset();
    cout << wp.use_count() << endl; //1
    //借助lock函数，返回一个和wp同指向的shared_ptr类型指针，获取其存储的数据
    //cout << "*(wp.lock()) = " << *(wp.lock()) << endl;
    str = !wp.expired() ? "wp未过期 " : "wp过期无效了";
    cout << str << endl;
    
}

int main()
{
    test();
    test2();

    return 0;
}