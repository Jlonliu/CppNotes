#include <iostream>
#include <cstdlib>
/*采用C++的异常机制进行处理*/
/*PS:
    noexcept关键字将告诉编译器函数不会发成异常
    noexcept()函数用于检测函数是否承诺了不会引发异常
    但是!!!请不要用它。
    人类的承诺，像屎一样。
*/
bool hmean(double a, double b)
{
    if (a == -b)
        // throw类似于返回语句，因为它将终止函数的执行
        // 但是throw不是将控制权返回给调用程序，而是回退到try语句后面
        throw "Bad hmean() arguments: a == -b not allowed";
    return 2.0 * a * b / (a + b);
}
int main()
{
    double x, y, z;
    std::cout << "Enter two numbers" << std::endl;
    while (std::cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
        }
        /*
        catch类似于函数定义，char *s 表明catch与字符串异常匹配
        如果出现字符串异常，catch将会检测到它，并执行catch后面的程序
        实际应用中，常常使用类对象而非字符串作为catch的参数。
        这样做的好处是，可以根据不同的异常类型，定义不同的异常对象。
        catch则根据不同的对象，执行不同的措施。
        */
        catch (const char *s)
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next set of numbers<q to quit>: ";
    }
    std::cout << "End of program" << std::endl;
    return 0;
}
