#!/bin/sh

set -x

alias CXX=clang++

if [ "$1" == "debug" ];
then
	CXX_FLAG="-std=c++17 -O0 -Wall -g"
else
	CXX_FLAG="-std=c++17 -O2 -Wall"
fi

INCLUDE_DIR=""
LINK_DIR=""

SRC_FILES="main.cpp Replay.cpp ChunkContainer.cpp"

CXX ${SRC_FILES} ${CXX_FLAG} ${INCLUDE_DIR} ${LINK_DIR} -o load_replay.exe
