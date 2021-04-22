#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>

#include "simple_test.h"
#include "test_replay.hpp"

int main(int argc, char *argvp[]) {
  TEST_START();

  ADD_TEST_FUNCTION(Replay_getKey1);
  ADD_TEST_FUNCTION(Replay_getKey2);
  ADD_TEST_FUNCTION(Replay_decrypt);
  ADD_TEST_FUNCTION(Replay_parseHeader);

  PRINT_STATICS();

  return EXIT_SUCCESS;
}
