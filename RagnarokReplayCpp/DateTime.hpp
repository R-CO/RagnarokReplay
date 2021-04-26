/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_DATETIME_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_DATETIME_H

#include <cstdint>

namespace RagnarokReplay {

class DateTime {
 public:
  int16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t reserved;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
};  // end of class DateTime

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_DATETIME_H
