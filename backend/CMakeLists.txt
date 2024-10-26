# CMake minimum required version
cmake_minimum_required(VERSION 3.10)

# Project name
project(TimelineBackend)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories for Crow
include_directories(third_party/crow/include)

# Find required packages
find_package(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})

# Add the executable
add_executable(TimelineBackend src/main.cpp)

# Link the PostgreSQL library
target_link_libraries(TimelineBackend ${PostgreSQL_LIBRARIES} pqxx pthread)