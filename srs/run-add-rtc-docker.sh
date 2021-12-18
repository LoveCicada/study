#! /bin/bash

export CANDIDATE="172.28.184.145"
docker run --rm --env CANDIDATE=$CANDIDATE \
  -p 1935:1935 -p 8080:8080 -p 1985:1985 -p 8000:8000/udp \
  registry.cn-hangzhou.aliyuncs.com/ossrs/srs:4 \
  objs/srs -c conf/rtc.conf