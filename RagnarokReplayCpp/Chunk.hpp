/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H

// C++ standard headers
#include <cstdint>

// C++ STL
#include <vector>

namespace RagnarokReplay {

class Chunk {
 public:
  Chunk() : header(0), id(0), length(0), time(0), data() {}

  uint16_t header;
  int32_t id;
  int32_t length;
  int32_t time;
  std::vector<uint8_t> data;
};

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNK_H
