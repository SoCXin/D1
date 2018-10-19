#include	"Timer_bitname.h"
/***********************************************************************************
;Company : 深圳市汇春科技股份有限公司(Yspring)
;Author : Zhu_Chuan_rong
;Create Data : 2018-03
;Last Modified :
;Description :  YS83/84XXXX_ 范例程序
;Version : 1.0
************************************************************************************/

#include "htc.h"
#include "define.h"
#include "pwm.h"
#include "timer.h"
#include "ad_simple.h"




//--------------------------------------------函数声明

void Init_IO(void);
void cleal_sfr(void);
void clear_ram(void);

void delay(u16 ctr);

void key_scan(void);
void pwm_output(void);



#define	Time_2s		1000	//2s 	= 1000 * 2ms
#define	Time_500ms	250		//500ms = 250 * 2ms
#define	T40ms		20		//40ms = 20 * 2ms

#define LED_ON()	(PD0 = 1)
#define LED_OFF()	(PD0 = 0)

u8 Timer_ctr = Clear_Byte;
u8 Timer_500ms_ctr = Clear_Byte;
u16 temp_cyc = Clear_Byte;
u16 temp_duty = Clear_Word;

u8 new_key = Clear_Byte;
u8 old_key = Clear_Byte;
u8 key_debunce_ctr = Clear_Byte;

u16 voltage_temp = Clear_Word;


/**************************************************************************************************
;函数名: main
;
;函数说明: 主函数入口
;			
;入口参数:  无
;
;返回值: 	无
;
;		PC0、PC1、PC2 作为输入，开启内部上拉，由PC2、PC1、PC0	3个IO 口的状态来确定PWM的输出频率
;
;		PC5 输出PWM		
;		
;		用到Timer0做定时功能，定时2ms产生一次中断
;		PA5 每2ms翻转一次
;		PA2 每500ms翻转一次
;
;
;备注说明: 	相关寄存器的某些位使用宏定义列出可选的功能组合，用户通过修改相关"宏名"来修改相应配置，
;			可通过"查找/搜索"找到对应的"宏名"来进行调整
;
***************************************************************************************************/

void main(void)
{
	cleal_sfr();
	clear_ram();

	SCS = 1;				//系统时钟选择位		1:内部振荡器用于系统时钟		0:时钟源由FOSC<2:0>决定
	IRCF_SEL_4MHz();		//用户根据需要修改，IRC内部振荡器频率选择	(这里将 IRCF设置为 4MHz)
	while(HTS == 0)			//等待内部快时钟稳定
		asm("clrwdt");		// 使用PICC编译器编译 ，嵌入的汇编指令 为 PIC指令
		
	Init_IO();	
	init_timer0();

	init_adc();
	init_PWM();

	temp_cyc = (1000 - 1);		
	T1PRLH = (temp_cyc & 0x03ff) >> 8;		//PWM0/1周期寄存器的高2位	b<1:0>
	T1PRLL = (temp_cyc & 0x00ff);			//PWM0/1周期寄存器的低字节	b<7:0>
	new_key = 0x07;

/*			
	T1PRLH = 0x00;	//PWM0/1周期寄存器的高2位	b<1:0>
	T1PRLL = 39;		//PWM0/1周期寄存器的低字节	b<7:0>
	
	EPR1 = 0x00;	//PWM1占空比重载寄存器高2位	 b<1:0>
	PRL1L = 19;	//PWM1占空比重载寄存器低字节	 b<7:0>
	
	EPR0 = 0x00;	//PWM0占空比重载寄存器高2位	 b<1:0>
	PRL0L = 19;		//PWM0占空比重载寄存器低字节	 b<7:0>
*/
	
	TIS = 1;		//使能Timer0中断
	GIE = 1;		//使能总中断
	
	while(1)
	{
		if(flag_2ms == true)
		{
			flag_2ms = false;
			asm("clrwdt");
			
			PORTA ^= 0x20;				//RA5	2ms 取反
			
			key_scan();		
			pwm_output();
	
			voltage_temp = get_adc_result();
	
			if(voltage_temp >= VOLT_1_1V)
				LED_ON(); 				//AD 口电压高于1.1V	LED 亮
			else if(voltage_temp < VOLT_1V)
				LED_OFF();				//AD 口电压低于1V		LED 灭
			
		}
	}	
}


/**************************************************************************************************
;函数名: pwm_output
;
;函数说明: PC5 输出PWM，每0.5s改变一次PWM占空比( 0%  --> 100% --> 50% --> 25%  循环)
;				
;入口参数:  无
;
;返回值: 	无
;
***************************************************************************************************/
void pwm_output(void)
{
	Timer_ctr ++ ;
	if(Timer_ctr >= Time_500ms)	
	{
		Timer_ctr = Clear_Byte;
		
		PORTA ^= 0x10;			//PA4	500ms取反
		
	//	FLAG0.byte ^= 0x02;		//flag_500ms
		
		Timer_500ms_ctr ++ ;
		if(Timer_500ms_ctr >= 4)
			Timer_500ms_ctr = 0;
		

		if(Timer_500ms_ctr == 0)
		{
			temp_duty = 0; 						//0% 
		}
		else if(Timer_500ms_ctr == 1)
		{
			temp_duty = temp_cyc; 				//100% 
		}
		else if(Timer_500ms_ctr == 2)
		{
			temp_duty = ((temp_cyc + 1) / 2) - 1; 	//50% 
		}
		else if(Timer_500ms_ctr == 3)
		{
			temp_duty = ((temp_cyc + 1) / 4) - 1; 	//25% 
		}
		
		EPR1 = (temp_duty & 0x03ff ) >> 8;	//PWM1占空比重载寄存器高2位	 b<1:0>
		PRL1L = (temp_duty & 0x00ff );		//PWM1占空比重载寄存器低字节	 b<7:0>
		
		EPR0 = (temp_duty & 0x03ff ) >> 8;	//PWM1占空比重载寄存器高2位	 b<1:0>
		PRL0L = (temp_duty & 0x00ff );		//PWM1占空比重载寄存器低字节	 b<7:0>

		
	}
}



/**************************************************************************************************
;函数名: key_scan
;
;函数说明: 
;				
;入口参数:  无
;
;返回值: 	无
;
;			开启PB2_PB1_PB0	内部上拉
;
;			由PPB2_PB1_PB0---3个IO 口的状态来确定PWM的输出频率
;
;			PB2_PB1_PB0 = 000	PWM_output_100KHz	
;
;			PB2_PB1_PB0 = 001	PWM_output_40kHz	
;
;			PB2_PB1_PB0 = 010	PWM_output_20kHz	
;
;			PB2_PB1_PB0 = 011	PWM_output_10KHz	
;
;			PB2_PB1_PB0 = 100	PWM_output_5KHz	
;
;			PB2_PB1_PB0 = 101	PWM_output_2KHz	
;
;			PB2_PB1_PB0 = 110	PWM_output_1KHz	
;
;			PB2_PB1_PB0 = 111	PWM_output_500Hz
;
***************************************************************************************************/
void key_scan(void)
{
	
	new_key = (PORTB & 0x07);	//(0000 0xxx)
	if(old_key == new_key)
	{
		if(flag_key == false)
		{
			key_debunce_ctr ++ ;
			if(key_debunce_ctr >= T40ms)
			{
				key_debunce_ctr = Clear_Byte;
				flag_key = true;
				
				if(new_key == 0x00)		//(000)
				{
					T1_CLK_DIV_1();					//用户根据需要修改	(Timer1时钟预分频比选择位)
					temp_cyc = (40 - 1);			//用户根据需要修改	(PWM周期设置)	 
				}
				else if(new_key == 0x01)//(001)
				{
					T1_CLK_DIV_1();				
					temp_cyc = (100 - 1);				
				}
				else if(new_key == 0x02)//(010)
				{
					T1_CLK_DIV_1();				
					temp_cyc = (200 - 1);
				}
				else if(new_key == 0x03)//(011)
				{
					T1_CLK_DIV_1();				
					temp_cyc = (400 - 1);
				}
				else if(new_key == 0x04)//(100)
				{
					T1_CLK_DIV_1();	
					temp_cyc = (800 - 1);					
				}
				else if(new_key == 0x05)//(101)
				{
					T1_CLK_DIV_8();	
					temp_cyc = (250 - 1);						
				}
				else if(new_key == 0x06)//(110)
				{
					T1_CLK_DIV_8();	
					temp_cyc = (500 - 1);						
				}
				else if(new_key == 0x07)//(111)	
				{
					T1_CLK_DIV_8();	
					temp_cyc = (1000 - 1);						
				}
				
				T1PRLH = (temp_cyc & 0x03ff) >> 8;		//PWM0/1周期寄存器的高2位	b<1:0>
				T1PRLL = (temp_cyc & 0x00ff);			//PWM0/1周期寄存器的低字节	b<7:0>
			}
		}
	}
	else
	{
		old_key = new_key; 
		key_debunce_ctr = Clear_Byte;
		flag_key = false;
	}
}

/**************************************************************************************************
;函数名: interrupt XXX
;
;函数说明: 中断入口
;				
;入口参数:  无
;
;返回值: 	无
;
***************************************************************************************************/
void interrupt XXX(void)
{
	if(TIF == 1)
	{
		TIF = 0;
		flag_2ms = true;
		
	}
}



/**************************************************************************************************
;函数名: delay
;
;函数说明: 软件延时
;				
;入口参数: ctr
;
;返回值: 	无
;
***************************************************************************************************/
void delay(u16 ctr)
{
	while(ctr)
	{
		ctr--;
//		#asm
//		nop
//		nop
//		#endasm
	}
}



/*******************************************************************
;
;函数名: clear_ram 
;
;函数说明:	清内存
;
********************************************************************/
void clear_ram(void)
{
	MSR = 0x20;
	while(MSR <= 0x7f)	//将0x20 ~ 0x7f  的RAM 清零
	{
		IAR = 0;
		MSR ++ ;
	}
	
	MSR = 0xa0;
	while(MSR <= 0xef)	//将0xa0 ~ 0xef  的RAM 清零
	{
		IAR = 0;
		MSR ++ ;
	}
}

/**************************************************************************************************
;函数名: Init_IO
;
;函数说明: I/O 口初始化
;
;		PB0、PB1、PB2 作为输入，开启内部上拉，检测输入电平状态  
;				
;入口参数:  无
;
;返回值: 	无
;
***************************************************************************************************/
void Init_IO(void)
{
	CPIOA = 0X03;  			//PA端口输入/输出设置，	1:输入，	0:输出
	CPIOB = 0X07; 
	CPIOC = 0X00;   		//PC端口输入/输出设置，	1:输入，	0:输出
	CPIOD = 0X00;
//	CPIOC0 = 1
	
	PORTA = 0X00;			//
	PORTB = 0X00;			//
	PORTC = 0X00;			//
	PORTD = 0X00;			//

	ADINS = 0X00;			//模拟选择寄存器				1: 模拟输入。引脚被分配为模拟输入		0: 数字I/O。引脚被分配给端口或特殊功能。

	PAPHR = 0X00;			//PA端口的弱上拉控制，			1:使能，	0:禁止	
	PBPHR = 0X07;			//PB端口的弱上拉控制，			1:使能，	0:禁止	
	PCPHR = 0X00;			//PC弱上拉和弱下拉寄存器		b<7:4>下拉控制，b<3:0>上拉控制		1:使能，	0:禁止	
	PDPHR = 0X00;			//PD端口的弱上拉控制，			1:使能，	0:禁止	


}





/**************************************************************************************************
;函数名: cleal_sfr
;
;函数说明: MCU 上电 对特殊功能寄存器进行初始化
;				
;入口参数:  无
;
;返回值: 	无
;
***************************************************************************************************/
void cleal_sfr(void)
{
	INTS = 0x00;
	PAINTR= 0x00;//电平变化中断PORTA寄存器	1 = 允许电平变化中断
	PBINTR= 0x00;
	ADINS = 0x00;

}
