#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include "account.h"
#include "rank.h"

User player;
void Controller::Start()//开始界面
{
    SetWindowSize(55, 40);//设置窗口大小
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//光标可见性
    SetColor(2);//设置开始动画颜色
    StartInterface* start = new StartInterface();//动态分配一个StartInterface类start
    start->Action();//开始动画
    delete start;//释放内存空间

    /*设置光标位置，并输出提示语，等待任意键输入结束*/
    SetCursorPosition(13, 26);
    std::cout << "请按任意键开始... ";
    SetCursorPosition(13, 27);
    system("pause");
}
bool Controller::enter_interface()
{
    /*绘制登录界面*/
    system("cls");
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃                 贪吃蛇                  ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃                  登录                   ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃                  注册                   ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃                修改密码                 ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃                查看排行                 ┃";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ┃                  说明                   ┃";
    Sleep(30);
    SetCursorPosition(9, 21);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 22);
    std::cout << " ┃                  退出                   ┃";
    SetCursorPosition(9, 23);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 24);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(10, 25);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(100);
    SetCursorPosition(19, 12);
    SetBackColor();
    std::cout << "登录";
    SetCursorPosition(19, 14);
    SetColor(11);
    std::cout << "注册";
    SetCursorPosition(18, 16);
    std::cout << "修改密码";
    SetCursorPosition(18, 18);
    std::cout << "查看排行";
    SetCursorPosition(19, 20);
    std::cout << "说明";
    SetCursorPosition(19, 22);
    std::cout << "退出";
    SetCursorPosition(0, 31);

    /*选择部分*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch())) {
        switch (ch) {
        case 72://UP
        {
            if (tmp_key > 1) {
                switch (tmp_key)
                {
                case 2:
                {
                    SetCursorPosition(19, 12);
                    SetBackColor();
                    std::cout << "登录";
                    SetCursorPosition(19, 14);
                    SetColor(11);
                    std::cout << "注册";
                    --tmp_key;
                    break;
                }
                case 3:
                {
                    SetCursorPosition(19, 14);
                    SetBackColor();
                    std::cout << "注册";
                    SetCursorPosition(18, 16);
                    SetColor(11);
                    std::cout << "修改密码";
                    --tmp_key;
                    break;
                }
                case 4:
                {
                    SetCursorPosition(18, 16);
                    SetBackColor();
                    std::cout << "修改密码";
                    SetCursorPosition(18, 18);
                    SetColor(11);
                    std::cout << "查看排行";
                    --tmp_key;
                    break;
                }
                case 5:
                {
                    SetCursorPosition(18, 18);
                    SetBackColor();
                    std::cout << "查看排行";
                    SetCursorPosition(19, 20);
                    SetColor(11);
                    std::cout << "说明";
                    --tmp_key;
                    break;
                }
                case 6:
                {
                    SetCursorPosition(19, 20);
                    SetBackColor();
                    std::cout << "说明";
                    SetCursorPosition(19, 22);
                    SetColor(11);
                    std::cout << "退出";
                    --tmp_key;
                    break;
                }
                }
            }
        }
        break;
        case 80://DOWN
        {
            if (tmp_key < 6) {
                switch (tmp_key) {
                case 1:
                    SetCursorPosition(19, 14);
                    SetBackColor();
                    std::cout << "注册";
                    SetCursorPosition(19, 12);
                    SetColor(11);
                    std::cout << "登录";
                    ++tmp_key;
                    break;

                case 2:
                    SetCursorPosition(18, 16);
                    SetBackColor();
                    std::cout << "修改密码";
                    SetCursorPosition(19, 14);
                    SetColor(11);
                    std::cout << "注册";
                    ++tmp_key;
                    break;

                case 3:
                    SetCursorPosition(18, 18);
                    SetBackColor();
                    std::cout << "查看排行";
                    SetCursorPosition(18, 16);
                    SetColor(11);
                    std::cout << "修改密码";
                    ++tmp_key;
                    break;

                case 4:
                    SetCursorPosition(19, 20);
                    SetBackColor();
                    std::cout << "说明";
                    SetCursorPosition(18, 18);
                    SetColor(11);
                    std::cout << "查看排行";
                    ++tmp_key;
                    break;

                case 5:
                    SetCursorPosition(19, 22);
                    SetBackColor();
                    std::cout << "退出";
                    SetCursorPosition(19, 20);
                    SetColor(11);
                    std::cout << "说明";
                    ++tmp_key;
                    break;
                }
            }
        }
        break;
        case 13://Enter
        {
            flag = true;
            break;
        }
        }

        if (flag)
        {
            break;
        }

    }



    if (tmp_key == 1)
    {
        system("cls");
        int judge = -1;
        try {
            while (true)
            {
                judge = loginUser();
                if (judge == 0)
                {
                    return true;
                }
                else if (judge == 1)
                {
                    continue;
                }
                else if (judge == 2)
                {
                    return false;
                }
            }
        }
        //异常处理catch
        catch (int error) {
            if (error == -114514)
            {
                SetCursorPosition(14, 20);
                std::cout << "没有用户！请先注册！" << std::endl;
                Sleep(1000);
                return false;
            }
        }

    }
    else if (tmp_key == 2)
    {
        system("cls");
        int judge = -1;;
        while (true)
        {
            judge = registerUser();
            if (judge == 1)
            {
                return false;
            }
            else if (judge == 2)
            {
                continue;
            }
            else if (judge == 3)
            {

            }
        }
    }
    else if (tmp_key == 3)
    {
        system("cls");
        int judge = -1;
        try {
            while (true)
            {
                judge = changePassword();
                if (judge == 0)
                {
                    return true;
                }
                else if (judge == 1)
                {
                    continue;
                }
                else if (judge == 2)
                {
                    return false;
                }
            }
        }
        catch (int error) {
            if (error == -114514)
            {
                std::cout << "没有用户！请先注册！" << std::endl;
                Sleep(1000);
                return false;
            }
        }
    }
    else if (tmp_key == 4)
    {
        system("cls");
        Rank temrank;
        temrank.SortRank();
        temrank.PrintRank();
        while (_getch() != 27);
        return false;
    }
    else if (tmp_key == 5)
    {
        system("cls");
        introduction();
        while (_getch() != 27);
        return false;
    }
    else if (tmp_key == 6)
    {
        system("cls");
        //std::cout << "Bye!";
        //Sleep(1000);
        exit(0);
    }

}

void Controller::introduction()
{

    system("cls");
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃                 游戏说明                ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃        欢迎来到贪吃蛇游戏!本游戏        ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃        提供了丰富的功能,包括用户        ┃";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃        用户登录和注册、VIP系统、        ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃        多样化的地图风格以及排行         ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃        榜功能                           ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃                                         ┃";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ┃               按ESC返回                 ┃";
    Sleep(30);
    SetCursorPosition(10, 20);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

}

void Controller::Select()//选择界面
{
    /*初始化界面选项*/
    SetColor(3);
    SetCursorPosition(13, 16);
    std::cout << "                          ";
    SetCursorPosition(13, 17);
    std::cout << "                          ";
    SetCursorPosition(6, 11);
    std::cout << "请选择游戏难度：";
    SetCursorPosition(6, 12);
    std::cout << "(上下键选择,回车确认)";
    SetCursorPosition(27, 12);
    SetBackColor();//第一个选项设置背景色以表示当前选中
    std::cout << "简单模式";
    SetCursorPosition(27, 14);
    SetColor(3);
    std::cout << "普通模式";
    SetCursorPosition(27, 16);
    std::cout << "困难模式";
    SetCursorPosition(27, 18);
    std::cout << "炼狱模式";
    SetCursorPosition(0, 21);
    score = 0;

    /*上下方向键选择模块*/
    int ch;//记录键入值
    key = 1;//记录选中项，初始选择第一个
    bool flag = false;//记录是否键入Enter键标记，初始置为否
    while ((ch = _getch()))
    {
        switch (ch)//检测输入键
        {
        case 72://UP上方向键
            if (key > 1)//当此时选中项为第一项时，UP上方向键无效
            {
                switch (key)
                {
                case 2:
                    SetCursorPosition(27, 12);//给待选中项设置背景色
                    SetBackColor();
                    std::cout << "简单模式";

                    SetCursorPosition(27, 14);//将已选中项取消我背景色
                    SetColor(3);
                    std::cout << "普通模式";

                    --key;
                    break;
                case 3:
                    SetCursorPosition(27, 14);
                    SetBackColor();
                    std::cout << "普通模式";

                    SetCursorPosition(27, 16);
                    SetColor(3);
                    std::cout << "困难模式";

                    --key;
                    break;
                case 4:
                    SetCursorPosition(27, 16);
                    SetBackColor();
                    std::cout << "困难模式";

                    SetCursorPosition(27, 18);
                    SetColor(3);
                    std::cout << "炼狱模式";

                    --key;
                    break;
                }
            }
            break;

        case 80://DOWN下方向键
            if (key < 4)
            {
                switch (key)
                {
                case 1:
                    SetCursorPosition(27, 14);
                    SetBackColor();
                    std::cout << "普通模式";
                    SetCursorPosition(27, 12);
                    SetColor(3);
                    std::cout << "简单模式";

                    ++key;
                    break;
                case 2:
                    SetCursorPosition(27, 16);
                    SetBackColor();
                    std::cout << "困难模式";
                    SetCursorPosition(27, 14);
                    SetColor(3);
                    std::cout << "普通模式";

                    ++key;
                    break;
                case 3:
                    SetCursorPosition(27, 18);
                    SetBackColor();
                    std::cout << "炼狱模式";
                    SetCursorPosition(27, 16);
                    SetColor(3);
                    std::cout << "困难模式";

                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter回车键
            flag = true;
            break;
        default://无效按键
            break;
        }
        if (flag) break;//输入Enter回车键确认，退出检查输入循环

        SetCursorPosition(0, 31);//将光标置于左下角，避免关标闪烁影响游戏体验
    }

    switch (key)//根据所选选项设置蛇的移动速度，speed值越小，速度越快
    {
    case 1:
        speed = 135;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 60;
        break;
    case 4:
        speed = 30;
        break;
    default:
        break;
    }
}

void Controller::DrawGame(int choice)//绘制游戏界面
{
    system("cls");//清屏

    /*绘制地图*/
    SetColor(3);
    Map* cmap = new Map(choice);
    cmap->PrintInitmap();
    delete cmap;

    /*绘制侧边栏*/
    SetColor(3);
    SetCursorPosition(34, 1);
    std::cout << "Greedy Snake";
    SetCursorPosition(35, 2);
    std::cout << "贪吃蛇";
    SetCursorPosition(32, 4);
    std::cout << "难度：";
    SetCursorPosition(37, 5);
    switch (key)
    {
    case 1:
        std::cout << "简单模式";
        break;
    case 2:
        std::cout << "普通模式";
        break;
    case 3:
        std::cout << "困难模式";
        break;
    case 4:
        std::cout << "炼狱模式";
        break;
    default:
        break;
    }
    SetCursorPosition(32, 7);
    std::cout << "得分：";
    SetCursorPosition(37, 7);
    SetColor(11);
    std::cout << "       0";//零
    SetColor(3);
    SetCursorPosition(32, 9);
    std::cout << "步数：";
    SetColor(3);
    SetCursorPosition(34, 13);
    std::cout << " 方向键移动";
    SetCursorPosition(34, 15);
    std::cout << " ESC键暂停";
}

int Controller::PlayGame(int choice)//游戏二级循环
{

    /*初始化蛇和食物*/
    Snake* csnake = new Snake();
    /*初始化步数*/
    foot = 0;
    /*初始化开始时间*/
    player.time = 0;
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();
    /*判断是否为vip蛇*/
    if (player.vipjudge == 1)
    {
        csnake = new SnakeVIP();
    }
    else
    {
        csnake = new Snake();
    }
    Food* cfood = new Food();
    SetColor(6);
    csnake->InitSnake();
    srand((unsigned)time(NULL));//设置随机数种子，如果没有 食物的出现位置将会固定

    cfood->DrawFood(*csnake, choice);
    Map* cmap = new Map(choice);
    /*游戏循环*/
    while (csnake->OverEdge() && csnake->HitItself() && csnake->CheckMap(*cmap)) //判断是否撞墙或撞到自身，即是否还有生命
    {
        /*蛇步长增加*/
        foot++;
        RewriteFoot();//重新绘制步数
        /*调出选择菜单*/
        if (!csnake->ChangeDirection()) //按Esc键时
        {
            /*暂停时间累加至总时间*/
            endTime = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = endTime - startTime;
            player.time += diff.count();
            int tmp = Menu();//绘制菜单，并得到返回值
            switch (tmp)
            {
            case 1://继续游戏
                /*重新开始计时*/
                startTime = std::chrono::system_clock::now();
                break;

            case 2://重新开始
                delete csnake;
                delete cfood;
                return 1;//将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始

            case 3://退出游戏
                delete csnake;
                delete cfood;
                return 2;//将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏

            default:
                break;
            }
        }

        if (csnake->GetFood(*cfood)) //吃到食物
        {
            csnake->Move();//蛇增长
            UpdateScore(1);//更新分数，1为分数权重
            RewriteScore();//重新绘制分数
            cfood->DrawFood(*csnake, choice);//绘制新食物
        }
        else
        {
            csnake->NormalMove();//蛇正常移动
        }

        if (csnake->GetBigFood(*cfood)) //吃到限时食物
        {
            csnake->Move();
            UpdateScore(cfood->GetProgressBar() / 5);//分数根据限时食物进度条确定
            RewriteScore();
        }

        if (cfood->GetBigFlag()) //如果此时有限时食物，闪烁它
        {
            cfood->FlashBigFood();
        }

        Sleep(speed);//制造蛇的移动效果
    }

    /*蛇死亡*/
    endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    player.time += diff.count();

    delete csnake;//释放分配的内存空间
    delete cfood;
    delete cmap;
    int tmp = GameOver();//绘制游戏结束界面，并返回所选项
    switch (tmp)
    {
    case 1:
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
    default:
        return 2;
    }
}

void Controller::UpdateScore(const int& tmp)//更新分数
{
    int map_add = 0;
    if (key_map != 1) map_add = 20;//所得分数同时根据地图选择，除了原始地图其他加20
    score += key * 10 * tmp + map_add;//所得分数根据游戏难度及传人的参数tmp确定
}

void Controller::RewriteScore()//重绘分数
{

    SetCursorPosition(38, 7);
    SetColor(11);
    int tmp = score;

    std::cout << std::setw(6) << score;
}

void Controller::RewriteFoot()//重绘步数
{
    /*为保持分数尾部对齐，将最大分数设置为6位，计算当前分数位数，将剩余位数用空格补全，再输出分数*/
    SetCursorPosition(38, 9);
    SetColor(11);
    int tmp = foot;

    std::cout << std::setw(6) << foot;
}

int Controller::Menu()//选择菜单
{
    /*绘制菜单*/
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "菜单：";
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "继续游戏";
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "重新开始";
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "退出游戏";
    SetCursorPosition(0, 31);

    /*选择部分*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))//查找
    {
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34, 21);
                    SetBackColor();
                    std::cout << "继续游戏";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始";

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始";
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "退出游戏";

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "重新开始";
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "继续游戏";

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "退出游戏";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "重新开始";

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }

    if (tmp_key == 1) //选择继续游戏，则将菜单擦除
    {
        SetCursorPosition(32, 19);
        std::cout << "      ";
        SetCursorPosition(34, 21);
        std::cout << "        ";
        SetCursorPosition(34, 23);
        std::cout << "        ";
        SetCursorPosition(34, 25);
        std::cout << "        ";
    }
    return tmp_key;
}

void Controller::Game()//游戏一级循环
{
    Start();//开始界面
    while (true)
    {
        while (true)
        {
            int judge_enter = enter_interface();
            if (judge_enter)
            {
                break;
            }
            else
            {
                continue;
            }

        }
        while (true)
        {
            int judge_after_enter = ui_after_enter();
            if (judge_after_enter == 1)
            {
                break;
            }
            else if (judge_after_enter == 2)
            {
                if (cdk_dh() == 1)
                {
                    player.vipjudge = 1;
                }
                else
                {
                    continue;
                }
            }
        }



        while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
        {
            Select();//选择界面
            system("cls");
            SetColor(11);
            SetCursorPosition(10, 8);

            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            Sleep(30);
            SetCursorPosition(9, 9);
            std::cout << " ┃                地图                   ┃";
            Sleep(30);
            SetCursorPosition(9, 10);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(9, 11);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(9, 12);
            std::cout << " ┃              原始地图                 ┃";
            Sleep(30);
            SetCursorPosition(9, 13);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(9, 14);
            std::cout << " ┃              十字路口                 ┃";
            Sleep(30);
            SetCursorPosition(9, 15);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(9, 16);
            std::cout << " ┃              中央花园                 ┃";
            Sleep(30);
            SetCursorPosition(9, 17);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(9, 18);
            std::cout << " ┃                                       ┃";
            Sleep(30);
            SetCursorPosition(10, 19);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

            Sleep(100);
            SetCursorPosition(17, 12);
            SetBackColor();
            std::cout << "原始地图";
            SetColor(11);

            int ch;
            int tmp_key = 1;
            bool flag = false;
            while ((ch = _getch()))
            {
                switch (ch)
                {
                case 72:
                    if (tmp_key > 1)
                    {
                        switch (tmp_key)
                        {
                        case 2:
                            SetCursorPosition(17, 12);
                            SetBackColor();
                            std::cout << "原始地图";
                            SetCursorPosition(17, 14);
                            SetColor(11);
                            std::cout << "十字路口";
                            --tmp_key;
                            break;
                        case 3:
                            SetCursorPosition(17, 14);
                            SetBackColor();
                            std::cout << "十字路口";
                            SetCursorPosition(17, 16);
                            SetColor(11);
                            std::cout << "中央花园";
                            --tmp_key;
                            break;
                        }
                    }
                    break;
                case 80:
                    if (tmp_key < 3)
                    {
                        switch (tmp_key)
                        {
                        case 1:
                            SetCursorPosition(17, 14);
                            SetBackColor();
                            std::cout << "十字路口";
                            SetCursorPosition(17, 12);
                            SetColor(11);
                            std::cout << "原始地图";
                            ++tmp_key;
                            break;
                        case 2:
                            SetCursorPosition(17, 16);
                            SetBackColor();
                            std::cout << "中央花园";
                            SetCursorPosition(17, 14);
                            SetColor(11);
                            std::cout << "十字路口";
                            ++tmp_key;
                            break;
                        }
                    }
                    break;

                case 13:
                    flag = true;
                    break;

                }
                if (flag)
                {
                    break;
                }
            }
            int choice;
            key_map = tmp_key;
            choice = tmp_key;
            system("cls");

            DrawGame(choice);//绘制游戏界面
            int tmp = PlayGame(choice);//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp

            if (tmp == 1) //返回值为1时重新开始游戏
            {
                system("cls");
                continue;
            }
            else if (tmp == 2) //返回值为2时退出游戏
            {
                break;
            }
            else
            {
                printf("无效指令!");
                Sleep(1000);
                break;
            }
        }

    }
}



int Controller::GameOver()//游戏结束界面
{
    /*分数同步至排行榜*/
    User_Rank temuser(player, score);
    Rank temrank;
    temrank.AddRank(temuser);
    temrank.SaveRank();
    /*绘制游戏结束界面*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃               Game Over !!!              ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃              很遗憾！你挂了              ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃             你的分数为：                 ┃";
    SetCursorPosition(22, 13);
    std::cout << std::setw(6) << score;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃             你的步数为：                 ┃";
    SetCursorPosition(22, 14);
    std::cout << std::setw(6) << foot;
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃             所用时间为：                 ┃";
    SetCursorPosition(22, 15);
    std::cout << std::setw(6) << int(player.time + 0.5);
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃          再来一局        学习去了        ┃";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(100);
    SetCursorPosition(15, 18);
    SetBackColor();
    std::cout << "再来一局";
    SetCursorPosition(0, 31);

    /*选择部分*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                SetCursorPosition(15, 18);
                SetBackColor();
                std::cout << "再来一局";
                SetCursorPosition(23, 18);
                SetColor(11);
                std::cout << "学习去了";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(23, 18);
                SetBackColor();
                std::cout << "学习去了";
                SetCursorPosition(15, 18);
                SetColor(11);
                std::cout << "再来一局";
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }

    SetColor(11);
    switch (tmp_key)
    {
    case 1:
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
    default:
        return 1;
    }
}