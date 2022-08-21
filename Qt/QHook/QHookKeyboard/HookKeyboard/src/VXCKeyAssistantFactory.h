
#pragma once

/*
@brief
*/

#include <memory>
using std::unique_ptr;
using std::make_unique;

#if _WIN32
#include "win/VXCKeyAssistantWin.h"
#endif  // WIN32

unique_ptr<CKeyAssistant> CreateKeyAssistant();