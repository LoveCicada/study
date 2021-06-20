#ifndef A_H
#define A_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

class ConcreteCommand1 : public Command
{
	string m_Arg;
public:
	ConcreteCommand1(const string& a)
		:m_Arg(a)
	{

	}

	void execute()
	{
		cout<<"ConcreteCommand1 process..."<<m_Arg<<endl;
	}
};

class ConcreteCommand2 : public Command
{
	string m_Arg;
public:
	ConcreteCommand2(const string& a)
		:m_Arg(a)
	{

	}

	void execute()
	{
		cout<<"ConcreteCommand2 process..."<<m_Arg<<endl;
	}
};

class MacroCommand : public Command
{
	vector<Command*> m_Commands;
public:
	void addCommand(Command* c)
	{
		m_Commands.push_back(c);
	}
	void execute()
	{
		for(auto& c : m_Commands)
		{
			c->execute();
		}
	}
};





#endif // A_H
