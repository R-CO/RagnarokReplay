/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
#include <string>

#include "Replay.hpp"

int main(int argc, char *argv[]) {
  std::string file_path = "../RagnarokReplayExample/Replay/woe1103-1.rrf";

  if (argc >= 2) {
    file_path = argv[1];
  }

  RagnarokReplay::Replay replay;
  replay.LoadFile(file_path);

  return EXIT_SUCCESS;
}
