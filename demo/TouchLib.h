
#include "Typedef.h"

#ifndef _TOUCH_LIB_H_
#define _TOUCH_LIB_H_


#define CCH0				0X0001
#define CCH1				0X0002
#define CCH2				0X0004
#define CCH3				0X0008
#define CCH4				0X0010
#define CCH5				0X0020
#define CCH6				0X0040
#define CCH7				0X0080
#define CCH8				0X0100
#define CCH9				0X0200
#define CCH10			0X0400
#define CCH11			0X0800
#define CCH12			0X1000
#define CCH13			0X2000
#define CCH14			0X4000
#define CCH15			0X8000



/*OSCCON*/

#define IRCF_31K	0X00
#define IRCF_250K	0X10
#define IRCF_500K	0X20
#define IRCF_1M		0X30
#define IRCF_2M		0X40
#define IRCF_4M		0X50		/*default*/
#define IRCF_8M		0X60
#define IRCF_16M	0X70

#define SET_HIRC(val)		do {OSCCON = val;} while (0)

/* CSANA0 */

#define CSANA0_BIAS_3_5UA		0X00		// BIAS 电流35UA
#define CSANA0_BIAS_3_75UA		0X10
#define CSANA0_BIAS_4UA			0X20		// default
#define CSANA0_BIAS_4_25UA		0X30
#define CSANA0_BIAS_4_5UA		0X40
#define CSANA0_BIAS_5UA			0X50
#define CSANA0_BIAS_5_5UA		0X60
#define CSANA0_BIAS_6UA			0X70

#define CSANA0_CMP_6UA			0X00		// 触摸内部比较器消耗电路6UA
#define CSANA0_CMP_12UA			0X04		// default
#define CSANA0_CMP_18UA			0X08
#define CSANA0_CMP_24UA			0X0C

#define CSANA0_CMP_0_65V		0X00		// 触摸内部比较高电平0.65V
#define CSANA0_CMP_1_3V			0X01
#define CSANA0_CMP_1_9V			0X02
#define CSANA0_CMP_2_55V		0X03		// defalut


/* CSANA1 */

#define CSANA1_TIME_0_75US		0X00		// 触摸放电时间
#define CSANA1_TIME_1US			0X08		// default
#define CSANA1_TIME_1_25US		0X10
#define CSANA1_TIME_1_5US		0X18

#define CSANA1_CAP_256PF		0X00		// 触摸量程选择,256pf
#define CSANA1_CAP_128PF		0X01
#define CSANA1_CAP_96PF			0X02
#define CSANA1_CAP_64PF			0X03		//default
#define CSANA1_CAP_56PF			0X04
#define CSANA1_CAP_48PF			0X05
#define CSANA1_CAP_40PF			0X06
#define CSANA1_CAP_32PF			0X07


/* CSCTL */

#define CSCTL_EN				0X80		// 1 使能触摸模块
#define CSCTL_CSRAM				0X40		// 1 CSRAM 有MCU控制，0 CSRAM有触摸控制
#define CSCTL_BANK7				0X20		// 0 访问BANK3; 1 访问BANK7
#define CSCTL_CSBUSY			0X10		// 1 触摸正在扫描，0 触摸空闲
#define CSCTL_INT				0X08		// 1有触摸产生中断

#define CSCTL_CNT_1				0x00		// 一次触摸扫描，单个通道扫描的次数1
#define CSCTL_CNT_2				0x01
#define CSCTL_CNT_4				0x02
#define CSCTL_CNT_8				0x03
#define CSCTL_CNT_16			0x04
#define CSCTL_CNT_32			0x05
#define CSCTL_CNT_64			0x06
#define CSCTL_CNT_128			0x07

/*THCTL*/
#define THCTL_THGAP_3			0X00     //门限抽取间隔帧数		
#define THCTL_THGAP_7			0X20	
#define THCTL_THGAP_15			0X40
#define THCTL_THGAP_31			0X60

#define THCTL_THMOD_2			0X00     //门限累加次数	
#define THCTL_THMOD_4			0X04	
#define THCTL_THMOD_8			0X08
#define THCTL_THMOD_16			0X0B
#define THCTL_THMOD_32			0X10     
#define THCTL_THMOD_64			0X14	
#define THCTL_THMOD_128			0X18
#define THCTL_THMOD_256			0X1B

#define THCTL_THDS_16			0X00     //触摸按键释放后门限更新累加所需要间隔的帧数
#define THCTL_THDS_32			0X01	
#define THCTL_THDS_64			0X02
#define THCTL_THDS_128			0X03


#define TOUCH_EN()				do {CSCTL |= CSCTL_EN;} while (0)
#define TOUCH_DIS()				do {CSCTL &= ~CSCTL_EN;} while (0)

#define MCU_RAM()				do {CSCTL |= CSCTL_CSRAM;} while (0)
#define TOUCH_RAM()				do {CSCTL &= ~CSCTL_CSRAM;} while (0)

#define RAM_BANK7()				do {CSCTL |= CSCTL_BANK7;} while (0)
#define RAM_BANK3()				do {CSCTL &= (~CSCTL_BANK7);} while (0)
#define TMR1_ON()				do {TMR1ON = 1;} while (0)
#define TMR1_OFF()				do {TMR1ON = 0;} while (0)

#define CH0_CAP					0X1C0  //电容值RAM

#define CH0_CAPH				0X1C0
#define CH0_CAPL				0X1C1
#define CH1_CAPH				0X1C2
#define CH1_CAPL				0X1C3
#define CH2_CAPH				0X1C4
#define CH2_CAPL				0X1C5
#define CH3_CAPH				0X1C6
#define CH3_CAPL				0X1C7
#define CH4_CAPH				0X1C8
#define CH4_CAPL				0X1C9
#define CH5_CAPH				0X1CA
#define CH5_CAPL				0X1CB
#define CH6_CAPH				0X1CC
#define CH6_CAPL				0X1CD
#define CH7_CAPH				0X1CE
#define CH7_CAPL				0X1CF
#define CH8_CAPH				0X1D0
#define CH8_CAPL				0X1D1
#define CH9_CAPH				0X1D2
#define CH9_CAPL				0X1D3
#define CH10_CAPH				0X1D4
#define CH10_CAPL				0X1D5
#define CH11_CAPH				0X1D6
#define CH11_CAPL				0X1D7
#define CH12_CAPH				0X1D8
#define CH12_CAPL				0X1D9
#define CH13_CAPH				0X1DA
#define CH13_CAPL				0X1DB
#define CH14_CAPH				0X1DC
#define CH14_CAPL				0X1DD
#define CH15_CAPH				0X1DE
#define CH15_CAPL				0X1DF


#define CH0_TH					0X1A0

#define CH0_THH				0X1A0
#define CH0_THL				0X1A1
#define CH1_THH				0X1A2
#define CH1_THL				0X1A3
#define CH2_THH				0X1A4
#define CH2_THL				0X1A5
#define CH3_THH				0X1A6
#define CH3_THL				0X1A7
#define CH4_THH				0X1A8
#define CH4_THL				0X1A9
#define CH5_THH				0X1AA
#define CH5_THL				0X1AB
#define CH6_THH				0X1AC
#define CH6_THL				0X1AD
#define CH7_THH				0X1AE
#define CH7_THL				0X1AF
#define CH8_THH				0X1B0
#define CH8_THL				0X1B1
#define CH9_THH				0X1B2
#define CH9_THL				0X1B3
#define CH10_THH			0X1B4
#define CH10_THL			0X1B5
#define CH11_THH			0X1B6
#define CH11_THL			0X1B7
#define CH12_THH			0X1B8
#define CH12_THL			0X1B9
#define CH13_THH			0X1BA
#define CH13_THL			0X1BB
#define CH14_THH			0X1BC
#define CH14_THL			0X1BD
#define CH15_THH			0X1BE
#define CH15_THL			0X1BF

#define CH0_DIFF					0X1A0		// 0X3A0

volatile unsigned char		CH0_DIFFH					@	0X1A0;
volatile unsigned char		CH0_DIFFL					@	0X1A1;
volatile unsigned char		CH1_DIFFH					@	0X1A2;
volatile unsigned char		CH1_DIFFL					@	0X1A3;
volatile unsigned char		CH2_DIFFH					@	0X1A4;
volatile unsigned char		CH2_DIFFL					@	0X1A5;
volatile unsigned char		CH3_DIFFH					@	0X1A6;
volatile unsigned char		CH3_DIFFL					@	0X1A7;
volatile unsigned char		CH4_DIFFH					@	0X1A8;
volatile unsigned char		CH4_DIFFL					@	0X1A9;
volatile unsigned char		CH5_DIFFH					@	0X1AA;
volatile unsigned char		CH5_DIFFL					@	0X1AB;
volatile unsigned char		CH6_DIFFH					@	0X1AC;
volatile unsigned char		CH6_DIFFL					@	0X1AD;
volatile unsigned char		CH7_DIFFH					@	0X1AE;
volatile unsigned char		CH7_DIFFL					@	0X1AF;

volatile unsigned char		CH8_DIFFH					@	0X1B0;
volatile unsigned char		CH8_DIFFL					@	0X1B1;
volatile unsigned char		CH9_DIFFH					@	0X1B2;
volatile unsigned char		CH9_DIFFL					@	0X1B3;
volatile unsigned char		CH10_DIFFH					@	0X1B4;
volatile unsigned char		CH10_DIFFL					@	0X1B5;
volatile unsigned char		CH11_DIFFH					@	0X1B6;
volatile unsigned char		CH11_DIFFL					@	0X1B7;
volatile unsigned char		CH12_DIFFH					@	0X1B8;
volatile unsigned char		CH12_DIFFL					@	0X1B9;
volatile unsigned char		CH13_DIFFH					@	0X1BA;
volatile unsigned char		CH13_DIFFL					@	0X1BB;
volatile unsigned char		CH14_DIFFH					@	0X1BC;
volatile unsigned char		CH14_DIFFL					@	0X1BD;
volatile unsigned char		CH15_DIFFH					@	0X1BE;
volatile unsigned char		CH15_DIFFL					@	0X1BF;

/*
#define CH0_DIFFH				0X1A0
#define CH0_DIFFL				0X1A1
#define CH1_DIFFH				0X1A2
#define CH1_DIFFL				0X1A3
#define CH2_DIFFH				0X1A4
#define CH2_DIFFL				0X1A5
#define CH3_DIFFH				0X1A6
#define CH3_DIFFL				0X1A7
#define CH4_DIFFH				0X1A8
#define CH4_DIFFL				0X1A9
#define CH5_DIFFH				0X1AA
#define CH5_DIFFL				0X1AB
#define CH6_DIFFH				0X1AC
#define CH6_DIFFL				0X1AD
#define CH7_DIFFH				0X1AE
#define CH7_DIFFL				0X1AF
#define CH8_DIFFH				0X1B0
#define CH8_DIFFL				0X1B1
#define CH9_DIFFH				0X1B2
#define CH9_DIFFL				0X1B3
#define CH10_DIFFH				0X1B4
#define CH10_DIFFL				0X1B5
#define CH11_DIFFH				0X1B6
#define CH11_DIFFL				0X1B7
#define CH12_DIFFH				0X1B8
#define CH12_DIFFL				0X1B9
#define CH13_DIFFH				0X1BA
#define CH13_DIFFL				0X1BB
#define CH14_DIFFH				0X1BC
#define CH14_DIFFL				0X1BD
#define CH15_DIFFH				0X1BE
#define CH15_DIFFL				0X1BF
//*/

#define CH0_SUM					0X1C0		// 0X3C0

#define CH0_SUMH				0X1C0
#define CH0_SUMM				0X1C1
#define CH1_SUMH				0X1C2
#define CH1_SUMM				0X1C3
#define CH2_SUMH				0X1C4
#define CH2_SUMM				0X1C5
#define CH3_SUMH				0X1C6
#define CH3_SUMM				0X1C7
#define CH4_SUMH				0X1C8
#define CH4_SUMM				0X1C9
#define CH5_SUMH				0X1CA
#define CH5_SUMM				0X1CB
#define CH6_SUMH				0X1CC
#define CH6_SUMM				0X1CD
#define CH7_SUMH				0X1CE
#define CH7_SUMM				0X1CF
#define CH8_SUMH				0X1D0
#define CH8_SUMM				0X1D1
#define CH9_SUMH				0X1D2
#define CH9_SUMM				0X1D3
#define CH10_SUMH				0X1D4
#define CH10_SUMM				0X1D5
#define CH11_SUMH				0X1D6
#define CH11_SUMM				0X1D7
#define CH12_SUMH				0X1D8
#define CH12_SUMM				0X1D9
#define CH13_SUMH				0X1DA
#define CH13_SUMM				0X1DB
#define CH14_SUMH				0X1DC
#define CH14_SUMM				0X1DD
#define CH15_SUMH				0X1DE
#define CH15_SUMM				0X1DF

#define SET_TOUCH_CHANNEL(val)		do {CHSELH =((val >> 8) & 0xff); CHSELL =((val >> 0) & 0xff);} while (0)

#define SET_TOUCH_SCAN_TIME(val)	do {CSTMRH = (((val * 31) >> 8) & 0xff); CSTMRL = (((val * 31) >> 0) & 0xff);} while (0)

#define SET_TOUCH_SCAN_TIMEL(val)	do {CSTMRH = ((val >> 8) & 0xff); CSTMRL = ((val >> 0) & 0xff);} while (0)

extern u16 Cap[], CapTh[], CapThSum[], CapDifLib[];
extern const u16 CapDif[];
extern u8 CapThCnt, CapThSampleCnt;
extern u16 TouchChannle;
extern u16 TouchResult;
extern u16 ResetTime;
extern bit BFaceUpData;
extern u8 TouchUpDebounce[];
extern u8 TouchDebounce[];
extern u8 Chatter;
extern u8 Filtration;
extern u8 TouchNum;
extern bit BSteady;

extern void InitTouch(void);
extern u16 CheckLowClk(u8 inDat);
extern void TouchPro(void);
extern void TouchKeyResult(void);
extern void InitTouchDeviceRam(void);
extern void GetCap(u16 *ptr);
extern void Sleep(void);

#define REG_W(addr,value)			do { *((u8 *)addr) = value; } while (0)


#endif


