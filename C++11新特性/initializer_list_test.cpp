//初始化列表测试
#include<iostream>

using namespace std;

void MyTestPrint(initializer_list<int>vals){
    for(auto p=vals.begin();p!=vals.end();++p)
    cout<<*p<<endl;
}

int main(void){

    MyTestPrint({1,2,3,4,5,6,7});
    
    return 0;
}