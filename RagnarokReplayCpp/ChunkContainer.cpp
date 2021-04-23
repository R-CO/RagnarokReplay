#include "ChunkContainer.hpp"

#include <istream>
#include <sstream>
#include <string>
#include <vector>

#include "Replay.hpp"

namespace RagnarokReplay {

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
    in_stream.read(reinterpret_cast<char *>(&packet.Id), sizeof(int32_t));
    in_stream.read(reinterpret_cast<char *>(&packet.Time), sizeof(int32_t));
    in_stream.read(reinterpret_cast<char *>(&packet.Length), sizeof(uint16_t));
    if (packet.Length > 0) {
      packet.Data.resize(packet.Length);
      in_stream.read(reinterpret_cast<char *>(packet.Data.data()),
                     packet.Length);
      Decrypt(kKey1_, kKey2_, packet.Data);
      packet.Header = *(reinterpret_cast<uint16_t *>(packet.Data.data()));
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
    in_stream.read(reinterpret_cast<char *>(&entry.Id), sizeof(int16_t));
    in_stream.read(reinterpret_cast<char *>(&entry.Length), sizeof(int32_t));
    entry.Data.resize(entry.Length);
    in_stream.read(reinterpret_cast<char *>(entry.Data.data()), entry.Length);
    chunk_container.data.emplace_back(entry);
  }
}

}  // end of namespace RagnarokReplay
