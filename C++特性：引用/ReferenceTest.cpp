#include<iostream>

using namespace std;

//C++�������ԣ�����
//�����൱�ڸ���һ����������һ�����������úͱ����ĵ�ַ�ʹ洢�����ݶ���ͬ
//���ò�ͬ��ָ��ĵط�������������ʱ���뽫���ʼ��
//���ýӽ�constָ�룬�����ڴ���ʱ��ʼ����һ����ĳ������������������һֱЧ��������
int main(void) {

	int rats = 101;
	int& rodents = rats;//rodents��rats������

	//�鿴���������õĵ�ַ����洢ֵ
	cout << "rats address is    :" <<&rats<<"; its value is :" << rats << endl;
	cout << "rodents address is :" << &rodents << "; its value is :" << rodents << endl;
	cout << "-------------------------------------------" << endl;//�ָ���
	int bunnies = 50;
	rodents = bunnies;//��������ֵΪ50

	//�ٴβ鿴���������õĵ�ַ����洢ֵ
	cout << "bunnies address is :" << &bunnies << "; its value is :" << bunnies << endl;
	cout << "rats address is    :" << &rats << "; its value is :" << rats << endl;
	cout << "rodents address is :" << &rodents << "; its value is :" << rodents << endl;
	//�����:
	//rats address is    : 00000001000FF904; its value is : 101
	//rodents address is : 00000001000FF904; its value is : 101
	//---------------------------------------------------------
	//bunnies address is : 00000001000FF944; its value is : 50
	//rats address is    : 00000001000FF904; its value is : 50
	//rodents address is : 00000001000FF904; its value is : 50

	//��������ֵͬʱ�ı��˱����ͱ����õı���
	//�޷��ñ�������������һ������
	//���õ�ʵ�ʾ���constָ��
	//int &rodents = rats������int* cosnt rodents = &rats
	return 0;
}
