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
	printf("id=0x%x\n",lcdid);//Һ������оƬ�ͺż��
	ILI9341_GramScan(6);
	LCD_SetBackColor(BACKGROUND);
	ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);
	LCD_SetTextColor(BLACK);
	LCD_SetBackColor(YELLOW);
	ILI9341_DispChar_EN (10, 170, 'M' );
	ILI9341_DispString_EN(110,0,a);
	LCD_SetTextColor(RED);
	LCD_SetBackColor(BACKGROUND);
	ILI9341_DispChar_CH(10,200,'ε');
	
	ILI9341_DispString_EN_CH(10,220,"o(*������*)����Ϧ����happy");
	
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
	
	
	
	
//	/*ҪʹFSMC_A��16��Ϊ�ߵ�ƽ��������16λ��������һλ����ΪLCDһ����ַ�Ƕ�Ӧ�����ֽڶ�HADDR
//	��һ����ַ��Ӧһ���ֽ����Զ��䷽ʽΪHADDR[25:1]��FSMC_A[24:0]��Ӧ������HADDR[0]δ�� ��temp
//	�൱����HADDR[25:0]д����Ȼ����ת�Ƶ�FSMC_A[24:0]��Ϊ������HADDR[1]��FSMC_A[0]���Ի�Ҫ����һλ
//	*/
//	temp|=(0x01<<(16+1));
//	//A16λΪ�ߵ�ƽ��ʾ����
//	printf("A16Ϊ�ߵ�ƽ=%x\n",temp);
//	temp=0x60000000;
//	temp&=~(0x01<<(16+1));
//	//A16λΪ�͵�ƽ��ʾ����
//	printf("A16Ϊ�͵�ƽ=%x\n",temp);
//	//��������
//	*CMD_ADDR=0xABCD;
//	//��������
//	*Data_ADDR=0x1234;
//	//A16λΪ�ߵ�ƽ��ȡ����
//	read_data=*Data_ADDR;
	
	
	
	

