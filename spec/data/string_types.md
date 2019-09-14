# [SCRIPT Specification](../readme.md)

## [ASCII Data Specification](readme.md)

### String Types

ASCII Strings Types consists of 8-bit (CH1), 16-bit (CH2), and 32-bit (CH4) characters, and Arrays and Vectors of characters called Strands and SPrinters (String Printers) that can be UTF-8, UTF-16, or UTF-32. Additionally, traditional C-style strings can be created using a Pointer (PTR) or Const Pointer (PTC) to a CH1, CH2, or CH4 types.

```C++
TKN key                   //< No quotes needed for a TKN.
ADR 123                   //< A ADR is a TKN.
STR_1  "\"Hello world!\"" //< UTF-8 STR that reads "Hello world!" with double quotes.
ARY_CH1_4 "Foo"           //< STR is shorthand for ARY_CH1_1/2/4.
STR_2 "Hello world!"      //< This is a _::TStrand<> that is up to 64KB long.
STR_4 "Hello world!"      //< This is a _::TStrand<> that is up to 4GB long.
```

**[<< Previous Section:Timestamps](./timestamps.md) | [Next Section: >>](./readme.md)**

## License

Copyright 2014-9 (C) [Cale McCollough](https://calemccollough.github.io); all rights reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at <https://mozilla.org/MPL/2.0/>.