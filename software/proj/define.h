
#ifndef		_DEFINE_H_
#define		_DEFINE_H_

//--------------------------------------------数据类型重定义
typedef unsigned char	u8;		
typedef unsigned int	u16;	
//typedef unsigned short	u16;	
typedef unsigned long	u32;




//--------------------------------------------联合体(共用体) 定义
typedef union	
{
	struct
	{
		unsigned b0		: 1;
		unsigned b1		: 1;
		unsigned b2		: 1;
		unsigned b3		: 1;
		unsigned b4		: 1;
		unsigned b5		: 1;
		unsigned b6		: 1;
		unsigned b7		: 1;
	}bit_type;
	unsigned char byte;
}FLAG;	


FLAG	FLAG0;		//结构变量声明

//--------------------------------------------结构类型变量位域宏定义

#define flag_2ms		FLAG0.bit_type.b0 
#define flag_500ms		FLAG0.bit_type.b1
#define flag_key		FLAG0.bit_type.b2
#define flag_3		FLAG0.bit_type.b3
#define flag_4		FLAG0.bit_type.b4
#define flag_5		FLAG0.bit_type.b5
#define flag_6		FLAG0.bit_type.b6
#define flag_7		FLAG0.bit_type.b7

//--------------------------------------------宏定义

#define true	1
#define false	0

#define ON	1
#define OFF	0

#define ENABLE	1
#define DISABLE	0

#define Clear_Byte	0x00
#define Clear_Word	0x0000
#define Clear_Long	0x00000000



/***********************		Fosc 系统时钟选择			************************************/
		
#define SYS_CLK_SEL_CFB			0x00	//b<1:0> = 00  系统时钟选择 由 配置字 1 中 FOSC<2:0> 决定的时钟
#define SYS_CLK_SEL_TIMER1		0x01	//b<1:0> = 01  系统时钟选择 由 Timer1振荡器 提供
#define SYS_CLK_SEL_INTOSC		0x02	//b<1:0> = 1x  系统时钟选择 由 内部振荡器模块 提供


/***********************		IRC 内部振荡器频率选择		************************************/

												//0x8f (1000 1111)	b<6:4> = 000
#define IRCF_SEL_31KHz()	OSCCON = ( 0x00 | (OSCCON & 0x8f) )		//b<6:4> = 0000 0000	
#define IRCF_SEL_250KHz()	OSCCON = ( 0x10 | (OSCCON & 0x8f) )		//b<6:4> = 0001 0000		
#define IRCF_SEL_500KHz()	OSCCON = ( 0x20 | (OSCCON & 0x8f) )		//b<6:4> = 0010 0000		
#define IRCF_SEL_1MHz()		OSCCON = ( 0x30 | (OSCCON & 0x8f) )		//b<6:4> = 0011 0000		

#define IRCF_SEL_2MHz()		OSCCON = ( 0x40 | (OSCCON & 0x8f) )		//b<6:4> = 0100 0000		
#define IRCF_SEL_4MHz()		OSCCON = ( 0x50 | (OSCCON & 0x8f) )		//b<6:4> = 0101 0000		
#define IRCF_SEL_8MHz()		OSCCON = ( 0x60 | (OSCCON & 0x8f) )		//b<6:4> = 0110 0000		
#define IRCF_SEL_16MHz()	OSCCON = ( 0x70 | (OSCCON & 0x8f) )		//b<6:4> = 0111 0000		

	


#endif


