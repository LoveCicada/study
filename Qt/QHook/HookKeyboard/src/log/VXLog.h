
#pragma once

#include <fstream>
#include <string>


class VXLog
{
public:
	static VXLog* GetInstance()
	{
		static VXLog instance;
		return &instance;
	}

public:
	void Write(std::string& str);

private:
	VXLog();
	~VXLog();

private:
	std::ofstream m_ofs;

};

#define LOG(str) VXLog::GetInstance()->Write(str);