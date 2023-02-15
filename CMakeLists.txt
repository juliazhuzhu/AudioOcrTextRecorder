cmake_minimum_required(VERSION 3.23)
project(AudioOcrTextRecorder)

set(CMAKE_CXX_STANDARD 11)

add_executable(AudioOcrTextRecorder main.cpp CAudioTextRecorder.cpp CAudioTextRecorder.h)
