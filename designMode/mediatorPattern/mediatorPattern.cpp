
/**
 * @file mediatorPattern.cpp
 * @author your name (you@domain.com)
 * @brief 中介者模式
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
using namespace std;


class Mediator;
 
//抽象人
class CPerson
{
protected:
    Mediator *m_mediator; //中介
public:
    virtual void SetMediator(Mediator *mediator){} //设置中介
    virtual void SendMessage(std::string message) {}    //向中介发送信息
    virtual void GetMessage(std::string message) {}     //从中介获取信息
};

//抽象中介机构
class Mediator
{
public:
    virtual void Send(std::string message, CPerson *person) {}
    virtual void SetA(CPerson *A) {}  //设置其中一方
    virtual void SetB(CPerson *B) {}
};

//Renter
class Renter: public CPerson
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(std::string message) { m_mediator->Send(message, this); }
    void GetMessage(std::string message) { std::cout<<"Renter: "<<message; }
};

//Landlord
class Landlord: public CPerson
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(std::string message) { m_mediator->Send(message, this); }
    void GetMessage(std::string message) { std::cout << "Landlord: " << message; }
};

//房屋中介
class HouseMediator : public Mediator
{
private:
    CPerson *m_A; //租房者
    CPerson *m_B; //房东
public:
    HouseMediator(): m_A(0), m_B(0) {}
    void SetA(CPerson *A) { m_A = A; }
    void SetB(CPerson *B) { m_B = B; }
    void Send(std::string message, CPerson *person) 
    {
        if(person == m_A) //租房者给房东发信息
            m_B->GetMessage(message); //房东收到信息
        else
            m_A->GetMessage(message);
    }
};
 
void MediatorTest()
{
    Mediator *mediator = new HouseMediator();
    CPerson *person1 = new Renter();    //租房者
    CPerson *person2 = new Landlord();  //房东
    mediator->SetA(person1);
    mediator->SetB(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    person1->SendMessage("123456789\n");
    person2->SendMessage("abcdefghi\n");
    
    delete person1; 
    delete person2; 
    delete mediator;
}


int main(int argc, char* argv[])
{
    cout << "mediator pattern" << endl;
    MediatorTest();

    return 0;
}