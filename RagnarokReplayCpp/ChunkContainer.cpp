/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include "ChunkContainer.hpp"

#include <istream>
#include <sstream>
#include <string>
#include <vector>

#include "Replay.hpp"

namespace RagnarokReplay {

ChunkContainer::ChunkContainer()
    : container_type(ContainerType::None), length(0), offset(0), data() {}

LoadChunkContainerV5::LoadChunkContainerV5(const DateTime &date_time)
    : kDateTime_(date_time),
      kKey1_(GetKey1(date_time)),
      kKey2_(GetKey2(date_time)) {}

int32_t LoadChunkContainerV5::GetKey1(const DateTime &date_time) const {
  return (0x0i32 | date_time.year | date_time.month << 16 |
          date_time.day << 24) >>
         5;
}

int32_t LoadChunkContainerV5::GetKey2(const DateTime &date_time) const {
  return (0x0i32 | date_time.hour << 8 | date_time.minute << 16 |
          date_time.second << 24) >>
         3;
}

void LoadChunkContainerV5::Decrypt(const int32_t kKey1, const int32_t kKey2,
                                   std::string &packet_data) {
  Decrypt(kKey1, kKey2, reinterpret_cast<uint8_t *>(packet_data.data()),
          packet_data.size());
}

void LoadChunkContainerV5::Decrypt(const int32_t kKey1, const int32_t kKey2,
                                   std::vector<uint8_t> &packet_data) {
  Decrypt(kKey1, kKey2, packet_data.data(), packet_data.size());
}

void LoadChunkContainerV5::Decrypt(const int32_t kKey1, const int32_t kKey2,
                                   uint8_t *packet_data,
                                   const size_t packet_size) {
  const size_t kSegmentCount = packet_size >> 2;
  int32_t *i32_ptr = reinterpret_cast<int32_t *>(packet_data);
  for (size_t i = 0; i < kSegmentCount; ++i) {
    *i32_ptr = *i32_ptr ^ (kKey1 + (i + 1)) * kKey2;
    ++i32_ptr;
  }
}

LoadChunkContainerPacketStreamV5::LoadChunkContainerPacketStreamV5(
    const DateTime &date_time)
    : LoadChunkContainerV5(date_time) {}

void LoadChunkContainerPacketStreamV5::LoadChunkContainer(
    std::istream &input_stream, const size_t kMaxReadSize,
    ChunkContainer &chunk_container) {
  std::string input;
  input.resize(kMaxReadSize);
  input_stream.read(input.data(), kMaxReadSize);
  std::stringstream in_stream(input,
                              std::ios::in | std::ios::out | std::ios::binary);

  while (in_stream.peek() != EOF) {
    Chunk packet;
    in_stream.read(reinterpret_cast<char *>(&packet.id), sizeof(int32_t));
    in_stream.read(reinterpret_cast<char *>(&packet.time), sizeof(int32_t));
    in_stream.read(reinterpret_cast<char *>(&packet.length), sizeof(uint16_t));
    if (packet.length > 0) {
      packet.data.resize(packet.length);
      in_stream.read(reinterpret_cast<char *>(packet.data.data()),
                     packet.length);
      Decrypt(kKey1_, kKey2_, packet.data);
      packet.header = *(reinterpret_cast<uint16_t *>(packet.data.data()));
    }
    chunk_container.data.emplace_back(packet);
  }
}

LoadChunkContainerNonPacketStreamV5::LoadChunkContainerNonPacketStreamV5(
    const DateTime &date_time)
    : LoadChunkContainerV5(date_time) {}

void LoadChunkContainerNonPacketStreamV5::LoadChunkContainer(
    std::istream &input_stream, const size_t kMaxReadSize,
    ChunkContainer &chunk_container) {
  std::string input;
  input.resize(kMaxReadSize);
  input_stream.read(input.data(), kMaxReadSize);
  Decrypt(kKey1_, kKey2_, input);
  std::stringstream in_stream(input,
                              std::ios::in | std::ios::out | std::ios::binary);

  while (in_stream.peek() != EOF) {
    Chunk entry;
    in_stream.read(reinterpret_cast<char *>(&entry.id), sizeof(int16_t));
    in_stream.read(reinterpret_cast<char *>(&entry.length), sizeof(int32_t));
    entry.data.resize(entry.length);
    in_stream.read(reinterpret_cast<char *>(entry.data.data()), entry.length);
    chunk_container.data.emplace_back(entry);
  }
}

}  // end of namespace RagnarokReplay
