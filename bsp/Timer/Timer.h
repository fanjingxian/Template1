#ifndef __TIMER_H__
#define __TIMER_H__

#include "board.h"

#define BSP_TIMER5_IRQHandler TIMER5_DAC_IRQHandler // 定时器中断服务函数;
#define  BSP_TIMER5_RCU     RCU_TIMER5  // 定时器5时钟
#define  BSP_TIMER5         TIMER5      // 定时器
#define  BSP_TIMER5_IRQ     TIMER5_DAC_IRQn   // 定时器中断
#define  Pre_tim5           24000       
#define  Per_tim5           10000       
/* 定时时间为：time = pre / 240 000 000 * per  = 24000 / 240 000 000 * 10000 = 1s */

void Timer_init(void);

#endif // !__TIMER_H__

