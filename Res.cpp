#include "Res.h"
#include <Windows.h> 
map<string, IMAGE*> Res::img;		//ͼƬ
map<string, string> Res::music;	    //����
int Res::MineNum = 10;				//�׵�����
int Res::ROW = 9;						    //��|��
int Res::COL = 9;
/*��������������������������������������������������������������������������������������
		���� �� ��ʼ�� ͼƬ�������
����������������������������������������������������������������������������������������*/
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


Res::Res()
{
	//����
	string background = "./images/background.png";
	//ש��
	string block[2] = { "./images/Initial.png","./images/0.png" };
	//Ц����ʶ smile victory  fail error(���)
	string face[4] = { "./images/ReStart0.png","./images/ReStartWin.png",
					   "./images/ReStartLose.png","./images/ReStartLose.png" };
	//���� δ���� ����� ������

	string mine[3] = { "./images/Unbombed.png", "./images/Bombed.png", "./images/Unbombed.png" };
	string sign[3] = { "./images/Marked.png","./images/Marked.png",
					  "./images/Marked.png" };
	//��ͨ���� 1-8
	for (int i = 1; i <= 8; i++) {
		string init = "./images/numbers/";
		string strURL = "0";
		strURL[0] += i;
		strURL += ".png";
		strURL = init + strURL;
		img[to_string(i - 1)] = new IMAGE;		  //img["0"]
		loadimage(img[to_string(i - 1)], strURL.c_str());
	}

	//����ʱ���� 0-9
	for (int i = 0; i <= 9; i++) {
		string init = "./images/timeing/";
		string strURY = "0";
		strURY[0] += i;
		strURY += "_1.png";
		strURY = init + strURY;
		img[to_string(i - 0) + "_"] = new IMAGE;		  //img["0_"]
		loadimage(img[to_string(i - 0) + "_"], strURY.c_str());
		//cout << strURL << endl;
	}

	img["����"] = new IMAGE;
	img["ש��"] = new IMAGE[2];
	img["Ц��"] = new IMAGE[4];
	img["����"] = new IMAGE[3];
	img["��ʶ"] = new IMAGE[3];
	loadimage(img["����"], background.c_str());	//370-250=120 479-320=159
	for (int i = 0; i < 3; i++)
	{
		std::wstring wmine = s2ws(mine[i]);
		std::wstring wsign = s2ws(sign[i]);
		loadimage(img["����"] + i, wmine.c_str());
		loadimage(img["���"] + i, wsign.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::wstring wface = s2ws(face[i]);
		loadimage(img["����"] + i, wface.c_str());
	}
	for (int i = 0; i < 2; i++)
	{
		std::wstring wblock = s2ws(block[i]);
		loadimage(img["����"] + i, wblock.c_str());
	}
}
//��ȡͼƬ�ĸ߶�
int Res::WIDTH(string name)
{
	return GetInstance()->img[name]->getwidth();
}

int Res::HEIGHT(string name)
{
	return GetInstance()->img[name]->getheight();
}

Res* Res::GetInstance()
{
	static Res* res = new Res;
	return res;
}
//ֻ��һ��ͼƬ����ͼ: ����ͼ��ͼ 
void Res::Draw_IMG(int x, int y, string name)
{
	putimage(x, y, GetInstance()->img[name]);
}
void Res::DrawIMG(int x, int y, string name, int preIndex)
{
	putimage(x, y, GetInstance()->img[name] + preIndex);
}
DWORD __stdcall Res::PlayMusic(LPVOID lparame)
{
	return 0;
}

Res::~Res()
{
	delete img["����"];
	delete[]img["ש��"];
	delete[]img["Ц��"];
	delete[]img["����"];
	delete[]img["��ʶ"];

}


void Res::setDifficulty(Difficulty diff) {
	switch (diff) {
	case Difficulty::BEGINNER:
		MineNum = 10;
		ROW = 9;
		COL = 9;
		break;
	case Difficulty::INTERMEDIATE:
		MineNum = 40;
		ROW = 16;
		COL = 16;
		break;
	case Difficulty::EXPERT:
		MineNum = 99;
		ROW = 16;
		COL = 30;
		break;
	}
}



// ѡ���ѶȲ����¼�����Դ
void Res::selectDifficulty(Difficulty diff) {
	setDifficulty(diff);

	// �ͷ�֮ǰ��ͼƬ��Դ
	for (auto& pair : img) {
		delete pair.second;
	}
	img.clear();

	// ���¼�����Դ
	string background = "./images/background.png";
	//ש��
	string block[2] = { "./images/Initial.png","./images/0.png" };
	//Ц����ʶ smile victory  fail error(���)
	string face[4] = { "./images/ReStart0.png","./images/ReStartWin.png",
					   "./images/ReStartLose.png","./images/ReStartLose.png" };
	//���� δ���� ����� ������

	string mine[3] = { "./images/Unbombed.png", "./images/Bombed.png", "./images/Unbombed.png" };
	string sign[3] = { "./images/Marked.png","./images/Marked.png",
					  "./images/Marked.png" };

	// ����ͼƬ��Դ
	img["����"] = new IMAGE;
	loadimage(img["����"], background.c_str());

	for (int i = 0; i < 3; i++)
	{
		loadimage(img["����"] + i, mine[i].data());
		loadimage(img["��ʶ"] + i, sign[i].data());
	}
	for (int i = 0; i < 4; i++)
	{
		loadimage(img["Ц��"] + i, face[i].data());
	}
	for (int i = 0; i < 2; i++)
	{
		loadimage(img["ש��"] + i, block[i].data());
	}
}

	// ����������������µ������ڴ�С�Ĵ���
	int width = Res::WIDTH("����") + (Res::COL - 9) * 24;
	int height = Res::HEIGHT("����") + (Res::ROW - 9) * 24;
	initgraph(width, height, EW_SHOWCONSOLE);
}

// ��ȡͼƬ�Ŀ��
int Res::WIDTH(string name)
{
	return GetInstance()->img[name]->getwidth();
}

// ��ȡͼƬ�ĸ߶�
int Res::HEIGHT(string name)
{
	return GetInstance()->img[name]->getheight();
}

Res* Res::GetInstance()
{
	static Res* res = new Res;
	return res;
}

// ���Ƶ���ͼƬ
void Res::Draw_IMG(int x, int y, string name)
{
	putimage(x, y, GetInstance()->img[name]);
}

// ����ͼƬ����
void Res::DrawIMG(int x, int y, string name, int preIndex)
{
	putimage(x, y, GetInstance()->img[name] + preIndex);
}

// ��������
DWORD __stdcall Res::PlayMusic(LPVOID lparame)
{
	return 0;
}

Res::~Res()
{
	// �ͷ�ͼƬ��Դ
	for (auto& pair : img) {
		delete pair.second;
	}
}