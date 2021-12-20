
- gdb调试
```
Linux下gdb调试（tui）
https://www.cnblogs.com/wuchanming/p/4494141.html
```
- Linux中用gdb 查看代码堆栈的信息
```
https://www.cnblogs.com/chengliangsheng/p/3597010.html
```


- 代码与调试分为上下两个窗口
```
 gdb ./bin/jmp_2flow -tui
```

- 执行程序
```
run
```

- 退出程序
```
q
```

- 设置断点
```
1. 设置行号
break 30
2. 设置函数
break main()
break thread0_functions()
break thread1_functions()

```

- 单步调试
```
next
```

- 恢复操作
```
continue
```

- 临时断点（一次性）
```
tbreak
```

- 检查变量
```
print j
```

- 在GDB中设置监视点以应对变量值的改变
```
watch z
```

- 基于条件表达式来设置监视点
```
watch (z>28)
```

- 上下移动栈
```
在函数调用期间，与调用关联的运行时信息存储在称为栈帧的内存区域中。帧中包含函数的局部变量的值、其形参，以及调用该函数的记录。每次发生函数调用时，都会创建一个新帧，并将其推导一个系统维护的栈上；栈最上方的帧表示当前正在执行的函数，当函数退出时，这个帧被弹出栈，并且被释放。

在GDB中可用用如下命令查看以前的帧：

(gdb) frame 1

当执行GDB的frame命令时，当前正在执行的函数的帧被编号为0，其父帧（即该函数的调用者的栈帧）被编号为1，父帧的父帧被编号为2，以此类推。GDB的up命令将你带到调用栈中的下一个父帧（例如，从帧0到帧1），down则引向相反方向。

显示整个栈：backtrace

浏览以前的GDB命令：上一个Ctrl+P、下一个Ctrl+N
```

- 查看断点列表
```
info breaks
```

- 删除断点
```
delete 1 2 3
此处1 2 3代表断点编号
```

- 在某个文件中某行设置断点
```
break filename:line_number
```

- 在某个文件中某函数设置断点
```
break filename:function
```

- 禁用某个断点
```
disable 3
```

- 启用某个断点
```
enable 3
```

- 打印当前的函数调用栈的所有信息
```
bt

bt n
n是一个正整数，表示只打印栈顶上n层的栈信息
反之亦然

```

- 切换当前栈
```
frame
f
n是一个从0开始的整数，是栈中的层编号。比如：frame 0，表示栈顶，frame 1，表示栈的第二层。

up
表示向栈的上面移动n层，可以不打n，表示向上移动一层。

down
表示向栈的下面移动n层，可以不打n，表示向下移动一层。
```

- 查看当前栈层的信息
```
frame
f
```

- 查看当前栈层的详细信息
```
info frame
info f
```

- 打印当前函数中的参数名量及其值
```
info agrs
```

- 打印当前函数中的所有局部变量及其值
```
info locals
```

- 打印当前函数中的异常处理信息
```
info catch
```

