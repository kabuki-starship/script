/* SCRIPT Script @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    \pch_footer.hpp
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// The below macros can be override in the pch.h file.

#if SCRIPT2_MAX_PARAMS < 0
#error MAX_ERRORS must be greater than 0
#endif

#ifndef SCRIPT2_MAX_WALLS
#define SCRIPT2_MAX_WALLS 65535
#endif
#ifndef SCRIPT2_MAX_ERRORS
#define SCRIPT2_MAX_ERRORS 65535
#endif
#ifndef SCRIPT2_MAX_PARAMS
#define SCRIPT2_MAX_PARAMS 65535
#endif
#ifndef SCRIPT2_COM_TIMEOUT_TICKS
#define SCRIPT2_COM_TIMEOUT_TICKS 65535
#else
#if SCRIPT2_COM_TIMEOUT_TICKS < 0
#error MAX_ERRORS must be greater than 0
#endif
#endif
#ifndef SCRIPT2_MAX_ADDRESS_LENGTH
#define SCRIPT2_MAX_ADDRESS_LENGTH 65535
#endif
#ifndef SCRIPT2_OP_MAX_NAME_LENGTH
#define SCRIPT2_OP_MAX_NAME_LENGTH 65535
#endif
#ifndef SCRIPT2_OP_MAX_DECRABSION_LENGTH
#define SCRIPT2_OP_MAX_DECRABSION_LENGTH 65535
#endif
#ifndef SCRIPT2_TEXT_LENGTH
#define SCRIPT2_TEXT_LENGTH 65535
#endif
#ifndef SCRIPT2_BUFFER_SIZE_RX
#define SCRIPT2_BUFFER_SIZE_RX 65535
#endif
#ifndef SCRIPT2_BUFFER_SIZE_TX
#define SCRIPT2_BUFFER_SIZE_TX 65535
#endif

#ifndef SCRIPT2_WINDOW_SIZE_MIN
#define SCRIPT2_WINDOW_SIZE_MIN 512
#endif
#ifndef SCRIPT2_CPU_CACHE_LINE_SIZE
#define SCRIPT2_CPU_CACHE_LINE_SIZE 64
#endif

#ifndef SCRIPT2_BUFFER_COUNT_DEFAULT
#define SCRIPT2_BUFFER_COUNT_DEFAULT 1024
#else
#if SCRIPT2_BUFFER_COUNT_DEFAULT < 1
#define SCRIPT2_BUFFER_COUNT_DEFAULT 512
#endif

#endif
#ifndef SCRIPT2_STACK_COUNT_MAX_DEFAULT
#define SCRIPT2_STACK_COUNT_MAX_DEFAULT 32
#endif
#ifndef SCRIPT2_FLOOR_SIZE
#define SCRIPT2_FLOOR_SIZE 1024
#endif
#ifndef SCRIPT2_STACK_COUNT_MAX_DEFAULT
#define SCRIPT2_STACK_COUNT_MAX_DEFAULT 16
#endif
#ifndef SCRIPT2_OBJ_SIZE_DEFAULT
#define SCRIPT2_OBJ_SIZE_DEFAULT 256
#endif
#ifndef SCRIPT2_TOKEN_COUNT
#define SCRIPT2_TOKEN_COUNT 32
#endif
#ifndef SCRIPT2_STRAND_COUNT_DEFAULT
#define SCRIPT2_STRAND_COUNT_DEFAULT 28
#endif
#ifndef SCRIPT2_CIN_BUFFER_SIZE
#define SCRIPT2_CIN_BUFFER_SIZE 81
#endif
#ifndef SCRIPT2_UNICODE_VERSION_MAJOR
#define SCRIPT2_UNICODE_VERSION_MAJOR 12
#endif
#ifndef SCRIPT2_UNICODE_VERSION_MINOR
#define SCRIPT2_UNICODE_VERSION_MINOR 1
#endif
#ifndef SCRIPT2_UNICODE_ASSIGNED_CODE_POINTS
#define SCRIPT2_UNICODE_ASSIGNED_CODE_POINTS 277576
#endif
#ifndef SCRIPT2_CONSOLE_WIDTH
#define SCRIPT2_CONSOLE_WIDTH 80
#endif
#ifndef SCRIPT2_DTA_WIDTH
#define SCRIPT2_DTA_WIDTH 0
#endif

// End overridable `pch.h` parameters.

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#ifdef ASSEMBLE_LIBRARY
#ifdef LIB_EXPORT == YES_0
#define LIB_MEMBER __declspec(dllexport)
#else
#define LIB_MEMBER __declspec(dllimport)
#endif
#else
#define LIB_MEMBER
#endif

#if SCRIPT2_PLATFORM == OS_WINDOWS
#define APP_EXIT_SUCCESS 0
#define APP_EXIT_FAILURE 1
#else
#define APP_EXIT_SUCCESS 0
#define APP_EXIT_FAILURE 1
#endif

#if USING_16_BYTE_POD_TYPES == YES_0
typedef int128_t SIH;
typedef uint128_t UIH;
#endif

#if SEAM < SCRIPT2_UNIPRINTER
#undef USING_UTF16
#undef USING_UTF32
#define USING_UTF16 NO_0
#define USING_UTF32 NO_0
#endif

#if SEAM < SCRIPT2_FTOS
#undef USING_FP4
#undef USING_FP8
#define USING_FP4 NO_0
#define USING_FP8 NO_0
#endif

#if USING_FP == 4
typedef FP4 FPW;
#elif USING_FP == 8
typedef FP8 FPW;
#endif

#if ALU_SIZE == ALU_16_BIT
#define CPU_IS_LESS_THAN_32_BIT 1
#define CPU_IS_LESS_THAN_64_BIT 1
#define CPU_IS_GREATER_THAN_16_BIT 0
#define CPU_IS_GREATER_THAN_32_BIT 0
#elif ALU_SIZE == ALU_32_BIT
#define CPU_IS_LESS_THAN_32_BIT 0
#define CPU_IS_LESS_THAN_64_BIT 1
#define CPU_IS_GREATER_THAN_16_BIT 1
#define CPU_IS_GREATER_THAN_32_BIT 0
#elif ALU_SIZE == ALU_64_BIT
#define CPU_IS_LESS_THAN_32_BIT 0
#define CPU_IS_LESS_THAN_64_BIT 0
#define CPU_IS_GREATER_THAN_16_BIT 1
#define CPU_IS_GREATER_THAN_32_BIT 1
#endif

// Default character type.
#if USING_STR == STRING_TYPE_2
typedef CH2 CHR;
#elif USING_STR == STRING_TYPE_3
typedef CH4 CHR;
#else  // ASCII or UTF-8.
typedef CH1 CHR;
#endif

//< The Largest char.
#if LARGEST_CHAR == STRING_TYPE_2
#if USING_UTF16 == YES_0
typedef CH2 CHA;
#else
#error You must set the LARGEST_CHAR to  STRING_TYPE_1.
#endif
#elif LARGEST_CHAR == STRING_TYPE_3
#if USING_UTF32 == YES_0
typedef CH4 CHA;
#else
#error You must set the LARGEST_CHAR to  STRING_TYPE_1 or STRING_TYPE_2.
#endif
#else
typedef CH1 CHA;
#endif

#if ALU_SIZE == ALU_64_BIT
typedef SI2 SIG;  //< Half of SIN type
typedef UI2 UIG;  //< Half of UIN type
#if COMPILER_SUPPORTS_16_BYTE_INTEGERS
#define LARGEST_POD_TYPE 16
#else
#define LARGEST_POD_TYPE 8
#endif
#elif ALU_SIZE == ALU_32_BIT
typedef SI2 SIG;  //< Half of SIN type
typedef UI2 UIG;  //< Half of UIN type
#define LARGEST_POD_TYPE 8
#elif ALU_SIZE == ALU_16_BIT
typedef SI1 SIG;  //< Half of SIN type
typedef UI1 UIG;  //< Half of UIN type
#else
#define LARGEST_POD_TYPE 4
#endif

#define PRIME_LARGEST_UI2 65521
#define PRIME_LARGEST_UI4 4294967291
#define PRIME_LARGEST_UI8 18446744073709551557

#define SIZEOF_ARRAY(type) ((CH1*)(&type + 1) - (CH1*)(&type))

namespace _ {
enum {
  kCpuCacheLineSize = SCRIPT2_CPU_CACHE_LINE_SIZE,
  kMaxFloorsCount = SCRIPT2_MAX_WALLS,  //< Size of the Room Floor (socket).
  kMaxErrors = SCRIPT2_MAX_ERRORS,      //< Max errors before blowing up.
  kParamsMax = SCRIPT2_MAX_PARAMS,      //< Max number_ of parameters.
  kTimeoutMicroseconds = SCRIPT2_COM_TIMEOUT_TICKS,  //< Sub-second ticks.
  kAddressLengthMax =
      SCRIPT2_MAX_ADDRESS_LENGTH,  //< Max address (kADR) length.
  kOpNameLengthMax = SCRIPT2_OP_MAX_NAME_LENGTH,
  // Max length of a Op description .
  kOpDescriptionLengthMax = SCRIPT2_OP_MAX_DECRABSION_LENGTH,
  // Max length of a Text.
  kCharCount = SCRIPT2_TEXT_LENGTH,

  // Size of the Display Print Slot.
  kSlotBufferSizeRx = SCRIPT2_BUFFER_SIZE_RX,

  // Size of the KeyboardInBuffer.
  kSlotBufferSizeTx = SCRIPT2_BUFFER_SIZE_TX,

  kWindowSizeMin = SCRIPT2_WINDOW_SIZE_MIN,

  kBufferSizeDefault = SCRIPT2_BUFFER_COUNT_DEFAULT,
  kFloorSize = SCRIPT2_FLOOR_SIZE,  //< Size, or initial size, of the Floor.
  kStackCountMaxDefault = SCRIPT2_STACK_COUNT_MAX_DEFAULT,
  kObjSizeDefault = SCRIPT2_OBJ_SIZE_DEFAULT,

  // Extra reserved memory at the stop of BOut.
  kBOutOverflowSize = 32,

  kPrintC0Offset = 176,  //< Value add to values 0-32 when printing.
  kTokenLongest = 31,    //< Max length of a token plus one.
  kMinStackSize = 1,     //< Min Crabs stack size.
  kBufferSizeDefaultWords =
      kBufferSizeDefault / sizeof(SIW) + kBufferSizeDefault % sizeof(SIW) ? 1
                                                                          : 0,
  kSTRCount = SCRIPT2_STRAND_COUNT_DEFAULT,
  kConsoleWidth = SCRIPT2_CONSOLE_WIDTH,
  kCInBufferSize =
      SCRIPT2_CIN_BUFFER_SIZE,         //< Preallocated CIn buffer char count.
  kKeyEnter = 0,                       //< The keyboard value for enter.
  kLargestPODType = LARGEST_POD_TYPE,  //< The largest POD type.
};

}  // namespace _

#undef MAX_ERRORS
#undef MAX_NUM_PARAMS
#undef MAX_STRING_LENGTH
#undef COM_TIMEOUT_TICKS
#undef SCRIPT2_LOG_SIZE
#undef OPERATION_MAX_NAME_LENGTH
#undef OPERATION_MAX_DECRABSION_LENGTH
#undef SCRIPT2_TEXT_LENGTH
#undef SCRIPT2_BUFFER_SIZE_RX
#undef SCRIPT2_BUFFER_SIZE_TX
#undef SCRIPT2_WINDOW_SIZE_MIN
#undef SCRIPT2_BUFFER_COUNT_DEFAULT
#undef SCRIPT2_STACK_COUNT_MAX_DEFAULT
#undef SCRIPT2_FLOOR_SIZE
#undef SCRIPT2_STACK_COUNT_MAX_DEFAULT
#undef SCRIPT2_OBJ_SIZE_DEFAULT
#undef SCRIPT2_TOKEN_COUNT
#undef SCRIPT2_CPU_CACHE_LINE_SIZE
#undef SCRIPT2_STRAND_COUNT_DEFAULT
