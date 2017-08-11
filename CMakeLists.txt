cmake_minimum_required(VERSION 3.0)

find_package(Qt5 REQUIRED COMPONENTS Core Network)
find_package(Snapd REQUIRED)

add_executable(testsnap main.cpp)
target_link_libraries(testsnap Qt5::Core Qt5::Network Snapd::Core)
