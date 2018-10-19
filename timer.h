#ifndef		_TIMER_H_
#define		_TIMER_H_


//***********************		
#define PD6_RISING_EDGE_EXT_INT()	(INT1EG = 1)	//PD6/INT1���ŵ������ش����ⲿ�ж�
#define PD6_FALLING_EDGE_EXT_INT()	(INT1EG = 0)	//PD6/INT1���ŵ��½��ش����ⲿ�ж�
	
#define PA1_RISING_EDGE_EXT_INT()	(INT0EG = 1)	//PA1/INT0���ŵ������ش����ⲿ�ж�
#define PA1_FALLING_EDGE_EXT_INT()	(INT0EG = 0)	//PA1/INT0���ŵ��½��ش����ⲿ�ж�

//***********************		
#define T0_CLK_SEL_PA2_T0CKI()		(TCS = 1)		//T0 ʱ��Դѡ�� ���� PA2/T0CKI �����ϵĵ�ƽ����
#define T0_CLK_SEL_FOSC_DIV4()		(TCS = 0)		//T0 ʱ��Դѡ�� ���� �ڲ�ָ������ʱ�� �� FOSC/4��

//***********************		
#define PA2_T0CKI_H_TO_L_CTR()		(TCE = 1)		//PA2/T0CKI �����źŴӸ���������ʱ����������
#define PA2_T0CKI_L_TO_H_CTR()		(TCE = 0)		//PA2/T0CKI �����źŴӵ���������ʱ����������

//***********************		

#define PSC_SEL_WDT()				(PSC = 1)		//Ԥ��Ƶ������� WDT ģ��
#define PSC_SEL_T0()				(PSC = 0)		//Ԥ��Ƶ������� T0 ģ��


/***********************		T0ʱ��Ԥ��Ƶ��ѡ�� 		************************************/

												//0xf8 (1111 1000)	b<2:0> = x000

#define T0_CLK_DIV_2()		OPT_REG = ( 0x00 | (0xf8 & OPT_REG) )	//b<2:0> = x000	T0 Ԥ��Ƶ��ѡ��  1 : 2
#define T0_CLK_DIV_4()		OPT_REG = ( 0x01 | (0xf8 & OPT_REG) )	//b<2:0> = x001	T0 Ԥ��Ƶ��ѡ��  1 : 4
#define T0_CLK_DIV_8()		OPT_REG = ( 0x02 | (0xf8 & OPT_REG) )	//b<2:0> = x010	T0 Ԥ��Ƶ��ѡ��  1 : 8
#define T0_CLK_DIV_16()		OPT_REG = ( 0x03 | (0xf8 & OPT_REG) )	//b<2:0> = x011	T0 Ԥ��Ƶ��ѡ��  1 : 16
#define T0_CLK_DIV_32()		OPT_REG = ( 0x04 | (0xf8 & OPT_REG) )	//b<2:0> = x100	T0 Ԥ��Ƶ��ѡ��  1 : 32
#define T0_CLK_DIV_64()		OPT_REG = ( 0x05 | (0xf8 & OPT_REG) )	//b<2:0> = x101	T0 Ԥ��Ƶ��ѡ��  1 : 64
#define T0_CLK_DIV_128()	OPT_REG = ( 0x06 | (0xf8 & OPT_REG) )	//b<2:0> = x110	T0 Ԥ��Ƶ��ѡ��  1 : 128
#define T0_CLK_DIV_256()	OPT_REG = ( 0x07 | (0xf8 & OPT_REG) )	//b<2:0> = x111	T0 Ԥ��Ƶ��ѡ��  1 : 256


												//0xcf (1100 1111)	b<5:4> = 00

#define T1_CLK_DIV_1()		T1STA = ( 0x00 | (0xcf & T1STA) )		//b<5:4> = xx00	T1 Ԥ��Ƶ��ѡ��  1 : 1
#define T1_CLK_DIV_2()		T1STA = ( 0x10 | (0xcf & T1STA) )		//b<5:4> = xx01	T1 Ԥ��Ƶ��ѡ��  1 : 2
#define T1_CLK_DIV_4()		T1STA = ( 0x20 | (0xcf & T1STA) )		//b<5:4> = xx10	T1 Ԥ��Ƶ��ѡ��  1 : 4
#define T1_CLK_DIV_8()		T1STA = ( 0x30 | (0xcf & T1STA) )		//b<5:4> = xx11	T1 Ԥ��Ƶ��ѡ��  1 : 8


#define T1_CLK_SEL_PA5_T1CKI()		(TMR1CS = 1)		//T1 ʱ��Դѡ�� ����T1CK1���ţ������أ����ⲿʱ��
#define T1_CLK_SEL_FOSC()			(TMR1CS = 0)		//T1 ʱ��Դѡ�� ���� �ڲ�ʱ��  FOSC



extern void init_timer0(void);


#endif
