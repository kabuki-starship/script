/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2_ascii_data.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2018 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#if SEAM >= _0_0_0__12

#include "tasciidata.h"

#include "tsocket.h"

#if SEAM == _0_0_0__12
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

namespace _ {

BOL TypeIsValid(SIN type) {
  if (type >= kLST && type <= kDIC ||
      (type >= (kADR + 32) && type <= (kTKN + 32)))
    return false;
  return true;
}

TypeValue::TypeValue(SIN type, const void* value) : type(type), value(value) {
  // Nothing to do here! (:-)-+=<
}

UIT TypeFixedSize(UIT type) {
  static const SI1 kWidths[] = {
      0,   //< kNIL: 0
      1,   //< kSI1: 1
      1,   //< kUI1: 2
      2,   //< kSI2: 3
      2,   //< kUI2: 4
      2,   //< kHLF: 5
      4,   //< kBOL: 6
      4,   //< kSI4: 7
      4,   //< kUI4: 8
      4,   //< kFLT: 9
      4,   //< kTMS: 10
      8,   //< kTME: 11
      8,   //< kSI8: 12
      8,   //< kUI8: 13
      8,   //< kDBL: 14
      16,  //< kSIH: 15
      16,  //< kUIH: 16
      16,  //< kDEC: 17
  };
  SIN type_upper_bits = type >> 3;
  type &= 0x1f;
  if (type == kUIX) return ((UIT)2) << type_upper_bits;
  if (type > kOBJ) return -1;
  return kWidths[type];
}

const char** TypeStrings() { return TTypeStrings<char>(); }

const char* TypeString(SIN type) { return TypeStrings()[type & 0x1f]; }

const char* TypeString(UIT type) { return TypeString((UI1)type); }

UI1 TypeMask(UI1 value) { return value & 0x1f; }

BOL TypeIsArray(UIT type) { return type >= kTypeCount; }

BOL TypeIsSet(UIT type) { return type >= kTypeCount; }

void* TypeAlign(SIN type, void* value) {
  ASSERT(value);
  if (type == 0) return nullptr;
  if (!TypeIsValid(type)) return nullptr;

  UIT size = TypeFixedSize(type);
  if (type <= kUI1) return value;
  SIN* value_ptr = reinterpret_cast<SIN*>(value);
#if WORD_SIZE == 2
  if (type <= kHLF) return AlignUpPointer2<>(value);
#else
  if (type <= kBOL) return TAlignUp2<>(value);
#endif
  if (type <= kTMS) return AlignUp<>(value, 3);
  if (type <= kDEC) return AlignUp<>(value, 7);

  switch (type >> 6) {
    case 0:
      return value;
    case 1:
      return TAlignUp2<>(value);
    case 2:
      return AlignUp<>(value, 3);
    case 3:
      return AlignUp<>(value, 7);
  }
  return 0;
}
/*
template <typename Char, typename UI>
inline char* WriteString(char* start, char* stop, const void* value) {
  start = AlignUpPointer<char>(start);
  if (stop - start < 2 * sizeof(UI)) return nullptr;
  const Char* source = reinterpret_cast<const Char*>(value);
  UI length = TStringLength<UI, Char>(source);
  UI* target = reinterpret_cast<UI*>(start);
  *target++ = length;
  return SocketCopy(target, stop, value, length + sizeof(Char));
}*/

template <typename UI>
inline char* WriteObj(char* start, char* stop, const void* value) {
  UI* target = AlignUpPointer<UI>(start);
  const UI* source = reinterpret_cast<const UI*>(value);
  UI size = *source++;
  if (size < sizeof(UI) || size >=) return nullptr;
  *target++ = size;
  return SocketCopy(target, stop, value, size - sizeof(UI));
}

char* Write(char* start, char* stop, SIN type, const void* value) {
  // Algorithm:
  // 1.) Determine type.
  // 2.) Align start pointer to type width.
  // 3.) Check for enough room in start-stop socket.
  // 4.) Use SocketCopy to copy the data into the given start-stop socket.

  if (!start || start >= stop || !value || !TypeIsValid(type)) return nullptr;

  if (type <= kUI1) {
    char* target_1 = reinterpret_cast<char*>(start);
    *target_1++ = *reinterpret_cast<const char*>(value);
    return target_1;
  }
  if (type <= kBOL) {
    char16_t* target_2 = TAlignUp2<char16_t>(start);
    *target_2++ = *reinterpret_cast<const char16_t*>(value);
    return reinterpret_cast<char*>(target_2);
  }
  if (type <= kTMS) {
    char32_t* target_4 = AlignUp<char32_t>(start, 3);
    *target_4++ = *reinterpret_cast<const char32_t*>(value);
    return reinterpret_cast<char*>(target_4);
  }
  if (type <= kDEC) {
    UI8* target_8 = AlignUp<UI8>(start, 7);
    const UI8* source_8 = reinterpret_cast<const UI8*>(value);
    *target_8++ = *source_8++;
    if (type == kDEC) {
      *target_8++ = *source_8;
      return reinterpret_cast<char*>(target_8);
    }
    return reinterpret_cast<char*>(target_8);
  }
  if (TypeIsString(type)) {
    switch (type >> 6) {
      case 0:
        return TPrint<char>(start, stop, reinterpret_cast<const char*>(value));
      case 1:
        return TPrint<char>(start, stop, reinterpret_cast<const char*>(value));
      case 2:
        return TPrint<char>(start, stop, reinterpret_cast<const char*>(value));
      case 3:
        return reinterpret_cast<char*>(TPrint<char16_t>(
            reinterpret_cast<UI2*>(start), reinterpret_cast<UI2*>(stop),
            reinterpret_cast<const UI2*>(value)));
      case 4:
        return TPrint<char>(start, stop, reinterpret_cast<const char*>(value));
      case 5:
        return reinterpret_cast<char*>(TPrint<char16_t>(
            reinterpret_cast<UI2*>(start), reinterpret_cast<UI2*>(stop),
            reinterpret_cast<const UI2*>(value)));
      case 6:
        return TPrint<char>(start, stop, reinterpret_cast<const char*>(value));
      case 7:
        return reinterpret_cast<char*>(TPrint<char16_t>(
            reinterpret_cast<UI2*>(start), reinterpret_cast<UI2*>(stop),
            reinterpret_cast<const UI2*>(value)));
    }
  }
  char array_type = type >> 6;
  switch (array_type) {
    case 0:
      return WriteObj<UI1>(start, stop, value);
    case 1:
      return WriteObj<UI2>(start, stop, value);
    case 2:
      return WriteObj<UI4>(start, stop, value);
    case 3:
      return WriteObj<UI8>(start, stop, value);
  }
  return nullptr;
}

BOL TypeIsObj(SIN type) {
  if (type < kOBJ) return false;
  return true;
}

BOL TypeIsString(SIN type) {
  type &= 0x1f;
  if (type >= kADR && type <= kTKN) return true;
  return false;
}

BOL TypeIsUtf16(SIN type) { return (BOL)(type & 0x20); }

inline int TypeSizeWidthCode(SIN type) { return type >> 6; }

}  // namespace _

#if USING_UTF8
namespace _ {
char* Print(char* start, char* stop, SIN type, const void* value) {
  return TPrint<char>(start, stop, type, value);
}
_::UTF1& operator<<(_::UTF1& utf, const _::TypeValue& item) {
  return utf.Set(_::Print(utf.start, utf.stop, item.type, item.value));
}
}  // namespace _
#endif
#if USING_UTF16
namespace _ {
char16_t* Print(char16_t* start, char16_t* stop, SIN type, const void* value) {
  return TPrint<char16_t>(start, stop, type, value);
}
}  // namespace _
_::UTF2& operator<<(_::UTF2& utf, const _::TypeValue& item) {
  return utf.Set(_::Print(utf.start, utf.stop, item.type, item.value));
}
#endif
#if USING_UTF32
namespace _ {
char32_t* Print(char32_t* start, char32_t* stop, SIN type, const void* value) {
  return TPrint<char32_t>(start, stop, type, value);
}
}  // namespace _
_::UTF4& operator<<(_::UTF4& utf, const _::TypeValue& item) {
  return utf.Set(_::Print(utf.start, utf.stop, item.type, item.value));
}
#endif

#endif  //< #if SEAM >= _0_0_0__12
