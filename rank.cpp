#include "rank.h"
#include "tools.h"

User_Rank::User_Rank(User& other, int a) {
    username = other.username;
    score = a;
}
std::string User_Rank::GetName() {
    return username;
}

int User_Rank::GetScore() {
    return score;
}

Rank::Rank() {
    std::ifstream file("rank.txt");
    int i = 0;
    User* tuser = new User();
    if (file.is_open()) {
        std::string tmp_name;
        int tmp_score;
        while (file >> tmp_name >> tmp_score) {
            tuser->username = tmp_name;
            User_Rank* tuser_rank = new User_Rank(*tuser, tmp_score);
            crank.push_back(*tuser_rank);
            delete tuser_rank;
        }
    }
    else {

    }
    delete tuser;
    file.close();
}

void Rank::AddRank(User_Rank& cuser) {
    crank.push_back(cuser);
}

bool rank_compare(User_Rank& a, User_Rank& b) {
    return a.GetScore() > b.GetScore();
}

void Rank::SortRank() {
    std::sort(crank.begin(), crank.end(), rank_compare);
}

void Rank::PrintRank() {
    system("cls");
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ┃                   排行榜                 ┃";
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
    std::cout << " ┃                                          ┃";
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
    SetCursorPosition(9, 19);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 21);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 22);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 23);
    std::cout << " ┃                                          ┃";
    Sleep(30);
    SetCursorPosition(9, 24);
    std::cout << " ┃                 按ESC返回                ┃";
    Sleep(30);
    SetCursorPosition(10, 25);
    std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
    for (int i = 0; i < crank.size() && i < 10; i++) {
        SetCursorPosition(16, 11 + i);
        std::cout << std::setw(8)<<crank[i].GetName() << "   " << crank[i].GetScore() << std::endl;
    }
}

void Rank::SaveRank() {
    std::ofstream file("rank.txt");
    if (file.is_open()) {
        for (int i = 0; i < crank.size(); i++) {
            file << crank[i].GetName() << " " << crank[i].GetScore();
            if (i != crank.size() - 1) file << std::endl;
        }

    }
    else {
        std::cout << "文件打开失败" << std::endl;
    }
    file.close();
}
void Rank::ClearRank() {
    std::ofstream file("rank.txt");
    file << "";
    file.close();
}