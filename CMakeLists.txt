cmake_minimum_required (VERSION 3.12)
project(storage)

add_library(storage INTERFACE)
target_include_directories(storage INTERFACE src/)
