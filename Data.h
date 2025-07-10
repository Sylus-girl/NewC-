#pragma once
#include"Common.h"
//根据鼠标消息，做数据的改变
class Data {

public:
	void Set();									//设置雷|按键开盖|设置标记
	void constValue(int i, int j, int value);	//设置数据(地图中的值)	限定数据|改变数据
	void changeValue(int i, int j, int value);
	array<array<int, 9>, 9>& getMap();			//在外面画图要访问数据,提供外部访问接口 

protected:
	array <array< int, 9 >, 9 > map = { 0 };

};