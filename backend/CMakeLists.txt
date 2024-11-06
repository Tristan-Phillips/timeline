cmake_minimum_required(VERSION 3.10)

include(FetchContent)

# Set the project name
project(TimelineBackend)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
)

FetchContent_MakeAvailable(json)

# Define the source files
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Find libpqxx using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    nlohmann_json::nlohmann_json
    ${LIBPQXX_LIBRARIES}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/localization
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/json
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/env
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/userinfo
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/blocked
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/collaborators
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/followers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/following
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/friends
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user/connections/teams
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database
    ${CMAKE_CURRENT_SOURCE_DIR}/src/setup/database
    ${CMAKE_CURRENT_SOURCE_DIR}/src/config
    ${LIBPQXX_INCLUDE_DIRS}
)

link_directories(${LIBPQXX_LIBRARY_DIRS})

# Environment File
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.env ${CMAKE_CURRENT_BINARY_DIR}/.env COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/localization/lang/en.json ${CMAKE_CURRENT_BINARY_DIR}/en.json COPYONLY)