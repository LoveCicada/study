#! /bin/bash

# export CANDIDATE=$(ifconfig eth0 inet| grep 'inet '|awk '{print $2}')

export CANDIDATE=$(ifconfig eth0 | grep 'inet' | awk 'NR==1 {print $2}') 
# export CANDIDATE=172.28.185.65
docker run --rm --env CANDIDATE=$CANDIDATE \
  -p 1935:1935 -p 8080:8080 -p 1985:1985 -p 8000:8000/udp \
  registry.cn-hangzhou.aliyuncs.com/ossrs/srs:4 \
  objs/srs -c conf/docker.conf
  