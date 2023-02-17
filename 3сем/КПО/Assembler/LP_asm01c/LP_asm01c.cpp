#include <iostream>
#pragma comment(lib, "..\\Debug\\LP_asm01a.lib")

extern "C"
{
	int __stdcall getmax(int*, int);
	int __stdcall getmin(int*, int);
}

int main()
{
	int array[10] = { -5, 5, 23, -1, 25, 9, -4, 22, 9, 0 };
	int max = getmax(array, sizeof(array) / sizeof(int));
	int min = getmin(array, sizeof(array) / sizeof(int));
	std::cout << "getmin - getmax = " << max - min << std::endl;
}