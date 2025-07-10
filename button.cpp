#include "button.h"
#include"Common.h"
#include"Res.h"
#include "Data.h"
Button::Button(int ImgSize) {

	this->ImgSize = ImgSize;
	Res::DrawIMG(105, 20, "笑脸", 0);
}

void Button::ClickButton(ExMessage msg, Data* pData)
{
	int r = (msg.x - 16) / ImgSize;	//x
	int c = (msg.y - 84) / ImgSize; //y

	//游戏控制的边框

	if ((msg.x >= 105 && msg.y >= 20) && (msg.x <= 141 && msg.y <= 56))
	{
		//printf("%d %d\n", msg.x, msg.y);
		if (msg.message == WM_LBUTTONDOWN)		//左键按下还原游戏
		{
			Res::DrawIMG(105, 20, "笑脸", 0);
			for (int i = 0; i < Res::ROW; i++)
			{
				for (int k = 0; k < Res::COL; k++)
				{
					if (pData->getMap()[i][k] >= -1 && pData->getMap()[i][k] <= 8)	//数字的还原
						pData->changeValue(i, k, 20);

					if (pData->getMap()[i][k] >= 39 && pData->getMap()[i][k] < 59)	//旗子的还原
						pData->changeValue(i, k, -20);

					if (pData->getMap()[i][k] >= 59)								//问号的还原
						pData->changeValue(i, k, -40);
				}
			}
		}
		else if (msg.message == WM_RBUTTONDOWN)		//右键按下开启bug
		{
			Res::DrawIMG(105, 20, "笑脸", 3);
			for (int i = 0; i < Res::ROW; i++)
			{
				for (int k = 0; k < Res::COL; k++)
				{
					if (pData->getMap()[i][k] >= 19 && pData->getMap()[i][k] <= 28)
						pData->changeValue(i, k, -20);
				}
			}
		}
	}

	//地图的边框

	int mapWidth = 16 + Res::COL * ImgSize;
	int mapHeight = 84 + Res::ROW * ImgSize;

	if ((msg.x >= 16 && msg.y >= 84) && (msg.x <= mapWidth && msg.y <= mapHeight))
	{
		//鼠标左键按下,有事件响应,左键打开格子
		if (msg.message == WM_LBUTTONDOWN)
		{
			printf("%d %d\n", msg.x, msg.y);
			printf("%d %d\n", r, c);
			//什么时候能够打开，没有打开的时候就打开（只能点击1次有效数字不会再变化）
			if (pData->getMap()[r][c] >= 19 && pData->getMap()[r][c] <= 28)
			{
				pData->changeValue(r, c, -20);      //map[r][c] -= 20  
				boomBlank(pData, r, c);	//检测一下是不是空白格子，是，炸开，不是直接退出
			}
		}
		//鼠标右键按下,有事件响应,右键标记格子
		else if (msg.message == WM_RBUTTONDOWN)
		{
			//是否能够标记：如果没有打开就能标记
			if (pData->getMap()[r][c] >= 19 && pData->getMap()[r][c] <= 28)
			{
				pData->changeValue(r, c, 20);		//再次加密 map[r][c] += 20
			}
			else if (pData->getMap()[r][c] >= 39 && pData->getMap()[r][c] < 59)
			{
				pData->changeValue(r, c, 20);		//再次点击能够出现问号 再次加密 map[r][c] += 20

			}
			else if (pData->getMap()[r][c] >= 59)	//再次点击能够取消格子 双层解密 map[r][c] -= 20
			{
				pData->changeValue(r, c, -40);
			}
		}
	}

}

void Button::boomBlank(Data* pData, int row, int col)
{
	//判断row col位置是不是空白格子(如果不是直接退出)
	if (pData->getMap()[row][col] == 0)
	{
		for (int r = row - 1; r <= row + 1; r++)            //遍历九宫格，是空白直接炸开
		{
			for (int c = col - 1; c <= col + 1; c++)
			{
				if ((r >= 0 && r < Res::ROW && c >= 0 && c < Res::COL)				//没越界
					&& pData->getMap()[r][c] >= 19 && pData->getMap()[r][c] <= 28)	//没有打开
				{
					pData->changeValue(r, c, -20);			 //map[r][c] -= 20
					boomBlank(pData, r, c);					 //继续遍历新的九宫格,继续打开
				}
			}
		}
	}
}
//游戏结束条件 [每点击一次就判断一下] 输了返回 -1  没结束返回 0 赢了返回 1
int Button::judge(Data* pData, int row, int col)
{
	if (!(row >= 0 && col >= 0 && row < Res::ROW && col < Res::COL))
	{
		return 0;
	}
	//点到了雷，结束	输了
	if (pData->getMap()[row][col] == -1 || pData->getMap()[row][col] == 19)    //任何时候都可以判断
	{
		return -1;
	}
	//点完了格子，结束 赢了 点开了81 - 10 = 71 个格子(都点开了)
	int cnt = 0;
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			//统计打开的格子的数量
			if (pData->getMap()[i][k] >= 0 && pData->getMap()[i][k] <= 8)
			{
				++cnt;    //最终有71个
			}
		}
	}
	if (Res::ROW * Res::COL - Res::MineNum == cnt)
	{
		return 1;
	}
	return 0;
}