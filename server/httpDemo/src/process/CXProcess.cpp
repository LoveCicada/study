
#include "CXProcess.h"

#ifdef __linux__
#include "./linux/CXProcessLinux.h"
#endif

CXProcess* CXProcess::Create()
{

#ifdef __linux__
    return new CXProcessLinux();
#endif

}