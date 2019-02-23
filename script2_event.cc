/* SCRIPT Script (Script^2) @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /script2/script2_event.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-19 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>
#if SEAM >= SCRIPT2_14
#include "c_event.h"

namespace _ {

Event::Event() : timestamp_(0, 0) {}

Event::~Event() {}

TSS Event::GetTimestamp() { return timestamp_; }

}  // namespace _
#endif  //< #if SEAM >= KABUKI_TOOLKIT_AV_1