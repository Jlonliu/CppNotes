#include <iostream>
using namespace std;

/*
dynamic_cast:派生类指针转换为基类指针
const_cast:将常量转换为变量
static_cast:可进行隐式转换的类型之间的转换
reinterpret_cast:依赖于底层实现的类型之间的转换
*/

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    ~Derived() override {}
};

int main()
{
    // /*dynamic_cast*/
    // // 创建一个派生类的对象
    // Derived *derived = new Derived();
    // // 尝试将派生类指针转换为基类指针
    // Base *base = dynamic_cast<Base *>(derived);
    // // 如果转换成功， base 指向一个 Base 类的对象
    // if (base != nullptr)
    //     std::cout << "Success Transform To Base object" << std::endl;

    // else
    //     std::cout << "Fail to Transform To Base object" << std::endl;

    // // 删除派生类指针
    // delete derived;

    // /*const_cast*/
    // /*很危险，这个const转换，很容易出错*/
    // const int a = 10;
    // int *b;
    // b = const_cast<int *>(&a);
    // *b = 11;
    // std::cout << "a=" << a << " b=" << *b << std::endl;

    // /*static_cast*/
    // double a = 10.09;
    // int b;
    // b = static_cast<int>(a);
    // cout << b << endl;

    /*reinterpret_cast*/
    struct dat
    {
        short a;
        short b;
    };
    long value = 0xA224B118;
    dat *pd = reinterpret_cast<dat *>(&value);
    cout << hex << pd->a << endl;

    return 0;
}