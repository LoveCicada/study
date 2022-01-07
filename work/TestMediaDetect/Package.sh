
#! /bin/bash

echo "build Debug lib"
./build.sh

echo "build Release lib"
./build-Debug.sh

echo "Package"

mkdir Package
cd Package
rm -rf ./*

echo "copy include"
cp -r ../include ./

echo "copy Debug lib"
cp -r ../Debug ./
cd Debug
rm -rf ./app
cd ..

echo "copy Release lib"
cp -r ../Release ./
cd Release
rm -rf ./app
cd ..

mkdir MediaDetect
cd MediaDetect
rm -rf ./*
cd ..
cp -r ./include ./MediaDetect
cp -r ./Release ./MediaDetect
cp -r ./Debug ./MediaDetect

LIBNAME="MediaDetect"
VERSION=`date +%Y%m%d.%H%M%S`
tar -zcvf ${LIBNAME}_${VERSION}.tar.gz ./MediaDetect

rm -rf ./include
rm -rf ./Debug
rm -rf ./Release
rm -rf ./MediaDetect

cd ../
echo "finish Package"



