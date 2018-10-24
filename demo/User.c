#include "YS8384XXU.h"
#include "TouchLib.h"
#include "Uart.h"
#include "User.h"


u16 sleepCnt = 0x0000;

///**********************************
//
//函数名：User
//
//函数功能：用户程序
//
//***********************************
void User(void)
{
	
	// 用户根据自己的程序，等待触摸稳定后执行Sleep();
	// 执行睡眠后程序将不在运行，直到再次有触摸，会顺序执行，退出Sleep()；函数

	if (0x00 != TouchResult)
	{
		sleepCnt = 0x0000;
	}

	if ((++sleepCnt >= 1000) && (BSteady))
	{
		sleepCnt = 0x0000;
		
		Sleep();
	}
}


