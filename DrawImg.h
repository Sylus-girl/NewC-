#pragma once
#include"Common.h"
#include"Data.h"
class Data;
class Draw
{
public:
	Draw();
	void Game_Draw();		//�������ݻ�ͼƬ|���ݵĴ����װ��Game��
	void showData();
	Data* getData() { return pData; }
	int& getTime() { return timeCnt; }
protected:
	Data* pData;			//��Ϸ��Ҫ�õ�����,�������ݵ�ָ��
	int timeCnt = 0;			//��������
	void initWindow();
};