cmake_minimum_required(VERSION 3.22)
project(BER_Kalkulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(BER_Kalkulator main.cpp dataFiles.h dataFiles.cpp calculateResullt.cpp calculateResullt.h BER_computer.cpp BER_computer.h logger.cpp logger.h)
