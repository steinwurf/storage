cmake_minimum_required(VERSION 3.12)
project(storage)

# Define library
add_library(storage INTERFACE)
target_compile_features(storage INTERFACE cxx_std_14)
target_include_directories(storage INTERFACE src/)
add_library(steinwurf::storage ALIAS storage)

# Install headers
install(
  DIRECTORY ./src/storage
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING
  PATTERN *.hpp)
