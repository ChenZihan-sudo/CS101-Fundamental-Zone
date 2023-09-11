#!/bin/bash

mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
echo "Execute now: "
./template_prog