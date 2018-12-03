	/*****************************************************
; 回春科技YS8384系列触摸库
;File Name :YS65F804.C
;20180507
;Version : 1.1
*****************************************************/
#include "YS8384XXU.h"
#include "83_84Touch.h"
#include "TouchLib.h"
#include "Uart.h"
#include "User.h"

#ifdef UART_EN
void InitTimer(void)
{
	OPT_REG = 0x00;  	// 2分频
	TMR0 = 256 - 52;	// 9600波特率
	UART_H();
	INTS = 0X00;
	TMR0EN = 1;		//使能定时器0
	SET_UART_OUTPUT();
}
#endif 

void InitPort(void)
{
	CPIOA = 0X00;
	PAPHR = 0X00;
	PAINTR = 0X00;
	PORTA = 0X00;
	
	CPIOB = 0X00;
	PBPHR = 0X00;
	PBINTR = 0X00;
	PORTB = 0X00;

	CPIOC = 0X00;
	PCPHR = 0X00;
	PORTC = 0X00;

	ADINS = 0X00;
	
	CPIOD = 0X00;
	PDPHR = 0X00;
	PORTD = 0X00;
}
	


void main(void)
{
	INTS = 0X00;
	
	SET_HIRC(IRCF_8M);
	
	RAM_BANK3();
	
	InitPort();
	InitTouch();
	CheckLowClk(TOUCH_SCAN_TIME);
	
	#ifdef UART_EN
	InitTimer(); 
	#endif 

	while(1)
	{
		CLR_WDT();
		
		if(CSIF)
		{
			CSIF = 0;
			TouchPro();  //触摸算法函数
			User();  //用户程序


			#ifdef UART_EN
		//	UartSendCap(&Cap, 0);  //通过Uart发送电容值
			UartSendUintByHex(&TouchResult,1);  //通过Uart发送触摸结果值
			#endif
		}
	}
}

void interrupt Isr(void)
{
	;
}
