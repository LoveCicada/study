### yuv420p学习
- `将jpg转换为yuv420p的ffmpeg命令`
```
ffmpeg -i a.jpg -s 1920*1200 -pix_fmt yuvj420p a.yuv
```

- `将jpg转换为yuyv的ffmpeg命令`
```
ffmpeg -i a.jpg -s 1920*1200 -pix_fmt yuyv422 yuyv.yuv
```

```
yuv的查看工具,网上下载的7yuv工具.
```

- `查看`
```
ffplay.exe -f rawvideo -pixel_format yuv422p -video_size 1920x1080 .\yuv422p.yuv
```

- `yuv2jpg`
```
ffmpeg -y -s 960x540 -pix_fmt yuv422p -i yuv422p_output.yuv yuv422p_output.jpg
```

- `note`
```
暂时只支持YUV422P
```
