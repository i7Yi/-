#include "account.h"
#include "tools.h"
#include "common.h"

// 注册函数
void registerUser() {
    std::fstream file("users.txt", std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    User newUser;
    std::cout << "请输入用户名: ";
    std::cin >> newUser.username;
    std::cout << "请输入密码: ";
    std::cin >> newUser.password;

    file << newUser.username << " " << newUser.password << std::endl;
    file.close();

    std::cout << "注册成功！" << std::endl;
}

// 登录函数
bool loginUser() {
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string username, password;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入密码: ";
    std::cin >> password;

    User currentUser;
    while (file >> currentUser.username >> currentUser.password) {
        if (currentUser.username == username && currentUser.password == password) {
            std::cout << "登录成功！" << std::endl;
            file.close();
            return true;
        }
    }

    file.close();
    std::cout << "用户名或密码错误，请重试！" << std::endl;
    return false;
}

// 修改密码函数
void changePassword() {
    std::fstream file("users.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 users.txt" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string username, password, newPassword;
    std::cout << "请输入用户名: ";
    std::cin >> username;
    std::cout << "请输入旧密码: ";
    std::cin >> password;

    User currentUser;
    std::streampos oldPos;
    while (file >> currentUser.username >> currentUser.password) {
        if (currentUser.username == username && currentUser.password == password) {
            std::cout << "请输入新密码: ";
            std::cin >> newPassword;
            oldPos = file.tellg();
            file.seekp(-static_cast<std::streamoff>(currentUser.password.length()) - 1, std::ios::cur);
            file << newPassword;
            std::cout << "密码修改成功！" << std::endl;
            file.close();
            return;
        }
    }

    file.close();
    std::cout << "用户名或密码错误，请重试！" << std::endl;
}
