#pragma once
#include "Common.h"
class MyTimer
{
public:
	static bool Timer(int duration, int id)     //ʱ����    id
	{
		static int startTime[10];               //��ʼʱ��---��̬�����Զ���ʼ��Ϊ0
		int endTime = clock();                  //����ʱ��
		if (endTime - startTime[id] >= duration)//����ʱ��-��ʼʱ��>=ʱ����
		{
			startTime[id] = endTime;            //��ԭ���Ľ���ʱ���Ϊ�µĿ�ʼʱ��
			return true;
		}
		return false;
	}
};