#pragma once
#include "Snake.h"
#include <cstdlib>
#include <ctime>

class Food {
private:
    Point position;
    COLORREF color;
    int size;

public:
    Food();
    void Generate(const Snake& snake1, const Snake& snake2);
    void Draw();
    Point GetPosition() const { return position; }
}; 