
### protobuf编译

- 下载
[proto-buf-github](https://github.com/protocolbuffers/protobuf/releases)
[proto-buf-cpp](https://github.com/protocolbuffers/protobuf/releases/download/v21.2/protobuf-cpp-3.21.2.zip)

- Windows编译 cmake
```bash
cd ./protobuf-cpp-3.21.2/cmake
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

# 运行protobuf.sln
```

- vcpkg
```bash
vcpkg install protobuf protobuf:x64-windows
```
- 使用zlib特性
```bash
vcpkg install protobuf[zlib] protobuf[zlib]:x64-windows
```
- 添加环境变量
```
将编译完成protoc.exe所在目录添加到系统环境变量中
D:\code\open\protobuf-cpp\protobuf-cpp-3.21.2\cmake\build\Release
```

- 查看protoc版本
```bash
protoc.exe --version
```

- 案例使用
1. 编写protobuf文件，例如msg.proto
2. 编译
```bash
# 在当前目录下新建out文件夹
protoc.exe msg.proto --cpp_out=./out
```
3. 进入demo文件夹，新建build文件，然后cmake编译
4. 编译时如果报错，可暂时把错误警告关闭，改为/W0