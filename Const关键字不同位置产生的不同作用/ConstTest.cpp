#include<iostream>

using namespace std;

//����const�ؼ����ڲ�ͬλ�ò����Ĳ�ͬ����
int main(void) {

	int iNum1 = 7;
	int iNum2 = 8;
	int iNum3 = 9;
	//������λ
	const int* p1 = &iNum1;//p1ָ����iNum1�ĵ�ַ
	//����*ǰ
	int const* p2 = &iNum2;//p2ָ����iNum2�ĵ�ַ
	//����*��
	int* const p3 = &iNum3;//p3ָ����iNum3�ĵ�ַ

	//����ָ��ָ�����������
	*p1 = 1;//�����޸�
	*p2 = 1;//�����޸�
	*p3 = 1;//���޸�

	//����ָ��ָ��ı���
	p1 = &iNum2;//���޸�
	p2 = &iNum3;//���޸�
	p3 = &iNum1;//�����޸�

	//���ۣ�
	//const����*ǰ��const int*ͬint const* ����*p(��ָ��ı���)�ǳ��������ɸ���
	//const����*��p(ָ��)�ǳ��������ɸ���
	
	return 0;
}
