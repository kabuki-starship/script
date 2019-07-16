/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/script2_puff.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <pch.h>

#ifndef SCRIPT2_PUFF
#define SCRIPT2_PUFF 1

namespace _ {

#if SEAM >= SEAM_SCRIPT2_ITOS

/* Lookup table of ASCII Char pairs for 00, 01, ..., 99. */
LIB_MEMBER LIB_INLINE const UI2* BinaryLUTDecimals();

enum {
  kUI2DigitCountMax = 5,
  kUI4DigitCountMax = 9,
  kUI8DigitCountMax = 20,
};

const UI8* Pow10_UI8();
UI8 Pow10(UI8 index);

const UI4* Pow10_UI4();
UI4 Pow10(UI4 index);

const UI2* Pow10_UI2();
UI2 Pow10(UI2 index);

SI4 STRLength(UI1 value);
SI4 STRLength(UI2 value);
SI4 STRLength(UI4 value);
SI4 STRLength(UI8 value);

#endif

#if SEAM >= SEAM_SCRIPT2_FTOS

/* IEEE754 Powers of 10 integral portions LUT. */
LIB_MEMBER LIB_INLINE const void* Binary32Pow10IntegralPortions();

/* IEEE754 Powers of 10 integral portions LUT. */
LIB_MEMBER LIB_INLINE const void* Binary64Pow10IntegralPortions();

/* Lookup table of the IEEE754 integral portion of pre-computed powers of 10.
 */
LIB_MEMBER LIB_INLINE const void* BinaryPow10Exponents();

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(SI1 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(UI1 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(SI2 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(UI2 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(SI4 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(UI4 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(SI8 value);

/* Checks if the given value is Not-a-Number.
@param  value The value to check.
@return True if the value is NaN and false otherwise. */
LIB_MEMBER BOL IsNaN(UI8 value);

#if USING_FP4 == YES
/* Gets the maximum number_ of digits required to represent a FP4 as in
ASCII. */
LIB_MEMBER SI4 FloatDigitsMax();

/* Checks if the given value is Not-a-Number. */
LIB_MEMBER BOL IsNaN(FP4 value);

/* Checks if the given value is not NaN or +/- Infinity. */
LIB_MEMBER BOL IsFinite(FP4 value);

/* Checks if the given value is not NaN or +/- Infinity. */
LIB_MEMBER BOL IsInfinite(FP4 value);

/* Returns the ceiling of the given value to the next highest up integer. */
LIB_MEMBER FP4 Ceiling(FP4 value);
#endif

#if USING_FP8 == YES
/* Gets the maximum number_ of digits required to represent a FP8 as in
ASCII. */
LIB_MEMBER SI4 DoubleDigitsMax();

/* Checks if the given value is Not-a-Number. */
LIB_MEMBER BOL IsNaN(FP8 value);

/* Checks if the given value is not NaN or +/- Infinity. */
LIB_MEMBER BOL IsFinite(FP8 value);

/* Returns the ceiling of the given value to the next highest up integer. */
LIB_MEMBER BOL IsInfinite(FP8 value);

/* Returns the ceiling of the given value to the next highest up integer. */
LIB_MEMBER FP8 Ceiling(FP8 value);
#endif

/* Gets the Most Significant Asserted Bit (MSbAsserted).
@return A negative number_ if value is zero and the highest bit. */
LIB_MEMBER SI4 MSbAsserted(UI1 value);
LIB_MEMBER SI4 MSbAsserted(SI1 value);
LIB_MEMBER SI4 MSbAsserted(UI2 value);
LIB_MEMBER SI4 MSbAsserted(SI2 value);
LIB_MEMBER SI4 MSbAsserted(UI4 value);
LIB_MEMBER SI4 MSbAsserted(SI4 value);
LIB_MEMBER SI4 MSbAsserted(UI8 value);
LIB_MEMBER SI4 MSbAsserted(SI8 value);

/* Returns the last UI1 in the given CH1, which is c in this case. */
LIB_MEMBER CH1* LastByte(CH1* c);

/* Prints the given FP4 to the socket. */
LIB_MEMBER CH1* Print(CH1* cursor, CH1* stop, FP4 value);

/* Prints the given FP4 to the socket. */
LIB_MEMBER CH1* Print(CH1* cursor, CH1* stop, FP8 value);

#if USING_UTF16 == YES
/* Returns the last UI1 in the given CH2. */
LIB_MEMBER CH1* LastByte(CH2* c);

/* Prints the given item to the socket. */
LIB_MEMBER CH2* Print(CH2* cursor, CH2* stop, FP4 item);
LIB_MEMBER CH2* Print(CH2* cursor, CH2* stop, FP8 item);
#endif

#if USING_UTF32 == YES
/* Returns the last UI1 in the given CH4. */
LIB_MEMBER CH1* LastByte(CH4* c);

/* Prints the given item to the socket. */
LIB_MEMBER CH4* Print(CH4* cursor, CH4* stop, FP4 value);
LIB_MEMBER CH4* Print(CH4* cursor, CH4* stop, FP8 value);
#endif

#endif
}  // namespace _

#endif
