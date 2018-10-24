#include "YS8384XXU.h"
#include "TouchLib.h"
#include "Uart.h"
#include "User.h"


u16 sleepCnt = 0x0000;

///**********************************
//
//��������User
//
//�������ܣ��û�����
//
//***********************************
void User(void)
{
	
	// �û������Լ��ĳ��򣬵ȴ������ȶ���ִ��Sleep();
	// ִ��˯�ߺ���򽫲������У�ֱ���ٴ��д�������˳��ִ�У��˳�Sleep()������

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


