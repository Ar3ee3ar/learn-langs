# Set minimum CMake version required
cmake_minimum_required(VERSION 3.20)

# Define project name and specify C++ language
PROJECT(torchtest LANGUAGES CXX)

# Require C++20 standard
# win
set(CMAKE_PREFIX_PATH D:/personal_proj/ml-basic/cpp/pytorch/lib/libtorch)
# ubuntu
# set(CMAKE_PREFIX_PATH /mnt/d/personal_proj/ml-basic/cpp/pytorch/lib/libtorch)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Enforce C++20 requirement (fail if not available)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Append Torch-specific compiler flags to global C++ flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

# [Commented out] Would add libtorch as a subdirectory for building from source
# add_subdirectory(lib/pytorch)

# Search for Torch package in CMAKE_PREFIX_PATH and fail if not found
find_package(Torch REQUIRED)

# Create executable named "pytorch" from main.cpp source file
# add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME} src/main.cpp
                    include/network.h)              

target_include_directories(${PROJECT_NAME} PRIVATE include)
# Link Torch libraries to the executable
target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")

# Explicitly set C++20 standard for the target
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET ${PROJECT_NAME}
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif (MSVC)