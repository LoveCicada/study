
#pragma once

//内核空间
//#include <linux/ioctl.h>

// 用户空间
#include <sys/ioctl.h>

/**
 * @brief 定义设备类型
 * 
 */
#define IOC_MAGIC 'c'

/**
 * @brief 初始化设备
 * 
 */
#define IOCINIT _IO(IOC_MAGIC,0)

/**
 * @brief 读寄存器
 * 
 */
#define IOCGREG _IOR(IOC_MAGINC, 1, int)

/**
 * @brief 写寄存器
 * 
 */
#define IOCWREG _IOW(IOC_MAGIC, 2, int)

#define IOC_MAXNR 3

struct msg
{
    int addr;
    unsigned int data;
};


