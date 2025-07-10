#pragma once
#include "Common.h"
class MyTimer
{
public:
	static bool Timer(int duration, int id)     //时间间隔    id
	{
		static int startTime[10];               //开始时间---静态变量自动初始化为0
		int endTime = clock();                  //结束时间
		if (endTime - startTime[id] >= duration)//结束时间-开始时间>=时间间隔
		{
			startTime[id] = endTime;            //把原来的结束时间改为新的开始时间
			return true;
		}
		return false;
	}
};