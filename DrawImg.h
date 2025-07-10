#pragma once
#include"Common.h"
#include"Data.h"
class Data;
class Draw
{
public:
	Draw();
	void Game_Draw();		//根据数据画图片|数据的处理封装在Game中
	void showData();
	Data* getData() { return pData; }
	int& getTime() { return timeCnt; }
protected:
	Data* pData;			//游戏需要用到数据,包含数据的指针
	int timeCnt = 0;			//秒数变量
	void initWindow();
};