
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

- 查看YUV数据
```
ffplay -f rawvideo -pixel_format yuv422p10le -video_size 3840x2160 .\spilt.yuv
yuv422p10le：颜色空间
```

- YUV转jpg
```
ffmpeg -y -s 3840x2160 -pix_fmt yuv420p -i cudaAfter.yuv image.jpg
```

- jpg转YUV
```
ffmpeg.exe -i .\bk.jpg -pix_fmt yuvj420p bk.yuv
```

- FFMPEG JPG转YUV命令
```
jpg转nv21
ffmpeg -i image_1920x1080.jpg -pix_fmt nv21 image_1920x1080.nv21.yuv
jpg转bgr24
ffmpeg -i image_1920x1080.jpg -pix_fmt bgr24 image_1920x1080.bgr24.rgb
jpg转bgr32
ffmpeg -i image_1920x1080.jpg -pix_fmt bgr32 image_1920x1080.bgr32.rgb
nv21转jpg
ffmpeg -y -s 1920x1080 -pix_fmt nv21 -i image.nv21.yuv image.jpg
```

- 截取视频并保存为图片
```
ffmpeg -i luna_test-audio.mp4 -r 25 -ss 00:00:00 -t 00:00:05 %03d.jpg

ffmpeg -i luna_test-audio.mp4 -r 25 -ss 00:00:00 -t 00:00:05 %03d.ppm
参数讲解：-i后为视频位置， -r后为帧率， -ss开始时间， -t结束时间，%03d为自动添加名称

```

- 查看YUV数据
```
# 1inputTransSrcYUV input transformer YUV Y
ffmpeg -y -s 1920x54 -pix_fmt gray -i 1inputTransSrcYUV.yuv 1inputTransSrcYUV.jpg

# inputSrcYUV YUV
ffmpeg -y -s 1920x54 -pix_fmt gray -i 1inputSrcYUV.yuv 1inputSrcYUV.jpg

# inputDstRGB10BE YUV
ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 1inputDstRGB10BE.yuv 1inputDstRGB10BE.jpg

```

- 当前重复帧有发现在 第一次 cuda 变换中
```
ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 56inputDstRGB10BE.yuv 56inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 57inputDstRGB10BE.yuv 57inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 58inputDstRGB10BE.yuv 58inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 59inputDstRGB10BE.yuv 59inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 60inputDstRGB10BE.yuv 60inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 61inputDstRGB10BE.yuv 61inputDstRGB10BE.jpg

```


```
输入数据
# YUV -> RGB10BE dst data

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 56inputDstRGB10BE.yuv 56inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 57inputDstRGB10BE.yuv 57inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 58inputDstRGB10BE.yuv 58inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 59inputDstRGB10BE.yuv 59inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 60inputDstRGB10BE.yuv 60inputDstRGB10BE.jpg

ffmpeg -y -s 1920x54 -pix_fmt rgb48le -i 61inputDstRGB10BE.yuv 61inputDstRGB10BE.jpg


# 超分回调
ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 58sisrCopyCbRGB10BE.yuv 58sisrCopyCbRGB10BE.jpg

ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 115sisrCopyCbRGB10BE.yuv 115sisrCopyCbRGB10BE.jpg

ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 116sisrCopyCbRGB10BE.yuv 116sisrCopyCbRGB10BE.jpg

ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 117sisrCopyCbRGB10BE.yuv 117sisrCopyCbRGB10BE.jpg

ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 118sisrCopyCbRGB10BE.yuv 118sisrCopyCbRGB10BE.jpg

ffmpeg -y -s 3840x216 -pix_fmt rgb48le -i 119sisrCopyCbRGB10BE.yuv 119sisrCopyCbRGB10BE.jpg

```

- `4K转8K`
```
#1257
# 1inputTransSrcYUV input transformer YUV Y
ffmpeg.exe -y -s 3840x108 -pix_fmt gray -i 1257inputTransSrcYUV.yuv 1257inputTransSrcYUV.jpg

# inputSrcYUV YUV
ffmpeg.exe -y -s 3840x108 -pix_fmt gray -i 1257inputSrcYUV.yuv 1257inputSrcYUV.jpg

# inputDstRGB10BE YUV
ffmpeg.exe -y -s 3840x54 -pix_fmt rgb48le -i 1257inputDstRGB10BE.yuv 1257inputDstRGB10BE.jpg

# inputDstRGB10BE YUV
ffmpeg.exe -y -s 7680x108 -pix_fmt rgb48le -i 1257sisrCopyCbRGB10BE.yuv 1257sisrCopyCbRGB10BE.jpg


# 1257sisrCopyCbRGB10BESrcCb
ffmpeg.exe -y -s 7680x108 -pix_fmt rgb48le -i 1257sisrCopyCbRGB10BESrcCb.yuv 1257sisrCopyCbRGB10BESrcCb.jpg

```

- `叠加水印`
```
ffmpeg.exe -i .\input.mp4 -vf "movie=1.svg.png,scale=130:130[watermask];[in][watermask] overlay=300:300[out]" -y out.mp4

```

- `水印`
```
movie=logo.png,scale=60:30[watermask];[in] [watermask] overlay=30:10 [out]

参数说明：

logo.png: 添加的水印图片；

scale：水印大小，水印长度＊水印的高度；

overlay：水印的位置，距离原视频左侧的距离：距离原视频上侧的距离；mainW主视频宽度， mainH主视频高度，overlayW水印宽度，overlayH水印高度

左上角overlay参数为 overlay=0:0

右上角为 overlay= main_w-overlay_w:0

右下角为 overlay= main_w-overlay_w:main_h-overlay_h

左下角为 overlay=0: main_h-overlay_h

```












