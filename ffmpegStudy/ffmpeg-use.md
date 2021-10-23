
### ffmpeg 安装
```
1. 从ffmpeg官网下载
http://ffmpeg.org/download.html

Ubuntu环境下，可通过sudo apt install命令安装
```
```
2. Windows下添加环境变量
解压官网下载的压缩文件，将ffmpeg程序所在的bin目录添加到环境变量中

例如：D:\ffmpeg\ffmpeg\bin
```

```
3. 验证ffmpeg是否安装成功
在cmd程序中，执行：ffmpeg -v
如果有输出关于ffmpeg的信息，则代表ffmpeg安装成功
```

### ffmpeg 常见使用

```
查看支持的编解码器（也就是-vcodec后面可以接的参数）:
ffmpeg -codecs > codec.txt

查看支持的封装格式（也就是-f后面可以接的参数）
ffmpeg -formats > formats.txt

查看支持的滤镜（也就是-vf后面可以接的参数）:
ffmpeg -filters > filters.txt
```

```
查看YUV数据
ffplay -f rawvideo -pixel_format yuv422p10le -video_size 3840x2160 .\spilt.yuv
yuv422p10le：颜色空间
```

```
YUV转jpg
ffmpeg -y -s 3840x2160 -pix_fmt yuv420p -i cudaAfter.yuv image.jpg
```

```
截取视频并保存为图片
ffmpeg -i luna_test-audio.mp4 -r 25 -ss 00:00:00 -t 00:00:05 %03d.jpg

ffmpeg -i luna_test-audio.mp4 -r 25 -ss 00:00:00 -t 00:00:05 %03d.ppm
参数讲解：-i后为视频位置， -r后为帧率， -ss开始时间， -t结束时间，%03d为自动添加名称

```















