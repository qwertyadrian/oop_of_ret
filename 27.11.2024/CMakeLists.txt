cmake_minimum_required(VERSION 3.28)
project(27_11_2024)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h )

#foreach( sourcefile ${APP_SOURCES} )
#    file( RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR} ${sourcefile} )
#    string( REPLACE ".cpp" "" file ${filename} )
#    string( CONCAT file ${PROJECT_NAME}_ ${file} )
#    add_executable( ${file} ${sourcefile} )
#    install(TARGETS ${file})
#endforeach( sourcefile ${APP_SOURCES} )

add_executable( 27_11_2024_main ${APP_SOURCES} )