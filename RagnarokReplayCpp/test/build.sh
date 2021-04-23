#!/bin/sh

alias CXX=clang++

CXX_FLAG="-std=c++17 -O2 -g -Wall"

INCLUDE_DIR=""
LINK_DIR=""

SRC_FILES="simple_test.c test_main.cpp ../Replay.cpp ../ChunkContainer.cpp"

CXX ${SRC_FILES} ${CXX_FLAG} ${INCLUDE_DIR} ${LINK_DIR} -o test.exe
