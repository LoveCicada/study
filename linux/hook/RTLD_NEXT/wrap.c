/**
 * @file wrap.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define _GNU_SOURCE // in order to use RTLD_NEXT

#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>

/**
 * @brief 注：void load_func() __attribute__((constructor))的含义是在执行main函数前，
 * 执行load_func这个函数，便于我们做一些准备工作。
 * 作用是触发dlsym以实现查找第一个"print_msg"函数符号的目的。
 * 
 */

void (*f)();
void load_func() __attribute__((constructor));
void load_func()
{
    f = ( void(*)())dlsym(RTLD_NEXT, "print_msg");
    char* error_str = dlerror();
    if(NULL != error_str){
        printf("%s\n", error_str);
    }
    printf("load func first f=%p\n", f);
}

void print_msg()
{
    printf("the wrap lib...\n");
    f();
}