/* Script2 (TM) @version 0.x
@link    https://github.com/KabukiStarship/Script2.git
@file    /_Seams/07.Matrix.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-20 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#if SEAM >= SCRIPT2_MATRIX
#include "../Matrix.hpp"
using namespace _;
#if SEAM == SCRIPT2_MATRIX
#include "../_Debug.inl"
#else
#include "../_Release.inl"
#endif

namespace Script2 {

template <typename IS, typename ISZ>
void TestMatrixIntegers() {
  D_COUT(Linef("\n\n+---\n| ")
         << "Testing AMatrix<IS" << sizeof(ISZ) << ">" << Linef("\n+---"));

  static const ISC array_3d_exected[2][2][2] = {{{0, 1}, {2, 3}},
                                                {{4, 5}, {6, 7}}};
  const ISC* dimensions = TStack4<2, 2, 2>();
  AMatrix<ISC> matrix(2, 2, 2, &array_3d_exected[0][0][0]);
  D_COUT_OBJ(matrix);
  ISC w = 0;
  ISC* array_base = matrix.Elements();
  for (ISC x = 0; x < 2; ++x)
    for (ISC y = 0; y < 2; ++y)
      for (ISC z = 0; z < 2; ++z) A_AVOW(w++, array_3d_exected[x][y][z]);
}
}  // namespace Script2
#endif

namespace Script2 {
static const CHA* Matrix(const CHA* args) {
#if SEAM >= SCRIPT2_MATRIX
  A_TEST_BEGIN;
  TestMatrixIntegers<ISA, ISA>();
  TestMatrixIntegers<ISA, ISB>();
  TestMatrixIntegers<ISA, ISC>();
  TestMatrixIntegers<ISA, ISD>();
  TestMatrixIntegers<IUB, ISA>();
  TestMatrixIntegers<IUB, ISB>();
  TestMatrixIntegers<IUB, ISC>();
  TestMatrixIntegers<IUB, ISD>();
  TestMatrixIntegers<ISC, ISA>();
  TestMatrixIntegers<ISC, ISB>();
  TestMatrixIntegers<ISC, ISC>();
  TestMatrixIntegers<ISC, ISD>();
  TestMatrixIntegers<IUD, ISA>();
  TestMatrixIntegers<IUD, ISB>();
  TestMatrixIntegers<IUD, ISC>();
  TestMatrixIntegers<IUD, ISD>();
#endif
  return nullptr;
}
}  // namespace Script2
