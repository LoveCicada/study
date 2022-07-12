#! /bin/bash

# echo "createWindows"
# g++ -o ./bin/createWindows createWindows.cpp -L/usr/local/lib -lfltk -lXext -lX11 -lm

# fltk-config --compile createWindows.cpp

# echo "controlCommunicate"
# fltk-config --compile controlCommunicate.cpp
# mv controlCommunicate ./bin

# echo "controlCommunicate2"
# fltk-config --compile controlCommunicate2.cpp
# mv controlCommunicate2 ./bin

# echo "controlCommunicate3"
# fltk-config --compile controlCommunicate3.cpp
# mv controlCommunicate3 ./bin

echo "event"
fltk-config --compile event.cpp
mv event ./bin