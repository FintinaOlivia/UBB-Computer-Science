cmake_minimum_required(VERSION 3.25)
project(a45_913_Fintina_Olivia_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a45_913_Fintina_Olivia_main
        Controller.cpp
        Controller.h
        Domain.cpp
        Domain.h
        DynamicArray.cpp
        DynamicArray.h
        main.cpp
        Repository.cpp
        Repository.h
        testController.cpp
        testDomain.cpp
        testDynamicArray.cpp
        testRepository.cpp
        UI.cpp
        UI.h TestAll.h)
