- Docker直接启动SRS
```
docker run --rm -it -p 1935:1935 -p 1985:1985 -p 8080:8080 \
    registry.cn-hangzhou.aliyuncs.com/ossrs/srs:4 ./objs/srs -c conf/srs.conf
```

- 若需要支持WebRTC，需要设置CANDIATE，并开启UDP/8000端口
```
CANDIDATE="192.168.1.10"
docker run --rm -it -p 1935:1935 -p 1985:1985 -p 8080:8080 \
    --env CANDIDATE=$CANDIDATE -p 8000:8000/udp \
    registry.cn-hangzhou.aliyuncs.com/ossrs/srs:4 ./objs/srs -c conf/srs.conf
```
- note
```
请将CANDIDATE设置为服务器的外网地址
```

- 进入容器
```
docker ps -a | grep srs
docker exec -it containerID /bin/bash
```

- wsl启动docker服务
```
sudo service docker start
```

- 查看srs进程
```
ps -aux | grep srs
```

- ffmpeg mp4 to flv
```
ffmpeg -i source.mp4 -c:v libx264 -crf 24 destination.flv
```

- note
```
-crf是控制转码后视频的质量，质量越高，文件也就越大
此值的范围是 0 到 51：0 表示高清无损；23 是默认值（如果没有指定此参数）；51 虽然文件最小，但效果是最差的。

值越小，质量越高，但文件也越大，建议的值范围是 18 到 28。而值 18 是视觉上看起来无损或接近无损的，当然不代表是数据（技术上）的转码无损。
```

- rtmp 推流
```
ffmpeg -re -i ./doc/source.flv -c copy -f flv -y rtmp://localhost/live/livestream
```

- 播放流
```
打开下面的页面播放流（若SRS不在本机，请将localhost更换成服务器IP）

RTMP (by VLC): rtmp://localhost/live/livestream
H5(HTTP-FLV): http://localhost:8080/live/livestream.flv
H5(HLS): http://localhost:8080/live/livestream.m3u8
H5(WebRTC): webrtc://localhost/live/livestream
```
- webrtc log
```
chrome://webrtc-internals
```
- note
```
find candidate
```
- 查看主机IP
```
ifconfig eth0 | grep inet
``` 

