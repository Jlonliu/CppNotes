//移动语义与右值引用

#include<iostream>

using namespace std;

int main(void){
    //右值引用
    int&& rref = 7;//7就是右值，rref是右值引用

    int a = rref;//a获取rref的值，因为rref是右值引用，所以这里a直接将rref的值拿了过来，而不是复制过来

    cout<<"rref : "<<&rref<<endl;
    cout<<"a    : "<<&a<<endl;

    cout<<"rref's value : "<<rref<<endl;
    cout<<"a's value    : "<<a<<endl;


    return 0;
}