#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H

// C++ standard headers
#include <cstdint>

// C++ STL
#include <vector>

namespace RagnarokReplay {

class Chunk {
 public:
  Chunk() : Header(0), Id(0), Length(0), Time(0), Data() {}

  uint16_t Header;
  int32_t Id;
  int32_t Length;
  int32_t Time;
  std::vector<uint8_t> Data;
};

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H
