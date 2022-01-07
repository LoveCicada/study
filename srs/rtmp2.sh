#!/bin/bash

# ffmpeg -re -i ./video/test.flv -c copy -f flv -y rtmp://localhost/live/livestream

# ffmpeg -re -i ./video/mst.flv -c copy -f flv -y rtmp://localhost/live/livestream

# localhost=$(ifconfig eth0 inet| grep 'inet '|awk '{print $2}')
# echo ${localhost}
ffmpeg -re -i ./video/mst.flv -c copy -f flv -y rtmp://172.28.178.69/live/livestream
