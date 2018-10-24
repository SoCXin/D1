
#include "Typedef.h"

#ifndef _YS83_84_TOUCH_H_
#define _YS83_84_TOUCH_H_


//---------------------------------------------------------------------------------------------
							//当触摸反应比较迟钝时可适当减小下面两个数字	
#define SET_CHATTER   3    //消抖次数

#define SET_FILTRATION 3   //滤波次数

// 长时间触摸，强制更新参数0，表示该功能无效，非0表示该功能有效
// 16bit, 长按时间 =  RESET_TOUCH_TIME * TOUCH_SCAN_TIME   单位ms
#define RESET_TOUCH_TIME 		1000

//--------------------------------------------------------------------------------------------


#define TOUCH_CHANNEL		(CCH3)

//--------------------------------------------------------------------------------------------

#define TOUCH_NUM    1			// 触摸通道个数

//---------------------------------------------------------------------------------------------
							//只使能一个通道时将该数字该成5
							//每增加一个通道增加5
#define TOUCH_SCAN_TIME	    10			// 设置触摸扫描时间间隔，单位MS
//-------------------------------------------------------------------------------------------
							//触摸灵敏度 设置范围 0 -255
							//请勿将该值设置低于30
#define TOUCH0_DIF			40  //触摸通道0 - 15 灵敏度 数字越小越灵敏
#define TOUCH1_DIF			40
#define TOUCH2_DIF			40
#define TOUCH3_DIF			40
#define TOUCH4_DIF			40
#define TOUCH5_DIF			40
#define TOUCH6_DIF			40
#define TOUCH7_DIF			40
#define TOUCH8_DIF			40
#define TOUCH9_DIF			40
#define TOUCH10_DIF			40
#define TOUCH11_DIF			40
#define TOUCH12_DIF			40
#define TOUCH13_DIF			40
#define TOUCH14_DIF			40
#define TOUCH15_DIF			40

#define CSANA0_VAL				(CSANA0_BIAS_6UA | CSANA0_CMP_24UA | CSANA0_CMP_1_3V)
#define CSANA1_VAL				(CSANA1_TIME_1_5US | CSANA1_CAP_32PF)

#define CSCTL_VAL				(CSCTL_EN  | CSCTL_CNT_64)

#define THCTL_VAL				(THCTL_THGAP_7 | THCTL_THMOD_8 | THCTL_THDS_16)

#endif


