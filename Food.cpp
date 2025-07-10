#include "Food.h"

Food::Food() : color(RED), size(20) {
    srand(static_cast<unsigned>(time(nullptr)));
    position = Point(0, 0);
}

void Food::Generate(const Snake& snake1, const Snake& snake2) {
    bool validPosition;
    do {
        validPosition = true;
        position.x = (rand() % 40) * 20;  // Grid size: 800/20 = 40
        position.y = (rand() % 30) * 20;  // Grid size: 600/20 = 30

        // Check overlap with snake bodies
        for (const auto& p : snake1.GetBody()) {
            if (position.x == p.x && position.y == p.y) {
                validPosition = false;
                break;
            }
        }
        
        for (const auto& p : snake2.GetBody()) {
            if (position.x == p.x && position.y == p.y) {
                validPosition = false;
                break;
            }
        }
    } while (!validPosition);
}

void Food::Draw() {
    setfillcolor(color);
    fillrectangle(position.x, position.y, position.x + size, position.y + size);
} 