# AUTH: GM
# DATE: 6/9/25
# DESC: SIMPLE CMAKE made in Visual Studio 2022 Community
# TODO: N/A

cmake_minimum_required (VERSION 3.8)
project ("FMCW")
set(CMAKE_CXX_STANDARD 17)
add_executable (FMCW src/main.cpp               
                "src/logger.cpp"
                "include/logger.h")
