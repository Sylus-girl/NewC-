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
	static void Draw_IMG(int x, int y, string name);			    //����ͼƬ����
	static void DrawIMG(int x, int y, string name, int preIndex);	//����ͼƬ����
	static DWORD WINAPI PlayMusic(LPVOID lparame);					//��������
	static void selectDifficulty(Difficulty diff);					//ѡ���Ѷ�
	~Res();
public:
	static map<string, IMAGE*> img;		//ͼƬ
	static map<string, string> music;	//����
	static int MineNum;					//�׵�����
	static int ROW;						//��|��
	static int COL;
};