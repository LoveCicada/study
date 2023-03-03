
#include <iostream>
#include <cstdint>
using namespace std;

/*
* @brief 
* # һ��#�ַ���������ת��Ϊ�ַ���
* ## ����##�ַ�����ƴ��ǰ�������
* __VA_ARGS__ ����...�ɱ����
* ##__VA_ARGS__ ��ǰ�����##���������ڣ����ɱ�����ĸ���Ϊ0ʱ��##��ǰ������","ȥ��
*/

namespace mtest
{
#define _STRI(s) #s
#define STRI(s) _STRI(s)
#define _CONS(a, b) int(a##+##b)
#define _CONSX(a, b) int(a+b)
#define LOG1(...)               printf(__VA_ARGS__)//...��ʾ�ɱ������__VA_ARGS__���ǽ�...��ֵ���Ƶ�����
//#define LOG2(fmt, ...)          printf("<%s:%s>:" fmt "\r\n", __FILE__, __FUNCTION__, __VA_ARGS__)
#define LOG3(fmt, ...)          printf("<%s:%s>:" fmt "\r\n", __FILE__, __FUNCTION__, ##__VA_ARGS__)
}

void test()
{
	using namespace mtest;
	cout << "_STRI(INT_MAX): " << _STRI(INT_MAX) << endl;
	cout << "STRI(INT_MAX): " << STRI(INT_MAX) << endl;
	cout << "_CONS(1, 9): " << _CONS(1, 9) << endl;
	cout << "CONS(1, 9): " << _CONSX(1, 9) << endl;

	cout << endl << "********** LOG1 **********" << endl;
	const char* str = "ARE YOU READY";
	int num = 10086;
	LOG1("I AM ABCDEFG\r\n");
	LOG1("I AM ABCDEFG:%s, %d\r\n", str, num);

	//cout << endl << "********** LOG2 **********" << endl;
	//LOG2("I AM ABCDEFG");
	//LOG2("I AM ABCDEFG:%s, %d", str, num);

	cout << endl << "********** LOG3**********" << endl;
	LOG3("I AM ABCDEFG");
	LOG3("I AM ABCDEFG:%s, %d", str, num);

	cout << endl << "********** LOG33**********" << endl;
	LOG3("%s, %d", str, num);
}

int main()
{
	test();

	return 0;
}

/*
* @result
	_STRI(INT_MAX): INT_MAX
	STRI(INT_MAX): 2147483647
	_CONS(1, 9): 10
	CONS(1, 9): 10
	
	********** LOG1 **********
	I AM ABCDEFG
	I AM ABCDEFG:ARE YOU READY, 10086
	
	********** LOG3**********
	<G:\test\macro\macro\macro\main.cpp:test>:I AM ABCDEFG
	<G:\test\macro\macro\macro\main.cpp:test>:I AM ABCDEFG:ARE YOU READY, 10086
	
	********** LOG33**********
	<G:\test\macro\macro\macro\main.cpp:test>:ARE YOU READY, 10086
*/