#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"
#include "map.h"

class Food;
class Map;
class Snake
{
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };

    Snake() {
        snake.emplace_back(2, 2);
        direction = Direction::DOWN;
    }
    void InitSnake();
    virtual void Move();//多态性体现
    void NormalMove();
    bool OverEdge();
    bool HitItself();
    bool ChangeDirection();
    bool GetFood(const Food&);
    bool GetBigFood(Food&);
    bool CheckMap(Map&);
protected:
    std::deque<Point> snake;
    Direction direction;
    friend class Food;//将Food类置为友元，以便访问其私有元素
};
class SnakeVIP :public Snake//继承体现
{
    void Move();
};
#endif // SNAKE_H