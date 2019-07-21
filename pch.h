/* SCRIPT Script @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/pch.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once

#ifndef PRECOMPILED_HEADER
#define PRECOMPILED_HEADER 1
#include "pch_header.h"

#define SEAM SEAM_SCRIPT2_TABLE

//#define ASSEMBLE_DYNAMIC_LIB 1
//#define LIB_MEMBER_IMPORT

#define CPU_WORD_SIZE CPU_64_BIT
#define CPU_ENDIAN CPU_ENDIAN_LITTLE

#define USING_CONSOLE YES_0

#define LARGEST_CHAR STRING_TYPE_3
#define USING_STR STRING_TYPE_1

#define USING_UTF8 YES_0
#define USING_UTF16 YES_0
#define USING_UTF32 YES_0

#define USING_FP 8
#define USING_FP4 YES_0
#define USING_FP8 YES_0

#define USING_128_BIT_POD_TYPES NO_0

#include "pch_footer.inl"

#endif
