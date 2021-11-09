echo "cd build/"
cd build
echo "delete old files"
rm -rf ./*
echo "cmake"
cmake -G "MinGW Makefiles" ..
echo "make"
make
./HelloCmake.exe