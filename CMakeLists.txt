cmake_minimum_required(VERSION 3.15)
project (avtl VERSION 0.1.0
    DESCRIPTION "Arjun Vinod's Template Library"
    LANGUAGES CXX)

set(CMAKE_CXX_STNADARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(third_party/googletest)
enable_testing()

add_library(avtl INTERFACE)
target_include_directories(avtl INTERFACE include)

add_subdirectory(tests)