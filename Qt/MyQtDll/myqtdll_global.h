#ifndef MYQTDLL_GLOBAL_H
#define MYQTDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYQTDLL_LIBRARY)
#  define MYQTDLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MYQTDLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MYQTDLL_GLOBAL_H
