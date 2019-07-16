/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/16_door.h
@author  Cale McCollough <cale@astartup.net>
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#if SEAM == SEAM_SCRIPT2_DOOR
#include "module_debug.inl"
#else
#include "module_release.inl"
#endif

#include "c_room.h"

using namespace _;

namespace script2 {
static const CH1* _16_Door(const CH1* args) {
#if SEAM == SEAM_SCRIPT2_DOOR
  A_TEST_BEGIN;
  Door door;
  Slot slot
#endif
      return nullptr;
}
}  // namespace script2
