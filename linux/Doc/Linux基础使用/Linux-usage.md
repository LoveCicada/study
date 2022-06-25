### Linux基础使用

- `查看ip`
```
ip addr
```

- `查看网关`
```
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         172.16.172.1    0.0.0.0         UG    100    0        0 ens16f0
172.16.172.0    0.0.0.0         255.255.255.0   U     0      0        0 ens16f0
172.16.172.1    0.0.0.0         255.255.255.255 UH    100    0        0 ens16f0
```

- `查看ip`
```
ip addr
```

- `查看DNS`
```
systemd-resolve --status

DNS Servers: 172.17.0.184
             192.168.252.3
             192.168.252.4
             202.98.96.68
             61.139.2.69
             218.6.200.139
```

- `配置静态IP`
```
network:
  version: 2
  #renderer: NetworkManager
  ethernets:
     enp3s0: #配置的网卡名称,使用ifconfig -a查看得到
       dhcp4: no #dhcp4关闭
       addresses: [172.16.172.51//24] #设置本机IP及掩码
       gateway4: 172.16.172.1 #设置网关
       nameservers:
         addresses: [172.17.0.184] #设置DNS
```

- `account`
```
root/sobeyhive
```

- `查看主机名`
```
hostname
```

- `切换root`
```
su root
```

- `登录root用户时，提示Access denied`
```
sudo gedit /etc/ssh/sshd_config
将如下
#PermitRootLogin prohibit-password
改为
PermitRootLogin yes

重启ssh
sudo /etc/init.d/ssh restart
```

- `ubuntu20.4更换国内镜像源`
cd /etc/apt
sudo mv sources.list sources.list.bac 
sudo vim sources.list

sudo apt update
sudo apt upgrade

```bash
#-----------------------------清华源-------------------------------------
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse
```

***
### Ubuntu20.04 新系统远程环境搭建 
- SSH
```bash
#!/bin/bash

#安装ssh客户端和服务端
sudo apt-get install openssh-client
sudo apt-get install openssh-server

#启动ssh
sudo service ssh start

#查看ssh状态
ps -e | grep ssh
pa -aux | grep ssh

#查看本机
ipifconfig

#ssh连接
ssh name@ip -22
```

[在Ubuntu 20.04服务器上安装TigerVNC并配置VNC的详细步骤](https://ywnz.com/linuxyffq/8969.html)

[搭建 Ubuntu 可视化界面-腾讯云服务器官方文档](https://cloud.tencent.com/document/product/213/46001#null)
- VNC
```bash

```

***