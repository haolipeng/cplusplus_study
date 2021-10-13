cmake_minimum_required(VERSION 3.15)
project(cplusplus_study)

set(CMAKE_CXX_STANDARD 11)

add_executable(cplusplus_study main.cpp copy_and_assign_construct/String.h)

#target_link_directories(cplusplus_study "")
target_link_libraries(cplusplus_study "/usr/local/lib/libunwind.a"
        lzma)