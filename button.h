#pragma once
#include "Common.h"
#include"DrawImg.h"
class Data;
/*��������������������������������������������������������������������������������������
			   ��갴������
���������: 1.�������Ϸ���Ƶİ���  2.����ǵ�ͼ�仯�İ���
����������������������������������������������������������������������������������������*/
class Button
{
public:
	Button(int ImgSize = 24);									//��ͼ�仯�İ���			
	void ClickButton(ExMessage msg, Data* pData);				/*���������¼���Ӧ: �����...*/
	void boomBlank(Data* pData, int row, int col);				//��Ǹ��Ӻ�����ը���հ׸���
	int judge(Data* pData, int row, int col);					//��Ϸ��������
protected:

	//ͼƬ�Ĵ�С
	int ImgSize;
};