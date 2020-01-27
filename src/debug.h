#ifndef DVM_DEBUG_H
#define DVM_DEBUG_H

#include <stdio.h>

#ifdef _DEBUG
  #define dbg printf
#else
  #define dbg(...)
#endif

#endif//DVM_DEBUG_H
