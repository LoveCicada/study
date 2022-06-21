
### windows常用命令
-`查找所有运行的端口`
```
netstat -ano
```
-`查看被占用端口对应的 PID`
```
netstat -aon|findstr "8081"
```

-`查看指定 PID 的进程`
```
tasklist|findstr "9088"
```

-`结束进程`
```
taskkill /T /F /PID 9088 
```

- `WSL2启动关闭`
```
管理员权限运行powershell
net stop LxssManager
net start LxssManager
```