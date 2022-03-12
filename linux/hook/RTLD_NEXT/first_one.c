/**
 * @file first_one.c
 * @author your name (you@domain.com)
 * @brief 编译成动态库: gcc -fpic --shared first_one.c -o libfirst_one.so
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

void first()
{
    printf("%s - %s\n", __FILE__, __func__);
}