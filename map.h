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
        initmap.emplace_back(Point(30, 1));
        initmap.emplace_back(Point(31, 1));
        initmap.emplace_back(Point(32, 1));
        initmap.emplace_back(Point(33, 1));
        initmap.emplace_back(Point(34, 1));
        initmap.emplace_back(Point(35, 1));
        initmap.emplace_back(Point(36, 1));
        initmap.emplace_back(Point(37, 1));
        initmap.emplace_back(Point(38, 1));
        initmap.emplace_back(Point(1, 2));
        initmap.emplace_back(Point(38, 2));
        initmap.emplace_back(Point(1, 3));
        initmap.emplace_back(Point(38, 3));
        initmap.emplace_back(Point(1, 4));
        initmap.emplace_back(Point(38, 4));
        initmap.emplace_back(Point(1, 5));
        initmap.emplace_back(Point(38, 5));
        initmap.emplace_back(Point(1, 6));
        initmap.emplace_back(Point(38, 6));
        initmap.emplace_back(Point(1, 7));
        initmap.emplace_back(Point(38, 7));
        initmap.emplace_back(Point(1, 8));
        initmap.emplace_back(Point(38, 8));
        initmap.emplace_back(Point(1, 9));
        initmap.emplace_back(Point(38, 9));
        initmap.emplace_back(Point(1, 10));
        initmap.emplace_back(Point(38, 10));
        initmap.emplace_back(Point(1, 11));
        initmap.emplace_back(Point(38, 11));
        initmap.emplace_back(Point(1, 12));
        initmap.emplace_back(Point(38, 12));
        initmap.emplace_back(Point(1, 13));
        initmap.emplace_back(Point(38, 13));
        initmap.emplace_back(Point(1, 14));
        initmap.emplace_back(Point(38, 14));
        initmap.emplace_back(Point(1, 15));
        initmap.emplace_back(Point(38, 15));
        initmap.emplace_back(Point(1, 16));
        initmap.emplace_back(Point(38, 16));
        initmap.emplace_back(Point(1, 17));
        initmap.emplace_back(Point(38, 17));
        initmap.emplace_back(Point(1, 18));
        initmap.emplace_back(Point(38, 18));
        initmap.emplace_back(Point(1, 19));
        initmap.emplace_back(Point(38, 19));
        initmap.emplace_back(Point(1, 20));
        initmap.emplace_back(Point(38, 20));
        initmap.emplace_back(Point(1, 21));
        initmap.emplace_back(Point(38, 21));
        initmap.emplace_back(Point(1, 22));
        initmap.emplace_back(Point(38, 22));
        initmap.emplace_back(Point(1, 23));
        initmap.emplace_back(Point(38, 23));
        initmap.emplace_back(Point(1, 24));
        initmap.emplace_back(Point(38, 24));
        initmap.emplace_back(Point(1, 25));
        initmap.emplace_back(Point(38, 25));
        initmap.emplace_back(Point(1, 26));
        initmap.emplace_back(Point(38, 26));
        initmap.emplace_back(Point(1, 27));
        initmap.emplace_back(Point(38, 27));
        initmap.emplace_back(Point(1, 28));
        initmap.emplace_back(Point(38, 28));
        initmap.emplace_back(Point(1, 29));
        initmap.emplace_back(Point(38, 29));
        initmap.emplace_back(Point(1, 30));
        initmap.emplace_back(Point(38, 30));
        initmap.emplace_back(Point(1, 31));
        initmap.emplace_back(Point(38, 31));
        initmap.emplace_back(Point(1, 32));
        initmap.emplace_back(Point(38, 32));
        initmap.emplace_back(Point(1, 33));
        initmap.emplace_back(Point(38, 33));
        initmap.emplace_back(Point(1, 34));
        initmap.emplace_back(Point(38, 34));
        initmap.emplace_back(Point(1, 35));
        initmap.emplace_back(Point(38, 35));
        initmap.emplace_back(Point(1, 36));
        initmap.emplace_back(Point(38, 36));
        initmap.emplace_back(Point(1, 37));
        initmap.emplace_back(Point(38, 37));









        initmap.emplace_back(Point(1, 38));
        initmap.emplace_back(Point(2, 38));
        initmap.emplace_back(Point(3, 38));
        initmap.emplace_back(Point(4, 38));
        initmap.emplace_back(Point(5, 38));
        initmap.emplace_back(Point(6, 38));
        initmap.emplace_back(Point(7, 38));
        initmap.emplace_back(Point(8, 38));
        initmap.emplace_back(Point(9, 38));
        initmap.emplace_back(Point(10, 38));
        initmap.emplace_back(Point(11, 38));
        initmap.emplace_back(Point(12, 38));
        initmap.emplace_back(Point(13, 38));
        initmap.emplace_back(Point(14, 38));
        initmap.emplace_back(Point(15, 38));
        initmap.emplace_back(Point(16, 38));
        initmap.emplace_back(Point(17, 38));
        initmap.emplace_back(Point(18, 38));
        initmap.emplace_back(Point(19, 38));
        initmap.emplace_back(Point(20, 38));
        initmap.emplace_back(Point(21, 38));
        initmap.emplace_back(Point(22, 38));
        initmap.emplace_back(Point(23, 38));
        initmap.emplace_back(Point(24, 38));
        initmap.emplace_back(Point(25, 38));
        initmap.emplace_back(Point(26, 38));
        initmap.emplace_back(Point(27, 38));
        initmap.emplace_back(Point(28, 38));
        initmap.emplace_back(Point(29, 38));
        initmap.emplace_back(Point(30, 38));
        initmap.emplace_back(Point(31, 38));
        initmap.emplace_back(Point(32, 38));
        initmap.emplace_back(Point(33, 38));
        initmap.emplace_back(Point(34, 38));
        initmap.emplace_back(Point(35, 38));
        initmap.emplace_back(Point(36, 38));
        initmap.emplace_back(Point(37, 38));
        initmap.emplace_back(Point(38, 38));

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
