#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
struct User {
    std::string username;
    std::string password;
    User* next;
};

void registerUser();
int loginUser();
int changePassword();

