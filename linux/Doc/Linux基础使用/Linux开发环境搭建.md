

[TOC]

### LINUX

#### 银河麒麟操作安装，QT安装(可参考./Linux虚拟机环境搭建.md)

#### 环境变量配置

>>> Linux下修改配置文件 /etc/profile，或者~/.bash_profile 重启一定生效
 /etc/profile 文件级别比 .bash_profile 更高
注意文件名是 .bash_profile， 而不是 bash_profile

```bash
sudo vim ~/.bash_profile
```

如果不熟悉vim, 则使用vscode打开, 或者使用gedit打开编辑

```bash
export QTDIR=/Users/sobey/Qt/5.15.2/clang_64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QTDIR/lib
export PATH=$PATH:$QTDIR/bin
```

然后重启电脑电脑确保生效`sudo reboot` 
或者在当前终端生效`source ~/.bash_profile`或`source /etc/profile`

- 验证Qt是否配置成功
```bash
qmake -v
```

#### 基础环境配置

- vscode
```bash
sudo apt install code
# 验证是否安装成功
code .
```

- gcc
```bash
sudo apt install gcc
# 验证是否安装成功
gcc -v 或者 gcc --version
```

- make
```bash
sudo apt install make
# 验证是否安装成功
make -v 或者 make --version
```

- gcc/g++ C++基础开发环境搭建
```bash
sudo apt-get install build-essential
```

- cmake
```bash
sudo apt install cmake
# 验证是否安装成功
cmake -v 或者 cmake --version
```

- git
```bash
sudo apt install git
# 验证是否安装成功
git -v 或者 git --version
```

#### linux常用命令

- ldd
```bash
# 查看库的依赖情况
ldd xx.so
```

- 查看xxx.so配置的依赖库的链接路径
```bash
readelf -d libxxx.so | grep rpath
```

- gdb
```bash
# 调试启动某程序
gdb xxprocess
```

#### 代码下载

```bash
# 下载指定分支代码 -b DEV
git clone -b DEV xxx.git

# 下载默认主分支代码
git clone xxx.git

# 如果仓库有大文件, 需要检测大文件是否拉取成功
git lfs pull
```


