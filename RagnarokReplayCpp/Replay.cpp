#include "Replay.hpp"

#include <cstdint>
#include <istream>
#include <string>

namespace RagnarokReplay {

void Replay::LoadFile(std::string filename) {}

int32_t Replay::GetKey1(const Replay::DateTime &date_time) {
  return (0x0i32 | date_time.year | date_time.month << 16 |
          date_time.day << 24) >>
         5;
}

int32_t Replay::GetKey2(const Replay::DateTime &date_time) {
  return (0x0i32 | date_time.hour << 8 | date_time.minute << 16 |
          date_time.second << 24) >>
         3;
}

void Replay::Decrypt(const int32_t kKey1, const int32_t kKey2,
                     std::vector<uint8_t> &packet_data) {
  const size_t kSegmentCount = packet_data.size() >> 2;
  int32_t *i32_ptr = reinterpret_cast<int32_t *>(packet_data.data());
  for (size_t i = 0; i < kSegmentCount; ++i) {
    *i32_ptr = *i32_ptr ^ (kKey1 + (i + 1)) * kKey2;
    ++i32_ptr;
  }
}

void Replay::ParseHeader(std::istream &input_stream) {
  input_stream.read(reinterpret_cast<char *>(&header), sizeof(header));
}

}  // end of namespace RagnarokReplay
