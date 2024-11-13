cmake_minimum_required(VERSION 3.28)
project(29_10_2024)

set(CMAKE_CXX_STANDARD 17)

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h )

add_executable( 29_10_2024_task1 ${APP_SOURCES} )