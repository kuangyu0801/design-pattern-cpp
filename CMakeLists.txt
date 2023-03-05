cmake_minimum_required(VERSION 3.14)

# set project name
project(design-pattern-cpp)

# set cpp standard to c17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ABSL_PROPAGATE_CXX_STD ON)

# set command for generation compile_commands.json
# used for clangd extension in VSCode
set(DCMAKE_EXPORT_COMPILE_COMMANDS 1)

# set include files
include_directories(hello_module)

# add subdirectory each contains own CMakeLists.txt
add_subdirectory(test)
add_subdirectory(hello_module)

add_subdirectory(lib/gtest)
add_subdirectory(lib/abseil-cpp)