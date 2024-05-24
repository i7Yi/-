#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

void Food::DrawFood(Snake& csnake, int choice)//绘制食物
{
    /*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。
      同时每5颗食物就出现一颗限时食物*/
    Map* cmap = new Map(choice);

    while (true)
    {
        int tmp_x = rand() % 29;
        int tmp_y = rand() % 29;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : csnake.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
                flag = true;
                break;
            }
        }
        if (!FoodCheckMap(tmp_x, tmp_y, *cmap))
        {
            flag = true;
        }

        if (flag)
            continue;
        x = tmp_x;
        y = tmp_y;
        SetCursorPosition(x, y);
        SetColor(13);
        std::cout << "★";
        ++cnt;
        cnt %= 3;
        if (cnt == 0)
        {
            DrawBigFood(csnake, choice);
        }
        break;
    }
    delete cmap;
}

void Food::DrawBigFood(Snake& csnake, int choice)//绘制限时食物
{
    SetCursorPosition(5, 0);
    SetColor(11);
    std::cout << "------------------------------------------";//进度条
    progress_bar = 42;
    Map* cmap = new Map(choice);
    while (true)
    {
        int tmp_x = rand() % 29;
        int tmp_y = rand() % 29;
        if (tmp_x < 2) tmp_x += 2;
        if (tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : csnake.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
            {
                flag = true;
                break;
            }
        }
        if (!BigFoodCheckMap(tmp_x, tmp_y, *cmap))
        {
            flag = true;
        }
        if (flag)
            continue;

        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(18);
        std::cout << "■";
        big_flag = true;
        flash_flag = true;
        break;
    }
    delete cmap;
}

int Food::GetCnt()
{
    return cnt;
}

void Food::FlashBigFood()//闪烁限时食物
{
    SetCursorPosition(big_x, big_y);
    SetColor(18);
    if (flash_flag)
    {
        std::cout << "  ";
        flash_flag = false;
    }
    else
    {
        std::cout << "■";
        flash_flag = true;
    }

    SetCursorPosition(26, 0);
    SetColor(11);
    for (int i = 42; i >= progress_bar; --i)//进度条缩短
        std::cout << "\b \b";
    --progress_bar;
    if (progress_bar == 0) {
        SetCursorPosition(big_x, big_y);
        std::cout << "  ";
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}

bool Food::GetBigFlag()
{
    return big_flag;
}

int Food::GetProgressBar()
{
    return progress_bar;
}

bool Food::FoodCheckMap(int tx, int ty, Map& cmap)
{
    for (auto& point : cmap.initmap)
    {
        if (tx == point.GetX() && ty == point.GetY())
        {
            return false;
        }
    }
    return true;
}
bool Food::BigFoodCheckMap(int tx, int ty, Map& cmap)
{
    for (auto& point : cmap.initmap)
    {
        if (tx == point.GetX() && ty == point.GetY())
        {
            return false;
        }
    }
    return true;
}