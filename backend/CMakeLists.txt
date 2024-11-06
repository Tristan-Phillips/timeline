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

# Add the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/localization
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/parsers/json
)

# Environment File: You might want to copy the .env file to the build directory if needed
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.env ${CMAKE_CURRENT_BINARY_DIR}/.env COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/localization/lang/en.json ${CMAKE_CURRENT_BINARY_DIR}/en.json COPYONLY)