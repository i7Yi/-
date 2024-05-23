#ifndef MAP_H
#define MAP_H

#include <vector>
#include "point.h"
#include "food.h"
#include "snake.h"
class Snake;
class Food;
class Map
{
public:
    Map(int);
    Map() { choose = 0; }
    void PrintInitmap();//���Ƴ�ʼ��ͼ
    void InitMap();
    void InitMap1();
    void InitMap2();
private:
    friend class Snake;
    friend class Food;
    int choose;
    std::vector<Point> initmap;//��ͬ������������ͬ�ĳ�ʼ������
};
#endif // MAP_H