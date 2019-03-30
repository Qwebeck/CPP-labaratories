cmake_minimum_required(VERSION 3.13)
project(names_)

set(CMAKE_CXX_STANDARD 14)

add_executable(names_ main.cpp Name.cpp Name.h SimpleTemplateEngine.cpp SimpleTemplateEngine.h SimpleUrl.cpp SimpleUrl.h)