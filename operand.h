/* Script2 (TM) @version 0.x
@link    https://github.com/KabukiStarship/Script2.git
@file    /Operand.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-20 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_Config.h>
#if SEAM >= SCRIPT2_CRABS
#ifndef SCRIPT2_OPERAND
#define SCRIPT2_OPERAND
#include "slot.h"

namespace _ {

struct LIB_MEMBER Crabs;

/* Interface for an abstract A*B Op operand.
    A Script Operand is an object that is being operated on.
    Let A be a set of states in a Chinese Room state machine.
    Let B be a set of bytes in a set of Abstract Serial Ports.

    @code
    +----------- Result: The set of finite states
    | +--------- Op
    | | +------- Set of finite states
    | | | +----- Star Op
    | | | | +--- Operands (input values)
    | | | | |
    v v v v v
    A = A * B
        |<->|   Op
    |<----->|   Evaluation
    @endcode

    When a device is selected by a Slot, the caller can then call functions
    of that device. The Slot has a stack of devices that it then pushes the
    Star* on top of. This object is now selected, and agents can now call
    functions of this object via the Data Controller (DC).

    @see Console for example of how to use Operand interface.
*/

struct LIB_MEMBER Operand {
  /* Script2 Operations.
      @param index The index of the expression.
      @param crabs  The Crabs to read and write from.
      @return      Returns nil upon success, a Set header upon query, and an
                   error_t ticket upon Read-Write failure. */
  virtual const Op* Star(CHC index, Crabs* crabs) = 0;
};

/* Returns the name of the given Operand. */
LIB_MEMBER const CHA* OperandName(Operand* op);

/* Gets the number_ of ops in the given expressions. */
LIB_MEMBER IUW OperandCount(Operand* op);

/* Returns the index of the given Op using the given slot.
    @param key_begin Beginning of the key slot socket.
    @param key_end   End of the key slot socket.
    @return A value printable Unicode CHA or invalid if the Operand doesn't
            Contain the given key. */
LIB_MEMBER CHC OperandIndex(Operand* operand, CHA* key_begin, CHA* key_end);

#if USING_SCRIPT2_TEXT
/* Queries the given Operand Op Header.
    @param crabs The expression to write the query to. Set to nil to return
                 op.
    @param op   The Op header.
    @return Returns nil upon success and an error Op upon failure.
LIB_MEMBER const Op* OperandQuery (Crabs* crabs, const Op* op);*/

/* Queries the operand for the given ??? @todo fix me */
Slot& OperandQuery(Operand* root, const CHA* address, Slot& key);

/* Prints the Operand to the Text.
    @param text     The Text to utf to.
    @param operand The Operand to utf.
    @return text. */
LIB_MEMBER UTF1& PrintOperand(UTF1& slot, Operand* operand);
#endif

}  // namespace _

#if USING_SCRIPT2_TEXT
/* Overloaded operator<< prints the given operand to the text. */
inline _::UTF1& operator<<(_::UTF1& printer, _::Operand* operand) {
  return _::PrintOperand(printer, operand);
}

#endif
#endif
#endif
