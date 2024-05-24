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
void Controller::Start()//��ʼ����
{
    SetWindowSize(55, 40);//���ô��ڴ�С
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ɼ���
    SetColor(2);//���ÿ�ʼ������ɫ
    StartInterface* start = new StartInterface();//��̬����һ��StartInterface��start
    start->Action();//��ʼ����
    delete start;//�ͷ��ڴ�ռ�

    /*���ù��λ�ã��������ʾ��ȴ�������������*/
    SetCursorPosition(13, 26);
    std::cout << "�밴�������ʼ... ";
    SetCursorPosition(13, 27);
    system("pause");
}
bool Controller::enter_interface()
{
    /*���Ƶ�¼����*/
    system("cls");
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "����������������������������������������������������������������������������������";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��                 ̰����                  ��";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��                  ��¼                   ��";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��                  ע��                   ��";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��                �޸�����                 ��";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��                �鿴����                 ��";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ��                  ˵��                   ��";
    Sleep(30);
    SetCursorPosition(9, 21);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 22);
    std::cout << " ��                  �˳�                   ��";
    SetCursorPosition(9, 23);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 24);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(10, 25);
    std::cout << "����������������������������������������������������������������������������������";
    Sleep(100);
    SetCursorPosition(19, 12);
    SetBackColor();
    std::cout << "��¼";
    SetCursorPosition(19, 14);
    SetColor(11);
    std::cout << "ע��";
    SetCursorPosition(18, 16);
    std::cout << "�޸�����";
    SetCursorPosition(18, 18);
    std::cout << "�鿴����";
    SetCursorPosition(19, 20);
    std::cout << "˵��";
    SetCursorPosition(19, 22);
    std::cout << "�˳�";
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
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
                    std::cout << "��¼";
                    SetCursorPosition(19, 14);
                    SetColor(11);
                    std::cout << "ע��";
                    --tmp_key;
                    break;
                }
                case 3:
                {
                    SetCursorPosition(19, 14);
                    SetBackColor();
                    std::cout << "ע��";
                    SetCursorPosition(18, 16);
                    SetColor(11);
                    std::cout << "�޸�����";
                    --tmp_key;
                    break;
                }
                case 4:
                {
                    SetCursorPosition(18, 16);
                    SetBackColor();
                    std::cout << "�޸�����";
                    SetCursorPosition(18, 18);
                    SetColor(11);
                    std::cout << "�鿴����";
                    --tmp_key;
                    break;
                }
                case 5:
                {
                    SetCursorPosition(18, 18);
                    SetBackColor();
                    std::cout << "�鿴����";
                    SetCursorPosition(19, 20);
                    SetColor(11);
                    std::cout << "˵��";
                    --tmp_key;
                    break;
                }
                case 6:
                {
                    SetCursorPosition(19, 20);
                    SetBackColor();
                    std::cout << "˵��";
                    SetCursorPosition(19, 22);
                    SetColor(11);
                    std::cout << "�˳�";
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
                    std::cout << "ע��";
                    SetCursorPosition(19, 12);
                    SetColor(11);
                    std::cout << "��¼";
                    ++tmp_key;
                    break;

                case 2:
                    SetCursorPosition(18, 16);
                    SetBackColor();
                    std::cout << "�޸�����";
                    SetCursorPosition(19, 14);
                    SetColor(11);
                    std::cout << "ע��";
                    ++tmp_key;
                    break;

                case 3:
                    SetCursorPosition(18, 18);
                    SetBackColor();
                    std::cout << "�鿴����";
                    SetCursorPosition(18, 16);
                    SetColor(11);
                    std::cout << "�޸�����";
                    ++tmp_key;
                    break;

                case 4:
                    SetCursorPosition(19, 20);
                    SetBackColor();
                    std::cout << "˵��";
                    SetCursorPosition(18, 18);
                    SetColor(11);
                    std::cout << "�鿴����";
                    ++tmp_key;
                    break;

                case 5:
                    SetCursorPosition(19, 22);
                    SetBackColor();
                    std::cout << "�˳�";
                    SetCursorPosition(19, 20);
                    SetColor(11);
                    std::cout << "˵��";
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
        //�쳣����catch
        catch (int error) {
            if (error == -114514)
            {
                SetCursorPosition(14, 20);
                std::cout << "û���û�������ע�ᣡ" << std::endl;
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
                std::cout << "û���û�������ע�ᣡ" << std::endl;
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
    std::cout << "����������������������������������������������������������������������������������";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��                 ��Ϸ˵��                ��";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��        ��ӭ����̰������Ϸ!����Ϸ        ��";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��        �ṩ�˷ḻ�Ĺ���,�����û�        ��";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��        �û���¼��ע�ᡢVIPϵͳ��        ��";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��        �������ĵ�ͼ����Լ�����         ��";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��        ����                           ��";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��                                         ��";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��               ��ESC����                 ��";
    Sleep(30);
    SetCursorPosition(10, 20);
    std::cout << "����������������������������������������������������������������������������������";

}

void Controller::Select()//ѡ�����
{
    /*��ʼ������ѡ��*/
    SetColor(3);
    SetCursorPosition(13, 16);
    std::cout << "                          ";
    SetCursorPosition(13, 17);
    std::cout << "                          ";
    SetCursorPosition(6, 11);
    std::cout << "��ѡ����Ϸ�Ѷȣ�";
    SetCursorPosition(6, 12);
    std::cout << "(���¼�ѡ��,�س�ȷ��)";
    SetCursorPosition(27, 12);
    SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
    std::cout << "��ģʽ";
    SetCursorPosition(27, 14);
    SetColor(3);
    std::cout << "��ͨģʽ";
    SetCursorPosition(27, 16);
    std::cout << "����ģʽ";
    SetCursorPosition(27, 18);
    std::cout << "����ģʽ";
    SetCursorPosition(0, 21);
    score = 0;

    /*���·����ѡ��ģ��*/
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while ((ch = _getch()))
    {
        switch (ch)//��������
        {
        case 72://UP�Ϸ����
            if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
            {
                switch (key)
                {
                case 2:
                    SetCursorPosition(27, 12);//����ѡ�������ñ���ɫ
                    SetBackColor();
                    std::cout << "��ģʽ";

                    SetCursorPosition(27, 14);//����ѡ����ȡ���ұ���ɫ
                    SetColor(3);
                    std::cout << "��ͨģʽ";

                    --key;
                    break;
                case 3:
                    SetCursorPosition(27, 14);
                    SetBackColor();
                    std::cout << "��ͨģʽ";

                    SetCursorPosition(27, 16);
                    SetColor(3);
                    std::cout << "����ģʽ";

                    --key;
                    break;
                case 4:
                    SetCursorPosition(27, 16);
                    SetBackColor();
                    std::cout << "����ģʽ";

                    SetCursorPosition(27, 18);
                    SetColor(3);
                    std::cout << "����ģʽ";

                    --key;
                    break;
                }
            }
            break;

        case 80://DOWN�·����
            if (key < 4)
            {
                switch (key)
                {
                case 1:
                    SetCursorPosition(27, 14);
                    SetBackColor();
                    std::cout << "��ͨģʽ";
                    SetCursorPosition(27, 12);
                    SetColor(3);
                    std::cout << "��ģʽ";

                    ++key;
                    break;
                case 2:
                    SetCursorPosition(27, 16);
                    SetBackColor();
                    std::cout << "����ģʽ";
                    SetCursorPosition(27, 14);
                    SetColor(3);
                    std::cout << "��ͨģʽ";

                    ++key;
                    break;
                case 3:
                    SetCursorPosition(27, 18);
                    SetBackColor();
                    std::cout << "����ģʽ";
                    SetCursorPosition(27, 16);
                    SetColor(3);
                    std::cout << "����ģʽ";

                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter�س���
            flag = true;
            break;
        default://��Ч����
            break;
        }
        if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

        SetCursorPosition(0, 31);//������������½ǣ�����ر���˸Ӱ����Ϸ����
    }

    switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
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

void Controller::DrawGame(int choice)//������Ϸ����
{
    system("cls");//����

    /*���Ƶ�ͼ*/
    SetColor(3);
    Map* cmap = new Map(choice);
    cmap->PrintInitmap();
    delete cmap;

    /*���Ʋ����*/
    SetColor(3);
    SetCursorPosition(34, 1);
    std::cout << "Greedy Snake";
    SetCursorPosition(35, 2);
    std::cout << "̰����";
    SetCursorPosition(32, 4);
    std::cout << "�Ѷȣ�";
    SetCursorPosition(37, 5);
    switch (key)
    {
    case 1:
        std::cout << "��ģʽ";
        break;
    case 2:
        std::cout << "��ͨģʽ";
        break;
    case 3:
        std::cout << "����ģʽ";
        break;
    case 4:
        std::cout << "����ģʽ";
        break;
    default:
        break;
    }
    SetCursorPosition(32, 7);
    std::cout << "�÷֣�";
    SetCursorPosition(37, 7);
    SetColor(11);
    std::cout << "       0";//��
    SetColor(3);
    SetCursorPosition(32, 9);
    std::cout << "������";
    SetColor(3);
    SetCursorPosition(34, 13);
    std::cout << " ������ƶ�";
    SetCursorPosition(34, 15);
    std::cout << " ESC����ͣ";
}

int Controller::PlayGame(int choice)//��Ϸ����ѭ��
{

    /*��ʼ���ߺ�ʳ��*/
    Snake* csnake = new Snake();
    /*��ʼ������*/
    foot = 0;
    /*��ʼ����ʼʱ��*/
    player.time = 0;
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();
    /*�ж��Ƿ�Ϊvip��*/
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
    srand((unsigned)time(NULL));//������������ӣ����û�� ʳ��ĳ���λ�ý���̶�

    cfood->DrawFood(*csnake, choice);
    Map* cmap = new Map(choice);
    /*��Ϸѭ��*/
    while (csnake->OverEdge() && csnake->HitItself() && csnake->CheckMap(*cmap)) //�ж��Ƿ�ײǽ��ײ���������Ƿ�������
    {
        /*�߲�������*/
        foot++;
        RewriteFoot();//���»��Ʋ���
        /*����ѡ��˵�*/
        if (!csnake->ChangeDirection()) //��Esc��ʱ
        {
            /*��ͣʱ���ۼ�����ʱ��*/
            endTime = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = endTime - startTime;
            player.time += diff.count();
            int tmp = Menu();//���Ʋ˵������õ�����ֵ
            switch (tmp)
            {
            case 1://������Ϸ
                /*���¿�ʼ��ʱ*/
                startTime = std::chrono::system_clock::now();
                break;

            case 2://���¿�ʼ
                delete csnake;
                delete cfood;
                return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

            case 3://�˳���Ϸ
                delete csnake;
                delete cfood;
                return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

            default:
                break;
            }
        }

        if (csnake->GetFood(*cfood)) //�Ե�ʳ��
        {
            csnake->Move();//������
            UpdateScore(1);//���·�����1Ϊ����Ȩ��
            RewriteScore();//���»��Ʒ���
            cfood->DrawFood(*csnake, choice);//������ʳ��
        }
        else
        {
            csnake->NormalMove();//�������ƶ�
        }

        if (csnake->GetBigFood(*cfood)) //�Ե���ʱʳ��
        {
            csnake->Move();
            UpdateScore(cfood->GetProgressBar() / 5);//����������ʱʳ�������ȷ��
            RewriteScore();
        }

        if (cfood->GetBigFlag()) //�����ʱ����ʱʳ���˸��
        {
            cfood->FlashBigFood();
        }

        Sleep(speed);//�����ߵ��ƶ�Ч��
    }

    /*������*/
    endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = endTime - startTime;
    player.time += diff.count();

    delete csnake;//�ͷŷ�����ڴ�ռ�
    delete cfood;
    delete cmap;
    int tmp = GameOver();//������Ϸ�������棬��������ѡ��
    switch (tmp)
    {
    case 1:
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    default:
        return 2;
    }
}

void Controller::UpdateScore(const int& tmp)//���·���
{
    int map_add = 0;
    if (key_map != 1) map_add = 20;//���÷���ͬʱ���ݵ�ͼѡ�񣬳���ԭʼ��ͼ������20
    score += key * 10 * tmp + map_add;//���÷���������Ϸ�Ѷȼ����˵Ĳ���tmpȷ��
}

void Controller::RewriteScore()//�ػ����
{

    SetCursorPosition(38, 7);
    SetColor(11);
    int tmp = score;

    std::cout << std::setw(6) << score;
}

void Controller::RewriteFoot()//�ػ沽��
{
    /*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/
    SetCursorPosition(38, 9);
    SetColor(11);
    int tmp = foot;

    std::cout << std::setw(6) << foot;
}

int Controller::Menu()//ѡ��˵�
{
    /*���Ʋ˵�*/
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "�˵���";
    Sleep(100);
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "������Ϸ";
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "���¿�ʼ";
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "�˳���Ϸ";
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = _getch()))//����
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
                    std::cout << "������Ϸ";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ";

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "���¿�ʼ";
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "�˳���Ϸ";

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
                    std::cout << "���¿�ʼ";
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "������Ϸ";

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "�˳���Ϸ";
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ";

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

    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
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

void Controller::Game()//��Ϸһ��ѭ��
{
    Start();//��ʼ����
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



        while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
        {
            Select();//ѡ�����
            system("cls");
            SetColor(11);
            SetCursorPosition(10, 8);

            std::cout << "������������������������������������������������������������������������������";
            Sleep(30);
            SetCursorPosition(9, 9);
            std::cout << " ��                ��ͼ                   ��";
            Sleep(30);
            SetCursorPosition(9, 10);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(9, 11);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(9, 12);
            std::cout << " ��              ԭʼ��ͼ                 ��";
            Sleep(30);
            SetCursorPosition(9, 13);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(9, 14);
            std::cout << " ��              ʮ��·��                 ��";
            Sleep(30);
            SetCursorPosition(9, 15);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(9, 16);
            std::cout << " ��              ���뻨԰                 ��";
            Sleep(30);
            SetCursorPosition(9, 17);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(9, 18);
            std::cout << " ��                                       ��";
            Sleep(30);
            SetCursorPosition(10, 19);
            std::cout << "������������������������������������������������������������������������������";

            Sleep(100);
            SetCursorPosition(17, 12);
            SetBackColor();
            std::cout << "ԭʼ��ͼ";
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
                            std::cout << "ԭʼ��ͼ";
                            SetCursorPosition(17, 14);
                            SetColor(11);
                            std::cout << "ʮ��·��";
                            --tmp_key;
                            break;
                        case 3:
                            SetCursorPosition(17, 14);
                            SetBackColor();
                            std::cout << "ʮ��·��";
                            SetCursorPosition(17, 16);
                            SetColor(11);
                            std::cout << "���뻨԰";
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
                            std::cout << "ʮ��·��";
                            SetCursorPosition(17, 12);
                            SetColor(11);
                            std::cout << "ԭʼ��ͼ";
                            ++tmp_key;
                            break;
                        case 2:
                            SetCursorPosition(17, 16);
                            SetBackColor();
                            std::cout << "���뻨԰";
                            SetCursorPosition(17, 14);
                            SetColor(11);
                            std::cout << "ʮ��·��";
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

            DrawGame(choice);//������Ϸ����
            int tmp = PlayGame(choice);//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp

            if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
            {
                system("cls");
                continue;
            }
            else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
            {
                break;
            }
            else
            {
                printf("��Чָ��!");
                Sleep(1000);
                break;
            }
        }

    }
}



int Controller::GameOver()//��Ϸ��������
{
    /*����ͬ�������а�*/
    User_Rank temuser(player, score);
    Rank temrank;
    temrank.AddRank(temuser);
    temrank.SaveRank();
    /*������Ϸ��������*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "����������������������������������������������������������������������������������";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��               Game Over !!!              ��";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��              ���ź��������              ��";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��             ��ķ���Ϊ��                 ��";
    SetCursorPosition(22, 13);
    std::cout << std::setw(6) << score;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��             ��Ĳ���Ϊ��                 ��";
    SetCursorPosition(22, 14);
    std::cout << std::setw(6) << foot;
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��             ����ʱ��Ϊ��                 ��";
    SetCursorPosition(22, 15);
    std::cout << std::setw(6) << int(player.time + 0.5);
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��          ����һ��        ѧϰȥ��        ��";
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ��                                          ��";
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "����������������������������������������������������������������������������������";
    Sleep(100);
    SetCursorPosition(15, 18);
    SetBackColor();
    std::cout << "����һ��";
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
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
                std::cout << "����һ��";
                SetCursorPosition(23, 18);
                SetColor(11);
                std::cout << "ѧϰȥ��";
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(23, 18);
                SetBackColor();
                std::cout << "ѧϰȥ��";
                SetCursorPosition(15, 18);
                SetColor(11);
                std::cout << "����һ��";
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
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    default:
        return 1;
    }
}