

#include <iostream>
#include "wfrest/json.hpp"
using namespace std;
using Json = nlohmann::json;

int main(int argc, char *argv[])
{
    Json animalObject = {{"kind", "dog"}, {"height", 50}}; //定义一个对象类型的json对象

    // {
    //     "color": "red"
    // }

    animalObject.push_back({"color", "red"});              //插入元素
    animalObject.erase("kind");                            //删除键值
    cout << "animalObject: " << animalObject << endl;
    animalObject["height"] = 99; //通过key修改value值
    //判断是否含有某个键值方式一
    if (animalObject.contains("height")) //通过contains函数判断是否包含某个key
    {
        auto height = animalObject["height"].get<double>();
        cout << "方式一:height: " << height << endl;
    }

    return 0;
}