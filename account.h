#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
struct User {
    std::string username;
    std::string password;
};

void registerUser();
bool loginUser();
void changePassword();

