/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H

#include <array>
#include <cstdint>
#include <exception>
#include <istream>
#include <string>
#include <vector>

#include "ChunkContainer.hpp"
#include "DateTime.hpp"
#include "Region.hpp"

namespace RagnarokReplay {

class Replay {
 public:
#pragma pack(1)
  struct Header {
    uint8_t discription[100];
    uint8_t version;
    uint8_t signature[3];
    DateTime date;
  };
#pragma pack()

  void LoadFile(std::string filename);

  Header header;
  std::array<ChunkContainer,
             static_cast<size_t>(ContainerType::LastContainerType)>
      chunk_container_array;

 protected:
  void ParseHeader(std::istream &input_stream);

  void LoadReplayV5(std::istream &input_stream);
};  // end of class Replay

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_REPLAY_H
