cmake_minimum_required(VERSION 3.25)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CLionProjects
        Controller.cpp
        Controller.h
        Domain.cpp
        Domain.h
        main.cpp
        Repository.cpp
        Repository.h
        TestAll.h
        testDomain.cpp
        UI.cpp
        UI.h TestRepository.cpp testController.cpp)
