cmake_minimum_required(VERSION 3.25)
project(t1_913_Fintina_Olivia_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1_913_Fintina_Olivia_1
        Domain.cpp
        Domain.h Repository.h Repository.cpp Controller.h Controller.cpp UI.h UI.cpp main.cpp Tests.h Tests.cpp)
