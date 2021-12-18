#!/bin/bash

# ffmpeg -re -i ./video/test.flv -c copy -f flv -y rtmp://localhost/live/livestream

ffmpeg -re -i ./video/mst.flv -c copy -f flv -y rtmp://localhost/live/livestream
