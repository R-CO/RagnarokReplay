#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H

// C++ standard headers
#include <cstdint>

// C++ STL
#include <list>

#include "Chunk.hpp"

namespace RagnarokReplay {

enum class ContainerType : int8_t {
  None = 0,
  PacketStream = 1,
  ReplayData = 2,
  Session = 3,
  Status = 4,
  Quests = 6,
  GroupAndFriends = 7,
  Items = 8,
  UnknownContainingPet = 9,
  Unknown_10 = 10,
  Unknown_12 = 12,
  Unknown_13 = 13,
  InitialPackets = 14,
  Unknown_15 = 15,
  Unknown_16 = 16,
  Efst = 17,
  Unknown_18 = 18,
  Unknown_19 = 19,
  Unknown_20 = 20,
  Unknown_21 = 21,
  Unknown_22 = 22,
  Unknown_23 = 23,
  Unknown_24 = 24,
  LastContainerType
};  // end of enum class ContainerType

class ChunkContainer {
 public:
  ContainerType ContainerType;
  int32_t Length;
  int32_t Offset;
  std::list<Chunk> Data;
};  // end of class ChunkContainer

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H
