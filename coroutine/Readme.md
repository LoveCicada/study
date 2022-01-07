- setjmp and longjmp
- 函数原型
```
#include <setjmp.h>
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);
```

- setjmp
```
setjmp 函数的功能是将函数在此处的上下文保存在 jmp_buf 结构体中，以供 longjmp 从此结构体中恢复。
参数 env 即为保存上下文的 jmp_buf 结构体变量；
如果直接调用该函数，返回值为 0； 若该函数从 longjmp 调用返回，返回值为非零，由 longjmp 函数提供。根据函数的返回值，我们就可以知道 setjmp 函数调用是第一次直接调用，还是由其它地方跳转过来的。
```

- longjmp
```
longjmp 函数的功能是从 jmp_buf 结构体中恢复由 setjmp 函数保存的上下文，该函数不返回，而是从 setjmp 函数中返回。

参数 env 是由 setjmp 函数保存过的上下文。
参数 val 表示从 longjmp 函数传递给 setjmp 函数的返回值，如果 val 值为0， setjmp 将会返回1，否则返回 val。
longjmp 不直接返回，而是从 setjmp 函数中返回，longjmp 执行完之后，程序就像刚从 setjmp 函数返回一样。
```