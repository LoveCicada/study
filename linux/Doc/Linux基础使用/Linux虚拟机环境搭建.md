
[TOC]

### Linux虚拟机环境搭建


1. 安装VMware(VMware-workstation-full-17.0.0-20800274 (3))(xxx)

2. [选择Kylin-Desktop-V10-SP1-General-Release-2203-X86_64.iso作为Linux系统镜像](https://blog.csdn.net/weixin_52799373/article/details/124324077?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167832170116800226546076%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=167832170116800226546076&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-124324077-null-null.142^v73^control,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%AE%89%E8%A3%85&spm=1018.2226.3001.4187)

3. [下载Qt(6.4.2)在线安装包](https://mirrors.tuna.tsinghua.edu.cn/qt/archive/online_installers/4.5/Qt)

4. 终端切换到Qt在线安装包下载目录，运行命令(安装时间很长，为避免黑屏把麒麟系统的电源设置修改为从不关闭显示器和从不睡眠)

./qt-unified-linux-x64-4.5.1-online.run --mirror https://mirrors.tuna.tsinghua.edu.cn/qt，如果使用这个镜像安装慢可以换一个

./qt-unified-linux-x64-4.5.1-online.run --mirror http://mirrors.neusoft.edu.cn/qt/

5. 参考Linux开发环境搭建，进行vscode，gcc，make，cmake，git，git-lfs 的安装

6. 环境变量配置
```bash
sudo vim /etc/profile
按i进入插入模式：
添加下列路径：
export QTDIR=/home/xiangjunchen/Qt/6.4.2/gcc_64
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QTDIR/lib
export PATH=$PATH:$QTDIR/bin
export QTDIR LD_LIBRARY_PATH
esc退出编辑模式
;wq！ 保存退出
```

7. 如果基础Qt QWidget示例无法编过，尝试手动安装OpenGL
```bash
1. *sudo a*pt install libglx-dev
2. *sudo a*pt install libgl1-mesa-dev
```  