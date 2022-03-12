#! /bin/bash

echo "libfirst_one.so"
gcc -fpic --shared first_one.c -o libfirst_one.so

echo "libsecond_one.so"
gcc -fpic --shared second_one.c -o libsecond_one.so

echo "libwrap.so"
gcc -fpic --shared wrap.c -o libwrap.so

echo "gcc -c main.c"
gcc -c main.c

echo "link libfirst_one.so"
gcc -o first main.o -lwrap -lfirst_one -lsecond_one -ldl -L.

# echo "link libsecond_one.so"
# gcc -o first main.o -lwrap -lsecond_one -lfirst_one -ldl -L.

echo "mv result to bin"
mv libfirst_one.so libsecond_one.so libwrap.so main.o first ./bin/

