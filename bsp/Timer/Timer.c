#include "Timer.h"
/*
    APB1总线(Fmax = 60Mhz): TIM1, TIM2, TIM3, TIM4, TIM5, TIM6, TIM11, TIM12, TIM13
    APB2总线(Fmax =120Mhz): TIM0, TIM7, TIM8, TIM9, TIM10
    General timer(16-bit): (2-3,8-13)
    General timer(32-bit): (1,4)
    Advanced timer(16-bit):(0,7)
    Basic timer(16-bit):   (5,6)
*/

void Timer_init(void){
    /* 开启时钟 */
    rcu_periph_clock_enable(BSP_TIMER5_RCU);                // 开启定时器时钟
    /* CK_TIMERx = 4 x CK_APB1  = 4x60M = 240MHZ */
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);   // 配置定时器时钟
    timer_deinit(BSP_TIMER5);                               // 复位定时器5
    
    /* 配置定时器参数 */
    timer_parameter_struct timer_initpara;                  // 定义定时器结构体
    timer_initpara.prescaler = Pre_tim5 -1;                 //  时钟预分频值 0-65535  psc_clk = CK_TIMER / pre
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;        // 边缘对齐
    timer_initpara.counterdirection = TIMER_COUNTER_UP;     // 向上计数
    timer_initpara.period = Per_tim5  - 1;                  // 周期
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;        // 分频因子
    /* 只有高级定时器才有 配置为x，就重复x+1次进入中断 */
    timer_initpara.repetitioncounter = 0;                   // 重复计数器 0-255
    timer_init(BSP_TIMER5,&timer_initpara);                 // 初始化定时器
    
    nvic_irq_enable(BSP_TIMER5_IRQ,3,2);                    // 设置中断优先级为 3,响应优先级为 2
    /* 使能中断 */
    timer_interrupt_enable(BSP_TIMER5,TIMER_INT_UP);        // 使能更新事件中断
    timer_enable(BSP_TIMER5);
}

void BSP_TIMER5_IRQHandler(void) {
    /* 这里是定时器中断 */
    if(timer_interrupt_flag_get(BSP_TIMER5,TIMER_INT_FLAG_UP) == SET)
    {
        timer_interrupt_flag_clear(BSP_TIMER5,TIMER_INT_FLAG_UP); // 清除中断标志位
        /* 执行操作 */
        bsp_led_toggle(0);// 翻转led
    }

}

