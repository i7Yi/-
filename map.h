#ifndef MAP_H
#define MAP_H

#include <vector>
#include "point.h"

class Map
{
public:
    Map()//默认构造函数，将正方形各点压入initmap
    {
        initmap.emplace_back(Point(1, 1));
        initmap.emplace_back(Point(2, 1));
        initmap.emplace_back(Point(3, 1));
        initmap.emplace_back(Point(4, 1));
        initmap.emplace_back(Point(5, 1));
        initmap.emplace_back(Point(6, 1));
        initmap.emplace_back(Point(7, 1));
        initmap.emplace_back(Point(8, 1));
        initmap.emplace_back(Point(9, 1));
        initmap.emplace_back(Point(10, 1));
        initmap.emplace_back(Point(11, 1));
        initmap.emplace_back(Point(12, 1));
        initmap.emplace_back(Point(13, 1));
        initmap.emplace_back(Point(14, 1));
        initmap.emplace_back(Point(15, 1));
        initmap.emplace_back(Point(16, 1));
        initmap.emplace_back(Point(17, 1));
        initmap.emplace_back(Point(18, 1));
        initmap.emplace_back(Point(19, 1));
        initmap.emplace_back(Point(20, 1));
        initmap.emplace_back(Point(21, 1));
        initmap.emplace_back(Point(22, 1));
        initmap.emplace_back(Point(23, 1));
        initmap.emplace_back(Point(24, 1));
        initmap.emplace_back(Point(25, 1));
        initmap.emplace_back(Point(26, 1));
        initmap.emplace_back(Point(27, 1));
        initmap.emplace_back(Point(28, 1));
        initmap.emplace_back(Point(29, 1));
        initmap.emplace_back(Point(1, 2));
        initmap.emplace_back(Point(29, 2));
        initmap.emplace_back(Point(1, 3));
        initmap.emplace_back(Point(29, 3));
        initmap.emplace_back(Point(1, 4));
        initmap.emplace_back(Point(29, 4));
        initmap.emplace_back(Point(1, 5));
        initmap.emplace_back(Point(29, 5));
        initmap.emplace_back(Point(1, 6));
        initmap.emplace_back(Point(29, 6));
        initmap.emplace_back(Point(1, 7));
        initmap.emplace_back(Point(29, 7));
        initmap.emplace_back(Point(1, 8));
        initmap.emplace_back(Point(29, 8));
        initmap.emplace_back(Point(1, 9));
        initmap.emplace_back(Point(29, 9));
        initmap.emplace_back(Point(1, 10));
        initmap.emplace_back(Point(29, 10));
        initmap.emplace_back(Point(1, 11));
        initmap.emplace_back(Point(29, 11));
        initmap.emplace_back(Point(1, 12));
        initmap.emplace_back(Point(29, 12));
        initmap.emplace_back(Point(1, 13));
        initmap.emplace_back(Point(29, 13));
        initmap.emplace_back(Point(1, 14));
        initmap.emplace_back(Point(29, 14));
        initmap.emplace_back(Point(1, 15));
        initmap.emplace_back(Point(29, 15));
        initmap.emplace_back(Point(1, 16));
        initmap.emplace_back(Point(29, 16));
        initmap.emplace_back(Point(1, 17));
        initmap.emplace_back(Point(29, 17));
        initmap.emplace_back(Point(1, 18));
        initmap.emplace_back(Point(29, 18));
        initmap.emplace_back(Point(1, 19));
        initmap.emplace_back(Point(29, 19));
        initmap.emplace_back(Point(1, 20));
        initmap.emplace_back(Point(29, 20));
        initmap.emplace_back(Point(1, 21));
        initmap.emplace_back(Point(29, 21));
        initmap.emplace_back(Point(1, 22));
        initmap.emplace_back(Point(29, 22));
        initmap.emplace_back(Point(1, 23));
        initmap.emplace_back(Point(29, 23));
        initmap.emplace_back(Point(1, 24));
        initmap.emplace_back(Point(29, 24));
        initmap.emplace_back(Point(1, 25));
        initmap.emplace_back(Point(29, 25));
        initmap.emplace_back(Point(1, 26));
        initmap.emplace_back(Point(29, 26));
        initmap.emplace_back(Point(1, 27));
        initmap.emplace_back(Point(29, 27));
        initmap.emplace_back(Point(1, 28));
        initmap.emplace_back(Point(29, 28));
        initmap.emplace_back(Point(1, 29));
        initmap.emplace_back(Point(29, 29));









        initmap.emplace_back(Point(1, 29));
        initmap.emplace_back(Point(2, 29));
        initmap.emplace_back(Point(3, 29));
        initmap.emplace_back(Point(4, 29));
        initmap.emplace_back(Point(5, 29));
        initmap.emplace_back(Point(6, 29));
        initmap.emplace_back(Point(7, 29));
        initmap.emplace_back(Point(8, 29));
        initmap.emplace_back(Point(9, 29));
        initmap.emplace_back(Point(10, 29));
        initmap.emplace_back(Point(11, 29));
        initmap.emplace_back(Point(12, 29));
        initmap.emplace_back(Point(13, 29));
        initmap.emplace_back(Point(14, 29));
        initmap.emplace_back(Point(15, 29));
        initmap.emplace_back(Point(16, 29));
        initmap.emplace_back(Point(17, 29));
        initmap.emplace_back(Point(18, 29));
        initmap.emplace_back(Point(19, 29));
        initmap.emplace_back(Point(20, 29));
        initmap.emplace_back(Point(21, 29));
        initmap.emplace_back(Point(22, 29));
        initmap.emplace_back(Point(23, 29));
        initmap.emplace_back(Point(24, 29));
        initmap.emplace_back(Point(25, 29));
        initmap.emplace_back(Point(26, 29));
        initmap.emplace_back(Point(27, 29));
        initmap.emplace_back(Point(28, 29));
        initmap.emplace_back(Point(29, 29));
    }
    void PrintInitmap();//绘制初始地图
private:
    std::vector<Point> initmap;//保存初始地图
    /*Map类可自定义多种地图，只需将表示地图的各个点保存在相应的map中，并在Snake类中增加相应判断撞墙函数即可
     std::vector<Point> map1;
     std::vector<Point> map2;
     */
};
#endif // MAP_H
