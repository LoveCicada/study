### windbg 调试

### `windbg调试进程`
####  添加pdb路径
![添加pdb路径](./img/add_pdb_path.png)

#### 添加程序源码路径
![添加程序源码](./img/add_source_path.png)

#### attach程序
![attach程序](./img/attach_exe.png)
![attach程序](./img/attach_exe_pid.png)

#### 设置断点
![设置断点](./img/set_breakpoint.png)

#### 程序往下执行
![attach程序](./img/run_exe.png)

#### 程序中断
![attach程序](./img/block_exe.png)

#### detach程序
![attach程序](./img/detach_exe.png)

#### 查看加载/未加载的dll
```
lm
```
![attach程序](./img/lm.png)

#### 查看指定dll加载情况
```
lmvm CXETimelinePef
lmvm命令可以查看任意一个已加载的DLL/EXE的详细信息，以及symbol的情况, 
特别提醒的是，不要加后缀名（无论EXE/DLL）
```
![attach程序](./img/lmvm.png)