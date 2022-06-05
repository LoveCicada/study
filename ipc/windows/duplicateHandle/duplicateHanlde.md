### DuplicateHandle的应用

>假设一个进程拥有对一个文件映射对象的读写权限，在程序中的某个位置，我们要调用一个函数，并希望它对文件映射对象进行只读访问。为了使应用程序变得更健壮，可以使用DuplicateHandle为现有的对象创建一个新句柄，并确保这个新句柄有只读权限。然后，把这个只读句柄传给函数。采取这种方式，函数中的代码绝对不会对文件映射对象执行意外的写入操作。


```C++
int WINAPI _tWinMain(HINSTANCE hInstExe, HINSTANCE, LPTSTR szCmdLine, int nCmdShow)
{
    //Create a file-mapping object;the handle has read/write access. 
    HANDLE hFileMapRW=CreateFileMapping(INVALID_HANDLE_VALUE, NULL,     PAGE_READWRITE, 0, 10240, NULL);
    //Create another handle to the file-mapping object;the handle   has read-only access.  
    HANDLE hFileMapRO;  
    DuplicateHandle(GetCurrentProcess(), hFileMapRW,    GetCurrentProcess(), &hFileMapRO, FILE_MAP_READ, FALSE,0);
    //Call the function that should only read from the file mapping. 
    ReadFromTheFileMapping(hFileMapRO);
    //Close the read-only file-mapping object.  
    CloseHandle(hFileMapRO); 
    ... 
    CloseHandle(hFileMapRW);
}
```

> 内存映射文件是由一个文件到进程地址空间的映射。使用内存映射文件处理存储于磁盘上的文件时，将不必再对文件执行I/O操作，使得内存映射文件在处理大数据量的文件时能起到相当重要的作用。Win32系统允许多个进程（运行在同一计算机上）使用内存映射文件来共享数据。这种函数最适用于需要读取文件并且对文件内包含的信息做语法分析的应用程序，如：对输入文件进行语法分析的彩色语法编辑器，编译器等。映射文件的另一个重要应用就是用来支持永久命名的共享内存。要在两个应用程序之间共享内存，可以在一个应用程序中创建一个文件并映射之，然后另一个应用程序可以通过打开和映射此文件把它作为共享的内存来使用。

