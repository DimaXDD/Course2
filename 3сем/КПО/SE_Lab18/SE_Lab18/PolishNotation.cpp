#include "stdafx.h"

namespace PolishNotation
{
	typedef char operation; // Тип операции

	map<operation, int> priorities = // Приоритеты операции
	{
		{'(', 1},
		{')', 1},
		{'+', 2},
		{'-', 2},
		{'*', 3},
		{'/', 3}
	};

	bool PolishNotation(char* expression)
	{
		if (!checkExpression(expression)) // Проверка выражения на правильность
		{
			return false;
		}


		char* polishExpression = new char[strlen(expression)];
		strcpy_s(polishExpression, strlen(expression), "");

		goThrowStr(expression, polishExpression); // Перевод выражения в обратную польскую запись

		out(expression, polishExpression); // Вывод выражения в обратной польской записи

		return true;
	}

	bool checkExpression(char* expression)
	{
		if (
			!checkBrackets(expression) &&
			!checkOperations(expression)
			)
		{
			return false;
		}
		return true;
	}

	bool checkBrackets(char* expression)
	{
		stack<char> brackets;

		for (int i = 0; i < strlen(expression); i++)
		{
			if (expression[i] == '(')
			{
				brackets.push(expression[i]);
			}
			else if (expression[i] == ')')
			{
				if (brackets.empty())
				{
					return false;
				}
				else
				{
					brackets.pop();
				}
			}
		}

		if (brackets.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool checkOperations(char* expression)
	{
		for (int i = 0; i < strlen(expression); i++)
		{
			if (isOperation(expression[i]) and not isBrackets(expression[i]))
			{
				if (i == 0) // Проверка первого символа
				{
					if (expression[i] == '-')
					{
						continue;
					}
					else
					{
						return false;
					}
				}
				else if (i == strlen(expression) - 1) // Проверка последнего символа
				{
					return false;
				}
				else if (isOperation(expression[i - 1]) and not isBrackets(expression[i - 1])) // Проверка двух операций подряд
				{
					return false;
				}
				else if (isBrackets(expression[i - 1])) // Проверка операции после скобки
				{
					if (expression[i] == '-')
					{
						continue;
					}
					else
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	void goThrowStr(char* expr, char* polExprs) // перевод в обратную польскую запись
	{
		stack<operation> _stack;
		int	polExprIndex = 0;

		for (auto i = 0; i < strlen(expr); i++)
		{
			if (isOperand(expr[i]))
			{
				polExprs[polExprIndex++] = expr[i];
			}
			else if (isOperation(expr[i]))
			{
				if (_stack.empty() ||
					expr[i] == '(' ||
					priorities[expr[i]] > priorities[_stack.top()])
				{
					_stack.push(expr[i]);
				}
				else
				{
					while (
						!_stack.empty() &&
						priorities[expr[i]] <= priorities[_stack.top()])
					{
						if (!isBrackets(_stack.top()))
						{
							polExprs[polExprIndex++] = _stack.top();
						}

						_stack.pop();
					}
					_stack.push(expr[i]);
				}
			}
		}

		polExprs[polExprIndex] = '\0';

		if (!_stack.empty())
		{
			writeTo(polExprs, _stack);
		}

	}

	void writeTo(char* expr, stack<operation> _stack) // запись в выражение
	{
		int exprIndex = strlen(expr);

		while (!_stack.empty())
		{
			if (!isBrackets(_stack.top()))
			{
				expr[exprIndex++] = _stack.top();
			}
			_stack.pop();
		}
		expr[exprIndex] = '\0';
	}

	bool isOperand(char symb) // проверка на операнд
	{
		return
			(symb >= '0' && symb <= '9') ||
			(symb >= 'a' && symb <= 'z') ||
			(symb >= 'A' && symb <= 'Z');
	}

	bool isOperation(char symb) // проверка на операцию
	{
		return symb ==
			'+' ||
			symb == '-' ||
			symb == '*' ||
			symb == '/' ||
			isBrackets(symb);
	}

	bool isBrackets(char symb) // проверка на скобки
	{
		return symb == '(' ||
			symb == ')';
	}

	void out(char* expr, char* polExpr) // вывод
	{
		cout << "Выражение: " << expr << endl;
		cout << "Польская запись: " << polExpr << endl;
	}

}