#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>

#include <vector>

#include "../Replay.hpp"
#include "simple_test.h"

class PublicReplay : public RagnarokReplay::Replay {
 public:
  int32_t GetKey1(const RagnarokReplay::Replay::DateTime &date_time) {
    return RagnarokReplay::Replay::GetKey1(date_time);
  }

  int32_t GetKey2(const RagnarokReplay::Replay::DateTime &date_time) {
    return RagnarokReplay::Replay::GetKey2(date_time);
  }

  void Decrypt(const int32_t kKey1, const int32_t kKey2,
               std::vector<uint8_t> &packet_data) {
    RagnarokReplay::Replay::Decrypt(kKey1, kKey2, packet_data);
  }

  void ParseHeader(std::istream &input_stream) {
    RagnarokReplay::Replay::ParseHeader(input_stream);
  }
};  // end of class PublicReplay

void Replay_getKey1() {
  RagnarokReplay::Replay::DateTime date_time;
  date_time.year = 2021;
  date_time.month = 4;
  date_time.day = 19;
  PublicReplay replay;

  EXPECT_EQ(replay.GetKey1(date_time), 0x130407E5 >> 5);
}

void Replay_getKey2() {
  RagnarokReplay::Replay::DateTime date_time;
  date_time.hour = 14;
  date_time.minute = 42;
  date_time.second = 30;
  PublicReplay replay;

  EXPECT_EQ(replay.GetKey2(date_time), 0x1E2A0E00 >> 3);
}

void Replay_decrypt() {
  RagnarokReplay::Replay::DateTime date_time;
  date_time.year = 2021;
  date_time.month = 4;
  date_time.day = 19;
  date_time.hour = 14;
  date_time.minute = 42;
  date_time.second = 30;
  PublicReplay replay;

  std::vector<uint8_t> packet_data = {1, 2, 3, 4, 5};
  replay.Decrypt(replay.GetKey1(date_time), replay.GetKey2(date_time),
                 packet_data);
  std::vector<uint8_t> expected_data = {1, 114, 139, 167, 5};

  EXPECT_EQ(
      std::equal(packet_data.begin(), packet_data.end(), expected_data.begin()),
      true);
}

void Replay_parseHeader() {
  unsigned char header_raw_data[112] = {
      0x3C, 0x3C, 0x20, 0x52, 0x61, 0x67, 0x6E, 0x61, 0x72, 0x6F, 0x6B, 0x20,
      0x52, 0x65, 0x70, 0x6C, 0x61, 0x79, 0x20, 0x46, 0x69, 0x6C, 0x65, 0x20,
      0x56, 0x65, 0x72, 0x73, 0x69, 0x6F, 0x6E, 0x20, 0x30, 0x2E, 0x30, 0x35,
      0x20, 0x3E, 0x3E, 0x0D, 0x0A, 0x20, 0xA1, 0xD8, 0x20, 0x44, 0x6F, 0x20,
      0x6E, 0x6F, 0x74, 0x20, 0x6D, 0x6F, 0x64, 0x69, 0x66, 0x79, 0x20, 0x66,
      0x69, 0x6C, 0x65, 0x21, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D,
      0x0A, 0x00, 0x00, 0x00, 0x05, 0x47, 0x41, 0x52, 0xE2, 0x07, 0x03, 0x0B,
      0x00, 0x14, 0x3B, 0x12};
  std::stringstream ss;
  ss.write(reinterpret_cast<const char *>(header_raw_data), sizeof(header_raw_data));

  PublicReplay replay;
  replay.ParseHeader(ss);

  EXPECT_EQ(replay.header.version, 5);
}

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP