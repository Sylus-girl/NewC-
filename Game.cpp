#include "Game.h"
#include <conio.h>
#include <windows.h>

// 游戏结束文本的Unicode编码
const wchar_t GAME_OVER_TEXT[] = L"\u6E38\u620F\u7ED3\u675F\uFF01";  // "游戏结束！" 的Unicode编码

Game::Game() : 
    snake1(100, 300, BLUE),    // 玩家1蓝色蛇
    snake2(700, 300, RED),     // 玩家2红色蛇
    gameOver(false) {
    // 初始化图形窗口
    initgraph(800, 600);
    setbkcolor(GREEN);
    cleardevice();
    
    // 生成第一个食物
    food.Generate(snake1, snake2);
}

void Game::ProcessInput() {
    // 处理玩家1的WASD控制
    if (GetAsyncKeyState('W') & 0x8000) snake1.ChangeDirection(UP);
    if (GetAsyncKeyState('S') & 0x8000) snake1.ChangeDirection(DOWN);
    if (GetAsyncKeyState('A') & 0x8000) snake1.ChangeDirection(LEFT);
    if (GetAsyncKeyState('D') & 0x8000) snake1.ChangeDirection(RIGHT);
    
    // 处理玩家2的方向键控制
    if (GetAsyncKeyState(VK_UP) & 0x8000) snake2.ChangeDirection(UP);
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) snake2.ChangeDirection(DOWN);
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) snake2.ChangeDirection(LEFT);
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) snake2.ChangeDirection(RIGHT);
}

void Game::Update() {
    if (gameOver) return;

    snake1.Move();
    snake2.Move();

    // 检查是否吃到食物
    if (snake1.EatFood(food.GetPosition()) || snake2.EatFood(food.GetPosition())) {
        food.Generate(snake1, snake2);
    }

    // 检查碰撞
    if (snake1.CheckCollision(snake2) || snake2.CheckCollision(snake1)) {
        gameOver = true;
    }

    // 检查是否有蛇死亡
    if (!snake1.IsAlive() || !snake2.IsAlive()) {
        gameOver = true;
    }
}

void Game::Draw() {
    cleardevice();
    
    // 绘制背景网格
    setcolor(DARKGRAY);
    for (int i = 0; i < 800; i += 20) {
        line(i, 0, i, 600);
    }
    for (int i = 0; i < 600; i += 20) {
        line(0, i, 800, i);
    }

    // 绘制蛇和食物
    snake1.Draw();
    snake2.Draw();
    food.Draw();

    // 如果游戏结束，显示结束信息
    if (gameOver) {
        settextcolor(WHITE);
        LOGFONT f;
        gettextstyle(&f);
        f.lfHeight = 30;
        wcscpy_s(f.lfFaceName, L"SimHei");
        f.lfQuality = ANTIALIASED_QUALITY;
        f.lfCharSet = GB2312_CHARSET;
        settextstyle(&f);
        
        int textWidth = textwidth(GAME_OVER_TEXT);
        int textHeight = textheight(GAME_OVER_TEXT);
        int x = (800 - textWidth) / 2;
        int y = (600 - textHeight) / 2;
        outtextxy(x, y, GAME_OVER_TEXT);
    }

    FlushBatchDraw();
}

void Game::Run() {
    BeginBatchDraw();
    while (!gameOver) {
        ProcessInput();
        Update();
        Draw();
        Sleep(100);  // 控制蛇的移动速度
    }
    EndBatchDraw();
    
    // 等待按键后退出
    _getch();
    closegraph();
} 