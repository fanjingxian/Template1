#include "board.h"

int main(void)
{
    board_init();
		bsp_led_init();
    OLED_Init();         //初始化OLED
    Key_Init();
    while (1)
    {
//			bsp_led_toggle(0);
//			delay_ms(50);

			OLED_ShowString(0,0,"ABC",8,1);//6*8 “ABC”
			OLED_ShowString(0,8,"ABC",12,1);//6*12 “ABC”
			OLED_ShowString(0,20,"ABC",16,1);//8*16 “ABC”
			OLED_ShowString(0,36,"ABC",24,1);//12*24 “ABC”
			OLED_Refresh();
    // 

    }
}


