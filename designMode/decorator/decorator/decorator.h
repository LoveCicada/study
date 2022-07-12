
#pragma once


#include <iostream>
using namespace std;

/**
 * @brief 
 * 
 */

//!
class Stream
{
public:
	virtual ~Stream() {
		cout << "Stream: " << __func__ << endl;
	}
public:
	virtual void Read() = 0;
	virtual void Seek() = 0;
	virtual void Write() = 0;
};

//!
class FileStream : public Stream{
public:
	virtual ~FileStream() {
		cout << "FileStream: " << __func__ << endl;
	}
public:
	virtual void Read(){
		cout << "FileStream: " << __func__ << endl;
	}
	virtual void Seek(){
		cout << "FileStream: " << __func__ << endl;
	}
	virtual void Write(){
		cout << "FileStream: " << __func__ << endl;
	}

};

class NetworkStream  : public Stream{
public:
	virtual ~NetworkStream () {
		cout << "NetworkStream : " << __func__ << endl;
	}
public:
	virtual void Read(){
		cout << "NetworkStream : " << __func__ << endl;
	}
	virtual void Seek(){
		cout << "NetworkStream : " << __func__ << endl;
	}
	virtual void Write(){
		cout << "NetworkStream : " << __func__ << endl;
	}

};

class MemoryStream  : public Stream{
public:
	virtual ~MemoryStream () {
		cout << "MemoryStream : " << __func__ << endl;
	}
public:
	virtual void Read(){
		cout << "MemoryStream : " << __func__ << endl;
	}
	virtual void Seek(){
		cout << "MemoryStream : " << __func__ << endl;
	}
	virtual void Write(){
		cout << "MemoryStream : " << __func__ << endl;
	}

};

//!
class DecoratorStream : public Stream{
protected:
	Stream* m_pStream;
public:
	DecoratorStream(Stream* pS) : m_pStream(pS) {
		cout << "DecoratorStream : " << __func__ << endl;
	}
};

class CryptoStream: public DecoratorStream {
public:
    CryptoStream(Stream* stm) : DecoratorStream(stm){
		cout << "CryptoStream : " << __func__ << endl;
    }
	~CryptoStream(){
		cout << "CryptoStream : " << __func__ << endl;
	}

    virtual void Read(){
       
        //额外的加密操作...
        m_pStream->Read();//读文件流
    }
    virtual void Seek(){
        //额外的加密操作...
        m_pStream->Seek();//定位文件流
        //额外的加密操作...
    }
    virtual void Write(){
        //额外的加密操作...
        m_pStream->Write();//写文件流
        //额外的加密操作...
    }
};

class BufferedStream: public DecoratorStream {
public:
    BufferedStream(Stream* stm) : DecoratorStream(stm){
		cout << "BufferedStream : " << __func__ << endl;
    }
	~BufferedStream(){
		cout << "BufferedStream : " << __func__ << endl;
	}

    virtual void Read(){
       
        //额外的加密操作...
        m_pStream->Read();//读文件流
    }
    virtual void Seek(){
        //额外的加密操作...
        m_pStream->Seek();//定位文件流
        //额外的加密操作...
    }
    virtual void Write(){
        //额外的加密操作...
        m_pStream->Write();//写文件流
        //额外的加密操作...
    }
};