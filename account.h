#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
struct User {
    std::string username;
    std::string password;
    bool vipjudge;
    User* next;
    double time;
};

int registerUser();
int loginUser();
int changePassword();
int ui_after_enter();
int cdk_dh();
