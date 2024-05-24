#include "map.h"
#include <windows.h>

void Map::PrintInitmap()//绘制初始地图
{
    for (auto& point : initmap)
    {
        point.Print();
        Sleep(13);//调用Sleep函数可营造动画效果
    }
}
Map::Map(int choice)//用于选择地图
{
    choose = choice;
    if (choice == 1) InitMap();
    else if (choice == 2) InitMap1();
    else if (choice == 3) InitMap2();

}
void Map::InitMap()
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
void Map::InitMap1()
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

    //竖线打印
    initmap.emplace_back(Point(1, 2));
    initmap.emplace_back(Point(29, 2));

    initmap.emplace_back(Point(1, 3));
    initmap.emplace_back(Point(29, 3));
    initmap.emplace_back(Point(6, 3));
    initmap.emplace_back(Point(8, 3));
    initmap.emplace_back(Point(24, 3));
    initmap.emplace_back(Point(22, 3));
    initmap.emplace_back(Point(1, 4));
    initmap.emplace_back(Point(29, 4));

    initmap.emplace_back(Point(6, 4));
    initmap.emplace_back(Point(8, 4));
    initmap.emplace_back(Point(24, 4));
    initmap.emplace_back(Point(22, 4));

    initmap.emplace_back(Point(1, 5));
    initmap.emplace_back(Point(29, 5));
    //对角线点--左上角十字和右上角十字
    initmap.emplace_back(Point(6, 5));
    initmap.emplace_back(Point(8, 5));
    initmap.emplace_back(Point(24, 5));
    initmap.emplace_back(Point(22, 5));
    initmap.emplace_back(Point(5, 5));
    initmap.emplace_back(Point(9, 5));
    initmap.emplace_back(Point(25, 5));
    initmap.emplace_back(Point(21, 5));
    initmap.emplace_back(Point(4, 5));
    initmap.emplace_back(Point(10, 5));
    initmap.emplace_back(Point(26, 5));
    initmap.emplace_back(Point(20, 5));


    initmap.emplace_back(Point(1, 6));
    initmap.emplace_back(Point(29, 6));
    initmap.emplace_back(Point(1, 7));
    initmap.emplace_back(Point(29, 7));

    initmap.emplace_back(Point(6, 7));
    initmap.emplace_back(Point(8, 7));
    initmap.emplace_back(Point(24, 7));
    initmap.emplace_back(Point(22, 7));
    initmap.emplace_back(Point(5, 7));
    initmap.emplace_back(Point(9, 7));
    initmap.emplace_back(Point(25, 7));
    initmap.emplace_back(Point(21, 7));
    initmap.emplace_back(Point(4, 7));
    initmap.emplace_back(Point(10, 7));
    initmap.emplace_back(Point(26, 7));
    initmap.emplace_back(Point(20, 7));

    initmap.emplace_back(Point(1, 8));
    initmap.emplace_back(Point(29, 8));
    initmap.emplace_back(Point(6, 8));
    initmap.emplace_back(Point(8, 8));
    initmap.emplace_back(Point(24, 8));
    initmap.emplace_back(Point(22, 8));
    initmap.emplace_back(Point(1, 9));
    initmap.emplace_back(Point(29, 9));
    initmap.emplace_back(Point(6, 9));
    initmap.emplace_back(Point(8, 9));
    initmap.emplace_back(Point(24, 9));
    initmap.emplace_back(Point(22, 9));
    initmap.emplace_back(Point(1, 10));
    initmap.emplace_back(Point(29, 10));
    initmap.emplace_back(Point(1, 11));
    initmap.emplace_back(Point(29, 11));
    //中心十字
    initmap.emplace_back(Point(14, 11));
    initmap.emplace_back(Point(16, 11));

    initmap.emplace_back(Point(1, 12));
    initmap.emplace_back(Point(29, 12));
    initmap.emplace_back(Point(14, 12));
    initmap.emplace_back(Point(16, 12));
    initmap.emplace_back(Point(1, 13));
    initmap.emplace_back(Point(29, 13));
    initmap.emplace_back(Point(14, 13));
    initmap.emplace_back(Point(16, 13));
    initmap.emplace_back(Point(13, 13));
    initmap.emplace_back(Point(17, 13));
    initmap.emplace_back(Point(12, 13));
    initmap.emplace_back(Point(18, 13));

    initmap.emplace_back(Point(1, 14));
    initmap.emplace_back(Point(29, 14));

    initmap.emplace_back(Point(1, 15));
    initmap.emplace_back(Point(29, 15));
    initmap.emplace_back(Point(14, 15));
    initmap.emplace_back(Point(16, 15));
    initmap.emplace_back(Point(13, 15));
    initmap.emplace_back(Point(17, 15));
    initmap.emplace_back(Point(12, 15));
    initmap.emplace_back(Point(18, 15));
    initmap.emplace_back(Point(1, 16));
    initmap.emplace_back(Point(29, 16));
    initmap.emplace_back(Point(14, 16));
    initmap.emplace_back(Point(16, 16));
    initmap.emplace_back(Point(1, 17));
    initmap.emplace_back(Point(29, 17));
    initmap.emplace_back(Point(14, 17));
    initmap.emplace_back(Point(16, 17));
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
    initmap.emplace_back(Point(6, 21));
    initmap.emplace_back(Point(8, 21));
    initmap.emplace_back(Point(24, 21));
    initmap.emplace_back(Point(22, 21));
    initmap.emplace_back(Point(1, 24));
    initmap.emplace_back(Point(29, 24));
    initmap.emplace_back(Point(6, 22));
    initmap.emplace_back(Point(8, 22));
    initmap.emplace_back(Point(24, 22));
    initmap.emplace_back(Point(22, 22));
    initmap.emplace_back(Point(1, 24));
    //对角线关键点左下角和右下角十字
    initmap.emplace_back(Point(6, 23));
    initmap.emplace_back(Point(8, 23));
    initmap.emplace_back(Point(24, 23));
    initmap.emplace_back(Point(22, 23));
    initmap.emplace_back(Point(5, 23));
    initmap.emplace_back(Point(9, 23));
    initmap.emplace_back(Point(25, 23));
    initmap.emplace_back(Point(21, 23));
    initmap.emplace_back(Point(4, 23));
    initmap.emplace_back(Point(10, 23));
    initmap.emplace_back(Point(26, 23));
    initmap.emplace_back(Point(20, 23));

    initmap.emplace_back(Point(1, 25));
    initmap.emplace_back(Point(29, 25));
    initmap.emplace_back(Point(6, 25));
    initmap.emplace_back(Point(8, 25));
    initmap.emplace_back(Point(24, 25));
    initmap.emplace_back(Point(22, 25));
    initmap.emplace_back(Point(5, 25));
    initmap.emplace_back(Point(9, 25));
    initmap.emplace_back(Point(25, 25));
    initmap.emplace_back(Point(21, 25));
    initmap.emplace_back(Point(4, 25));
    initmap.emplace_back(Point(10, 25));
    initmap.emplace_back(Point(26, 25));
    initmap.emplace_back(Point(20, 25));

    initmap.emplace_back(Point(1, 26));
    initmap.emplace_back(Point(29, 26));
    initmap.emplace_back(Point(6, 26));
    initmap.emplace_back(Point(8, 26));
    initmap.emplace_back(Point(24, 26));
    initmap.emplace_back(Point(22, 26));


    initmap.emplace_back(Point(1, 27));
    initmap.emplace_back(Point(29, 27));


    initmap.emplace_back(Point(1, 28));
    initmap.emplace_back(Point(29, 28));
    initmap.emplace_back(Point(6, 27));
    initmap.emplace_back(Point(8, 27));
    initmap.emplace_back(Point(24, 27));
    initmap.emplace_back(Point(22, 27));
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

void Map::InitMap2()
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
    //左上角
    initmap.emplace_back(Point(15, 6));
    initmap.emplace_back(Point(14, 6));
    initmap.emplace_back(Point(16, 6));
    initmap.emplace_back(Point(13, 6));
    initmap.emplace_back(Point(17, 6));
    initmap.emplace_back(Point(12, 6));
    initmap.emplace_back(Point(18, 6));
    initmap.emplace_back(Point(9, 6));
    initmap.emplace_back(Point(21, 6));
    initmap.emplace_back(Point(8, 6));
    initmap.emplace_back(Point(22, 6));
    initmap.emplace_back(Point(7, 6));
    initmap.emplace_back(Point(23, 6));
    initmap.emplace_back(Point(6, 6));
    initmap.emplace_back(Point(24, 6));




    //内正方形
    initmap.emplace_back(Point(9, 9));
    initmap.emplace_back(Point(21, 9));
    initmap.emplace_back(Point(10, 9));
    initmap.emplace_back(Point(20, 9));
    initmap.emplace_back(Point(11, 9));
    initmap.emplace_back(Point(19, 9));
    initmap.emplace_back(Point(12, 9));
    initmap.emplace_back(Point(18, 9));
    initmap.emplace_back(Point(13, 9));
    initmap.emplace_back(Point(17, 9));
    initmap.emplace_back(Point(14, 9));
    initmap.emplace_back(Point(16, 9));

    //外边界
    initmap.emplace_back(Point(1, 7));
    initmap.emplace_back(Point(29, 7));
    initmap.emplace_back(Point(6, 7));
    initmap.emplace_back(Point(24, 7));

    initmap.emplace_back(Point(1, 8));
    initmap.emplace_back(Point(29, 8));
    initmap.emplace_back(Point(6, 8));
    initmap.emplace_back(Point(24, 8));

    initmap.emplace_back(Point(1, 9));
    initmap.emplace_back(Point(29, 9));
    initmap.emplace_back(Point(6, 9));
    initmap.emplace_back(Point(24, 9));

    initmap.emplace_back(Point(1, 10));
    initmap.emplace_back(Point(29, 10));
    initmap.emplace_back(Point(9, 10));
    initmap.emplace_back(Point(21, 10));

    initmap.emplace_back(Point(1, 11));
    initmap.emplace_back(Point(29, 11));
    initmap.emplace_back(Point(9, 11));
    initmap.emplace_back(Point(21, 11));

    initmap.emplace_back(Point(1, 12));
    initmap.emplace_back(Point(29, 12));
    initmap.emplace_back(Point(6, 12));
    initmap.emplace_back(Point(24, 12));
    initmap.emplace_back(Point(9, 12));
    initmap.emplace_back(Point(21, 12));

    initmap.emplace_back(Point(1, 13));
    initmap.emplace_back(Point(29, 13));
    initmap.emplace_back(Point(6, 13));
    initmap.emplace_back(Point(24, 13));
    initmap.emplace_back(Point(9, 13));
    initmap.emplace_back(Point(21, 13));

    initmap.emplace_back(Point(1, 14));
    initmap.emplace_back(Point(29, 14));
    initmap.emplace_back(Point(6, 14));
    initmap.emplace_back(Point(24, 14));
    initmap.emplace_back(Point(9, 14));
    initmap.emplace_back(Point(21, 14));
    initmap.emplace_back(Point(15, 14));
    initmap.emplace_back(Point(14, 14));
    initmap.emplace_back(Point(16, 14));
    initmap.emplace_back(Point(15, 15));
    initmap.emplace_back(Point(14, 15));
    initmap.emplace_back(Point(16, 15));
    initmap.emplace_back(Point(14, 16));
    initmap.emplace_back(Point(16, 16));
    initmap.emplace_back(Point(15, 16));

    initmap.emplace_back(Point(1, 15));
    initmap.emplace_back(Point(29, 15));
    initmap.emplace_back(Point(6, 15));
    initmap.emplace_back(Point(24, 15));

    initmap.emplace_back(Point(1, 16));
    initmap.emplace_back(Point(29, 16));
    initmap.emplace_back(Point(6, 16));
    initmap.emplace_back(Point(24, 16));
    initmap.emplace_back(Point(9, 16));
    initmap.emplace_back(Point(21, 16));

    initmap.emplace_back(Point(1, 17));
    initmap.emplace_back(Point(29, 17));
    initmap.emplace_back(Point(6, 17));
    initmap.emplace_back(Point(24, 17));
    initmap.emplace_back(Point(9, 17));
    initmap.emplace_back(Point(21, 17));

    initmap.emplace_back(Point(1, 18));
    initmap.emplace_back(Point(29, 18));
    initmap.emplace_back(Point(6, 18));
    initmap.emplace_back(Point(24, 18));
    initmap.emplace_back(Point(9, 18));
    initmap.emplace_back(Point(21, 18));

    initmap.emplace_back(Point(1, 19));
    initmap.emplace_back(Point(29, 19));
    initmap.emplace_back(Point(9, 19));
    initmap.emplace_back(Point(21, 19));

    initmap.emplace_back(Point(1, 20));
    initmap.emplace_back(Point(29, 20));
    initmap.emplace_back(Point(9, 20));
    initmap.emplace_back(Point(21, 20));

    initmap.emplace_back(Point(1, 21));
    initmap.emplace_back(Point(29, 21));
    initmap.emplace_back(Point(6, 21));
    initmap.emplace_back(Point(24, 21));
    initmap.emplace_back(Point(9, 21));
    initmap.emplace_back(Point(21, 21));
    initmap.emplace_back(Point(10, 21));
    initmap.emplace_back(Point(20, 21));
    initmap.emplace_back(Point(11, 21));
    initmap.emplace_back(Point(19, 21));
    initmap.emplace_back(Point(12, 21));
    initmap.emplace_back(Point(18, 21));
    initmap.emplace_back(Point(13, 21));
    initmap.emplace_back(Point(17, 21));
    initmap.emplace_back(Point(14, 21));
    initmap.emplace_back(Point(16, 21));

    initmap.emplace_back(Point(1, 22));
    initmap.emplace_back(Point(29, 22));
    initmap.emplace_back(Point(6, 22));
    initmap.emplace_back(Point(24, 22));

    initmap.emplace_back(Point(1, 23));
    initmap.emplace_back(Point(29, 23));
    initmap.emplace_back(Point(6, 23));
    initmap.emplace_back(Point(24, 23));

    initmap.emplace_back(Point(1, 24));
    initmap.emplace_back(Point(29, 24));
    initmap.emplace_back(Point(6, 24));
    initmap.emplace_back(Point(24, 24));
    initmap.emplace_back(Point(7, 24));
    initmap.emplace_back(Point(23, 24));
    initmap.emplace_back(Point(8, 24));
    initmap.emplace_back(Point(22, 24));
    initmap.emplace_back(Point(9, 24));
    initmap.emplace_back(Point(21, 24));
    initmap.emplace_back(Point(12, 24));
    initmap.emplace_back(Point(18, 24));
    initmap.emplace_back(Point(13, 24));
    initmap.emplace_back(Point(17, 24));
    initmap.emplace_back(Point(14, 24));
    initmap.emplace_back(Point(16, 24));
    initmap.emplace_back(Point(15, 24));

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
};