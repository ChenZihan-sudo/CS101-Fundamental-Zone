#!/bin/bash

mkdir build
cd build
cmake -G "Unix Makefiles" ..
ccmake .
make
echo "Execute now: "
./template_prog