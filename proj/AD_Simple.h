
#ifndef		_AD_SIMPLE_H_
#define		_AD_SIMPLE_H_


/***********************		AD输入通道选择		************************************/

												//0x0f (0000 1111)	b<7:4> = 0000 xxxx

#define AD_CH_SEL_OFF()			ADS0 = ( 0x00 | (0x0f & ADS0) )		//b<7:4> = 0000 xxxx	ADC 输入通道关断
#define AD_CH_SEL_AN0_PD0()		ADS0 = ( 0x10 | (0x0f & ADS0) )		//b<7:4> = 0001 xxxx	选择PD0口作为AD输入通道
#define AD_CH_SEL_AN1_PD1()		ADS0 = ( 0x20 | (0x0f & ADS0) )		//b<7:4> = 0010 xxxx	选择PD1口作为AD输入通道
#define AD_CH_SEL_AN2_PD2()		ADS0 = ( 0x30 | (0x0f & ADS0) )		//b<7:4> = 0011 xxxx	选择PD2口作为AD输入通道
#define AD_CH_SEL_AN3_PD3()		ADS0 = ( 0x40 | (0x0f & ADS0) )		//b<7:4> = 0100 xxxx	选择PD3口作为AD输入通道

#define AD_CH_SEL_AN4_PD4()		ADS0 = ( 0x50 | (0x0f & ADS0) )		//b<7:4> = 0101 xxxx	选择PD4口作为AD输入通道
#define AD_CH_SEL_AN5_PD5()		ADS0 = ( 0x60 | (0x0f & ADS0) )		//b<7:4> = 0110 xxxx	选择PD5口作为AD输入通道
#define AD_CH_SEL_AN6_PD6()		ADS0 = ( 0x70 | (0x0f & ADS0) )		//b<7:4> = 0111 xxxx	选择PD6口作为AD输入通道
#define AD_CH_SEL_AN7_PD7()		ADS0 = ( 0x80 | (0x0f & ADS0) )		//b<7:4> = 1000 xxxx	选择PD7口作为AD输入通道
#define AD_CH_SEL_VSS()			ADS0 = ( 0xe0 | (0x0f & ADS0) )		//b<7:4> = 1110 xxxx	ADC 输入电压为 VSS
#define AD_CH_SEL_VDD_DIV_4()	ADS0 = ( 0xf0 | (0x0f & ADS0) )		//b<7:4> = 1111 xxxx	ADC 输入电压为 VDD/4

												//0xf3(1111 0011)	b<3:2> = 00xx

#define AD_REF_VOL_SEL_VDD()	ADS0 = ( 0x00 | (0xf3 & ADS0) )		//b<3:2> = xxxx 00xx	ADC 电压参考是 VDD pin
#define AD_REF_VOL_SEL_PD0()	ADS0 = ( 0x04 | (0xf3 & ADS0) )		//b<3:2> = xxxx 01xx	ADC 电压参考是 PD0/VREF pin
#define AD_REF_VOL_SEL_INT()	ADS0 = ( 0x08 | (0xf3 & ADS0) )		//b<3:2> = xxxx 1xxx	ADC 电压参考是内部电压参考



/***********************		内部参考电压选择	************************************/

#define INT_REF_VOL_SEL_1024MV()	(VREFSEL = 0)	//内部电压参考选择 1.024V
#define INT_REF_VOL_SEL_2048MV()	(VREFSEL = 1)	//内部电压参考选择 2.048V



/***********************		AD转换时钟选择 		************************************/

													//0xcf(1100 1111)	b<5:4> = xx00
	 
#define AD_CLK_SEL_FOSC_DIV_2()		ADC0CN = ( 0x00 | (0xcf & ADC0CN) )		//b<5:4> = xx00 xxxx	AD转换时钟选择 FOSC/2	(注意: Fosc >= 4MHz 不能选)
#define AD_CLK_SEL_FOSC_DIV_4()		ADC0CN = ( 0x10 | (0xcf & ADC0CN) )		//b<5:4> = xx01 xxxx	AD转换时钟选择 FOSC/4	(注意: Fosc >= 8MHz 不能选)	
#define AD_CLK_SEL_FOSC_DIV_8()		ADC0CN = ( 0x20 | (0xcf & ADC0CN) )		//b<5:4> = xx10 xxxx	AD转换时钟选择 FOSC/8	(注意: Fosc >= 16MHz 不能选)
#define AD_CLK_SEL_FOSC_DIV_16()	ADC0CN = ( 0x30 | (0xcf & ADC0CN) )		//b<5:4> = xx11 xxxx	AD转换时钟选择 FOSC/16



													//0xfc(1111 1100)	b<1:0> = xxxx xx00
	 
#define AD_STA_SEL_GODONE_SET()	ADC0CN = ( 0x00 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx00	GODONE 置 "1" 启动ADC转换
#define AD_STA_SEL_T0_OVER()	ADC0CN = ( 0x02 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx10	Timer0溢出 启动ADC转换
#define AD_STA_SEL_T1_OVER()	ADC0CN = ( 0x03 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx11	Timer1溢出 启动ADC转换



/***********************		AD采样值定义		************************************/
#define VOLT_1_1V	2200		// 2200 = ( (1.1V  *  4096)  / 2.048V)	-----AD口电压 1.1V，12分辨率4096，参考电压选择内部2.048V
#define VOLT_1V		2000		// 2000 = ( (1V  *  4096)  / 2.048V)	-----AD口电压 1V，12分辨率4096，参考电压选择内部2.048V



extern u16 get_adc_result(void);
extern void init_adc(void);


#endif

