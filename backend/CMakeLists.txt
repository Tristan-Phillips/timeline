cmake_minimum_required(VERSION 3.10)

project(TimelineBackend)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(src)

# Crow uses header-only library, so just include the path
# Add your source files
add_executable(TimelineBackend main.cpp)