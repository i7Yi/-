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
    virtual void Move();//��̬������
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
    friend class Food;//��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
};
class SnakeVIP :public Snake//�̳�����
{
    void Move();
};
#endif // SNAKE_H