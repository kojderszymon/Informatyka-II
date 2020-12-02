#!/bin/bash

if [ ! -d './build' ]; then
    echo `mkdir build`
fi

if [ -f "./CMakeLists.txt" ]; then
    echo `cmake -B build -G "MinGW Makefiles"`
    echo `mingw32 -make --directory=build`
    sleep 5
    exit
fi