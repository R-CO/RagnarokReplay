#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H

#include <cstdint>
#include <exception>
#include <istream>
#include <string>
#include <vector>

#include "ChunkContainer.hpp"
#include "Region.hpp"

namespace RagnarokReplay {

class Replay {
 public:
#pragma pack(1)
  struct DateTime {
    int16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t reserved;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
  };

  struct Header {
    uint8_t discription[100];
    uint8_t version;
    uint8_t signature[3];
    DateTime date;
  } header;
#pragma pack()

  void LoadFile(std::string filename);

 protected:
  int32_t GetKey1(const DateTime &date_time);
  int32_t GetKey2(const DateTime &date_time);

  void Decrypt(const int32_t kKey1, const int32_t kKey2,
               std::vector<uint8_t> &packet_data);

  void ParseHeader(std::istream &input_stream);
};  // end of class Replay

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H
