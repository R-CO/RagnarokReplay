/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include "Replay.hpp"

int main(int argc, char *argv[]) {
  RagnarokReplay::Replay replay;

  replay.LoadFile("../RagnarokReplayExample/Replay/woe1103-1.rrf");

  return EXIT_SUCCESS;
}
