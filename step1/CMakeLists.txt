#Simple CMakeLists for C++20
cmake_minimum_required (VERSION 3.20)
project(step1 CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS -Wfatal-errors)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src/step1)
