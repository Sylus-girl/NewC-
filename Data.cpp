#include "Data.h"
#include "Res.h"             //用到资源
#include"Common.h"
void Data::constValue(int i, int j, int value)
{
	map[i][j] = value;
}

void Data::changeValue(int i, int j, int value)
{
	map[i][j] += value;
}

void Data::Set()
{
	//设置随机数种子
	srand((unsigned)time(NULL));
	//把map全部初始化为0
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int j = 0; j < Res::COL; j++)
		{
			map[i][j] = 0;
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//随机设置十个雷 用-1表示 
	for (int i = 0; i < Res::MineNum; )
	{
		//数组的有效下标 [0,9]
		int r = rand() % Res::ROW;
		int c = rand() % Res::COL;
		//随机下标可能有重复的---需要判断当前位置是否有设置为雷
		if (map[r][c] == 0)
		{
			changeValue(r, c, -1);
			//只有执行了这里的代码，才成功设置了雷 -1 后++
			i++;
		}
	}
	//把以雷为中心的九宫格数据都+1，雷除外
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			//找到雷,并遍历雷所在的九宫格
			if (map[i][k] == -1)
			{
				for (int r = i - 1; r <= i + 1; r++)
				{
					for (int c = k - 1; c <= k + 1; c++)
					{
						//对周围的数据加1,注意要防止出现数组下标为-1的情况(越界)
						if ((r >= 0 && r < Res::ROW && c >= 0 && c < Res::COL) && map[r][c] != -1)
						{
							changeValue(r, c, 1);//++map[r][c];
						}
					}
				}
			}
		}
	}
	//加密格子 遍历每一个元素,对每一个元素加一个数处理,让它与原来不同,就不会输出原来对应的图片
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			changeValue(i, k, 20);    //所有的都需要加密
		}
	}

}
array<array<int, 9>, 9>& Data::getMap()
{
	// TODO: 在此处插入 return 语句
	return map;

}
