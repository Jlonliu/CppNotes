#include <iostream>
#include <cmath>
// #include<eigen3/Eigen/Dense>

// Fibonacci数列公式F_k+2 = F_k+1 + F_k
// 令u_k=[F_k F_k+1]
// u_k+1 = [F_k+1 F_k+2] = [1 0]u_k
//                         [1 1]
// 特征值：lam1 = (1+sqrt(5))/2和 lam2 = (1-sqrt(5))/2
// 特征向量为：[lam1 1],[lam2 1]
// u_k = (lam1^k x_1 - lam2^ x_2)/(lam1-lam2)

#define SQRT5 2.23606797749979
typedef unsigned int uint;

uint64_t Fibonacci(uint n)
{
    double lam1, lam2;
    lam1 = (1.0 + SQRT5) / 2;
    lam2 = (1.0 - SQRT5) / 2;

    return (pow(lam1, n) - pow(lam2, n)) / (lam1 - lam2);
}

int main(void)
{
    for (uint i = 0; i < 80; i++)
    {
        std::cout << Fibonacci(i) << std::endl;
    }
    return 0;
}