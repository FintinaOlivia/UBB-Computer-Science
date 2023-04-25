cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Domain.cpp Domain.h Repository.cpp Repository.h Controller.cpp Controller.h UI.cpp UI.h)
