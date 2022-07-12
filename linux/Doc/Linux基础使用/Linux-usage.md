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

### ubuntu18.04新系统开发环境配置
```bash
# 添加用户到sudo用户列表中
su -
vim /etc/sudooers

# 1. 先cd到/etc/sudoers目录下
# 2. 由于sudoers文件为只读权限，所以需要添加写入权限，chmod u+w sudoers
# 3. vim sudoers
# 4. 找到root ALL = (ALL) ALL这一行，在下一行加入username ALL = (ALL) ALL。
#     username指代你想加入sudo组的用户名。
# 5. 把sudoers文件的权限修改回来。chmod u-w sudoers
# 6. 这样普通用户可以执行sudo命令了。

# tab命令无法补全
cat /etc/passwd
# 将/bin/sh  改为/bin/bash

# 安装git
sudo apt-get install git

# 安装ssh
sudo apt-get install openssh-client
sudo apt-get install openssh-server

#启动ssh
sudo service ssh start

# C/C++
sudo apt-get install build-essential

# 修复版本编译冲突
sudo apt-get install --reinstall pkg-config cmake-data


```