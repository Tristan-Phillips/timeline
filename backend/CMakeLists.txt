cmake_minimum_required(VERSION 3.10)
project(TimelineBackend)

set(CMAKE_CXX_STANDARD 17)

# Include directories for Crow and other source files
include_directories(
    third_party/crow/include
    src/config
    src/controllers
    src/models
    src/routes
    src/utils
)

# Find required packages
find_package(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})

# Define source files
set(SOURCES
    src/main.cpp
    src/App.cpp
    src/controllers/TimelineController.cpp
    src/controllers/UserController.cpp
    src/models/TimelineModel.cpp
    src/models/UserModel.cpp
    src/routes/TimelineRoutes.cpp
    src/routes/UserRoutes.cpp
    src/utils/CryptoUtils.cpp
    src/utils/DbUtils.cpp
    src/config/config.cpp
)

# Add the executable
add_executable(TimelineBackend ${SOURCES})

# Link the PostgreSQL and Crow libraries
target_link_libraries(TimelineBackend PRIVATE ${PostgreSQL_LIBRARIES} pqxx pthread)