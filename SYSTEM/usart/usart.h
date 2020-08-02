#ifndef __USART_H
#define __USART_H
#include "stdio.h"
#include "stm32f4xx_conf.h"
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////

//串口1初始化
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com
//********************************************************************************
//V1.3修改说明
//支持适应不同频率下的串口波特率设置.
//加入了对printf的支持
//增加了串口接收命令功能.
//修正了printf第一个字符丢失的bug
//V1.4修改说明
//1,修改串口初始化IO的bug
//2,修改了USART_RX_STA,使得串口最大接收字节数为2的14次方
//3,增加了USART_REC_LEN,用于定义串口最大允许接收的字节数(不大于2的14次方)
//4,修改了EN_USART1_RX的使能方式
//////////////////////////////////////////////////////////////////////////////////
#define USART_REC_LEN 300 //定义最大接收字节数 200
#define EN_USART1_RX 1    //使能（1）/禁止（0）串口1接收

extern u8 USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符
extern u16 USART_RX_STA;               //接收状态标记
extern u16 USART2_RX_STA;              //接收状态标记

//usart6
#define Usart6_DMA_Len 4096 //定义DMA缓冲区长度
#define BAUD_RATE 128000
#define WATE_TIME Usart6_DMA_Len * 10000 / BAUD_RATE //串口发送Usart6_DMA_Len长度字节所需要的时间，单位：ms
void MYDMA_Enable(DMA_Stream_TypeDef *DMA_Streamx, u16 ndtr);
void uart6_init(u32 bound);
void send(u8 ch);

//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
#endif
