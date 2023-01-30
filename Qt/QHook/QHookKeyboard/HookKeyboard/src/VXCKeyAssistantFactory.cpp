
#include "VXCKeyAssistantFactory.h"

unique_ptr<CKeyAssistant> CreateKeyAssistant()
{
#if defined(_WIN32)
    return make_unique<CKeyAssistantWin>();

#elif defined(__APPLE__) && defined(__MACH__)
    return make_unique<CKeyAssistantMac>();
#else
    //! to do

#endif
}