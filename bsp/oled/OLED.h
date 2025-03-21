#ifndef __OLED_H
#define __OLED_H 

#include "board.h"
#include "stdlib.h"	

#define IIC_Mode 1 //IIC模式 1-硬件IIC 0-软件IIC

#ifdef IIC_Mode
//-----------------OLED端口定义---硬件IIC---------------- 
#define RCU_LCD_SCL     RCU_GPIOB//SCL
#define PORT_LCD_SCL    GPIOB
#define GPIO_LCD_SCL    GPIO_PIN_6

#define RCU_LCD_SDA     RCU_GPIOB//SDA
#define PORT_LCD_SDA    GPIOB
#define GPIO_LCD_SDA    GPIO_PIN_7

#define I2C_TIME_OUT         50000
#define I2C_SPEED            400000
#define I2CX_SLAVE_ADDRESS7  0x78
#define I2CX                 I2C0
#define RCU_I2CX             RCU_I2C0

#define OLED_SCL_Clr() gpio_bit_write(PORT_LCD_SCL, GPIO_LCD_SCL, RESET)//SCL
#define OLED_SCL_Set() gpio_bit_write(PORT_LCD_SCL, GPIO_LCD_SCL, SET)//SCL

#define OLED_SDA_Clr() gpio_bit_write(PORT_LCD_SDA, GPIO_LCD_SDA, RESET)//SDA
#define OLED_SDA_Set()gpio_bit_write(PORT_LCD_SDA, GPIO_LCD_SDA, SET)//SDA
#else
//-----------------OLED端口定义---软件IIC---------------- 
#define RCU_LCD_SCL     RCU_GPIOA//SCL
#define PORT_LCD_SCL    GPIOA
#define GPIO_LCD_SCL    GPIO_PIN_8

#define RCU_LCD_SDA     RCU_GPIOC//SDA
#define PORT_LCD_SDA    GPIOC
#define GPIO_LCD_SDA    GPIO_PIN_9

#define OLED_SCL_Clr() gpio_bit_write(PORT_LCD_SCL, GPIO_LCD_SCL, RESET)//SCL
#define OLED_SCL_Set() gpio_bit_write(PORT_LCD_SCL, GPIO_LCD_SCL, SET)//SCL

#define OLED_SDA_Clr() gpio_bit_write(PORT_LCD_SDA, GPIO_LCD_SDA, RESET)//SDA
#define OLED_SDA_Set()gpio_bit_write(PORT_LCD_SDA, GPIO_LCD_SDA, SET)//SDA
#endif
//----------------------------------------------------------------
#ifndef u8
#define u8 uint8_t
#endif

#ifndef u16
#define u16 uint16_t
#endif

#ifndef u32
#define u32 uint32_t
#endif
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

void OLED_ClearPoint(u8 x,u8 y);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_WaitAck(void);
void Send_Byte(u8 dat);
void OLED_WR_Byte(u8 dat,u8 mode);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Refresh(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawLine(u8 x1,u8 y1,u8 x2,u8 y2,u8 mode);
void OLED_DrawCircle(u8 x,u8 y,u8 r);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
void OLED_ShowChar6x8(u8 x,u8 y,u8 chr,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
void OLED_Init(void);

#endif


