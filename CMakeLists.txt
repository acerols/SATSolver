cmake_minimum_required(VERSION 3.1)
project(SATSolver
        VERSION 0.0.0
        LANGUAGES CXX)
find_package(Boost REQUIRED)
set(CMAKE_CXX_STANDARD 14)
include_directories(SATSolver ./include)
add_executable(SATSolver main.cpp)
target_compile_features(SATSolver PRIVATE cxx_std_14)

