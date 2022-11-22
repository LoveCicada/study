

### 国产麒麟系统运行docker


#### 麒麟系统部署docker环境

##### 1.docker安装
[国产中标麒麟系统-docker安装](https://blog.csdn.net/qq_42511550/article/details/119188889)


##### 2.开启binfmt_misc来运行非本地架构的Docker镜像
```bash
docker run --privileged --rm tonistiigi/binfmt --install all
```

***

#### 非ARM架构生成linux/arm docker镜像

##### 1.Docker构建器切换为多架构构建器
[构建多架构镜像的最佳实践](https://xcbeyond.cn/blog/containers/build-multi-platform-images-best-practices/)

##### 2.构建多架构镜像
```bash
docker buildx build -t <image-name> --platform=linux/arm64,linux/amd64 .
```


#### 测试
```bash
docker pull xcbeyond/multi-arch-test:latest
```

```bash
docker pull lovecicada/multi-arch-test:latest
```