cmake_minimum_required( VERSION 3.0.0 )

project( LAB6 )

include_directories( ./include ./src )

add_executable( main ./src/main.cpp ./src/employee.cpp ./src/hrms.cpp )