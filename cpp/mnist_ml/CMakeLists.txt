cmake_minimum_required(VERSION 3.20)
project(mnist_ml LANGUAGES CXX)

# Required C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# add pybind11
add_subdirectory(pybind11)

# Find Python and pybind11
find_package(Python COMPONENTS Interpreter Development REQUIRED)
# find_package(pybind11 REQUIRED)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/data.cc
    src/data_handler.cc
    src/pybind_wrapper.cpp)

# Build Python module
pybind11_add_module(libdata ${SOURCES})

# Set output directory for the Python module
set_target_properties(libdata PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/python)

