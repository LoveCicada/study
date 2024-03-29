#
# ffplay.exe -f rawvideo -pixel_format yuv422p -video_size 1920x1080 .\yuv422p.yuv

# 裁切，取到右下角
ffplay.exe -f rawvideo -pixel_format yuv422p -video_size 960x540 .\yuv422p_output.yuv

# yuv2jpg
ffmpeg -y -s 960x540 -pix_fmt yuv422p -i yuv422p_output.yuv yuv422p_output.jpg

# f1.yuv
ffplay.exe -f rawvideo -pixel_format yuv422p -video_size 1920x1080 .\f1.yuv

# f2.yuv
ffplay.exe -f rawvideo -pixel_format yuv422p -video_size 1920x1080 .\f2.yuv

# yuv2jpg
ffmpeg -y -s 1920x1080 -pix_fmt yuv422p -i f1.yuv f1.jpg
ffmpeg -y -s 1920x1080 -pix_fmt yuv422p -i f2.yuv f2.jpg