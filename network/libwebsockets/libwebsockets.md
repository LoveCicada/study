
### Windows编译libwebsockets
1. 安装vcpkg
2. 在vcpkg目录下打开powershell
执行如下命令
```bash
.\vcpkg.exe install libwebsockets:x64-windows
```
3. 编译文件生成在目录./vcpkg/packages/libwebsockets_x64-windows
4. 参考demo程序cmakelists.txt
5. 运行时，讲dll目录下的库拷贝到client/server程序路径下