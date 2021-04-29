/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H

// C++ standard headers
#include <cstdint>
#include <istream>
#include <memory>
#include <string>

// C++ STL
#include <vector>

#include "Chunk.hpp"
#include "DateTime.hpp"

namespace RagnarokReplay {

enum class ContainerType : uint16_t {
  None = 0,
  PacketStream = 1,
  ReplayData = 2,
  Session = 3,
  Status = 4,
  Undefined_1 = 5,
  Quests = 6,
  GroupAndFriends = 7,
  Items = 8,
  UnknownContainingPet = 9,
  Unknown_10 = 10,
  Undefined_2 = 11,
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
  ChunkContainer();

  ContainerType container_type;
  int32_t length;
  int32_t offset;
  std::vector<Chunk> data;
};  // end of class ChunkContainer

class LoadChunkContainerInterface {
 public:
  virtual void LoadChunkContainer(std::istream &input_stream,
                                  const size_t kMaxReadSize,
                                  ChunkContainer &chunk_container) = 0;
};

class LoadChunkContainerV5 : public LoadChunkContainerInterface {
 public:
  explicit LoadChunkContainerV5(const DateTime &date_time);

  virtual void LoadChunkContainer(std::istream &input_stream,
                                  const size_t kMaxReadSize,
                                  ChunkContainer &chunk_container) = 0;

 protected:
  int32_t GetKey1(const DateTime &date_time) const;
  int32_t GetKey2(const DateTime &date_time) const;

  void Decrypt(const int32_t kKey1, const int32_t kKey2,
               std::string &packet_data);
  void Decrypt(const int32_t kKey1, const int32_t kKey2,
               std::vector<uint8_t> &packet_data);
  void Decrypt(const int32_t kKey1, const int32_t kKey2, uint8_t *packet_data,
               const size_t packet_size);

  const DateTime kDateTime_;
  const int32_t kKey1_;
  const int32_t kKey2_;
};

class LoadChunkContainerPacketStreamV5 : public LoadChunkContainerV5 {
 public:
  explicit LoadChunkContainerPacketStreamV5(const DateTime &date_time);

  virtual void LoadChunkContainer(std::istream &input_stream,
                                  const size_t kMaxReadSize,
                                  ChunkContainer &chunk_container) override;
};

class LoadChunkContainerNonPacketStreamV5 : public LoadChunkContainerV5 {
 public:
  explicit LoadChunkContainerNonPacketStreamV5(const DateTime &date_time);

  virtual void LoadChunkContainer(std::istream &input_stream,
                                  const size_t kMaxReadSize,
                                  ChunkContainer &chunk_container) override;
};

}  // end of namespace RagnarokReplay

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_CHUNKCONTAINER_H
