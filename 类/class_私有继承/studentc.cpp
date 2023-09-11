#include"studentc.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average()const {//ʹ���������������������������÷���
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}
const string& Student::Name()const {//ʹ��ǿ��ת������ȡ�ڲ��Ļ������
	return (const string &)*this;
}
double &Student::operator[](int i) {//���ص�i���ɼ�
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
istream & operator>>(istream & is, Student & stu) {//�������֣�
	is >> (string &)stu;
	return is;
}
istream & getline(istream & is, Student &stu) {//ʹ��getline()��������������
	getline(is, (string &)stu);
	return is;
}
ostream & operator<<(ostream & os, const Student & stu) {
	os << "Scores for " << (const string &)stu << ":\n";
	stu.arr_out(os);//��ʽ������ɼ�
	return os;
}