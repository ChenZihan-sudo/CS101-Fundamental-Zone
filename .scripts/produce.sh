#!/bin/bash

mkdir build
cd build
cmake -G "Unix Makefiles" ..
# ccmake .
make
