#include "template.hpp"
#include <utility>
#include <string>
#include <vector>


void test()
{
	cout << "test c++11" << endl;

	cout << "右值引用" << endl;
	A a = GetA();

	//A&& aa = GetA();




	cout << "可变参数模板" << endl;

	func();
	func(1);
	func(1, 2.0);
	func(1, 2.0, "1", true);

	//2.1.1
	print(1, 2, 3, 4);

	//
	cout << "sum = " << sum(1, 2, 3, 4) << endl;

	//
	expand(1, 2, 3, 4);
	cout << endl;

	//
	expandEx([](int i) {
		cout << i << endl;
		}, 1, 2, 3);
	cout << endl;

	//
	expandEx([](auto i) {
		cout << i << endl; 
		}, 1, 2.0, "test");
	cout << endl;


	[]() {};
	[] {};

	//
	//2.2 可变模板参数类
	std::tuple<> tp;
	std::tuple<int> tp1 = std::make_tuple(1);
	std::tuple<int, double> tp2 = std::make_tuple(1, 2.5);
	std::tuple<int, double, string> tp3 = std::make_tuple(1, 2.5, "");


	//delegate
	AA aa;
	auto dd = CreateDelegate(&aa, &AA::Fun);
	dd(1);
	auto dd1 = CreateDelegate(&aa, &AA::Fun1);
	dd1(1, 2.5);


	//移动语义
	{
		std::string str = "hello";
		std::vector<std::string> v;
		v.push_back(str);
		std::cout << "str = " << str << endl;
		v.push_back(std::move(str));
		std::cout << "after move" << endl;
		std::cout << "str = " << str << endl;
		std::vector<string>::const_iterator it = v.begin();
		for (; it != v.end(); ++it)
		{
			std::cout << *it << endl;
		}

	}

}
