/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include <cstdint>

#include "simple_test.h"
#include "test_chunk_container.hpp"
#include "test_replay.hpp"

int main(int argc, char *argvp[]) {
  TEST_START();

  ADD_TEST_FUNCTION(ChunkContainerV5_getKey1);
  ADD_TEST_FUNCTION(ChunkContainerV5_getKey2);
  ADD_TEST_FUNCTION(ChunkContainerV5_decrypt);

  ADD_TEST_FUNCTION(Replay_parseHeader);

  PRINT_STATICS();

  return EXIT_SUCCESS;
}
