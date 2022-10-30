

### KeyboardEventRecordTool
测试小工具
- 用于记录键盘按键中Qt记录的键盘值
```
Qt::key 
Qt::nativeScanCode 
Qt::nativeVirtualKey 
Qt::nativeModifiers 
Qt::modifiers
``` 
- 以及Windows Hook中记录的键盘值PKBDLLHOOKSTRUCT
```
p->flags 
p->dwExtraInfo 
p->scanCode 
p->vkCode 
wParam 
lParam 
```

### 工程构建
在当前目录下执行如下操作，本demo暂不添加到主工程中
```
mkdir build 
cd build 
cmake .. 
```

### 日志
1. 日志文件默认记录在当前可执行程序所在目录 
2. 日志以追加形式记录
3. 日志文件名keyevent.log