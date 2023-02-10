
#include "VXCKeyAssistantFactory.h"

std::unique_ptr<CKeyAssistant> CreateKeyAssistant()
{
#if defined(_WIN32)
    return std::make_unique<CKeyAssistantWin>();

#elif defined(__APPLE__) && defined(__MACH__)
    return std::make_unique<CKeyAssistantMac>();
#else
    //! to do

#endif
}