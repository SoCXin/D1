#include	"Timer_bitname.h"
/***********************************************************************************
;Company : �����л㴺�Ƽ��ɷ����޹�˾(Yspring)
;Author : Zhu_Chuan_rong
;Create Data : 2018-03
;Last Modified :
;Description :  YS83/84XXXX_ ��������
;Version : 1.0
************************************************************************************/

#include "htc.h"
#include "define.h"
#include "pwm.h"
#include "timer.h"
#include "ad_simple.h"




//--------------------------------------------��������

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
;������: main
;
;����˵��: ���������
;			
;��ڲ���:  ��
;
;����ֵ: 	��
;
;		PC0��PC1��PC2 ��Ϊ���룬�����ڲ���������PC2��PC1��PC0	3��IO �ڵ�״̬��ȷ��PWM�����Ƶ��
;
;		PC5 ���PWM		
;		
;		�õ�Timer0����ʱ���ܣ���ʱ2ms����һ���ж�
;		PA5 ÿ2ms��תһ��
;		PA2 ÿ500ms��תһ��
;
;
;��ע˵��: 	��ؼĴ�����ĳЩλʹ�ú궨���г���ѡ�Ĺ�����ϣ��û�ͨ���޸����"����"���޸���Ӧ���ã�
;			��ͨ��"����/����"�ҵ���Ӧ��"����"�����е���
;
***************************************************************************************************/

void main(void)
{
	cleal_sfr();
	clear_ram();

	SCS = 1;				//ϵͳʱ��ѡ��λ		1:�ڲ���������ϵͳʱ��		0:ʱ��Դ��FOSC<2:0>����
	IRCF_SEL_4MHz();		//�û�������Ҫ�޸ģ�IRC�ڲ�����Ƶ��ѡ��	(���ｫ IRCF����Ϊ 4MHz)
	while(HTS == 0)			//�ȴ��ڲ���ʱ���ȶ�
		asm("clrwdt");		// ʹ��PICC���������� ��Ƕ��Ļ��ָ�� Ϊ PICָ��
		
	Init_IO();	
	init_timer0();

	init_adc();
	init_PWM();

	temp_cyc = (1000 - 1);		
	T1PRLH = (temp_cyc & 0x03ff) >> 8;		//PWM0/1���ڼĴ����ĸ�2λ	b<1:0>
	T1PRLL = (temp_cyc & 0x00ff);			//PWM0/1���ڼĴ����ĵ��ֽ�	b<7:0>
	new_key = 0x07;

/*			
	T1PRLH = 0x00;	//PWM0/1���ڼĴ����ĸ�2λ	b<1:0>
	T1PRLL = 39;		//PWM0/1���ڼĴ����ĵ��ֽ�	b<7:0>
	
	EPR1 = 0x00;	//PWM1ռ�ձ����ؼĴ�����2λ	 b<1:0>
	PRL1L = 19;	//PWM1ռ�ձ����ؼĴ������ֽ�	 b<7:0>
	
	EPR0 = 0x00;	//PWM0ռ�ձ����ؼĴ�����2λ	 b<1:0>
	PRL0L = 19;		//PWM0ռ�ձ����ؼĴ������ֽ�	 b<7:0>
*/
	
	TIS = 1;		//ʹ��Timer0�ж�
	GIE = 1;		//ʹ�����ж�
	
	while(1)
	{
		if(flag_2ms == true)
		{
			flag_2ms = false;
			asm("clrwdt");
			
			PORTA ^= 0x20;				//RA5	2ms ȡ��
			
			key_scan();		
			pwm_output();
	
			voltage_temp = get_adc_result();
	
			if(voltage_temp >= VOLT_1_1V)
				LED_ON(); 				//AD �ڵ�ѹ����1.1V	LED ��
			else if(voltage_temp < VOLT_1V)
				LED_OFF();				//AD �ڵ�ѹ����1V		LED ��
			
		}
	}	
}


/**************************************************************************************************
;������: pwm_output
;
;����˵��: PC5 ���PWM��ÿ0.5s�ı�һ��PWMռ�ձ�( 0%  --> 100% --> 50% --> 25%  ѭ��)
;				
;��ڲ���:  ��
;
;����ֵ: 	��
;
***************************************************************************************************/
void pwm_output(void)
{
	Timer_ctr ++ ;
	if(Timer_ctr >= Time_500ms)	
	{
		Timer_ctr = Clear_Byte;
		
		PORTA ^= 0x10;			//PA4	500msȡ��
		
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
		
		EPR1 = (temp_duty & 0x03ff ) >> 8;	//PWM1ռ�ձ����ؼĴ�����2λ	 b<1:0>
		PRL1L = (temp_duty & 0x00ff );		//PWM1ռ�ձ����ؼĴ������ֽ�	 b<7:0>
		
		EPR0 = (temp_duty & 0x03ff ) >> 8;	//PWM1ռ�ձ����ؼĴ�����2λ	 b<1:0>
		PRL0L = (temp_duty & 0x00ff );		//PWM1ռ�ձ����ؼĴ������ֽ�	 b<7:0>

		
	}
}



/**************************************************************************************************
;������: key_scan
;
;����˵��: 
;				
;��ڲ���:  ��
;
;����ֵ: 	��
;
;			����PB2_PB1_PB0	�ڲ�����
;
;			��PPB2_PB1_PB0---3��IO �ڵ�״̬��ȷ��PWM�����Ƶ��
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
					T1_CLK_DIV_1();					//�û�������Ҫ�޸�	(Timer1ʱ��Ԥ��Ƶ��ѡ��λ)
					temp_cyc = (40 - 1);			//�û�������Ҫ�޸�	(PWM��������)	 
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
				
				T1PRLH = (temp_cyc & 0x03ff) >> 8;		//PWM0/1���ڼĴ����ĸ�2λ	b<1:0>
				T1PRLL = (temp_cyc & 0x00ff);			//PWM0/1���ڼĴ����ĵ��ֽ�	b<7:0>
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
;������: interrupt XXX
;
;����˵��: �ж����
;				
;��ڲ���:  ��
;
;����ֵ: 	��
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
;������: delay
;
;����˵��: �����ʱ
;				
;��ڲ���: ctr
;
;����ֵ: 	��
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
;������: clear_ram 
;
;����˵��:	���ڴ�
;
********************************************************************/
void clear_ram(void)
{
	MSR = 0x20;
	while(MSR <= 0x7f)	//��0x20 ~ 0x7f  ��RAM ����
	{
		IAR = 0;
		MSR ++ ;
	}
	
	MSR = 0xa0;
	while(MSR <= 0xef)	//��0xa0 ~ 0xef  ��RAM ����
	{
		IAR = 0;
		MSR ++ ;
	}
}

/**************************************************************************************************
;������: Init_IO
;
;����˵��: I/O �ڳ�ʼ��
;
;		PB0��PB1��PB2 ��Ϊ���룬�����ڲ���������������ƽ״̬  
;				
;��ڲ���:  ��
;
;����ֵ: 	��
;
***************************************************************************************************/
void Init_IO(void)
{
	CPIOA = 0X03;  			//PA�˿�����/������ã�	1:���룬	0:���
	CPIOB = 0X07; 
	CPIOC = 0X00;   		//PC�˿�����/������ã�	1:���룬	0:���
	CPIOD = 0X00;
//	CPIOC0 = 1
	
	PORTA = 0X00;			//
	PORTB = 0X00;			//
	PORTC = 0X00;			//
	PORTD = 0X00;			//

	ADINS = 0X00;			//ģ��ѡ��Ĵ���				1: ģ�����롣���ű�����Ϊģ������		0: ����I/O�����ű�������˿ڻ����⹦�ܡ�

	PAPHR = 0X00;			//PA�˿ڵ����������ƣ�			1:ʹ�ܣ�	0:��ֹ	
	PBPHR = 0X07;			//PB�˿ڵ����������ƣ�			1:ʹ�ܣ�	0:��ֹ	
	PCPHR = 0X00;			//PC���������������Ĵ���		b<7:4>�������ƣ�b<3:0>��������		1:ʹ�ܣ�	0:��ֹ	
	PDPHR = 0X00;			//PD�˿ڵ����������ƣ�			1:ʹ�ܣ�	0:��ֹ	


}





/**************************************************************************************************
;������: cleal_sfr
;
;����˵��: MCU �ϵ� �����⹦�ܼĴ������г�ʼ��
;				
;��ڲ���:  ��
;
;����ֵ: 	��
;
***************************************************************************************************/
void cleal_sfr(void)
{
	INTS = 0x00;
	PAINTR= 0x00;//��ƽ�仯�ж�PORTA�Ĵ���	1 = �����ƽ�仯�ж�
	PBINTR= 0x00;
	ADINS = 0x00;

}
