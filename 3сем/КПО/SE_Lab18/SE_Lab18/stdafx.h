#pragma once
#include <iostream>
#include <string.h>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

namespace PolishNotation
{
	bool PolishNotation(char* expression); // Проверка выражения на правильность
	bool isOperand(char symb); // Проверка символа на операнд
	bool isOperation(char symb); // Проверка символа на операцию
	bool isBrackets(char symb); // Проверка на скобки
	bool checkExpression(char* expression); // Проверка выражения на правильность
	bool checkOperations(char* expression); // Проверка операций
	bool checkBrackets(char* expression); // Проверка скобок
	void goThrowStr(char* expr, char* polExprs); // Перевод выражения в обратную польскую запись
	void out(char* expr, char* polExpr); // Вывод выражения в обратной польской записи
	void writeTo(char* expr, stack<char> _stack); // Запись в строку выражения в обратной польской записи
}