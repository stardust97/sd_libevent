cmake_minimum_required(VERSION 3.10)

project(test VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_definitions("-Wall -g")

find_package(log4cxx)

include_directories(
  $<TARGET_PROPERTY:log4cxx,INTERFACE_INCLUDE_DIRECTORIES>
  ${PROJECT_SOURCE_DIR}/../build/output/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/../build/output/lib
)

add_subdirectory(${PROJECT_SOURCE_DIR}/service)
add_subdirectory(${PROJECT_SOURCE_DIR}/client)