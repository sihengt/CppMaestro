cmake_minimum_required(VERSION 3.16)
project(CppMaestro)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(include ${Boost_INCLUDE_DIRS})

set(SOURCES src/Maestro.cpp)

add_library(CppMaestro STATIC ${SOURCES})

target_link_libraries(CppMaestro ${LIBRARIES})

# For testing
enable_testing()

add_subdirectory(test)