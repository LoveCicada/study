#! /bin/bash

qmake -o MakeFile.useQstyle ./useQstyle.pro CONFIG+=release CONFIG+=force_debug_info
make -f MakeFile.useQstyle -j4


