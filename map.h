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
    void PrintInitmap();//绘制初始地图
    void InitMap();
    void InitMap1();
    void InitMap2();
private:
    friend class Snake;
    friend class Food;
    int choose;
    std::vector<Point> initmap;//相同的数组名，不同的初始化函数
};
#endif // MAP_H