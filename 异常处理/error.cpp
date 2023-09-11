#include <iostream>
#include <cstdlib>
/*自定义异常处理*/
bool hmean(double a, double b, double *ans)
{
    if (a == -b)
    {
        *ans = TMP_MAX; // 极大值
        return false;
        // std::cout << "Division by zero" << std::endl;
        // std::abort();
    }
    else
    {
        *ans = 2.0 * a * b / (a + b);
        return true;
    }
}
int main()
{
    double x, y, z;
    std::cout << "Enter two numbers" << std::endl;
    while (std::cin >> x >> y)
    {
        if (hmean(x, y, &z))
        {

            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
            std::cout << "Enter two numbers" << std::endl;
        }
        else
        {
            std::cout << "Division by zero" << std::endl;
            std::cout << "Enter two numbers" << std::endl;
        }
    }
    std::cout << "End of program" << std::endl;
    return 0;
}
