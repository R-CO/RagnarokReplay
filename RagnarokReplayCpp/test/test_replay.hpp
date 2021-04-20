#ifndef RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP
#define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP

#include <cstdint>
#include <iostream> // TODO: remove this

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
	replay.Decrypt(replay.GetKey1(date_time), replay.GetKey2(date_time), packet_data);

	for (const auto byte : packet_data) {

	}
}

#endif  // end of define RAGNAROKREPLAY_RAGNAROKREPLAYCPP_TEST_TESTREPLAY_HPP