cmake_minimum_required(VERSION 3.13)
project(phyg)

set(CMAKE_CXX_STANDARD 14)
add_executable(main main.cpp World.cpp Physics.cpp Body.cpp Section.cpp Vector.cpp utils.cpp Double.cpp)
