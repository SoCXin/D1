
#ifndef		_AD_SIMPLE_H_
#define		_AD_SIMPLE_H_


/***********************		AD����ͨ��ѡ��		************************************/

												//0x0f (0000 1111)	b<7:4> = 0000 xxxx

#define AD_CH_SEL_OFF()			ADS0 = ( 0x00 | (0x0f & ADS0) )		//b<7:4> = 0000 xxxx	ADC ����ͨ���ض�
#define AD_CH_SEL_AN0_PD0()		ADS0 = ( 0x10 | (0x0f & ADS0) )		//b<7:4> = 0001 xxxx	ѡ��PD0����ΪAD����ͨ��
#define AD_CH_SEL_AN1_PD1()		ADS0 = ( 0x20 | (0x0f & ADS0) )		//b<7:4> = 0010 xxxx	ѡ��PD1����ΪAD����ͨ��
#define AD_CH_SEL_AN2_PD2()		ADS0 = ( 0x30 | (0x0f & ADS0) )		//b<7:4> = 0011 xxxx	ѡ��PD2����ΪAD����ͨ��
#define AD_CH_SEL_AN3_PD3()		ADS0 = ( 0x40 | (0x0f & ADS0) )		//b<7:4> = 0100 xxxx	ѡ��PD3����ΪAD����ͨ��

#define AD_CH_SEL_AN4_PD4()		ADS0 = ( 0x50 | (0x0f & ADS0) )		//b<7:4> = 0101 xxxx	ѡ��PD4����ΪAD����ͨ��
#define AD_CH_SEL_AN5_PD5()		ADS0 = ( 0x60 | (0x0f & ADS0) )		//b<7:4> = 0110 xxxx	ѡ��PD5����ΪAD����ͨ��
#define AD_CH_SEL_AN6_PD6()		ADS0 = ( 0x70 | (0x0f & ADS0) )		//b<7:4> = 0111 xxxx	ѡ��PD6����ΪAD����ͨ��
#define AD_CH_SEL_AN7_PD7()		ADS0 = ( 0x80 | (0x0f & ADS0) )		//b<7:4> = 1000 xxxx	ѡ��PD7����ΪAD����ͨ��
#define AD_CH_SEL_VSS()			ADS0 = ( 0xe0 | (0x0f & ADS0) )		//b<7:4> = 1110 xxxx	ADC �����ѹΪ VSS
#define AD_CH_SEL_VDD_DIV_4()	ADS0 = ( 0xf0 | (0x0f & ADS0) )		//b<7:4> = 1111 xxxx	ADC �����ѹΪ VDD/4

												//0xf3(1111 0011)	b<3:2> = 00xx

#define AD_REF_VOL_SEL_VDD()	ADS0 = ( 0x00 | (0xf3 & ADS0) )		//b<3:2> = xxxx 00xx	ADC ��ѹ�ο��� VDD pin
#define AD_REF_VOL_SEL_PD0()	ADS0 = ( 0x04 | (0xf3 & ADS0) )		//b<3:2> = xxxx 01xx	ADC ��ѹ�ο��� PD0/VREF pin
#define AD_REF_VOL_SEL_INT()	ADS0 = ( 0x08 | (0xf3 & ADS0) )		//b<3:2> = xxxx 1xxx	ADC ��ѹ�ο����ڲ���ѹ�ο�



/***********************		�ڲ��ο���ѹѡ��	************************************/

#define INT_REF_VOL_SEL_1024MV()	(VREFSEL = 0)	//�ڲ���ѹ�ο�ѡ�� 1.024V
#define INT_REF_VOL_SEL_2048MV()	(VREFSEL = 1)	//�ڲ���ѹ�ο�ѡ�� 2.048V



/***********************		ADת��ʱ��ѡ�� 		************************************/

													//0xcf(1100 1111)	b<5:4> = xx00
	 
#define AD_CLK_SEL_FOSC_DIV_2()		ADC0CN = ( 0x00 | (0xcf & ADC0CN) )		//b<5:4> = xx00 xxxx	ADת��ʱ��ѡ�� FOSC/2	(ע��: Fosc >= 4MHz ����ѡ)
#define AD_CLK_SEL_FOSC_DIV_4()		ADC0CN = ( 0x10 | (0xcf & ADC0CN) )		//b<5:4> = xx01 xxxx	ADת��ʱ��ѡ�� FOSC/4	(ע��: Fosc >= 8MHz ����ѡ)	
#define AD_CLK_SEL_FOSC_DIV_8()		ADC0CN = ( 0x20 | (0xcf & ADC0CN) )		//b<5:4> = xx10 xxxx	ADת��ʱ��ѡ�� FOSC/8	(ע��: Fosc >= 16MHz ����ѡ)
#define AD_CLK_SEL_FOSC_DIV_16()	ADC0CN = ( 0x30 | (0xcf & ADC0CN) )		//b<5:4> = xx11 xxxx	ADת��ʱ��ѡ�� FOSC/16



													//0xfc(1111 1100)	b<1:0> = xxxx xx00
	 
#define AD_STA_SEL_GODONE_SET()	ADC0CN = ( 0x00 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx00	GODONE �� "1" ����ADCת��
#define AD_STA_SEL_T0_OVER()	ADC0CN = ( 0x02 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx10	Timer0��� ����ADCת��
#define AD_STA_SEL_T1_OVER()	ADC0CN = ( 0x03 | (0xfc & ADC0CN) )		//b<1:0> = xxxx xx11	Timer1��� ����ADCת��



/***********************		AD����ֵ����		************************************/
#define VOLT_1_1V	2200		// 2200 = ( (1.1V  *  4096)  / 2.048V)	-----AD�ڵ�ѹ 1.1V��12�ֱ���4096���ο���ѹѡ���ڲ�2.048V
#define VOLT_1V		2000		// 2000 = ( (1V  *  4096)  / 2.048V)	-----AD�ڵ�ѹ 1V��12�ֱ���4096���ο���ѹѡ���ڲ�2.048V



extern u16 get_adc_result(void);
extern void init_adc(void);


#endif

