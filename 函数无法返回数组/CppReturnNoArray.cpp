#include<iostream>

using namespace std;
//C++��������ֵ�޷�ֱ�ӷ������飬���ǿ�����ָ����ʽ��������
char* ReturnArrayFunction(void);
char* ReturnArrayFunction2(void);
int main(void) {
	char* pt = ReturnArrayFunction();//���ܵ��������׵�ַָ��
	char* pt2 = ReturnArrayFunction2();
	//char newdata[3] = { 'N','e','w' };
	for (int i = 0; i < 3; i++) {
		//��ӡ����������δ����"Ary"��
		//��Ϊ��ַ�Ѿ����ͷţ���ַ�洢�����ݿ��ܱ�������
		cout << pt[i];
	}
	cout << '\n';

	for (int i = 0; i < 3; i++) {
		cout << pt2[i];
	}
	cout << '\n';
	delete[] pt2;
	cout << "pt2�Ѿ����ͷ�\n";
	return 0;
}
char* ReturnArrayFunction(void) {
	char arrTest[3] = { 'A','r','y'};//����洢�ھֲ������У����ڱ�����ķ���
									 //�ɹ������ǽ��ң����ݶ�ʧ�ǳ�̬
	return arrTest;//���������׵�ַָ��
}

char* ReturnArrayFunction2(void) {
	//new������ڴ�ռ䣬��delete֮ǰ�ǲ��ᱻ�ͷŵģ��Ӻ������������ᱻ�ͷ�
	//��ʹ����������Ҳ���ᱻ�ͷţ��ڴ�й©��
	char* parr = new char[3];
	parr[0] = 'A';
	parr[1] = 'r';
	parr[2] = 'y';
	return parr;//���������׵�ַָ��
}