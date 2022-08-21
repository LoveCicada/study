
#include "VXLog.h"

VXLog::VXLog()
{
	m_ofs.open("keyevent.log", std::ios_base::app);
}

VXLog::~VXLog()
{
	m_ofs.close();
}

void VXLog::Write(std::string& str)
{
	m_ofs.write(str.c_str(), str.length());
	m_ofs << std::endl;
	m_ofs.flush();
}