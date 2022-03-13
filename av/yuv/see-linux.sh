#! /bin/bash

echo "yuv2jpg"
ffmpeg -y -s 960x540 -pix_fmt yuv422p -i yuv422p_output.yuv yuv422p_output.jpg

