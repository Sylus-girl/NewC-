#include "Data.h"
#include "Res.h"             //�õ���Դ
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
	//�������������
	srand((unsigned)time(NULL));
	//��mapȫ����ʼ��Ϊ0
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

	//�������ʮ���� ��-1��ʾ 
	for (int i = 0; i < Res::MineNum; )
	{
		//�������Ч�±� [0,9]
		int r = rand() % Res::ROW;
		int c = rand() % Res::COL;
		//����±�������ظ���---��Ҫ�жϵ�ǰλ���Ƿ�������Ϊ��
		if (map[r][c] == 0)
		{
			changeValue(r, c, -1);
			//ֻ��ִ��������Ĵ��룬�ųɹ��������� -1 ��++
			i++;
		}
	}
	//������Ϊ���ĵľŹ������ݶ�+1���׳���
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			//�ҵ���,�����������ڵľŹ���
			if (map[i][k] == -1)
			{
				for (int r = i - 1; r <= i + 1; r++)
				{
					for (int c = k - 1; c <= k + 1; c++)
					{
						//����Χ�����ݼ�1,ע��Ҫ��ֹ���������±�Ϊ-1�����(Խ��)
						if ((r >= 0 && r < Res::ROW && c >= 0 && c < Res::COL) && map[r][c] != -1)
						{
							changeValue(r, c, 1);//++map[r][c];
						}
					}
				}
			}
		}
	}
	//���ܸ��� ����ÿһ��Ԫ��,��ÿһ��Ԫ�ؼ�һ��������,������ԭ����ͬ,�Ͳ������ԭ����Ӧ��ͼƬ
	for (int i = 0; i < Res::ROW; i++)
	{
		for (int k = 0; k < Res::COL; k++)
		{
			changeValue(i, k, 20);    //���еĶ���Ҫ����
		}
	}

}
array<array<int, 9>, 9>& Data::getMap()
{
	// TODO: �ڴ˴����� return ���
	return map;

}
