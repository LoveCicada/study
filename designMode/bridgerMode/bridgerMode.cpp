
/**
 * @file bridgerMode.cpp
 * @author your name (you@domain.com)
 * @brief bridger Mode
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// forward declaration
class Color;

// abstract
class Pen
{
public:
    virtual ~Pen() {}

    virtual void draw(const string& name) = 0;

    void setColor(shared_ptr<Color> pColor)
    {
        m_pColor = pColor;
    }

    shared_ptr<Color> getColor()
    {
        return m_pColor;
    }

private:
    shared_ptr<Color> m_pColor;
};

// implementation
class Color
{
public:
    virtual ~Color() {}

    virtual void bepaint(const string& penType, const string& name) = 0;
};

class BigPen : public Pen
{
public:
    void draw(const string& name)
    {
        string pen_type = "大号钢笔绘制";
        getColor()->bepaint(pen_type, name);
    }
};

class SmallPencil : public Pen 
{
public:
    void draw(std::string name) 
    {
        std::string pen_type = "小号铅笔绘制";
        getColor()->bepaint(pen_type, name);
    }
};

class Red : public Color
{
public:
    void bepaint(const string& penType, const string& name) override
    {
        cout << penType << " 红色的 " << name << "." << endl;
    }
};

class Green : public Color
{
public:
    void bepaint(const string& penType, const string& name) override
    {
        cout << penType << " 绿色的 " << name << "." << endl;
    }
};

int main(int argc, char * argv[])
{
    shared_ptr<Color> pColor(new Red());
    shared_ptr<Pen> pPen(new BigPen());

    pPen->setColor(pColor);
    pPen->draw("地球");

    return 0;
}

//! @see https://blog.csdn.net/m0_46655373/article/details/123948257