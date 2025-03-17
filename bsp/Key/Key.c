#include "Key.h"

void Key_Init(void) {
    rcu_periph_clock_enable(BSP_KEY_RCU);
		gpio_mode_set(BSP_KEY_PORT, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, BSP_KEY_PIN);
//    if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET) // 按键按下
//    {
//        delay_ms(20);
//        if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET) // 再次检测按键是否按下
//        {
//          /*_ 执行功能 */
//            bsp_led_toggle(0); // led电平状态翻转
//            //printf("key press!\r\n");
//            while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET); // 等待按键松开
//            //printf("key release!\r\n");
//        }
//    }
}