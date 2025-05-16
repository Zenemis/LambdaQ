cmake_minimum_required(VERSION 3.10)

# Project name and version
project(LambdaQ VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src)

# Find Eigen3
find_package(Eigen3 REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/examples/*.cpp
)

# Executable target
add_executable(LambdaQ ${SOURCES})

# Link Eigen3 to the target
target_link_libraries(LambdaQ PRIVATE Eigen3::Eigen)

# Set runtime output directory inside the build directory
set_target_properties(LambdaQ PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Link libraries (if needed)
# target_link_libraries(LambdaQ <library_name>)

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(LambdaQ PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Add custom target for examples
add_custom_target(run_example
    COMMAND LambdaQ
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/examples
    COMMENT "Running the functional example"
)