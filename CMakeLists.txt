cmake_minimum_required(VERSION 4.0)
project(S_D_P)

set(CMAKE_CXX_STANDARD 20)

add_executable(S_D_P start_dos.cpp
        wifi_scanner.cpp
        SDP.cpp
        termcolor.hpp
)
