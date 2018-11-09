/* Script
@version 0.x
@file    /bsq.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= _0_0_0__14
#ifndef INCLUDED_SCRIPTVARINT
#define INCLUDED_SCRIPTVARINT

#include "config.h"

namespace _ {

#if WORD_SIZE == 16
inline int16_t UnpackSVI(int16_t value) {
  if (value < 0) {
    uint16_t result = 0x8000 return result | ~(value - 1);
  }
  return value;
}

inline int16_t PackSVI(int16_t value) {
  if (value < 0) {
    uint16_t result = 1 << 15;
    return result | ((~value + 1) << 1);
  }
  return value;
}
#else
inline int32_t UnpackSVI(int32_t value) {
  if (value < 0) {
    uint32_t result = 0x80000000;
    return result | ~(value - 1);
  }
  return value;
}

inline int32_t PackSVI(int32_t value) {
  if (value < 0) {
    int32_t result = 0x80000000;
    return result | ((~value + 1) << 1);
  }
  return value;
}
#endif

inline int64_t UnpackSV8(int64_t value) {
  if (value < 0) {
    int64_t result = 0x8000000000000000;
    return result | ~(value - 1);
  }
  return value;
}

inline int64_t PackSV8(int64_t value) {
  if (value < 0) {
    int64_t result = 0x8000000000000000;
    return result | ((~value + 1) << 1);
  }
  return value;
}

// template<typename T>
// T UnpackSVI (T value) {
//    T temp = value << sizeof (T) * 8 - 1;
//    temp |= value;
//    return temp;
//}

}  //< namespace _
#endif  //< INCLUDED_SCRIPTVARINT
#endif  //< #if SEAM >= _0_0_0__14
