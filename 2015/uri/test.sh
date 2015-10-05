#!/bin/bash

g++ -O2 -std=c++11 -o cg_1908 cg_1908.cpp
g++ -O2 -std=c++11 -o 1908_2 1908_2.cpp
g++ -O2 -std=c++11 -o 1908 1908.cpp


./cg_1908 > in_1908


./1908 < in_1908 > out_1
./1908_2 < in_1908 > out_2

diff out_1 out_2

