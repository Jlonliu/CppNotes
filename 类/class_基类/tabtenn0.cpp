#include<iostream>
#include"tabtenn0.h"

TableTennisPlayer::TableTennisPlayer
(const string & fn , const string & ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht) {}
TableTennisPlayer::TableTennisPlayer(const char*fn, const char*ln, bool ht) {
	firstname = fn;
	lastname = ln;
	hasTable = ht;
}
TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer & tp) {
	firstname = tp.firstname;
	lastname = tp.lastname;
	hasTable = tp.hasTable;
}
void TableTennisPlayer::Name()const {
	std::cout << lastname << ", " << firstname;
}
RatedPlayer::RatedPlayer
(unsigned int r, const string & fn, const string & ln, bool ht) :rating(r), TableTennisPlayer(fn, ln, ht) {}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r) {}