/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /cclock.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2018 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>

#if SEAM >= _0_0_0__04
#ifndef INCLUDED_SCRIPTCCLOCK
#define INCLUDED_SCRIPTCCLOCK

namespace _ {

/* A time in seconds and optional microseconds format that is compatible with
the C++ standard library.
Data structure is identical to std::tm with the execution that it has an
additional microseconds from start of second variable.
*/
struct API CClock {
  int second,  //< Second of the minute [0, 59].
      minute,  //< Minute of the hour [0, 59].
      hour,    //< Hour of the day [0, 23].
      day,     //< Day of the month [1, 31].
      month,   //< Months since December [0, 11].
      year;    //< Number of years since epoch [-1902, 1970] U [1970, 2038].

  /* Constructs a clock with the set to Epoch. */
  CClock();

  /* Constructs a clock from the given 32-bit seconds timestamp. */
  CClock(TMS time);

  /* Constructs a clock from the given 64-bit seconds timestamp. */
  CClock(TME time);

  /* Sets the time to the given 32-bit kTMS timestamp. */
  void SetTime(TMS t);

  /* Sets the time to the given 32-bit kTMS timestamp. */
  void SetTime(TME t);
};

/* A sub-second timestamp composed of a kTMS and a kUI4 tick.
Operation of the Tss is intended for two scenarios:
1. Processor has a real microsecond timer stored as a 24-bit value.
2. Processor is an x86 and timer gets updated with a tread or OS.
In the real microsecond timer scenario the processor will just
take the unsigned in value and copy it to the kUI4 member. In the
case of the OS having a variable update tick period, the ticker will
work best if the value gets incremented using the ++operator and you will
need to use modulo updates_per_second unless the timer is set to 64 updates
per second or some other power of 2 in which case bit masking is the
tool of choice. For desktop operating systems other threads may hijack the
OS scheduler. */
struct Tss {
  TMS seconds;  //< Seconds since epoch.
  UI4 ticks;    //< Ticks since epoch.
};

enum ClockConstants {
  kClockEpochInit = 1970,                    //< Initial clock epoch.
  kSecondsPerMinute = 60,                    //< Number of seconds in an minute.
  kSecondsPerHour = 60 * kSecondsPerMinute,  //< Number of seconds in an hour.
  kSecondsPerDay = 24 * kSecondsPerHour,     //< Number of seconds in an day.
  kSecondsPerYear = kSecondsPerDay * 365,    //< Number of seconds in an year.
  kSecondsPerEpoch = 10 * kSecondsPerYear,   //< Number of seconds in an year.
  kDaysInJanuary = 31,                       //< Number of days in January.
  kDaysInFebruary = 28,                      //< Number of days in February.
  kDaysInMarch = 31,                         //< Number of days in March.
  kDaysInApril = 30,                         //< Number of days in April.
  kDaysInMay = 31,                           //< Number of days in May.
  kDaysInJune = 30,                          //< Number of days in June.
  kDaysInJuly = 31,                          //< Number of days in July.
  kDaysInAugust = 31,                        //< Number of days in August.
  kDaysInSeptember = 30,                     //< Number of days in September.
  kDaysInOctober = 31,                       //< Number of days in October.
  kDaysInNovember = 30,                      //< Number of days in November.
  kDaysInDecember = 31,                      //< Number of days in December.
};

/* Gets the 32-bit kTMS clock epoch. */
API inline SI2 ClockEpoch();

/* Lookup table for converting from day-of-year to month. */
API inline const SI2* ClockLastDayOfMonth();

/* Lookup table for converting from day-of-year to month. */
API inline const SI2* ClockLastDayOfMonthLeapYear();

/* Returns which month the given day is in based on the year. */
API inline int MonthByDay(int day, int year);

/* Initializes the clock from the given timestamp. */
API CClock* ClockInit(CClock& clock, TMS time);

/* Initializes the clock from the given timestamp. */
API CClock* ClockInit(CClock& clock, TME time);

/* Initializes the clock from the given 64-bit microsecond timestamp. */
API Tss& StopwatchInit(Tss& clock, TMS t, UI4 ticks);

/* Initializes the clock from the given timestamp. */
API CClock* ClockInit(CClock& clock);

/* Gets the current microsecond timestamp. */
API inline TME ClockNow();

/* Calculates the seconds from epoch from the clock and stores it to the result.
 */
API inline TMS ClockTMS(CClock& clock);

/* Calculates the seconds from epoch from the clock and stores it to the result.
 */
API inline TME ClockTME(CClock& clock);

/* Gets the number of days in a months.
    @todo Maybe get some open-source date utility? */
API int ClockMonthDayCount(TMS t);

/* Gets the number of days in a months.
@param month The month index 0-11.
@param year   */
API int ClockMonthDayCount(int month, int year);

/* Gets the abbreviated day of the week char of the given day number 1-7. */
API const char* ClockWeekDay(int day_number);

/* Gets the abbreviated day of the week char of the given day number 1-7. */
API char ClockDayOfWeekInitial(int day_number);

/* Compares the two the time and prints the results. */
API int ClockCompare(TMS a, TMS b);

/* Compares the two the time and prints the results. */
API int ClockCompare(TMS a, TMS b);

/* Compares the two the time and prints the results. */
API int ClockCompare(const CClock& clock, const CClock& other);

/* Compares the given TMS to the time and prints the results. */
API int ClockCompare(const CClock& clock, int year, int month, int day,
                     int hour, int minute, int second);

/* Zeros out the struct values.
    @param calendar_time A calendar time struct to zero out. */
API void ClockZeroTime(CClock& seconds);

/* Creates a 32-bit seconds timestamp.  */
API TMS ClockTimeTMS(int year, int month, int day, int hour = 0, int minute = 0,
                     int second = 0);

/* Creates a 64-bit seconds timestamp.  */
API TME ClockTimeTME(int year, int month, int day, int hour = 0, int minute = 0,
                     int second = 0);

#if USING_UTF8 == YES
/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char* Print(char* start, char* stop, const CClock& clock);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param stop   The stop of the write socket.
@param t     The 64-bit stopwatch timestamp. */
API char* Print(char* start, char* stop, Tss& t);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char* PrintTime(char* start, char* stop, TMS time);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char* PrintTime(char* start, char* stop, TME time);

/* Prints the given timestamp to the stdout. */
API void PrintTime(const CClock& clock);

/* Prints the given timestamp to the stdout. */
API void PrintTime(Tss t);

/* Prints the given timestamp to the stdout. */
API void PrintTime(TMS t);

/* Prints the given timestamp to the stdout. */
API void PrintTime(TME t);

/* Reads a time or time delta from a a char starting with an '@' sign.
@brief
@code
@4        (This is 4AM)
@4PM      (No space required)
@4:20P    (Or M)
@4:20 PM
@16:20
@4:20 am
@4:20a.m.
@4:20:00
@4:20:00AM
@16:20:00
@endcode

@param input  The char to parse.
@param hour   The location to write the number of hours to.
@param minute The location to write the number of minutes to.
@param Second The location to write the number of seconds to. */
API const char* TStringScanTime(const char* string, int& hour, int& minute,
                                int& second);

/* Converts a keyboard input to char and deletes the char.
@return Nil upon socket failure or char directly after the stop of the
timestamp upon success.
*/
API const char* Scan(const char* string, CClock& clock);

/* Converts a keyboard input to a Tss. */
API const char* Scan(const char* string, Tss& result);

/* Converts a keyboard input to a TMS. */
API const char* TStringScanTime(const char* string, TMS& result);

/* Converts a keyboard input to a TME. */
API const char* TStringScanTime(const char* string, TME& result);

#endif  //< #if USING_UTF8 == YES

#if USING_UTF16 == YES

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char16_t* Print(char16_t* start, char16_t* stop, CClock& clock);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char16_t* Print(char16_t* start, char16_t* stop, Tss& t);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char16_t* PrintTime(char16_t* start, char16_t* stop, TMS time);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char16_t* Print(char16_t* start, char16_t* stop, TME time);

/* Reads a time or time delta from a a char16_t starting with an '@' sign.

# Legal Time Formats

@code
@4        (This is 4AM)
@4PM      (No space required)
@4:20P    (Or M)
@4:20 PM
@16:20
@4:20 am
@4:20a.m.
@4:20:00
@4:20:00AM
@16:20:00
@endcode

@param input  The char16_t to parse.
@param hour   The location to write the number of hours to.
@param minute The location to write the number of minutes to.
@param Second The location to write the number of seconds to. */
API const char16_t* TStringScanTime(const char16_t* string, int& hour,
                                    int& minute, int& second);

/* Converts a keyboard input to char16_t and deletes the char16_t.
@return Nil upon socket failure or char16_t directly after the stop of the
timestamp upon success.
*/
API const char16_t* Scan(const char16_t* string, CClock& result);

/* Converts a keyboard input to a Tss. */
API const char16_t* Scan(const char16_t* string, Tss& result);

/* Converts a keyboard input to a TMS. */
API const char16_t* TStringScanTime(const char16_t* string, TMS& result);

/* Converts a keyboard input to a TME. */
API const char16_t* TStringScanTime(const char16_t* string, TME& result);

#endif  //< #if USING_UTF16 == YES
#if USING_UTF32 == YES
/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char32_t* Print(char32_t* start, char32_t* stop, CClock& clock);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char32_t* Print(char32_t* start, char32_t* stop, Tss& time);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char32_t* PrintTime(char32_t* start, char32_t* stop, TMS time);

/* Writes the given time to the text socket.
@return Null upon failure or a pointer to the UI1 after the last
UI1 written.
@param start The beginning of the write socket.
@param time  The time to utf.
@param stop   The stop of the write socket. */
API char32_t* PrintTime(char32_t* start, char32_t* stop, TME time);

/* Reads a time or time delta from a a char starting with an '@' sign..
@param input  The char to parse.
@param hour   The location to write the number of hours to.
@param minute The location to write the number of minutes to.
@param Second The location to write the number of seconds to.
@return The offset The stop of where the parser exited successfully at.

@code
@4        (This is 4AM)
@4PM      (No space required)
@4:20P    (Or M)
@4:20 PM
@16:20
@4:20 am
@4:20a.m.
@4:20:00
@4:20:00AM
@16:20:00
@endcode
*/
API const char32_t* TStringScanTime(const char32_t* input, int& hour,
                                    int& minute, int& second);

/* Converts a keyboard input to char and deletes the char.
 */
API const char32_t* Scan(const char32_t* input, CClock& time);

/* Converts a keyboard input to a TMS. */
API const char32_t* Scan(const char32_t* input, Tss& result);

/* Converts a keyboard input to a TMS. */
API const char32_t* TStringScanTime(const char32_t* input, TMS& result);

/* Converts a keyboard input to a TMS. */
API const char32_t* TStringScanTime(const char32_t* input, TME& result);

#endif  //< #if USING_UTF32 == YES
}  // namespace _

#undef PRINT
#undef PRINTF
#endif  //< #ifndef INCLUDED_SCRIPTCCLOCK
#endif  //< #if SEAM >= _0_0_0__04
