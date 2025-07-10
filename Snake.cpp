#include "Snake.h"

Snake::Snake(int x, int y, COLORREF c) : direction(NONE), color(c), speed(20), isAlive(true), needMove(false) {
    body.push_back(Point(x, y));
    for (int i = 1; i < 3; i++) {
        body.push_back(Point(x - i * 20, y));
    }
}

void Snake::Move() {
    if (!isAlive || direction == NONE) return;

    Point newHead = body[0];
    switch (direction) {
        case UP:    newHead.y -= speed; break;
        case DOWN:  newHead.y += speed; break;
        case LEFT:  newHead.x -= speed; break;
        case RIGHT: newHead.x += speed; break;
    }

    // Check wall collision
    if (newHead.x < 0 || newHead.x >= 800 || newHead.y < 0 || newHead.y >= 600) {
        isAlive = false;
        return;
    }

    // 检查是否会与自己的身体碰撞
    for (size_t i = 0; i < body.size(); i++) {
        if (newHead.x == body[i].x && newHead.y == body[i].y) {
            isAlive = false;
            return;
        }
    }

    body.insert(body.begin(), newHead);
    body.pop_back();
}

void Snake::Draw() {
    for (const auto& p : body) {
        setfillcolor(color);
        fillrectangle(p.x, p.y, p.x + 19, p.y + 19);  // 留出1像素的网格线
    }
}

void Snake::ChangeDirection(Direction newDir) {
    // Prevent 180-degree turns
    if ((direction == UP && newDir == DOWN) ||
        (direction == DOWN && newDir == UP) ||
        (direction == LEFT && newDir == RIGHT) ||
        (direction == RIGHT && newDir == LEFT))
        return;
    
    direction = newDir;
}

bool Snake::CheckCollision(const Snake& other) {
    // Check collision with other snake's body
    Point head = GetHead();
    for (const auto& p : other.GetBody()) {
        if (head.x == p.x && head.y == p.y) {
            return true;
        }
    }
    return false;
}

bool Snake::EatFood(const Point& food) {
    Point head = GetHead();
    if (head.x == food.x && head.y == food.y) {
        body.push_back(body.back());
        return true;
    }
    return false;
} 