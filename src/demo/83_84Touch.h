
#include "Typedef.h"

#ifndef _YS83_84_TOUCH_H_
#define _YS83_84_TOUCH_H_


//---------------------------------------------------------------------------------------------
							//��������Ӧ�Ƚϳٶ�ʱ���ʵ���С������������	
#define SET_CHATTER   3    //��������

#define SET_FILTRATION 3   //�˲�����

// ��ʱ�䴥����ǿ�Ƹ��²���0����ʾ�ù�����Ч����0��ʾ�ù�����Ч
// 16bit, ����ʱ�� =  RESET_TOUCH_TIME * TOUCH_SCAN_TIME   ��λms
#define RESET_TOUCH_TIME 		1000

//--------------------------------------------------------------------------------------------


#define TOUCH_CHANNEL		(CCH3)

//--------------------------------------------------------------------------------------------

#define TOUCH_NUM    1			// ����ͨ������

//---------------------------------------------------------------------------------------------
							//ֻʹ��һ��ͨ��ʱ�������ָó�5
							//ÿ����һ��ͨ������5
#define TOUCH_SCAN_TIME	    10			// ���ô���ɨ��ʱ��������λMS
//-------------------------------------------------------------------------------------------
							//���������� ���÷�Χ 0 -255
							//���𽫸�ֵ���õ���30
#define TOUCH0_DIF			40  //����ͨ��0 - 15 ������ ����ԽСԽ����
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


