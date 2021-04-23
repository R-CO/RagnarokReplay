#!/bin/sh

alias CXX=clang++

CXX_FLAG="-std=c++17 -O2 -Wall -g"

INCLUDE_DIR=""
LINK_DIR=""

SRC_FILES="main.cpp Replay.cpp ChunkContainer.cpp"

CXX ${SRC_FILES} ${CXX_FLAG} ${INCLUDE_DIR} ${LINK_DIR} -o load_replay.exe
