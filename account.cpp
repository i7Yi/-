#include "account.h"
#include "tools.h"
#include "common.h"
#define maxLength_CDK 5//CDK最大长度
#define maxLength_username 8//用户名最大长度
extern User player;
// 注册函数
bool registerUser() {
    system("cls");
    std::fstream file("users.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (true)
    {
        
        try
        {
            User newUser;
            std::cout << "请输入用户名(" << maxLength_username << "位以内): ";
            std::cin >> newUser.username;
            if (newUser.username.length() > maxLength_username)
            {
                throw(std::length_error)("用户名长度超过限制");
            }

            User currentUser;
            bool usernameExists = false;
            while (file >> currentUser.username >> currentUser.password) {
                if (currentUser.username == newUser.username) {
                    std::cout << "用户名已存在，请换个名字:" << std::endl;
                    std::cin >> newUser.username;
                    file.clear(); // 清除文件流的错误状态
                    file.seekg(0, std::ios::beg); // 将文件读取指针重新定位到文件的开头
                    usernameExists = true;
                    break;
                }
            }
            file.clear(); // 清除文件流的错误状态
            file.seekg(0, std::ios::beg); // 将文件读取指针重新定位到文件的开头
            if (!usernameExists) {
                std::cout << "请输入密码: ";
                std::cin >> newUser.password;

                // 将写入指针定位到文件开头，以便在文件开头写入新的用户名和密码
                file.seekp(0, std::ios::beg);

                file << newUser.username << " " << newUser.password << " " << "0" << std::endl;
                std::cout << "注册成功！" << std::endl;
                file.close();
                return 1;
            }


        }
        catch (const std::length_error& e)
        {
            std::cerr << "错误: " << e.what() << std::endl;
            std::cout << "1.再试一次   2.返回" << std::endl;
            int judge_regist = -1;
            while (true)
            {
                std::cin >> judge_regist;
                switch (judge_regist)
                {
                case 1:
                    system("cls");
                    break;
                case 2:
                    return false;
                }
            }
        }
    }

}

// 登录函数
int loginUser() {
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
    std::cout << " ┃                ¯¯¯¯¯¯¯¯¯¯¯               ┃";
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ┃         密码：                           ┃";
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ┃                ¯¯¯¯¯¯¯¯¯¯¯               ┃";
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
    std::cin >> player.username;
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
        SetCursorPosition(18, 15);
        std::cin >> player.password;
        if (currentUser.password == player.password) {
            system("cls");
            std::cout << "用户" << " " << currentUser.username << " " << "登录成功！" << std::endl;
            file.close();
            return 0;
        }
        file.close();
        std::cout << "用户名或密码错误!" << std::endl;
        int judge_login = 0;
        while (1)
        {
            std::cout << "1.重新输入 2.返回" << std::endl;
            std::cin >> judge_login;
            switch (judge_login)
            {
            case 1:
                return 1;
            case 2:
                return 2;
            default:
                std::cout << "无效指令，请重新输入！" << std::endl;
                Sleep(1000);
                system("cls");
            }
        }
    }
    else
    {
        std::cout << "用户名不存在！" << std::endl;
        Sleep(1000);
        system("cls");
        return 1;
    }
}

// 修改密码函数
int changePassword() {
    std::fstream file("users.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    User* head = nullptr;
    int judge_find = -1;
    std::cout << "请输入用户名: ";
    std::cin >> player.username;

    User currentUser;
    while (file >> currentUser.username >> currentUser.password>>currentUser.vipjudge) {
        if (player.username == currentUser.username) {
            judge_find = 1;
            std::cout << "请输入旧密码: ";
            std::cin >> player.password;
            if (currentUser.password != player.password) {
                std::cout << "密码错误！" << std::endl;
                file.close();
                return 1;
            }

            std::cout << "请输入新密码: ";
            std::cin >> player.password;
            currentUser.password = player.password;
        }
        User* newUser = new User{ currentUser.username, currentUser.password, currentUser.vipjudge,nullptr };
        newUser->next = head;
        head = newUser;
    }

    if (judge_find == -1) {
        std::cout << "用户名不存在！" << std::endl;
        file.close();
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

    std::cout << "密码修改成功！" << std::endl;
    Sleep(1000); // 暂停1秒
    return 2;
}
//after_enter_interface
int ui_after_enter()
{
    system("cls");
    if (player.vipjudge == 1)
    {
        std::cout << "尊贵的VIP ";
    }
    else
    {
        std::cout << "普通用户 ";
    }
    std::cout << player.username << " 登陆成功！" << std::endl;
    std::cout << "1.开始游戏\n2.CDK兑换\n";
    int judge_after_enter = -1;
    while(1)
    {
        std::cin >> judge_after_enter;
        switch (judge_after_enter)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            std::cout << "无效指令！请重新输入";
        }
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
    std::fstream file("cdk.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (true)
    {
        try
        {
            std::cout << "请输入5位CDK:";
            std::cin >> cdk_input;
            if (cdk_input.length() > maxLength_CDK)
            {
                throw std::length_error("CDK长度超过限制5位");
            }
            
            while (file >> cdk)
            {
                cdk_all.push_back(cdk);
                if (cdk == cdk_input)
                {
                    found = true;
                    cdk_all.remove(cdk);
                }
            }
            /**************************/
            //将用过的CDK删除后写回文件
            std::ofstream file("cdk.txt");
            for (auto& cdk : cdk_all)
            {
                file << cdk << std::endl;
            }
            if (found)
            {
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

                std::cout << "恭喜您成为尊贵的贪吃会员！" << std:: endl;
                std::cout << "按任意键继续" << std::endl;
                system("pause");
                return 1;
            }
            else
            {
                std::cout << "CDK错误！" << std::endl;
                std::cout << "1.重新输入\n2.返回" << std::endl;
                int judge_cdk = -1;
                std::cin >> judge_cdk;
                switch (judge_cdk)
                {
                case 1:
                    continue;
                case 2:
                    return 2;
                }

            }
        }
        catch (const std::length_error& e)
        {
            std::cerr << "错误: " << e.what() << std::endl;
        }
    }

}
