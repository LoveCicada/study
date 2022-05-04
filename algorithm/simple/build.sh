#! /bin/bash

echo "fibonacci"
g++ -o ./bin/fibonacci fibonacci.cpp -g -O0

echo "fibonacci2"
g++ -o ./bin/fibonacci2 fibonacci2.cpp -g -O0

echo "recordLetter"
g++ -o ./bin/recordLetter recordLetter.cpp -g -O0

echo "removeElement"
g++ -o ./bin/removeElement removeElement.cpp -g -O0

echo "minSubArrayLen"
g++ -o ./bin/minSubArrayLen minSubArrayLen.cpp -g -O0

echo "generateMatrix"
g++ -o ./bin/generateMatrix generateMatrix.cpp -g -O0

echo "removeElements_list"
g++ -o ./bin/removeElements_list removeElements_list.cpp -g -O0