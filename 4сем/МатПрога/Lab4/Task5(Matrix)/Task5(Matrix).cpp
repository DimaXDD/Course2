// - main  
// -- вычисления длины LCS 
#include <iostream>
#include "LCS.h"
#include <Windows.h>
#include <ctime>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char z[100] = "";
    char X[] = "TOUEXAZ";
    char Y[] = "HIEHXZ";

    clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
    std::cout << std::endl << "-- последовательность X: " << X;
    std::cout << std::endl << "-- последовательность Y: " << Y;
    t1 = clock();
    int s = lcs(sizeof(X) - 1, "TOUEXAZ", sizeof(Y) - 1, "HIEHXZ");
    t2 = clock();
    std::cout << std::endl << "-- длина LCS: " << s << std::endl;

    //   наибольшая общая подпоследовательность   
    t3 = clock();
    int l = lcsd(X, Y, z);
    t4 = clock();
    std::cout << std::endl
        << "-- наибольшая общая подпоследовательость - LCS(динамическое"
        << " программирование)" << std::endl;
    std::cout << std::endl << "последовательость X: " << X;
    std::cout << std::endl << "последовательость Y: " << Y;
    std::cout << std::endl << "                LCS: " << z;
    std::cout << std::endl << "          длина LCS: " << l;
    std::cout << std::endl;

    std::cout << std::endl << "Время вычисления LCS";
    std::cout << std::endl << "Рекурсия: " << (t2 - t1);
    std::cout << std::endl << "Динамическое программирование: " << (t4 - t3) << std::endl;

    system("pause");
    return 0;
}
