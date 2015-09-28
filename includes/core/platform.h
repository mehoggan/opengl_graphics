#ifndef OPENGL_GRAPHICS_PLATFORM_H_INCLUDED
#define OPENGL_GRAPHICS_PLATFORM_H_INCLUDED

#if defined(__ANDROID__)
  #define __OPENGL_GRAPHICS_ANDROID__ 1
  #define msvc_typename
#elif defined(__CYGWIN__)
  #define __OPENGL_GRAPHICS_CYGWIN__ 1
  #define msvc_typename
#elif defined(__gnu_linux__) || defined(__linux__)
  #define __OPENGL_GRAPHICS_GNULINUX__ 1
  #define msvc_typename
#elif defined(macintosh) || defined(Macintosh) || defined(__APPLE__)
  #define __OPENGL_GRAPHICS_MACOSX__ 1
  #define msvc_typename
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
  #include <Windows.h>
  #define __OPENGL_GRAPHICS_WINDOWS__ 1
  #define msvc_typename typename
  #if defined(_WIN16)
    #define __OPENGL_GRAPHICS_16_BIT__ 1
  #elif defined(_WIN32)
    #define __OPENGL_GRAPHICS_32_BIT__ 1
  #elif defined(_M_IA64) || defined(_M_AMD64) || defined(__x86_64__) || defined(__x86_64)
    #define __OPENGL_GRAPHICS_64_BIT__ 1
  #else
    #define __OPENGL_GRAPHICS_32_BIT__ 1
  #endif
#endif

#endif
