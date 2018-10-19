

#include "htc.h"
#include "define.h"
#include "ad_simple.h"
#include "timer.h"

u16 get_adc_result(void);
void init_adc(void);


u8 i;
u16 adc_max;
u16 adc_min;
u16 adc_sum;
u16 adc_res;

/**************************************************************************************************
;函数名: get_adc_result
;
;函数说明: 获取AD采样结果，12位AD结果(0~4095)
;				
;入口参数:  无
;
;返回值: 	adc_res
;
***************************************************************************************************/
u16 get_adc_result(void)
{
	adc_sum = 0x0000;
	adc_max = 0x0000;
//12位AD结果最大值0x0fff (4095)
	adc_min = 0x0fff;
	
	ADC_EN = 1;				//开启AD模块
//	delay(10);
	for(i=0;i<10;i++)
	{
		GO_DONE = 1;		//启动AD 开始转换
		while(GO_DONE);		//等待AD 转换完成
		
		adc_res = 0x0000;
		if(ADFM == 1)					
		{		
			//AD结果右对齐	
			adc_res = ADRESH;	//(0000 0000 0000 xxxx)读取12位AD 结果高字节寄存器(高4位为0，低4位值有效)
			adc_res <<= 8;		//(0000 xxxx 0000 0000)
			adc_res += ADRESL;	//(0000 xxxx xxxx xxxx)读取12位AD 结果低字节寄存器(8位值有效)，存放在adc_res 中
		}
		else
		{
			//AD结果左对齐	
			adc_res = ADRESH;	//(0000 0000 xxxx xxxx)读取12位AD 结果高字节寄存器(8位值有效)
			adc_res <<= 8;		//(xxxx xxxx 0000 0000)
			adc_res += ADRESL;	//(xxxx xxxx xxxx 0000)读取12位AD 结果低字节寄存器(高4位值有效，低4位为0)
			adc_res >>= 4;;		//(0000 xxxx xxxx xxxx)结果存放在adc_res 中
		}
		
		if(adc_res >= adc_max)
			adc_max = adc_res;	//记录10次采样结果的最大值
			
		if(adc_res < adc_min)
			adc_min = adc_res;	//记录10次采样结果的最小值
			
		adc_sum += adc_res;		//累加10次AD采样结果
	}
	ADC_EN = 0;					//关闭AD模块 省电
	
	adc_sum -= adc_max;			//减去最大值
	adc_sum -= adc_min;			//减去最小值
	
	adc_res = adc_sum >> 3;		//求平均值 (adc_sum / 8)

	return(adc_res);
}


/*************************************************************************************************
;
;函数名:	init_adc
;
;函数功能: 	初始化 ADC 模块 ，用户通过修改相关寄存器进行AD模块的初始化
;
;			例程中用到AN1_PD1 脚 作为AD输入，选择使用内部 2.048V 作为参考电压，12位AD结果(0~4095)
;
;入口参数:  无
;
;返回值: 	无
;
;备注说明: 	相关寄存器的某些位使用宏定义列出可选的功能组合，用户通过修改相关"宏名"来修改相应配置，
;			可通过"查找/搜索"找到对应的"宏名"来进行调整
;
*************************************************************************************************/
void init_adc(void)
{
	CPIOD1 = 1;				//PD端口输入/输出设置，			1:输入，			0:输出
	PDPHR1 = 0;				//PD端口的弱上拉控制，			1:使能，			0:禁止	
	ANS1 = 1;				//模拟 、数字I/O选择			1: 模拟输入。引脚被分配为模拟输入		0: 数字I/O。引脚被分配给端口或特殊功能。
	AD_CH_SEL_AN1_PD1();	//选择PD1作为AD输入通道
	
	ADFM = 1;					//ADC输出结果对齐方式选择位	1:右对齐,高位补零	0:左对齐，低位补零
	AD_CLK_SEL_FOSC_DIV_4();	//AD转换时钟选择 FOSC/4	
	AD_REF_VOL_SEL_INT();		//AD 电压参考是内部电压参考
	INT_REF_VOL_SEL_2048MV();	//AD 内部参考电压选择 2.048V
	AD_STA_SEL_GODONE_SET();	//GODONE 置 "1" 启动ADC转换
	
}
