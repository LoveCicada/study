
#pragma once

#include <iostream>
using namespace std;

/**
 * @brief 装饰者模式采用组合+继承，来实现拓展功能。
 *		  仅采用继承，会导致子类数量急剧增加。
 *
 */

#include <typeinfo> // typeid need
#include <cxxabi.h> // abi need

#ifdef __linux__

//! get class name
static int demangle_status; //注意这里必须是static，否则会运行时报错多重定义
#define __CLASS__ __class__
#define __class__ abi::__cxa_demangle(typeid(*this).name(), 0, 0, &demangle_status)

#else

#define __CLASS__ ""

#endif

//!
class Stream
{
public:
	virtual ~Stream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

public:
	virtual void Read() = 0;
	virtual void Seek() = 0;
	virtual void Write() = 0;
};

//!
class FileStream : public Stream
{
public:
	virtual ~FileStream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

public:
	virtual void Read()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Seek()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Write()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
};

class NetworkStream : public Stream
{
public:
	virtual ~NetworkStream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

public:
	virtual void Read()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Seek()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Write()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
};

class MemoryStream : public Stream
{
public:
	virtual ~MemoryStream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

public:
	virtual void Read()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Seek()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	virtual void Write()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
};

/**
 * @brief 1. DecoratorStream继承Stream，是为了继续使用Stream抽象类接口
 * 		  2. 内部存放了Stream指针，是为了运行时调用对应实例的实现函数
 * 
 */
class DecoratorStream : public Stream
{
protected:
	Stream *m_pStream;

public:
	DecoratorStream(Stream *pS) : m_pStream(pS)
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
};

class CryptoStream : public DecoratorStream
{
public:
	CryptoStream(Stream *stm) : DecoratorStream(stm)
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	~CryptoStream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

	virtual void Read()
	{

		//额外的加密操作...
		m_pStream->Read(); //读文件流
	}
	virtual void Seek()
	{
		//额外的加密操作...
		m_pStream->Seek(); //定位文件流
		//额外的加密操作...
	}
	virtual void Write()
	{
		//额外的加密操作...
		m_pStream->Write(); //写文件流
		//额外的加密操作...
	}
};

class BufferedStream : public DecoratorStream
{
public:
	BufferedStream(Stream *stm) : DecoratorStream(stm)
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}
	~BufferedStream()
	{
		cout << __CLASS__ << "::" << __func__ << endl;
	}

	virtual void Read()
	{

		//额外的加密操作...
		m_pStream->Read(); //读文件流
	}
	virtual void Seek()
	{
		//额外的加密操作...
		m_pStream->Seek(); //定位文件流
		//额外的加密操作...
	}
	virtual void Write()
	{
		//额外的加密操作...
		m_pStream->Write(); //写文件流
		//额外的加密操作...
	}
};