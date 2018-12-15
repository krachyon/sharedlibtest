cmake_minimum_required(VERSION 3.0)

project(sharedlibrarytest)

include(GenerateExportHeader)

#set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic -Wall -Wextra -Wpedantic -std=c++17")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -rdynamic")
message(${CMAKE_CXX_FLAGS})
message(${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS})


add_library(sharedlib SHARED shared.cpp)
generate_export_header(sharedlib)

target_include_directories(sharedlib PUBLIC ${CMAKE_BINARY_DIR})

add_executable(sharedlibrarytest main.cpp)


target_link_libraries(sharedlibrarytest sharedlib)


install(TARGETS sharedlibrarytest RUNTIME DESTINATION bin)
