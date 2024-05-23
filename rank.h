#pragma once
#ifndef RANK_H
#define RANK_H
#include "common.h"
#include "account.h"

class User_Rank :public User {
private:
	int score;
public:
	User_Rank(User&, int);
	std::string GetName();
	int GetScore();
};

class Rank {

private:
	std::vector<User_Rank> crank;
public:
	Rank();
	void AddRank(User_Rank&);
	void SortRank();
	void PrintRank();
	void SaveRank();
	void ClearRank();
};


#endif