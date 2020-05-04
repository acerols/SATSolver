# CMake Version
cmake_minimum_required(VERSION 3.0)

# Project name, Use Language
project(SATSolver CXX)

#use compiler
set(CMAKE_C_COMPILER "~/mybuilddir/llvm-project/build/bin/clang")
set(CMake_CXX_COMPILER "~/mybuilddir/llvm-project/build/bin/clang++")

#find Boost library
find_package(Boost REQUIRED)

#add include dir
include_directories(SATSolver ./include)

#set source files
set(SOURCE
    main.cpp
    lexer.cpp
)

#make executable file
add_executable(SATSolver ${SOURCE})
#link target
target_link_libraries(SATSolver ${Boost_LIBRARIES})
#Use compiler for CXX
target_compile_features(SATSolver PRIVATE cxx_std_11)
