cmake_minimum_required (VERSION 3.10)
project(storage)

file(GLOB storage_headers ./src/storage/*.hpp)

add_library(storage INTERFACE)
add_library(steinwurf::storage ALIAS storage)

target_include_directories(storage INTERFACE src/)

install(FILES ${storage_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/storage)
