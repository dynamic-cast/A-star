cmake_minimum_required(VERSION 3.10)
project(graphs)

add_definitions(-std=c++17)

set(GRAPHS_VERSION_MAJOR 0)
set(GRAPHS_VERSION_MINOR 1)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_INSTALL_PREFIX ../install)

set(graph_src ${PROJECT_SOURCE_DIR}/Graph.cpp
              ${PROJECT_SOURCE_DIR}/main.cpp
   )

add_executable(graphs ${graph_src})
