#pragma once
#include "Common.h"
#include"DrawImg.h"
class Data;
/*———————————————————————————————————————————
			   鼠标按键控制
分两种情况: 1.鼠标是游戏控制的按键  2.鼠标是地图变化的按键
————————————————————————————————————————————*/
class Button
{
public:
	Button(int ImgSize = 24);									//地图变化的按键			
	void ClickButton(ExMessage msg, Data* pData);				/*鼠标操作的事件响应: 鼠标点击...*/
	void boomBlank(Data* pData, int row, int col);				//标记格子和连环炸开空白格子
	int judge(Data* pData, int row, int col);					//游戏结束条件
protected:

	//图片的大小
	int ImgSize;
};