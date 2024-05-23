#include "account.h"
#include "tools.h"
#include "common.h"
#define maxLength_CDK 5//CDK最大长度
#define maxLength_username 8//用户名最大长度
extern User player;
// 注册函数
int registerUser() {
    system("cls");
    while (true)
    {
        system("cls");
        SetColor(11);
        SetCursorPosition(10, 8);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
        Sleep(30);
        SetCursorPosition(9, 9);
        std::cout << " ┃                  注册                    ┃";
        Sleep(30);
        SetCursorPosition(9, 10);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 11);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 12);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 13);
        std::cout << " ┃        用户名：                          ┃";
        Sleep(30);
        SetCursorPosition(9, 14);
        std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
        Sleep(30);
        SetCursorPosition(9, 15);
        std::cout << " ┃         密码：                           ┃";
        Sleep(30);
        SetCursorPosition(9, 16);
        std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
        Sleep(30);
        SetCursorPosition(9, 17);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 18);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(10, 19);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
        std::fstream file_regist("users.txt", std::ios::in | std::ios::out | std::ios::app);
        if (!file_regist.is_open()) {
            SetCursorPosition(14, 18);
            std::cerr << "无法打开文件 users.txt" << std::endl;
            exit(EXIT_FAILURE);
        }

        User newUser;

        SetCursorPosition(14, 11);
        std::cout << "请输入" << maxLength_username << "位以内用户名 ";
        
        char c;
        SetCursorPosition(18.5, 13);
        while (1)
        {
            c = getchar();
            if (c == 10)
            {
                SetCursorPosition(18.5, 13);
                if (newUser.username.size() == 0)
                {
                    continue;
                }
                else break;
            }
            newUser.username += c;

        }
        if (newUser.username.length() > maxLength_username)
        {
            SetCursorPosition(16, 18);
            std::cout << "用户名超出限制" << std::endl;
            Sleep(1000);
            return 2;
        }
        for (auto& ch : newUser.username)
        {
            if ( !((ch>='0'&&ch<='9') || (ch >= 'a' && ch <= 'z') || (ch>='A'&&ch<='Z')))
            {
                SetCursorPosition(16, 18);
                std::cout << "用户名存在非法字符" << std::endl;
                Sleep(1000);
                return 2;
            }
        }
        User currentUser;
        bool usernameExists = false;
        while (file_regist >> currentUser.username >> currentUser.password >> currentUser.vipjudge) {
            if (currentUser.username == newUser.username) {
                SetCursorPosition(15, 18);
                std::cout << "用户名已存在，请换个名字!" << std::endl;
                SetCursorPosition(9, 13);
                std::cout << " ┃        用户名：                          ┃";
                SetCursorPosition(18.5, 13);
                std::cin >> newUser.username;
                file_regist.seekg(0, std::ios::beg); // 将文件读取指针重新定位到文件的开头
                usernameExists = true;
            }
        }
        SetCursorPosition(9, 18);
        std::cout << " ┃                                          ┃";
        SetCursorPosition(10, 11);
        std::cout << "                                         ";
        SetCursorPosition(14, 11);
        std::cout << "请输入密码: ";
        SetCursorPosition(18, 15);
        while (1)
        {
            c = getchar();

            if (c == 10)
            {
                if (newUser.password.size() == 0)
                {
                    SetCursorPosition(18, 15);
                    continue;
                }
                else break;
            }
            newUser.password += c;

        }

        file_regist.close();
        std::fstream file_save("users.txt", std::ios::app);
        usernameExists = true;
        player = newUser;
        file_save << newUser.username << " " << newUser.password << " " << "0" << std::endl;
        SetCursorPosition(10, 11);
        std::cout << "                                          ";
        SetCursorPosition(18, 11);
        std::cout << "注册成功";
        Sleep(1000);
        file_save.close();
        return 1;
    }


}

// 登录函数
int loginUser() {
    while (true)
    {
        system("cls");
        SetColor(11);
        SetCursorPosition(10, 8);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
        Sleep(30);
        SetCursorPosition(9, 9);
        std::cout << " ┃                  登录                    ┃";
        Sleep(30);
        SetCursorPosition(9, 10);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 11);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 12);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 13);
        std::cout << " ┃        用户名：                          ┃";
        Sleep(30);
        SetCursorPosition(9, 14);
        std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
        Sleep(30);
        SetCursorPosition(9, 15);
        std::cout << " ┃         密码：                           ┃";
        Sleep(30);
        SetCursorPosition(9, 16);
        std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
        Sleep(30);
        SetCursorPosition(9, 17);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 18);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(10, 19);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

        std::ifstream file("users.txt", std::ios::in);
        if (!file.is_open()) {
            SetCursorPosition(14, 18);
            std::cerr << "无法打开文件 users.txt" << std::endl;
            throw(-114514);
        }
        file.seekg(0, std::ios::end); // 将文件读取指针定位到文件末尾
        std::streampos fileSize = file.tellg(); // 获取文件读取指针的当前位置（即文件大小）
        file.seekg(0, std::ios::beg); // 将文件读取指针重新定位到文件开头
        if (fileSize == 0)
        {
            throw(-114514);
        }
        SetCursorPosition(18.5, 13);


        /*限制输入位数*/
        std::string temname;
        while (true)
        {
            char c;
            while (1)
            {
                c = getchar();
                if (c == 10)
                {
                    SetCursorPosition(18.5, 13);
                    if (temname.size() == 0)
                    {
                        continue;
                    }
                    else break;
                }
                temname += c;

            }

            if (temname.size() > maxLength_username)
            {
                SetCursorPosition(18.5, 18);
                std::cout << "用户名超出限制";
                Sleep(1000);
                return 1;
            }
            else
            {
                break;
            }
        }
        player.username = temname;
        User currentUser;
        int judge_find = -1;
        while (file >> currentUser.username >> currentUser.password >> currentUser.vipjudge) {
            if (currentUser.username == player.username)
            {
                judge_find = 1;
                break;
            }
        }
        if (judge_find == 1)
        {
            /*输入密码*/
            player.password = "";

            char c;
            SetCursorPosition(18, 15);
            while (1)
            {
                c = getchar();
                
                if (c == 10)
                {   
                    if (player.password.size() == 0)
                    {
                        SetCursorPosition(18, 15);
                        continue;
                    }
                    else break;
                }
                player.password += c;

            }
            if (currentUser.password == player.password) {
                system("cls");
                player = currentUser;
                file.close();
                return 0;
            }
            file.close();
            system("cls");
            SetColor(11);
            SetCursorPosition(10, 8);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            Sleep(30);
            SetCursorPosition(9, 9);
            std::cout << " ┃                  登录                    ┃";
            Sleep(30);
            SetCursorPosition(9, 10);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 11);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 12);
            std::cout << " ┃            用户名或密码错误!             ┃";
            Sleep(30);
            SetCursorPosition(9, 13);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 14);
            std::cout << " ┃                重新输入                  ┃";
            Sleep(30);
            SetCursorPosition(9, 15);
            std::cout << " ┃                  返回                    ┃";
            Sleep(30);
            SetCursorPosition(9, 16);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 17);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 18);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(10, 19);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

            SetCursorPosition(18, 14);
            SetBackColor();
            std::cout << "重新输入";
            SetCursorPosition(19, 15);
            SetColor(11);
            std::cout << "返回";

            int ch;
            int tem_key = 1;
            bool flag = false;
            while (ch = _getch())
            {
                switch (ch)
                {
                case 72://UP
                {
                    if (tem_key > 1)
                    {
                        SetCursorPosition(18, 14);
                        SetBackColor();
                        std::cout << "重新输入";
                        SetCursorPosition(19, 15);
                        SetColor(11);
                        std::cout << "返回";
                        --tem_key;
                    }
                    break;
                }
                case 80://DOWN
                {
                    if (tem_key < 2)
                    {
                        SetCursorPosition(18, 14);
                        SetColor(11);
                        std::cout << "重新输入";
                        SetCursorPosition(19, 15);
                        SetBackColor();
                        std::cout << "返回";
                        ++tem_key;
                    }
                    break;
                }
                case 13://Enter
                {
                    SetColor(11);
                    flag = true;
                    break;
                }
                }
                if (flag)
                {
                    break;
                }
            }
            if (tem_key == 1)
            {
                return 1;
            }
            else if (tem_key == 2)
            {
                return 2;
            }
        }
        else
        {
            SetCursorPosition(17, 18);
            std::cout << "用户名不存在！" << std::endl;
            Sleep(1000);
            system("cls");
            return 1;
        }
    }
}

// 修改密码函数
int changePassword() {
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃                 修改密码                 ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃        用户名：                          ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃        旧密码：                          ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃        新密码：                          ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(10, 19);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";






    std::fstream file("users.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    User* head = nullptr;
    int judge_find = -1;
    //输入用户名
    player.username = "";

    char c;
    SetCursorPosition(18, 12);
    while (1)
    {
        c = getchar();

        if (c == 10)
        {
            if (player.username.size() == 0)
            {
                SetCursorPosition(18, 12);
                continue;
            }
            else break;
        }
        player.username += c;

    }

    User currentUser;
    while (file >> currentUser.username >> currentUser.password >> currentUser.vipjudge) {
        if (player.username == currentUser.username) {
            judge_find = 1;
            //输入旧密码
            player.password = "";

            SetCursorPosition(18.5, 18);
            std::cout << "请输入旧密码！" << std::endl;
            SetCursorPosition(18, 14);
            while (1)
            {
                c = getchar();

                if (c == 10)
                {
                    if (player.password.size() == 0)
                    {
                        SetCursorPosition(18, 14);
                        continue;
                    }
                    else break;
                }
                player.password += c;

            }
            if (currentUser.password != player.password) {
                SetCursorPosition(18.5, 18);
                std::cout << "密码错误！   " << std::endl;
                file.close();
                Sleep(1000);
                system("cls");
                return 1;
            }
            SetCursorPosition(18.5, 18);
            std::cout << "密码匹配成功！" << std::endl;
            //输入新密码
            player.password = "";

            SetCursorPosition(18, 16);
            while (1)
            {
                c = getchar();

                if (c == 10)
                {
                    if (player.password.size() == 0)
                    {
                        SetCursorPosition(18, 16);
                        continue;
                    }
                    else break;
                }
                player.password += c;

            }
            currentUser.password = player.password;
        }
        User* newUser = new User{ currentUser.username, currentUser.password, currentUser.vipjudge,nullptr };
        newUser->next = head;
        head = newUser;
    }

    if (judge_find == -1) {
        SetCursorPosition(18.5, 18);
        std::cout << "用户名不存在！" << std::endl;
        file.close();
        Sleep(1000);
        system("cls");
        return 1;
    }

    file.close();

    // 写回文件
    std::ofstream file_("users.txt");
    if (!file_.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    User* current = head;
    while (current != nullptr) {
        file_ << current->username << " " << current->password << " " << current->vipjudge << std::endl;
        User* temp = current;
        current = current->next;
        delete temp; // 释放链表节点的内存
    }
    file_.close();
    SetCursorPosition(18.5, 18);
    std::cout << "密码修改成功！" << std::endl;
    Sleep(1000); // 暂停1秒
    return 2;
}
//after_enter_interface
int ui_after_enter()
{
    system("cls");
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ┃                开始游戏                  ┃";
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃                CDK兑换                   ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(10, 19);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    SetCursorPosition(18, 13);
    SetBackColor();
    std::cout << "开始游戏";
    SetCursorPosition(18, 15);
    SetColor(11);
    std::cout << "CDK兑换";

    if (player.vipjudge == 1)
    {
        SetCursorPosition(14, 9);
        std::cout << "尊贵的VIP ";
    }
    else
    {
        SetCursorPosition(15, 9);
        std::cout << "普通用户 ";
    }
    SetCursorPosition(19, 9);
    std::cout << player.username << " 登陆成功！" << std::endl;

    /*选择部分*/
    int ch;
    int tem_key = 1;
    bool flag = false;
    while (ch = _getch())
    {
        switch (ch)
        {
        case 72://UP
        {
            if (tem_key == 2)
            {
                SetCursorPosition(18, 13);
                SetBackColor();
                std::cout << "开始游戏";
                SetCursorPosition(18, 15);
                SetColor(11);
                std::cout << "CDK兑换";
                --tem_key;
            }
            break;
        }
        case 80://DOWN
        {
            if (tem_key == 1)
            {
                SetCursorPosition(18, 13);
                SetColor(11);
                std::cout << "开始游戏";
                SetCursorPosition(18, 15);
                SetBackColor();
                std::cout << "CDK兑换";
                ++tem_key;
            }
            break;
        }
        case 13://Enter
        {
            flag = true;
            break;
        }
        default:
            break;
        }

        if (flag)
        {
            SetColor(11);
            break;
        }
    }

    if (tem_key == 1)
    {
        system("cls");
        return 1;
    }
    else if (tem_key == 2)
    {
        system("cls");
        return 2;
    }
}
//VIP-CDK
int cdk_dh()
{
    system("cls");
    bool found = false;
    std::string cdk_input;
    std::string cdk;
    std::list<std::string> cdk_all;
    std::fstream file("cdk.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 cdk.txt" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (file >> cdk)
    {
        cdk_all.push_back(cdk);
    }
    while (true)
    {
        system("cls");
        SetColor(11);
        SetCursorPosition(10, 8);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
        Sleep(30);
        SetCursorPosition(9, 9);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 10);
        std::cout << " ┃                 CDK兑换                  ┃";
        Sleep(30);
        SetCursorPosition(9, 11);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 12);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 13);
        std::cout << " ┃  请输入5位CDK：                          ┃";
        Sleep(30);
        SetCursorPosition(9, 14);
        std::cout << " ┃                ￣￣￣￣￣￣￣            ┃";
        Sleep(30);
        SetCursorPosition(9, 15);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 16);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 17);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(9, 18);
        std::cout << " ┃                                          ┃";
        Sleep(30);
        SetCursorPosition(10, 19);
        std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";


        SetCursorPosition(18.5, 13);
        std::cin >> cdk_input;
        if (cdk_input.length() != maxLength_CDK)
        {
            SetCursorPosition(15, 17);
            std::cout << "请输入正确长度的CDK" << std::endl;
            Sleep(1000);
            continue;
        }
        auto it = std::find(cdk_all.begin(), cdk_all.end(), cdk_input);
        if (it != cdk_all.end())
        {
            found = true;
            cdk_all.remove(cdk_input);
        }


        if (found)
        {
            /**************************/
            //将用过的CDK删除后写回文件
            std::ofstream file_cdk("cdk.txt");
            for (auto& cdk : cdk_all)
            {
                file_cdk << cdk << std::endl;
            }

            //写入账户txt
            std::fstream file("users.txt", std::ios::in | std::ios::out);
            if (!file.is_open()) {
                std::cerr << "无法打开文件 users.txt" << std::endl;
                exit(EXIT_FAILURE);
            }
            User* head = nullptr;
            User currentUser;
            while (file >> currentUser.username >> currentUser.password >> currentUser.vipjudge) {
                if (player.username == currentUser.username) {
                    currentUser.vipjudge = 1;
                }
                User* newUser = new User{ currentUser.username, currentUser.password, currentUser.vipjudge,nullptr };
                newUser->next = head;
                head = newUser;
            }


            file.close();

            // 写回文件
            std::ofstream file_("users.txt");
            if (!file_.is_open()) {
                std::cerr << "无法打开文件 users.txt" << std::endl;
                exit(EXIT_FAILURE);
            }

            User* current = head;
            while (current != nullptr) {
                file_ << current->username << " " << current->password << " " << current->vipjudge << std::endl;
                User* temp = current;
                current = current->next;
                delete temp; // 释放链表节点的内存
            }
            file_.close();

            system("cls");
            SetCursorPosition(10, 8);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            Sleep(30);
            SetCursorPosition(9, 9);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 10);
            std::cout << " ┃                 CDK兑换                  ┃";
            Sleep(30);
            SetCursorPosition(9, 11);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 12);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 13);
            std::cout << " ┃        恭喜您成为尊贵的贪吃会员！        ┃";
            Sleep(30);
            SetCursorPosition(9, 14);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 15);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 16);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 17);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 18);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(10, 19);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            SetCursorPosition(15, 18);
            system("pause");
            return 1;
        }
        else
        {
            /**********/
            system("cls");
            SetCursorPosition(10, 8);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
            Sleep(30);
            SetCursorPosition(9, 9);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 10);
            std::cout << " ┃                 CDK兑换                  ┃";
            Sleep(30);
            SetCursorPosition(9, 11);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 12);
            std::cout << " ┃                 CDK错误！                ┃";
            Sleep(30);
            SetCursorPosition(9, 13);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 14);
            std::cout << " ┃                 重新输入                 ┃";
            Sleep(30);
            SetCursorPosition(9, 15);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 16);
            std::cout << " ┃                   返回                   ┃";
            Sleep(30);
            SetCursorPosition(9, 17);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(9, 18);
            std::cout << " ┃                                          ┃";
            Sleep(30);
            SetCursorPosition(10, 19);
            std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";



            SetCursorPosition(18.5, 14);
            SetBackColor();
            std::cout << " 重新输入";
            SetCursorPosition(19.5, 16);
            SetColor(11);
            std::cout << " 返回";

            int ch;
            bool flag=false;
            int key=1;
            while (ch=_getch())
            {
                switch (ch)
                {
                case 72://UP
                {
                    if (key > 1)
                    {
                        SetCursorPosition(18.5, 14);
                        SetBackColor();
                        std::cout << " 重新输入";
                        SetCursorPosition(19.5, 16);
                        SetColor(11);
                        std::cout << " 返回";
                        --key;
                    }
                    break;
                }
                case 80://DOWN
                {
                    if (key < 2)
                    {
                        SetCursorPosition(18.5, 14);
                        SetColor(11);
                        std::cout << " 重新输入";
                        SetCursorPosition(19.5, 16);
                        SetBackColor();
                        std::cout << " 返回";
                        ++key;
                    }
                    break;
                }
                case 13://Enter
                {
                    SetColor(11);
                    flag = true;
                    break;
                }
                }
                if (flag)
                {
                    break;
                }
            }
            if (key == 1)
            {
                continue;
            }
            else if (key == 2)
            {
                return 2;
            }
        }
    }
}