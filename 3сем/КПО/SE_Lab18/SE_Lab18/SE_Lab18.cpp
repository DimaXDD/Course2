#include "stdafx.h"


void main()
{
	setlocale(LC_ALL, "rus");
#pragma region Test1
	char* expr1 = new char[20];
	strcpy_s(expr1, 20, "2+3*4-5");
	if (PolishNotation::PolishNotation(expr1))
	{
		cout << "��������� ����������\n" << endl;
	}
	else
	{
		cout << "��������� " << expr1 << " ������������\n" << endl;
	}
#pragma endregion

#pragma region Test2
	char* expr2 = new char[20];
	strcpy_s(expr2, 20, "(1+2)*(3+4)-5");

	if (PolishNotation::PolishNotation(expr2))
	{
		cout << "��������� ����������\n" << endl;
	}
	else
	{
		cout << "��������� " << expr2 << " ������������\n" << endl;
	}
#pragma endregion

#pragma region Test3
	char* expr3 = new char[50];
	strcpy_s(expr3, 50, "2-2-8+9*(3-3/2)*(1-2))");

	if (PolishNotation::PolishNotation(expr3))
	{
		cout << "��������� ����������\n" << endl;
	}
	else
	{
		cout << "��������� " << expr3 << " ������������\n" << endl;
	}
#pragma endregion
}