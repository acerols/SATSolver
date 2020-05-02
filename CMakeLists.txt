cmake_minimum_required(VERSION 3.1)
project(SATSolver
        VERSION 0.0.0
        LANGUAGES CXX)

add_executable(solver main.cpp)
target_compile_features(SATSolver PRIVATE cxx_std_11)
target_include_directories(SATSolver INTERFACE ./include)
set_target_properties(SATSolver
    PROPERTIES
    VERSION $(PROJECT_VERSION))