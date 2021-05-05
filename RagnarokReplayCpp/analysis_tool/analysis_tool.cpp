/**
 * Author: R-CO
 * E-mail: daniel1820kobe@gmail.com
 **/
#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <direct.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "ChunkContainer.hpp"
#include "Replay.hpp"
using namespace RagnarokReplay;

//
// read-only data
//
const auto &getContainerTypeStr() {
  static const std::array<const std::string,
                          static_cast<size_t>(ContainerType::LastContainerType)>
      container_type_str = {u8"None",           u8"PacketStream",
                            u8"ReplayData",     u8"Session",
                            u8"Status",         u8"Undefined_1",
                            u8"Quests",         u8"GroupAndFriends",
                            u8"Items",          u8"UnknownContainingPet",
                            u8"Unknown_10",     u8"Undefined_2",
                            u8"Unknown_12",     u8"Unknown_13",
                            u8"InitialPackets", u8"Unknown_15",
                            u8"Unknown_16",     u8"Efst",
                            u8"Unknown_18",     u8"Unknown_19",
                            u8"Unknown_20",     u8"Unknown_21",
                            u8"Unknown_22",     u8"Unknown_23",
                            u8"Unknown_24"};

  return container_type_str;
}

//
// read-only data
//
const auto &getRootDirPath() {
  static const string root_dir_path = u8"output";

  return root_dir_path;
}

bool isDirExist(const string &dir_path);

bool createOuputDirectories();

int main(int argc, char *argv[]) {
  string file_path = "210227.rrf";

  if (argc >= 2) {
    file_path = argv[1];
  }

  if (!createOuputDirectories()) {
    cerr << u8"createOuputDirectories() returns false" << endl;
    return EXIT_FAILURE;
  }

  Replay replay;
  replay.LoadFile(file_path);

  for (const auto &chunk_container : replay.chunk_container_array) {
    const auto dir_path = getRootDirPath() + u8'/' +
                          getContainerTypeStr()[static_cast<size_t>(
                              chunk_container.container_type)] +
                          u8'/';
    for (const auto &chunk : chunk_container.data) {
      const auto output_file_path = dir_path + to_string(chunk.header) + u8'_' +
                                    to_string(chunk.id) + u8'_' +
                                    to_string(chunk.time);
      ofstream output_file(output_file_path, ios::out | ios::binary);
      output_file.write(reinterpret_cast<const char *>(chunk.data.data()),
                        chunk.data.size());
    }
  }

  return EXIT_SUCCESS;
}

bool isDirExist(const string &dir_path) {
  struct _stat info;
  if (_stat(dir_path.c_str(), &info) == 0 && info.st_mode & _S_IFDIR) {
    return true;
  }
  return false;
}

bool createOuputDirectories() {
  _mkdir(getRootDirPath().c_str());
  if (!isDirExist(getRootDirPath())) {
    return false;
  }

  for (auto &sub_dir_name : getContainerTypeStr()) {
    const auto dir_path = getRootDirPath() + u8'/' + sub_dir_name;
    _mkdir(dir_path.c_str());
    if (!isDirExist(dir_path)) {
      return false;
    }
  }

  return true;
}
