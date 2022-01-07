#! /bin/bash

# ffmpeg -i test.mp4 -c:v libx264 -crf 24 test.flv

ffmpeg -i mst.mp4 -c:v libx264 -crf 0 mst.flv

