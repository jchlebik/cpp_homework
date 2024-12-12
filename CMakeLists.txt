cmake_minimum_required(VERSION 3.10)
project(rba_homework VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
