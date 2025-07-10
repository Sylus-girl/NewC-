#pragma once
#include "Common.h"


enum class Difficulty {
	BEGINNER,
	INTERMEDIATE,
	EXPERT
};


class Res
{
private:
	Res();
	static void setDifficulty(Difficulty diff);
public:
	static int WIDTH(string name);
	static int HEIGHT(string name);
	static Res* GetInstance();
	static void Draw_IMG(int x, int y, string name);			    //背景图片绘制
	static void DrawIMG(int x, int y, string name, int preIndex);	//其他图片绘制
	static DWORD WINAPI PlayMusic(LPVOID lparame);					//播放音乐
	static void selectDifficulty(Difficulty diff);					//选择难度
	~Res();
public:
	static map<string, IMAGE*> img;		//图片
	static map<string, string> music;	//音乐
	static int MineNum;					//雷的数量
	static int ROW;						//行|列
	static int COL;
};