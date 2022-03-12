#! /bin/bash

cd ./bin/
echo "export lib path"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
echo $LD_LIBRARY_PATH

echo "ldd first"
ldd first

echo "run first"
echo "------------------->"
./first
echo "<-------------------"
cd ..

# cd ./bin/
# echo "ldd second"
# ldd second

# echo "run second"
# echo "------------------->"
# ./second
# echo "<-------------------"
# cd ..