#include "Res.h"
#include <Windows.h> 
map<string, IMAGE*> Res::img;		//图片
map<string, string> Res::music;	    //音乐
int Res::MineNum = 10;				//雷的数量
int Res::ROW = 9;						    //行|列
int Res::COL = 9;
/*———————————————————————————————————————————
		加载 和 初始化 图片相关内容
————————————————————————————————————————————*/
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
	//背景
	string background = "./images/background.png";
	//砖块
	string block[2] = { "./images/Initial.png","./images/0.png" };
	//笑脸标识 smile victory  fail error(外挂)
	string face[4] = { "./images/ReStart0.png","./images/ReStartWin.png",
					   "./images/ReStartLose.png","./images/ReStartLose.png" };
	//地雷 未踩雷 标记雷 踩中雷

	string mine[3] = { "./images/Unbombed.png", "./images/Bombed.png", "./images/Unbombed.png" };
	string sign[3] = { "./images/Marked.png","./images/Marked.png",
					  "./images/Marked.png" };
	//普通数字 1-8
	for (int i = 1; i <= 8; i++) {
		string init = "./images/numbers/";
		string strURL = "0";
		strURL[0] += i;
		strURL += ".png";
		strURL = init + strURL;
		img[to_string(i - 1)] = new IMAGE;		  //img["0"]
		loadimage(img[to_string(i - 1)], strURL.c_str());
	}

	//倒计时数字 0-9
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

	img["背景"] = new IMAGE;
	img["砖块"] = new IMAGE[2];
	img["笑脸"] = new IMAGE[4];
	img["地雷"] = new IMAGE[3];
	img["标识"] = new IMAGE[3];
	loadimage(img["背景"], background.c_str());	//370-250=120 479-320=159
	for (int i = 0; i < 3; i++)
	{
		std::wstring wmine = s2ws(mine[i]);
		std::wstring wsign = s2ws(sign[i]);
		loadimage(img["地雷"] + i, wmine.c_str());
		loadimage(img["标记"] + i, wsign.c_str());
	}
	for (int i = 0; i < 4; i++)
	{
		std::wstring wface = s2ws(face[i]);
		loadimage(img["表情"] + i, wface.c_str());
	}
	for (int i = 0; i < 2; i++)
	{
		std::wstring wblock = s2ws(block[i]);
		loadimage(img["方块"] + i, wblock.c_str());
	}
}
//获取图片的高度
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
//只有一张图片的贴图: 背景图贴图 
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
	delete img["背景"];
	delete[]img["砖块"];
	delete[]img["笑脸"];
	delete[]img["地雷"];
	delete[]img["标识"];

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



// 选择难度并重新加载资源
void Res::selectDifficulty(Difficulty diff) {
	setDifficulty(diff);

	// 释放之前的图片资源
	for (auto& pair : img) {
		delete pair.second;
	}
	img.clear();

	// 重新加载资源
	string background = "./images/background.png";
	//砖块
	string block[2] = { "./images/Initial.png","./images/0.png" };
	//笑脸标识 smile victory  fail error(外挂)
	string face[4] = { "./images/ReStart0.png","./images/ReStartWin.png",
					   "./images/ReStartLose.png","./images/ReStartLose.png" };
	//地雷 未踩雷 标记雷 踩中雷

	string mine[3] = { "./images/Unbombed.png", "./images/Bombed.png", "./images/Unbombed.png" };
	string sign[3] = { "./images/Marked.png","./images/Marked.png",
					  "./images/Marked.png" };

	// 加载图片资源
	img["背景"] = new IMAGE;
	loadimage(img["背景"], background.c_str());

	for (int i = 0; i < 3; i++)
	{
		loadimage(img["地雷"] + i, mine[i].data());
		loadimage(img["标识"] + i, sign[i].data());
	}
	for (int i = 0; i < 4; i++)
	{
		loadimage(img["笑脸"] + i, face[i].data());
	}
	for (int i = 0; i < 2; i++)
	{
		loadimage(img["砖块"] + i, block[i].data());
	}
}

	// 可以在这里添加重新调整窗口大小的代码
	int width = Res::WIDTH("背景") + (Res::COL - 9) * 24;
	int height = Res::HEIGHT("背景") + (Res::ROW - 9) * 24;
	initgraph(width, height, EW_SHOWCONSOLE);
}

// 获取图片的宽度
int Res::WIDTH(string name)
{
	return GetInstance()->img[name]->getwidth();
}

// 获取图片的高度
int Res::HEIGHT(string name)
{
	return GetInstance()->img[name]->getheight();
}

Res* Res::GetInstance()
{
	static Res* res = new Res;
	return res;
}

// 绘制单张图片
void Res::Draw_IMG(int x, int y, string name)
{
	putimage(x, y, GetInstance()->img[name]);
}

// 绘制图片数组
void Res::DrawIMG(int x, int y, string name, int preIndex)
{
	putimage(x, y, GetInstance()->img[name] + preIndex);
}

// 播放音乐
DWORD __stdcall Res::PlayMusic(LPVOID lparame)
{
	return 0;
}

Res::~Res()
{
	// 释放图片资源
	for (auto& pair : img) {
		delete pair.second;
	}
}