#include<iostream>
#include<vector>
#include<string>
using namespace std;

//����ģ��
//�����������ȼ�����ģ�庯��>���廯ģ�庯��>����ģ��

//����һ��ģ�壬������������ΪTypename
template<class Typename>
//��ģ�������������׼������
vector<double> ArrayToVector(Typename arr[], int size);//��������ģ�������Ҫ��ģ�����ͣ���������Ĭ��ֵ
template<class Typename>//����ģ��Ҳ��������
vector<vector<double>> ArrayToVector(Typename* arr[], int rows, int cols);//������Ҫ�в�ͬ��������
//��ʾ���廯���������������뺯������ƥ��ľ��廯����ʱ������Ѱ��ģ��
//���ʣ�����ֱ�Ӷ������ķ�ģ�庯�����Ǹ��ã�Ҫʲô��ʾ���廯
//���char����ʽ���廯
template<>vector<double> ArrayToVector(char arr[], int size);
//���char�ķ�ģ�庯��
vector<double> ArrayToVector(char arr[], int size);
//���char����ʽʵ����
template vector<double> ArrayToVector(char arr[], int size);
int main(void) {

	int iArr[3] = { 1,2,3 };//int����
	char cArr[3] = { 'A','B','C' };//char����
	double dArr[3] = { 3.14,2.78,1.41 };//double����
	int* piArr[2] = { iArr,iArr };//intָ������
	double* pdArr[2] = {dArr,dArr};//doubleָ������

	vector<double> vec_int = ArrayToVector(iArr, 3);
	vector<double> vec_dou = ArrayToVector(dArr, 3);
	vector<double> vec_char = ArrayToVector(cArr, 3);//���ȵ��÷�ģ����
	vector<vector<double>> mat_int = ArrayToVector(piArr, 2, 3);
	vector<vector<double>> mat_dou = ArrayToVector(pdArr, 2, 3);


	return 0;

}
template<class Typename>
vector<double> ArrayToVector(Typename arr[], int size) {
	cout << "�����������Ͳ���ģ�庯��\n";
	vector<double> vec(arr, arr + size);
	return vec;
}
template<class Typename>
vector<vector<double>> ArrayToVector(Typename* arr[], int rows, int cols) {
	cout << "������ָ�������Ͳ���ģ�庯��\n";
	vector<vector<double>> mat(rows, vector<double>(cols));
	for (int i = 0; i < rows; i++) {//���������ڵ�ÿһ��ָ��
		mat[i] = vector<double>(arr[i], arr[i] + cols);//��ÿ��ָ��ָ������鸳ֵ���������
	}
	return mat;
}
template<>vector<double> ArrayToVector(char arr[], int size) {
	cout << "�����˾��廯char���������ģ�庯��\n";
	vector<double> vec;
	return vec;
}

//ʵ�����������ٶ��壺ʵ�������ǽ�ģ�幤������ʽ������ʾ�˳���
//template vector<double> ArrayToVector(char arr[], int size){
//	cout << "������ʵ����char���������ģ�庯��\n";
//	vector<double> vec;
//	return vec;
//}
// 
vector<double> ArrayToVector(char arr[], int size) {
	cout << "�����˷�ģ��char�����������\n";
	vector<double> vec;
	return vec;
}