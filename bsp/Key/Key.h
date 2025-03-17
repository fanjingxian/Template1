#ifndef __KEY_H__
#define __KEY_H__
#include "board.h"


/* 定义key的引脚 */
#define BSP_KEY_RCU         RCU_GPIOA
#define BSP_KEY_PORT        GPIOA
#define BSP_KEY_PIN         GPIO_PIN_0

void Key_Init(void);

#endif // !__KEY_H__