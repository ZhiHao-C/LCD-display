#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include <stdio.h>
#include "bps_ili9341_lcd.h"
extern uint16_t lcdid;
extern uint16_t read_Pixel_Format(void);
extern void delay_ms(unsigned int n);

char a[]="Maple";

int main()
{
	Init_ILI9341();
	USART_Config();
	printf("id=0x%x\n",lcdid);//液晶控制芯片型号检查
	ILI9341_GramScan(6);
	LCD_SetBackColor(BACKGROUND);
	ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
	LCD_SetTextColor(BLACK);
	LCD_SetBackColor(YELLOW);
	ILI9341_DispChar_EN (10, 170, 'M' );
	ILI9341_DispString_EN(110,0,a);
	LCD_SetTextColor(RED);
	LCD_SetBackColor(BACKGROUND);
	ILI9341_DispChar_CH(10,200,'蔚');
	
	ILI9341_DispString_EN_CH(10,220,"o(*￣▽￣*)ブ七夕快乐happy");
	
	printf("225\n");
	while(1)
	{}
//	LCD_SetTextColor(BLACK);
//	while(1)
//	{
//		ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
//		ILI9341_DrawRectangle(188,50,50,50,1);
//		delay_ms(10000);
//		ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
//		ILI9341_DrawLine(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
//		delay_ms(10000); 
//	}
	
}
	
	
	
	
//	/*要使FSMC_A【16】为高电平，先左移16位，再左移一位是因为LCD一个地址是对应两个字节而HADDR
//	是一个地址对应一个字节所以对其方式为HADDR[25:1]与FSMC_A[24:0]对应相连，HADDR[0]未接 ，temp
//	相当于往HADDR[25:0]写数据然后再转移到FSMC_A[24:0]因为现在是HADDR[1]接FSMC_A[0]所以还要左移一位
//	*/
//	temp|=(0x01<<(16+1));
//	//A16位为高电平表示数据
//	printf("A16为高电平=%x\n",temp);
//	temp=0x60000000;
//	temp&=~(0x01<<(16+1));
//	//A16位为低电平表示命令
//	printf("A16为低电平=%x\n",temp);
//	//发送命令
//	*CMD_ADDR=0xABCD;
//	//发送数据
//	*Data_ADDR=0x1234;
//	//A16位为高电平读取数据
//	read_data=*Data_ADDR;
	
	
	
	

