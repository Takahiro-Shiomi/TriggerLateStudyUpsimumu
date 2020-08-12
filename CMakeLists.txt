# setup the cmake version
cmake_minimum_required(VERSION 2.8)

# define project name
project(TriggerLateStudy CXX)

# make .out from .cxx
add_subdirectory(src)
add_subdirectory(test)
