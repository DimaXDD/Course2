//-- Fibonachi.cpp  
#include "Fibonachi.h"
#include <iostream>

// Посчитать N-ое число Фибоначчи
long double fibonachi(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonachi(n - 1) + fibonachi(n - 2);
}