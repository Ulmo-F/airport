# airport

# Compile : Linux + cmake
(checked with gcc 11)

mkdir build && cd build

cmake ..

make

[ctest]

# Compile : MSVC
TODO

# Usage
./build/airport data/sample1.txt 2

Second parameter is for algorithm selection. 
- '1' Gives best solution - but not always valid
- '2' Gives a valid solution, but not always the best one
- '3' Gives the best valid solution, but is not implemented
