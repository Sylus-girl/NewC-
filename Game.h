#pragma once
#include "Snake.h"
#include "Food.h"

class Game {
private:
    Snake snake1;
    Snake snake2;
    Food food;
    bool gameOver;

public:
    Game();
    void Run();
    void ProcessInput();
    void Update();
    void Draw();
    bool IsGameOver() const { return gameOver; }
}; 