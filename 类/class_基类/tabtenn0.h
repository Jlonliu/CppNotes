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
	TableTennisPlayer(const TableTennisPlayer & );//���ƹ��캯��
	void Name()const;//�������
	bool HasTable()const { return hasTable; }
	void ResetTable(bool v) { hasTable = v; }//�����Ƿ�����
};

class RatedPlayer :public TableTennisPlayer {
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);//���캯��
	RatedPlayer(unsigned int r, const TableTennisPlayer & tp);//���캯��
	unsigned int Rating()const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
};

#endif
