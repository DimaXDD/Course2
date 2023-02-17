#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции 
#include "Fibonachi.h"
#include <iostream>
#include <ctime>
#include <locale>

#define  CYCLE  1000000                       // количество циклов  

int main(int argc, char* argv[])
{

	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");

	std::cout << "=============\n\nФункция чисел Фиббоначи";
	clock_t  t3 = 0, t4 = 0; int a;
	std::cout << std::endl << "Введите N-ое число: ";
	std::cin >> a;
	t3 = clock();
	long double result = fibonachi(a);
	std::cout << std::endl << a << " число Фиббоначи = " << result;
	t4 = clock();
	std::cout << std::endl << "продолжительность (у.е):   " << (t4 - t3);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	system("pause");
	return 0;
}