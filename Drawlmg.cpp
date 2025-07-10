#include "DrawImg.h"
#include"Res.h"
#include"Data.h"
#include"time.hpp"
Draw::Draw() :pData(new Data)
{
	initWindow();
	pData->Set();
	//����
	initgraph(Res::WIDTH("����"), Res::HEIGHT("����"), EW_SHOWCONSOLE);
	Res::Draw_IMG(0, 0, "����");
	Res::Draw_IMG(16, 21, "0_");
	Res::Draw_IMG(21 + 20, 21, "1_");
	Res::Draw_IMG(21 + 20 * 2, 21, "0_");

	Res::Draw_IMG(21 + 20 * 6 + 25, 21, "0_");
	Res::Draw_IMG(21 + 20 * 8 + 4, 21, "0_");
	Res::Draw_IMG(21 + 20 * 9 + 4, 21, "0_");
}
void Draw::showData()
{
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			cout << pData->getMap()[k][i] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void Draw::Game_Draw()
{
	int width = Res::WIDTH("����") + (Res::COL - 9) * 24;
	int height = Res::HEIGHT("����") + (Res::ROW - 9) * 24;
	initgraph(width, height, EW_SHOWCONSOLE);
	Res::Draw_IMG(0, 0, "����");

	int ge = 0, shi = 0, bai = 0;
	if (MyTimer::Timer(1000, 0))
	{
		getTime()++;	//���������ĵ���
	}

	ge = getTime() % 10;
	shi = getTime() / 10 % 10;
	bai = getTime() / 100;
	//ge
	Res::Draw_IMG(21 + 20 * 9 + 4, 21, to_string(ge) + "_");
	//shi
	Res::Draw_IMG(18 + 20 * 8 + 4, 21, to_string(shi) + "_");
	//bai
	Res::Draw_IMG(14+ 20 * 6 + 25, 21, to_string(bai) + "_");

	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			//��Χȫ�����м���8---��Χû�����м���0
			if (pData->getMap()[i][k] >= 0 && pData->getMap()[i][k] <= 8)	//��Χ[0,8]
			{
				switch (pData->getMap()[i][k]) {					//0 1 2 3 4 5 6 7 
				case 0:
					Res::DrawIMG(16 + 24 * i, 84 + 24 * k, "ש��", 1);
					break;
				case 1:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "0");	//��Ӧ����1
					break;
				case 2:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "1");	//��Ӧ����2
					break;
				case 3:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "2");	//��Ӧ����3
					break;
				case 4:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "3");	//��Ӧ����4
					break;
				case 5:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "4");	//��Ӧ����5
					break;
				case 6:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "5");	//��Ӧ����6
					break;
				case 7:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "6");	//��Ӧ����7
					break;
				case 8:
					Res::Draw_IMG(16 + 24 * i, 84 + 24 * k, "7");	//��Ӧ����8
					break;
				}
			}
			else if (pData->getMap()[i][k] == -1)
			{
				Res::DrawIMG(16 + 24 * i, 84 + 24 * k, "����", 0);
			}
			else if (pData->getMap()[i][k] >= 19 && pData->getMap()[i][k] <= 28)  //������---��Χ�ж� ��С������
			{
				Res::DrawIMG(16 + 24 * i, 84 + 24 * k, "ש��", 0);
			}
			else if (pData->getMap()[i][k] >= 39 && pData->getMap()[i][k] < 59)	 //-1 + 20 + 20
			{
				Res::DrawIMG(16 + 24 * i, 84 + 24 * k, "��ʶ", 0); //����
			}
			else if (pData->getMap()[i][k] >= 59)
			{
				Res::DrawIMG(16 + 24 * i, 84 + 24 * k, "��ʶ", 1);//�ʺ�
			}
		}
	}
}