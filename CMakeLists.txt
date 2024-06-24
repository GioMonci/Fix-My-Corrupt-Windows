cmake_minimum_required(VERSION 3.27)
project(Fix_My_Corrupt_Windows)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")
# fixes "libstdc++-6.dll is missing" error

add_executable(Fix_My_Corrupt_Windows main.cpp)
