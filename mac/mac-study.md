
### mac study

- 在macOS上打印可执行文件的rpath
```bash
otool -l myexecutable | grep RPATH -A2
```

- 使用macOS打印共享库的安装名称
```bash
otool -D mylib

```

- 打印依赖库
```bash
otool -l <my executable>
```

***

- doc

[03-什么是Mach-O文件？](https://blog.csdn.net/ldszw/article/details/111137442)

[深入浅出@executable_path @loader_path @rpath](http://events.jianshu.io/p/be014d4c28c8)

[Mac下程序依赖库路径查看及修改](https://www.cnblogs.com/chyshx/p/13254342.html)

[Mac添加环境变量的三种方法](https://www.cnblogs.com/androidsj/p/5977511.html)

[MAC下的环境变量设置](https://blog.csdn.net/axiaofeijia/article/details/124900498)

[Mac下使用macdeployqt打包qt程序](https://blog.csdn.net/blqzj214817/article/details/122828414)

***


