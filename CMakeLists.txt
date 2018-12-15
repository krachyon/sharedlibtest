cmake_minimum_required(VERSION 3.0)

project(sharedlibrarytest)

add_executable(sharedlibrarytest main.cpp)

install(TARGETS sharedlibrarytest RUNTIME DESTINATION bin)
