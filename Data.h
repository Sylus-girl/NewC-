#pragma once
#include"Common.h"
//���������Ϣ�������ݵĸı�
class Data {

public:
	void Set();									//������|��������|���ñ��
	void constValue(int i, int j, int value);	//��������(��ͼ�е�ֵ)	�޶�����|�ı�����
	void changeValue(int i, int j, int value);
	array<array<int, 9>, 9>& getMap();			//�����滭ͼҪ��������,�ṩ�ⲿ���ʽӿ� 

protected:
	array <array< int, 9 >, 9 > map = { 0 };

};