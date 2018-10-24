#ifndef		_TIMER_H_
#define		_TIMER_H_


//***********************		
#define PD6_RISING_EDGE_EXT_INT()	(INT1EG = 1)	//PD6/INT1引脚的上升沿触发外部中断
#define PD6_FALLING_EDGE_EXT_INT()	(INT1EG = 0)	//PD6/INT1引脚的下降沿触发外部中断
	
#define PA1_RISING_EDGE_EXT_INT()	(INT0EG = 1)	//PA1/INT0引脚的上升沿触发外部中断
#define PA1_FALLING_EDGE_EXT_INT()	(INT0EG = 0)	//PA1/INT0引脚的下降沿触发外部中断

//***********************		
#define T0_CLK_SEL_PA2_T0CKI()		(TCS = 1)		//T0 时钟源选择 来自 PA2/T0CKI 引脚上的电平跳变
#define T0_CLK_SEL_FOSC_DIV4()		(TCS = 0)		//T0 时钟源选择 来自 内部指令周期时钟 （ FOSC/4）

//***********************		
#define PA2_T0CKI_H_TO_L_CTR()		(TCE = 1)		//PA2/T0CKI 引脚信号从高至低跳变时，递增计数
#define PA2_T0CKI_L_TO_H_CTR()		(TCE = 0)		//PA2/T0CKI 引脚信号从低至高跳变时，递增计数

//***********************		

#define PSC_SEL_WDT()				(PSC = 1)		//预分频器分配给 WDT 模块
#define PSC_SEL_T0()				(PSC = 0)		//预分频器分配给 T0 模块


/***********************		T0时钟预分频比选择 		************************************/

												//0xf8 (1111 1000)	b<2:0> = x000

#define T0_CLK_DIV_2()		OPT_REG = ( 0x00 | (0xf8 & OPT_REG) )	//b<2:0> = x000	T0 预分频比选择  1 : 2
#define T0_CLK_DIV_4()		OPT_REG = ( 0x01 | (0xf8 & OPT_REG) )	//b<2:0> = x001	T0 预分频比选择  1 : 4
#define T0_CLK_DIV_8()		OPT_REG = ( 0x02 | (0xf8 & OPT_REG) )	//b<2:0> = x010	T0 预分频比选择  1 : 8
#define T0_CLK_DIV_16()		OPT_REG = ( 0x03 | (0xf8 & OPT_REG) )	//b<2:0> = x011	T0 预分频比选择  1 : 16
#define T0_CLK_DIV_32()		OPT_REG = ( 0x04 | (0xf8 & OPT_REG) )	//b<2:0> = x100	T0 预分频比选择  1 : 32
#define T0_CLK_DIV_64()		OPT_REG = ( 0x05 | (0xf8 & OPT_REG) )	//b<2:0> = x101	T0 预分频比选择  1 : 64
#define T0_CLK_DIV_128()	OPT_REG = ( 0x06 | (0xf8 & OPT_REG) )	//b<2:0> = x110	T0 预分频比选择  1 : 128
#define T0_CLK_DIV_256()	OPT_REG = ( 0x07 | (0xf8 & OPT_REG) )	//b<2:0> = x111	T0 预分频比选择  1 : 256


												//0xcf (1100 1111)	b<5:4> = 00

#define T1_CLK_DIV_1()		T1STA = ( 0x00 | (0xcf & T1STA) )		//b<5:4> = xx00	T1 预分频比选择  1 : 1
#define T1_CLK_DIV_2()		T1STA = ( 0x10 | (0xcf & T1STA) )		//b<5:4> = xx01	T1 预分频比选择  1 : 2
#define T1_CLK_DIV_4()		T1STA = ( 0x20 | (0xcf & T1STA) )		//b<5:4> = xx10	T1 预分频比选择  1 : 4
#define T1_CLK_DIV_8()		T1STA = ( 0x30 | (0xcf & T1STA) )		//b<5:4> = xx11	T1 预分频比选择  1 : 8


#define T1_CLK_SEL_PA5_T1CKI()		(TMR1CS = 1)		//T1 时钟源选择 来自T1CK1引脚（上升沿）的外部时钟
#define T1_CLK_SEL_FOSC()			(TMR1CS = 0)		//T1 时钟源选择 来自 内部时钟  FOSC



extern void init_timer0(void);


#endif
