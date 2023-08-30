#Simple CMakeLists for C++20
cmake_minimum_required (VERSION 3.20)
project(step1 CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS -Wfatal-errors)


add_executable(CodeChallenge CodeChallenge.cpp)


