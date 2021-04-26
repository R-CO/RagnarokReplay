/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTCHUNKCONTAINER_HPP
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTCHUNKCONTAINER_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

#include "../ChunkContainer.hpp"
#include "simple_test.h"

class PublicChunkContainerV5 : public RagnarokReplay::LoadChunkContainerV5 {
 public:
  PublicChunkContainerV5(const RagnarokReplay::DateTime &date_time)
      : LoadChunkContainerV5(date_time) {}

  int32_t GetKey1(const RagnarokReplay::DateTime &date_time) {
    return RagnarokReplay::LoadChunkContainerV5::GetKey1(date_time);
  }

  int32_t GetKey2(const RagnarokReplay::DateTime &date_time) {
    return RagnarokReplay::LoadChunkContainerV5::GetKey2(date_time);
  }

  void Decrypt(const int32_t kKey1, const int32_t kKey2,
               std::vector<uint8_t> &packet_data) {
    RagnarokReplay::LoadChunkContainerV5::Decrypt(kKey1, kKey2, packet_data);
  }

 private:
  virtual void LoadChunkContainer(
      std::istream &input_stream, const size_t kMaxReadSize,
      RagnarokReplay::ChunkContainer &chunk_container) override {}
};  // end of class PublicChunkContainer

void ChunkContainerV5_getKey1() {
  RagnarokReplay::DateTime date_time;
  date_time.year = 2021;
  date_time.month = 4;
  date_time.day = 19;
  PublicChunkContainerV5 chunk_container_v5(date_time);

  EXPECT_EQ(chunk_container_v5.GetKey1(date_time), 0x130407E5 >> 5);
}

void ChunkContainerV5_getKey2() {
  RagnarokReplay::DateTime date_time;
  date_time.hour = 14;
  date_time.minute = 42;
  date_time.second = 30;
  PublicChunkContainerV5 chunk_container_v5(date_time);

  EXPECT_EQ(chunk_container_v5.GetKey2(date_time), 0x1E2A0E00 >> 3);
}

void ChunkContainerV5_decrypt() {
  RagnarokReplay::DateTime date_time;
  date_time.year = 2021;
  date_time.month = 4;
  date_time.day = 19;
  date_time.hour = 14;
  date_time.minute = 42;
  date_time.second = 30;
  PublicChunkContainerV5 chunk_container_v5(date_time);

  std::vector<uint8_t> packet_data = {1, 2, 3, 4, 5};
  chunk_container_v5.Decrypt(chunk_container_v5.GetKey1(date_time),
                             chunk_container_v5.GetKey2(date_time),
                             packet_data);
  std::vector<uint8_t> expected_data = {1, 114, 139, 167, 5};

  EXPECT_EQ(
      std::equal(packet_data.begin(), packet_data.end(), expected_data.begin()),
      true);
}

#endif  // end of define
        // RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTCHUNKCONTAINER_HPP