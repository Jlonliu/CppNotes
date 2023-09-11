#include<iostream>
#ifndef TABTENN0_H_	
#define TABTENN0_H_
#include<string>
using std::string;
class TableTennisPlayer {
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
	TableTennisPlayer(const char*fn, const char*ln, bool ht);
	TableTennisPlayer(const TableTennisPlayer & );//复制构造函数
	void Name()const;//输出名字
	bool HasTable()const { return hasTable; }
	void ResetTable(bool v) { hasTable = v; }//返回是否有座
};

class RatedPlayer :public TableTennisPlayer {
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);//构造函数
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);//构造函数
	unsigned int Rating()const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

#endif
