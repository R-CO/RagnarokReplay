/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include "Replay.hpp"

#include <cstdint>
#include <exception>
#include <fstream>
#include <istream>
#include <string>

#include "ChunkContainer.hpp"

namespace RagnarokReplay {

void Replay::LoadFile(std::string filename) {
  std::ifstream in_file(filename, std::ios::in | std::ios::binary);
  ParseHeader(in_file);
  switch (header.version) {
    case 5: {
      LoadReplayV5(in_file);
    } break;
    default: {
      char error_msg[64];
      sprintf_s(error_msg, sizeof(error_msg), "Non support file version [%d]\n",
                header.version);
      throw std::runtime_error(error_msg);
    } break;
  }
}

void Replay::ParseHeader(std::istream &input_stream) {
  input_stream.read(reinterpret_cast<char *>(&header), sizeof(header));
}

void Replay::LoadReplayV5(std::istream &input_stream) {
  const auto current_pos = input_stream.tellg();
  input_stream.seekg(0, std::ios::end);
  const size_t file_size = input_stream.tellg();
  input_stream.seekg(current_pos, std::ios::beg);

  LoadChunkContainerPacketStreamV5 packet_stream_loader{header.date};
  LoadChunkContainerNonPacketStreamV5 non_packet_stream_loader{header.date};

  for (auto i = 0; i < static_cast<int32_t>(ContainerType::LastContainerType);
       ++i) {
    ChunkContainer temp_chunk_container;
    input_stream.read(
        reinterpret_cast<char *>(&temp_chunk_container.container_type),
        sizeof(uint16_t));
    input_stream.read(reinterpret_cast<char *>(&temp_chunk_container.length),
                      sizeof(int32_t));
    input_stream.read(reinterpret_cast<char *>(&temp_chunk_container.offset),
                      sizeof(int32_t));

    if (temp_chunk_container.container_type >=
        ContainerType::LastContainerType) {
      continue;
    }

    if (temp_chunk_container.offset == 0 &&
        temp_chunk_container.container_type == ContainerType::None) {
      continue;
    }

    auto &chunk_container = chunk_container_array[static_cast<size_t>(
        temp_chunk_container.container_type)];
    chunk_container = std::move(temp_chunk_container);

    if (chunk_container.length == 0) {
      chunk_container.length = (int32_t)file_size - chunk_container.offset;
    }

    const auto last_offset = input_stream.tellg();
    input_stream.seekg(chunk_container.offset, std::ios::beg);
    LoadChunkContainerV5 *loader =
        (chunk_container.container_type == ContainerType::PacketStream)
            ? reinterpret_cast<LoadChunkContainerV5 *>(&packet_stream_loader)
            : reinterpret_cast<LoadChunkContainerV5 *>(
                  &non_packet_stream_loader);

    loader->LoadChunkContainer(input_stream, chunk_container.length,
                               chunk_container);

    input_stream.seekg(last_offset, std::ios::beg);
  }
}

}  // end of namespace RagnarokReplay
