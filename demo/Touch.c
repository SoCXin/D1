#include "YS8384XXU.h"
#include "83_84Touch.h"
#include "TouchLib.h"
#include "Typedef.h"


const u16 CapDif[16] = {TOUCH0_DIF, 		TOUCH1_DIF, 		TOUCH2_DIF, 		TOUCH3_DIF,
					TOUCH4_DIF, 		TOUCH5_DIF, 		TOUCH6_DIF, 		TOUCH7_DIF,
					TOUCH8_DIF, 		TOUCH9_DIF, 		TOUCH10_DIF, 	TOUCH11_DIF,
					TOUCH12_DIF, 	TOUCH13_DIF, 	TOUCH14_DIF, 	TOUCH15_DIF,
					};
					
u8 TouchUpDebounce[TOUCH_NUM];
u8 TouchDebounce[TOUCH_NUM];

u16 Cap[TOUCH_NUM], CapTh[TOUCH_NUM], CapThSum[TOUCH_NUM], CapDifLib[TOUCH_NUM];
u16 TouchChannle;

u16 TouchResult = 0X0000;			// �������ֵ��ÿ��λ��Ӧһ������ͨ����1�д�����0û�д���

u16 ResetTime;


/*
������	:	InitTouch()		��ʼ������
����		:	��ƽ��QQ:2581358733
ʱ��		:	2017-8-24
*/
void InitTouch(void)
{
	u8 i,j;
	u16 k;

	TouchChannle = TOUCH_CHANNEL;
	ResetTime = RESET_TOUCH_TIME;

	CPIOB |= TOUCH_CHANNEL & 0XFF;				// ����ͨ������ΪINPUT
	PBPHR |= TOUCH_CHANNEL & 0XFF;				// ���ô���ͨ������
	
	CPIOC |= (TOUCH_CHANNEL>>8) & 0X0F;
	PCPHR |= (TOUCH_CHANNEL>>8) & 0X0F;
	
	CPIOD |= (TOUCH_CHANNEL>>12) & 0X0F;
	PDPHR |= (TOUCH_CHANNEL>>12) & 0X0F;

	ADINS |= (TOUCH_CHANNEL>>12) & 0X0F;		// ��������Ϊģ��ڵĴ���ͨ������Ϊģ���

	SET_TOUCH_CHANNEL(TOUCH_CHANNEL);
	SET_TOUCH_SCAN_TIME(TOUCH_SCAN_TIME);

	CSANA0 = CSANA0_VAL;
	CSANA1 = CSANA1_VAL;
	THCTL = THCTL_VAL;
	
	InitTouchDeviceRam();
	
	CSCTL = CSCTL_VAL;

	for (i = 0; i < TOUCH_NUM; i++)
	{
		CapTh[i] = 0x0FFF;
		CapThSum[i] = 0x0000;
		TouchDebounce[i] = 0;
	}

	for(i = 0, k = 0x0001, j = 0; i < 16; i++)
	{
		if(k == (k & TouchChannle))
		{
			CapDifLib[j++] = CapDif[i];
		}
		
		k <<= 1;
	}
	
	TouchResult = 0X0000;
	
	CapThCnt = 0;
	CapThSampleCnt = 0;

	BFaceUpData = 1;

	Chatter = SET_CHATTER;  
	Filtration = SET_FILTRATION;
	TouchNum = TOUCH_NUM;
	
}


void InitTouchDeviceRam(void)
{
//	u8 i;
	
	MCU_RAM();
	RAM_BANK7();
	
	//for (i = 0, MSR = (CH0_DIFFH & 0X7F); i < 16; i++)
	//for (i = 0; i < 16; i++)
	//{
		/*
		IAR = ((CapDif[i] >>8) & 0XFF);
		MSR++;
		IAR = ((CapDif[i] >>0) & 0XFF);
		MSR++;
		//*/
	//	REG_W(CH0_DIFFL + (1 << i), (CapDif[i] & 0XFF));
	//	REG_W(CH0_DIFFH + (1 << i), ((CapDif[i] >>8) & 0XFF));
	//}

	CH0_DIFFL = (CapDif[0] & 0XFF);
	CH0_DIFFH = ((CapDif[0] >>8) & 0XFF);

	CH1_DIFFL = (CapDif[1] & 0XFF);
	CH1_DIFFH = ((CapDif[1] >>8) & 0XFF);

	CH2_DIFFL = (CapDif[2] & 0XFF);
	CH2_DIFFH = ((CapDif[2] >>8) & 0XFF);

	CH3_DIFFL = (CapDif[3] & 0XFF);
	CH3_DIFFH = ((CapDif[3] >>8) & 0XFF);

	CH4_DIFFL = (CapDif[4] & 0XFF);
	CH4_DIFFH = ((CapDif[4] >>8) & 0XFF);

	CH5_DIFFL = (CapDif[5] & 0XFF);
	CH5_DIFFH = ((CapDif[5] >>8) & 0XFF);

	CH6_DIFFL = (CapDif[6] & 0XFF);
	CH6_DIFFH = ((CapDif[6] >>8) & 0XFF);

	CH7_DIFFL = (CapDif[7] & 0XFF);
	CH7_DIFFH = ((CapDif[7] >>8) & 0XFF);

	CH8_DIFFL = (CapDif[8] & 0XFF);
	CH8_DIFFH = ((CapDif[8] >>8) & 0XFF);

	CH9_DIFFL = (CapDif[9] & 0XFF);
	CH9_DIFFH = ((CapDif[9] >>8) & 0XFF);

	CH10_DIFFL = (CapDif[10] & 0XFF);
	CH10_DIFFH = ((CapDif[10] >>8) & 0XFF);

	CH11_DIFFL = (CapDif[11] & 0XFF);
	CH11_DIFFH = ((CapDif[11] >>8) & 0XFF);

	CH12_DIFFL = (CapDif[12] & 0XFF);
	CH12_DIFFH = ((CapDif[12] >>8) & 0XFF);

	CH13_DIFFL = (CapDif[13] & 0XFF);
	CH13_DIFFH = ((CapDif[13] >>8) & 0XFF);

	CH14_DIFFL = (CapDif[14] & 0XFF);
	CH14_DIFFH = ((CapDif[14] >>8) & 0XFF);

	CH15_DIFFL = (CapDif[15] & 0XFF);
	CH15_DIFFH = ((CapDif[15] >>8) & 0XFF);
	
	RAM_BANK3();
	TOUCH_RAM();
	
}

//*******************************************************
//
//��������Sleep
//
//�������ܣ�û����ʱIC����˯��ģʽ
//
//********************************************************
//*
void Sleep(void)
{	
	u8 i;
	u8 iEBak = 0;
	
	if (GIE)
	{
		iEBak = 1;
	}
	
	GIE = 0;
	
	if (CSIE)
	{
		iEBak |= 0x02;
	}
	
	CSIE = 1;
	
	if (PEIE)
	{
		iEBak |= 0x04;
	}
	
	PEIE = 1;
	
	CSINTS = 1;
	
	SLEEP();
	
	CSIF = 0;

	CSINTS = 0;

	GetCap((u16 *)CH0_TH);
	
	for (i = 0; i < TOUCH_NUM; i++)
	{
		CapTh[i] = Cap[i];
	}
	
	CLR_WDT();
	SWDTEN = 0; 		//����ʵ����Ҫ�������Ƿ���Ҫ��WDT
	CLR_WDT();
	
	if (0X02 != (iEBak & 0X02))
	{
		CSIE = 0;
	}
	
	if (0x04 != (iEBak & 0x04))
	{
		PEIE = 0;
	}
	
	if (0x01 == (iEBak & 0x01))
	{
		GIE = 1;
	}
	
}
//*/



//*******************************************
//
//��������u16 CheckLowClk(u8 inDat)
//
//�������ܣ���ʱ�ӽ�����ʱ��
//
//*******************************************
u16 CheckLowClk(u8 inDat)
{
	u8 bGIE = 0;
	
	u8 i;
	u16 tmr1Cnt;
	u32 longTmp = 0;
	
	u8 oscconBak = (OSCCON & 0X70);

	SET_HIRC(IRCF_4M);

	if (GIE)
	{
		bGIE = 1;
	}
	
	GIE = 0;
	
	PWMCON = (PWMCON & 0X02);   //ʹ�ܶ�ʱ��0
	T1STA = 0X30;		// 8��Ƶ
	
	TMR1_OFF();   //�ض�ʱ��1
	
	TMR1L = 0;
	TMR1H = 0;

	TMR1IF = 0;

	SET_TOUCH_SCAN_TIME(10);
	
	CSIF = 0;
	while (!CSIF) CLR_WDT();

	CSIF = 0;
	while (!CSIF) CLR_WDT();

	TMR1_ON();

	CSIF = 0;
	while (!CSIF) CLR_WDT();

	TMR1_OFF();
	CSIF = 0;

	tmr1Cnt = TMR1H;
	tmr1Cnt <<= 8;
	tmr1Cnt |= TMR1L;

	for (i = 0; i < inDat; i++)
	{
		longTmp += 310000L;
	}

	longTmp >>= 1;
	
	tmr1Cnt = longTmp/tmr1Cnt;

	SET_TOUCH_SCAN_TIMEL(tmr1Cnt);
	
	SET_HIRC(oscconBak);

	if (0 != bGIE)
	{
		GIE = 1;
	}
	
	return tmr1Cnt;
	
}


