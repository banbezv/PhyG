cmake_minimum_required(VERSION 3.13)
project(phyg)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(main main.cpp World.cpp Physics.cpp Body.cpp Section.cpp Vector.cpp utils.cpp Double.cpp Geometry.cpp)
target_link_libraries(main sfml-graphics sfml-audio)
