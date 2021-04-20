#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>

#include "simple_test.h"
#include "test_replay.hpp"

int main(int argc, char *argvp[]) {
  TEST_START();

  Replay_getKey1();
  Replay_getKey2();

  PRINT_STATICS();

  return EXIT_SUCCESS;
}
