#include "rank.h"
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
	for (int i = 0; i < crank.size(); i++) {
		std::cout << crank[i].GetName() << "   " << crank[i].GetScore() << std::endl;
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