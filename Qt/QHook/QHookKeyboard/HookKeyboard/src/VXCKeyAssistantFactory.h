
#pragma once

/*
@brief
*/

#include <memory>
using std::unique_ptr;
using std::make_unique;

#if defined(_WIN32)
#include "win/VXCKeyAssistantWin.h"
#elif defined(__APPLE__) && defined(__MACH__)
#include "mac/VXCKeyAssistantMac.h"
#else

#endif  // WIN32

unique_ptr<CKeyAssistant> CreateKeyAssistant();