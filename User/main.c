#include "stm32f10x.h"                  // Device header
#include "bps_led.h"
#include "bps_usart.h"
#include <stdio.h>
#include "bps_ili9341_lcd.h"
#include "bps_Font.h"
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
	
	sprintf(dispBuff,"液晶显示器的id号：%x",lcdid);
	ILI9341_DispString_EN_CH(10,236,dispBuff);//打印一个变量
	
	sprintf(dispBuff,"浮点型(保留2位小数):%f ",3.141592);//sprintf
	ILI9341_DispString_EN_CH(10,236+1*16,dispBuff);//打印一个小数
	
	sprintf(dispBuff,"浮点型(保留2位小数):%.2f ",3.14159);
	ILI9341_DispString_EN_CH(10,236+2*16,dispBuff);//打印一个小数（两位）
	
	pStr="显示中文居中测试";
	//%*c带星号在这里表示有多少个' '（空格）
	//用总的像素减去中文所消耗的像素再去除以一个字节所要的像素再除以2
	//英文中的空格相当于一个英文字符，中文相当于两个英文字符（两个字节）
	//所以strlen(pStr)除以2才得到有多少个中文字
	sprintf(dispBuff,"%*c%s",(LCD_X_LENGTH-(strlen(pStr)/2*WIDTH_CH_CHAR))/(WIDTH_CH_CHAR/2)/2,' ',pStr);
	ILI9341_DispString_EN_CH(0,0+16*2,dispBuff);
	
	//居中时，要插入的空格个数 = (液晶宽度/字体宽度 - 字符串长度)/2
	//中文相当于两个字符
	pStr="显示中文和英文居中测试ABC";
	sprintf(dispBuff,"%*c%s",(LCD_X_LENGTH/(WIDTH_CH_CHAR/2)-strlen(pStr))/2,' ',pStr);
	ILI9341_DispString_EN_CH(0,0+16*3,dispBuff);
	
	printf("225\n");//串口显示检测到这步为止有没有卡死
	while(1)
	{}
	

	
	

	
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
	
	
	
	

