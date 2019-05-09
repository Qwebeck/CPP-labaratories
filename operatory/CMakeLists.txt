cmake_minimum_required(VERSION 3.13)
project(operatory)

set(CMAKE_CXX_STANDARD 14)

add_executable(operatory main.cpp Student.cpp Student.h StudyYear.cpp StudyYear.h StudentRepository.cpp StudentRepository.h)