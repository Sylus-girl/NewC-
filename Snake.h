#pragma once
#include <vector>
#include <graphics.h>

enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Snake {
private:
    std::vector<Point> body;
    Direction direction;
    COLORREF color;
    int speed;
    bool isAlive;
    bool needMove;

public:
    Snake(int x, int y, COLORREF c);
    void Move();
    void Draw();
    void ChangeDirection(Direction newDir);
    bool CheckCollision(const Snake& other);
    bool EatFood(const Point& food);
    bool IsAlive() const { return isAlive; }
    void Die() { isAlive = false; }
    Point GetHead() const { return body[0]; }
    const std::vector<Point>& GetBody() const { return body; }
    void SetNeedMove(bool need) { needMove = need; }
}; 