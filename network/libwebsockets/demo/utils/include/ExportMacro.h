
#pragma once

#if WIN32
#if defined(LIB_SHARED_LIBRARY)
#define LIB_EXPORT __declspec(dllexport)
#else
#define LIB_EXPORT __declspec(dllimport)
#endif
#else
#if __has_attribute(visibility) && defined(LIB_SHARED_LIBRARY)
#define LIB_EXPORT __attribute__((visibility("default")))
#endif
#endif

#ifndef LIB_EXPORT
#define LIB_EXPORT
#endif