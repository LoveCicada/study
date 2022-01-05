
- media detect library
```
use for luna and mpc, maybe nonlinear
```

- Linux
```

```

- Windows
```

```

- error code
```
if interface return code greater than 0, it will be fail.
only return 0 is success
```
- 
```
Success = 0,    
InitLibraryFail = 1,

```

- depends sdk library
```
libVXCutlistV2Plus.so
we can target at cmakelists.txt,
actually is implicit link
```
- info
```
1. file detail
2. video detail
3. audio detail
4. system stream detail
5. data stream detail
```

- lib doc struct
```
├── Debug
├── MediaDetect
│   └── src
├── Release
├── app
├── build
├── include
│   ├── linux
│   ├── nle
│   │   └── LinuxTTMedia
│   │       ├── File
│   │       ├── helper
│   │       └── plugin
│   └── windows
└── lib
```

- description
```
1. use linux sdk to get file media info
```

- how to build Release
```
run build.sh
or
mkdir build
cd build
cmake ..
make
```

- how to build Debug
```
run build.sh
or
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
```

- how to test
```
cd app

```

- how to use
```

```

- interface
```
// SDK style
virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) = 0;
virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) = 0;

virtual int ConvertToNovaInfo() = 0;
// Nova style
virtual int ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo) = 0;
virtual int ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2) = 0;
```
- find lib export function
```
nm -D libCXEMediaDetect.so | grep CreateMediaDetect

result:0000000000013d60 T CreateMediaDetect
```
- find lib depend
```
ldd libCXEMediaDetect.so 
```