#include "account.h"
#include "tools.h"
#include "common.h"

// 注册函数
void registerUser() {
    std::fstream file("users.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    User newUser;
    std::cout << "请输入用户名: ";
    std::cin >> newUser.username;

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

        file << newUser.username << " " << newUser.password << std::endl;
        std::cout << "注册成功！" << std::endl;
    }

    file.close();
}

// 登录函数
int loginUser() {
    std::ifstream file("users.txt",std::ios::in);
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
    std::string username, password;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    User currentUser;
    int judge_find = -1;
    while (file >> currentUser.username >> currentUser.password) {
        if (currentUser.username == username)
        {
            judge_find = 1;
            break;
        }
    }
    if (judge_find == 1)
    {
        std::cout << "请输入密码: ";
        std::cin >> password;
        if (currentUser.password == password) {
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
    std::string username, password, newPassword;
    int judge_find = -1;
    std::cout << "请输入用户名: ";
    std::cin >> username;

    User currentUser;
    while (file >> currentUser.username >> currentUser.password) {
        if (username == currentUser.username) {
            judge_find = 1;
            std::cout << "请输入旧密码: ";
            std::cin >> password;
            if (currentUser.password != password) {
                std::cout << "密码错误！" << std::endl;
                file.close();
                return 1;
            }

            std::cout << "请输入新密码: ";
            std::cin >> newPassword;
            currentUser.password = newPassword;
        }
        User* newUser = new User{currentUser.username, currentUser.password, nullptr};
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
        file_ << current->username << " " << current->password << std::endl;
        User* temp = current;
        current = current->next;
        delete temp; // 释放链表节点的内存
    }
    file_.close();

    std::cout << "密码修改成功！" << std::endl;
    Sleep(1000); // 暂停1秒
    return 2;
}