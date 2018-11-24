/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /cutf4.h
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
#if SEAM >= _0_0_0__02
#ifndef INCLUDED_SCRIPTPRINT_UTF32
#define INCLUDED_SCRIPTPRINT_UTF32

#include "clock.h"

#if USING_UTF32 == YES

namespace _ {

/* UTF-8 printing utilities
@ingroup Utf
*/

/* Checks if the given character is whitespace.
 */
API BOL IsWhitespace(char32_t character);

/* Converts the given value to a printable char32_t if it's non-printable. */
API char32_t PrintableChar(char32_t value);

/* Scrolls over to the next DBL quote mark.
@warning This function is only safe to use on ROM strings with a nil-term
char32_t. */
API const char32_t* TStringEnd(const char32_t* start);

/* Gets the length of the given char32_t.
@return  Returns -1 if the text char32_t is nil.
@warning This function is only safe to use on ROM strings with a nil-term
char32_t. */
API int TStringLength(const char32_t* start);

/* Clones the given string_.
@param  A nil-terminated string_ in ROM.
@return Returns a new copy you must delete. */
API char32_t* StringClone(const char32_t* start);

/* Returns a pointer to the char32_t at the stop of the line. */
API const char32_t* StringLineEnd(const char32_t* start, int column_count);

/* Returns the pointer to the next char32_t in the char32_t that is not an ASCII
number_.
@return A pointer to the next non-number_ in the text char32_t. */
API const char32_t* TStringDecimalEnd(const char32_t* start);

/* Skips the leading zeros of a number_ if there are any. */
API const char32_t* TStringSkipChar(const char32_t* start, char32_t skip_char);

/* Skips all the spaces at the start of the char32_t. */
API const char32_t* StringSkipSpaces(const char32_t* start);

/* Skips all the spaces at the start of the char32_t.
@param  start Beginning address of the read socket.
@param  stop   The stop address of the input socket.
@return A pointer to the stop of the text read or if no text read. */
API const char32_t* StringSkipSpaces(const char32_t* start,
                                     const char32_t* text_end);

/* Compares the source and query char32_t as nil-terminated strings. */
API const char32_t* StringEquals(const char32_t* text_a,
                                 const char32_t* text_b);

/* Compares the source and query char32_t as nil-terminated strings. */
API const char32_t* StringEquals(const char32_t* start, const char32_t* stop,
                                 const char32_t* query);

/* Searches the given char32_t for the given char32_t.
@param  start  The char32_t to search.
@param  query The char32_t to search for.
@return Returns nil if the parsing failed and a pointer to the first char32_t
after the stop of the text upon success. */
API const char32_t* StringFind(const char32_t* start, const char32_t* query);

/* Prints the given string_ to the utf socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param  start  The beginning address of the socket.
@param  stop    The stop address of the socket.
@param  string_ The potentially unsafe string_ to write. */
API char32_t* Print(char32_t* start, char32_t* stop, const char32_t* string_);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start     Beginning address of the socket.
@param stop       The stop address of the socket.
@param character The value to write. */
API char32_t* Print(char32_t* start, char32_t* stop, char32_t character);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, UI4 value);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, SI4 value);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, UI8 value);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, SI8 value);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, FLT value);

/* Writes the give char32_t to the given socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* Print(char32_t* start, char32_t* stop, DBL value);

/* Prints the given string_ to the utf socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start  The beginning address of the socket.
@param stop    The stop address of the socket.
@param string_ The potentially unsafe string_ to write. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop,
                          const char32_t* string_, int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start Beginning address of the socket.
@param stop The stop address of the socket.
@param character The value to write. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, char32_t character,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, UI4 valu,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, SI4 value,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, UI8 value,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, SI8 value,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, FLT value,
                          int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintCenter(char32_t* start, char32_t* stop, DBL value,
                          int column_count);

/* Prints the given string_ to the utf socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start  The beginning address of the socket.
@param stop    The stop address of the socket.
@param string_ The potentially unsafe string_ to write. */
API char32_t* PrintRight(char32_t* start, char32_t* stop,
                         const char32_t* string_, int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start     Beginning address of the socket.
@param stop       The stop address of the socket.
@param character The value to write. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, char32_t character,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, UI4 value,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, SI4 value,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, UI8 value,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, SI8 value,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, FLT value,
                         int column_count);

/* Writes the give char32_t to the given socket center.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintRight(char32_t* start, char32_t* stop, DBL value,
                         int column_count);

/* Prints the given string_ to the utf socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start   The beginning address of the socket.
@param stop     The stop address of the socket.
@param pointer The pointer to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, const void* pointer);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, UI1 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, SI1 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, UI2 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, SI2 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, UI4 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, SI4 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, UI8 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, SI8 value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, FLT value);

/* Writes the give char32_t to the given socket in hex form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* PrintHex(char32_t* start, char32_t* stop, DBL value);

/* Prints the given string_ to the utf socket.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start  The beginning address of the socket.
@param stop    The stop address of the socket.
@param pointer The pointer to utf to hex. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop,
                           const void* pointer);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, UI1 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, SI1 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, UI2 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, SI2 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, UI4 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, SI4 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, UI8 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, SI8 value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, FLT value);

/* Writes the give char32_t to the given socket in binary form.
@return Returns nil upon socket overflow and a pointer to the nil-term char32_t
upon success.
@param start The beginning address of the socket.
@param stop The stop address of the socket.
@param value The value to utf. */
API char32_t* TPrintBinary(char32_t* start, char32_t* stop, DBL value);

/* Prints the given memory socket to the text socket.
@param start The beginning of the write socket.
@param stop   The stop of the write socket.
@param begin The beginning of the read socket.
@param size  The size of the socket in bytes. */
API char32_t* PrintSocket(char32_t* start, char32_t* stop, const void* begin,
                          size_t size);

/* Prints out the contents of the address to the printer socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param stop   The stop of the write socket.
@param begin The beginning of the read socket.
@param end  The stop of the read socket. */
API char32_t* PrintSocket(char32_t* start, char32_t* stop, const void* begin,
                          const void* end);

/* Prints out the contents of the address to the printer socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param stop   The stop of the write socket.
@param begin The beginning of the read socket.
@param size  The size of the read socket. */
API char32_t* PrintSocket(char32_t* start, char32_t* stop, const void* begin,
                          size_t size);

/* Prints th given type or type-value.
@return Returns a pointer to the next char after the stop
of the read number_ or nil upon failure.
@param printer The printer to utf to.
@param type    The type to utf.
@param value   The value to utf or nil. */
API char32_t* Print(char32_t* start, char32_t* stop, SIN type,
                    const void* value);

/* Prints a line of the given column_count.
@return Returns a pointer to the next char32_t after the stop of the read
number_ or nil upon failure.
@param start The beginning of the write socket.
@param stop  The stop of the write socket.
@param token The token to utf.
@param column_count The number_ of tokens to utf. */
API char32_t* PrintLine(char32_t* cursor, char32_t* stop, char32_t token,
                        int column_count);

/* Prints a line of the given column_count.
@return Returns a pointer to the next char32_t after the stop of the read
number_ or nil upon failure.
@param start  The beginning of the write socket.
@param stop   The stop of the write socket.
@param string_ The string_ to utf.
@param column_count The number_ of columns. */
API char32_t* TPrintLineString(char32_t* cursor, char32_t* stop,
                               const char32_t* string_, int column_count);

/* Prints the socket to the console as a UTF-8 string_. */
void COutUtf32(UIW* socket);

/* Prints the socket to the console as a UTF-8 string_. */
void COutAutoUtf32(UIW* socket);

/* Converts the given string_ to a 8-bit signed integer.
@param  start A nil-terminated string_ in ROM.
@param  result  The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, SI1& result);

/* Converts the given string_ to a 8-bit unsigned integer.
@param  start   A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, UI1& result);

/* Converts the given string_ to a 16-bit signed integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, SI2& result);

/* Converts the given string_ to a 16-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, UI2& result);

/* Converts the given string_ to a 32-bit signed integer.
@param  start A nil-terminated string_ in ROM.
@param  result  The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, SI4& result);

/* Converts the given string_ to a 32-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, UI4& result);

/* Converts the given string_ to a 64-bit signed integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, SI8& result);

/* Converts the given string_ to a 64-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, UI8& result);

/* Converts the given string_ to a 32-bit floating-point number_.
@param  start A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, FLT& result);

/* Converts the given string_ to a 64-bit floating-point number_.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* start, DBL& result);
/* Converts the given string_ to a 8-bit signed integer.
@param  start A nil-terminated string_ in ROM.
@param  result  The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, SI1& result);

/* Converts the given string_ to a 8-bit unsigned integer.
@param  start A nil-terminated string_ in ROM.
@param  result  The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, UI1& result);

/* Converts the given string_ to a 16-bit signed integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, SI2& result);

/* Converts the given string_ to a 16-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, UI2& result);

/* Converts the given string_ to a 32-bit signed integer.
@param  start A nil-terminated string_ in ROM.
@param  result  The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, SI4& result);

/* Converts the given string_ to a 32-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, UI4& result);

/* Converts the given string_ to a 64-bit signed integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, SI8& result);

/* Converts the given string_ to a 64-bit unsigned integer.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, UI8& result);

/* Converts the given string_ to a 32-bit floating-point number_.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, FLT& result);

/* Converts the given string_ to a 64-bit floating-point number_.
@param  start  A nil-terminated string_ in ROM.
@param  result The result of the conversion.
@return Returns a pointer to the next char32_t after the stop
of the read number_ or nil upon failure. */
API const char32_t* Scan(const char32_t* text, DBL& result);

/* Universal Text Formatter (UTF) 8 is a utility class for printing UTF-8
strings.
This class only stores the stop of socket pointer and a pointer to the
write start. It is up the user to store start of socket pointer and if they
would like to replace the start with the beginning of socket pointer when they
are done printing.
*/
struct API UTF4 {
  char32_t *start,  //< Write start pointer.
      *stop;        //< End of socket pointer.

  /* Initializes the Utf& from the given socket pointers.
  @param start The beginning of the socket.
  @param stop   The stop of the socket. */
  UTF4(char32_t* start, size_t size);

  /* Initializes the Utf& from the given socket pointers.
  @param start The beginning of the socket.
  @param stop   The stop of the socket. */
  UTF4(char32_t* start, char32_t* stop);

  /* Clones the other utf. */
  UTF4(const UTF4& other);

  /* Sets the start pointer to the new_pointer. */
  inline UTF4& Set(char32_t* new_pointer);

  /* Prints the given value as hex. */
  inline UTF4& Hex(SI1 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(UI1 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(SI2 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(UI2 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(SI4 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(UI4 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(SI8 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(UI8 value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(FLT value);

  /* Prints the given value as hex. */
  inline UTF4& Hex(DBL value);

  /* Prints the given pointer as hex. */
  inline UTF4& Hex(const void* pointer);

  /* Prints the given value as binary. */
  inline UTF4& Binary(SI1 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(UI1 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(SI2 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(UI2 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(SI4 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(UI4 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(SI8 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(UI8 value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(FLT value);

  /* Prints the given value as binary. */
  inline UTF4& Binary(DBL value);

  /* Prints the given pointer as binary. */
  inline UTF4& Binary(const void* pointer);
};

/* Utility class for printing numbers. */
class Text4 {
 public:
  /* Default constructor does nothing. */
  Text4();

  /* Prints the value to the text socket. */
  Text4(char32_t character);

  /* Prints the value to the text socket. */
  Text4(SI4 value);

  /* Prints the value to the text socket. */
  Text4(UI4 value);

  /* Prints the value to the text socket. */
  Text4(SI8 value);

  /* Prints the value to the text socket. */
  Text4(UI8 value);

  /* Prints the value to the text socket. */
  Text4(FLT value);

  /* Prints the value to the text socket. */
  Text4(DBL value);

  /* Gets the number_ string_. */
  const char32_t* GetString();

 private:
  enum { kSize = 24 };

  char32_t string_[kSize * sizeof(char32_t) + 1];  //< String socket.
};

/* Utility class for printing hex with operator<<. */
class Utf32Center {
 public:
  /* Prints the value to the text socket. */
  Utf32Center(const char32_t* string_, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(SI4 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(UI4 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(SI8 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(UI8 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(FLT value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Center(DBL value, int column_count);

  /* Gets the number_ string_. */
  const char32_t* GetString();

  /* Gets the column_count. */
  int GetColumnCount();

 private:
  const char32_t* string_;  //< Pointer to the string_.
  Text4 number_;            //< Pointer to a pointer to utf.
  int column_count;         //< Number of columns to center.
};

/* Utility class for printing hex with operator<<. */
class Utf32Right {
 public:
  /* Prints the value to the text socket. */
  Utf32Right(const char32_t* string_, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(SI4 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(UI4 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(SI8 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(UI8 value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(FLT value, int column_count);

  /* Prints the value to the text socket. */
  Utf32Right(DBL value, int column_count);

  /* Gets the number_ string_. */
  const char32_t* GetString();

  /* Gets the column_count. */
  int GetColumnCount();

 private:
  const char32_t* string_;  //< Pointer to the string_.
  Text4 number_;            //< Pointer to a pointer to utf.
  int column_count;         //< Number of columns to center.
};

}  // namespace _

/* Writes a nil-terminated UTF-8 or ASCII string_ to the utf.
@param  printer The printer.
@param  value   The value to utf.
@return The printer. */
API _::UTF4& operator<<(_::UTF4& printer, const char32_t* string_);

/* Writes the given value to the utf.
@param  printer The printer.
@param  value   The value to utf.
@return The printer. */
API _::UTF4& operator<<(_::UTF4& printer, char32_t value);

/* Writes the given value to the utf.
@param  printer The printer.
@param  value The value to write to the utf.
@return The printer. */
API _::UTF4& operator<<(_::UTF4& printer, UI1 value);

/* Writes the given value to the utf.
@param  printer The printer.
@param  value The value to write to the utf.
@return The printer. */
API _::UTF4& operator<<(_::UTF4& printer, SI2 value);

/* Writes the given value to the utf.
@param  printer The printer.
@param  value The value to write to the utf.
@return The printer. */
API _::UTF4& operator<<(_::UTF4& printer, UI2 value);

/* Writes the given value to the utf.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, SI4 value);

/* Writes the given value to the utf.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, UI4 value);

/* Writes the given value to the utf.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, SI8 value);

/* Writes the given value to the utf.
@return The printer.
@desc
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, UI8 value);

/* Writes the given value to the utf.
@return The printer.
@desc
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, FLT value);

/* Writes the given value to the utf.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, DBL value);

/* Writes the given value to the utf.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf justified center. */
API _::UTF4& operator<<(_::UTF4& printer, _::Utf32Center item);

/* Writes the given value to the utf justified right.
@return The printer.
@param  printer The printer.
@param  value The value to write to the utf. */
API _::UTF4& operator<<(_::UTF4& printer, _::Utf32Right item);

#endif  //< #if USING_UTF32 == YES
#endif  //< #if INCLUDED_SCRIPTPRINT_UTF32
#endif  //< #if SEAM >= _0_0_0__02
