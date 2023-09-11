#include"studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average()const {//使用类名和作用域解析运算符来调用方法
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}
const string& Student::Name()const {//使用强制转换，获取内部的基类对象
	return (const string &)*this;
}
double &Student::operator[](int i) {//返回第i个成绩
	return ArrayDb::operator[](i);//use valarray<double>::operator[]()
}
double Student::operator[](int i)const {
	return ArrayDb::operator[](i);
}
ostream & Student::arr_out(ostream & os)const {
	int i;
	int lim = ArrayDb::size();
	if (lim > 0) {
		for (i = 0; i < lim; i++) {
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << " Empty array \n";
	return os;
}
istream & operator>>(istream & is, Student & stu) {//输入名字？
	is >> (string &)stu;
	return is;
}
istream & getline(istream & is, Student &stu) {//使用getline()函数，输入名字
	getline(is, (string &)stu);
	return is;
}
ostream & operator<<(ostream & os, const Student & stu) {
	os << "Scores for " << (const string &)stu << ":\n";
	stu.arr_out(os);//格式化输出成绩
	return os;
}