#include<iostream>
//#include"new.h"
//#include<utility>
//#include<iterator>
//#include<list>
//#include<functional>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<set>
//#include<cstdlib>
//#include<ctime>
//#include<typeinfo>
//#include<cmath>
//#include<new>
//#include<exception>
//#include<memory>
//#include<cstring>

using namespace std;

template<class T> 
T Max(const T& t1, const T& t2) {
	return (t1 > t2) ? t1 : t2;
}
//�����Ǿ��廯�汾��Ҳ��Ϊ�ػ�
typedef const char* CCP;
template<> CCP Max<CCP>(const CCP& s1, const CCP& s2) {
	unsigned int len = (strlen(s1) < strlen(s2)) ? strlen(s1)+1 : strlen(s2)+1;
	//֮���Լ�һ��Ϊ�˽�'\0'����Ƚ��ڣ��Դﵽ���������Ƚϵ���ĸ������ͬ����ô�̵�����С��
	return (strncmp(s1, s2, len) > 0) ? s1 : s2;
}

////���������ذ汾
//typedef const char* CCP;
//CCP Max(const CCP& s1, const CCP& s2) {
//	unsigned int len = (strlen(s1) < strlen(s2)) ? strlen(s1) + 1 : strlen(s2) + 1;
//	return (strncmp(s1, s2, len) > 0) ? s1 : s2;
//}
int main(void) {
	cout << Max(3, 9) << endl;
	cout << Max<CCP>("very", "ver") << endl;
	cout << "\n�ݰ��ˣ����ţ�\n";
	return 0;
}
