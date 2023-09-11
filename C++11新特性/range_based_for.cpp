//基于范围的for循环
//for(decl:coll){statement;}

#include<iostream>
#include<vector>

using namespace std;

int main(void){

    for(int i:{1,2,3,4,5,6,7,8,9})
        cout<<i<<endl;

    vector<double> vec{1.41,2.71,3.14};
    //vector提供成员函数begin()和end()，那么下面的for循环等同于
    //for(auto posi = vec.begin(),end = vec.end();posi!=end;++posi)
    for(auto& elem : vec){
        elem*=2;
        cout<<elem<<endl;
    }

    int arr[4] = {11,12,13,14};
    //普通数组没有提供成员函数begin()和end()，那么下面的for循环等同于
    //for(auto posi = begin(arr),end=end(arr);posi!=end;++posi)
    for(auto i:arr)
        cout<<i<<endl;

    char carr[4] = {'t','e','s','t'};
    char* pcarr = carr;
    // for(auto i:pcarr)/*基于范围的for循环不支持指针*/
    //     cout<<i<<endl;

    return 0;
}