
#include "VXCKeyAssistantFactory.h"

unique_ptr<CKeyAssistant> CreateKeyAssistant()
{
#if _WIN32
    return make_unique<CKeyAssistantWin>();
#endif
}