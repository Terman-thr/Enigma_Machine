cmake_minimum_required(VERSION 3.17)
project(Enigma_Machine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enigma_Machine main.cpp Rotor.h Enigma.h)