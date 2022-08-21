

### KeyboardEventRecordTool
测试小工具，用于记录键盘按键中Qt记录的键盘值
Qt::key
Qt::nativeScanCode
Qt::nativeVirtualKey
Qt::nativeModifiers
Qt::modifiers
以及Windows Hook中记录的键盘值PKBDLLHOOKSTRUCT
p->flags
p->dwExtraInfo
p->scanCode
p->vkCode
wParam
lParam

### 工程构建
mkdir build
cd build
cmake ..

### 日志
日志文件默认记录在当前可执行程序所在目录
日志以追加形式记录