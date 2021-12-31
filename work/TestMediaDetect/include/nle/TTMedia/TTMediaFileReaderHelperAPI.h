
#ifndef __def_media_file_reader__helper__header__
#define __def_media_file_reader__helper__header__

#include "./TTMediaFileReaderAPI.h"

#include <memory>
#include <functional>

#if _MSC_VER > 1500

typedef std::shared_ptr<ITTMediaReader> ITTMediaReaderSPtr;
inline ITTMediaReaderSPtr TT_CreateMediaReaderSptr()
{
    ITTMediaReader* pReader = TT_CreateMediaReader();
    if (pReader)
        return ITTMediaReaderSPtr(pReader, std::mem_fn(&ITTMediaReader::Destroy));
    return ITTMediaReaderSPtr();
}

#elif _MSC_VER==1500 && _HAS_TR1

/** ������װ��ITTMediaReader, @see ITTMediaReader */
typedef std::tr1::shared_ptr<ITTMediaReader> ITTMediaReaderSPtr;

/**
����VFR Reader, 
@note �ͷ�ʱ������ITTMediaReader::Destroy, ����std.shared_ptr.reset
@param TTMediaReaderType, TTMediaReaderType_VFR��֡��Reader
@return ITTMediaReaderSPtr
@see ITTMediaReader, ITTMediaReaderSPtr
*/
inline ITTMediaReaderSPtr TT_CreateMediaReaderSptr()
{
    ITTMediaReader* pReader = TT_CreateMediaReaderEx();
    if (pReader)
        return ITTMediaReaderSPtr(pReader, std::tr1::mem_fn(&ITTMediaReader::Destroy));
    return ITTMediaReaderSPtr();
}

/**
����VFR Reader, CFR Reader
@note �ͷ�ʱ������ITTMediaReader::Destroy, ����std.shared_ptr.reset
@param TTMediaReaderType, TTMediaReaderType_VFR��֡��Reader, TTMediaReaderType_CFR�̶�֡��Reader
@return ITTMediaReaderSPtr
@see ITTMediaReader, ITTMediaReaderSPtr
*/
inline ITTMediaReaderSPtr TT_CreateMeidaReaderExSptr(const wchar_t* TTMediaReaderType = TTMediaReaderType_VFR)
{
    ITTMediaReader* pReader = TT_CreateMediaReaderEx(TTMediaReaderType);
    if (pReader)
        return ITTMediaReaderSPtr(pReader, std::tr1::mem_fn(&ITTMediaReader::Destroy));
    return ITTMediaReaderSPtr();
}

#endif

#endif
