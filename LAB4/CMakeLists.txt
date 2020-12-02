cmake_minimum_required( VERSION 3.0 )

project( LAB4 )

include_directories( ./include ./src )

add_executable( output ./src/main.cpp ./src/matrix.cpp )