/**
 * @file second_one.c
 * @author your name (you@domain.com)
 * @brief 编译成动态库: gcc -fpic --shared second_one.c -o libsecond_one.so
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

void print_msg()
{
    printf("%s - %s\n", __FILE__, __func__);
}

void second()
{
    printf("%s - %s\n", __FILE__, __func__);
}