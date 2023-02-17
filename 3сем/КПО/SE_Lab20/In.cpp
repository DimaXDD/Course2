#include "stdafx.h"
#include "In.h"
#include "Error.h"
namespace In
{
	IN::IN()
	{
		this->add('a', 'z', IN::T);
		this->add('A', 'Z', IN::T);
		this->add('а', 'я', IN::T);
		this->add('А', 'Я', IN::T);
		this->add('0', '9', IN::T);

		this->code[(unsigned int)' '] = IN::T;
		this->code[(unsigned int)'\t'] = IN::T;
		this->code[(unsigned int)'\n'] = IN::T;
		this->code[(unsigned int)'\r'] = IN::T;

		this->code[(unsigned int)'('] = IN::T;
		this->code[(unsigned int)')'] = IN::T;
		this->code[(unsigned int)'{'] = IN::T;
		this->code[(unsigned int)'}'] = IN::T;
		this->code[(unsigned int)'['] = IN::T;
		this->code[(unsigned int)']'] = IN::T;
		this->code[(unsigned int)';'] = IN::T;
		this->code[(unsigned int)':'] = IN::T;
		this->code[(unsigned int)'\''] = IN::T;
		this->code[(unsigned int)','] = IN::T;
		this->code[(unsigned int)'.'] = IN::T;
		this->code[(unsigned int)'+'] = IN::T;
		this->code[(unsigned int)'-'] = IN::T;
		this->code[(unsigned int)'*'] = IN::T;
		this->code[(unsigned int)'/'] = IN::T;
		this->code[(unsigned int)'='] = IN::T;
	}

	IN getin(wchar_t infile[]) // Функция проверки входных данных
	{
		int lines = 0;
		int cols = 0;
		int ignors = 0;
		int iter = 0;
		char* str = new char[MAX_LEN_LINE];
		unsigned char* code = new unsigned char[IN_MAX_LEN_TEXT];

		IN in;
		in.size = 0;
		std::fstream file(infile, std::fstream::in);

		if (!file.is_open())
		{
			throw ERROR_THROW(110);
		}
		while (!file.eof())
		{
			lines++;
			file.getline(str, MAX_LEN_LINE);

			checkSpaces(str);
			for (unsigned short i = 0; i < strlen(str); i++)
			{
				cols++;
				in.size++;
				if (in.code[int((unsigned char)str[i])] == IN::F) // Вывод ошибки
				{
					throw ERROR_THROW_IN(111, lines, cols);
				}
				else if (
					in.code[int((unsigned char)str[i])] == IN::I) // Пропуск символа
				{
					ignors++;
					dell_in(str, i);
				}
				else if ( // Замена символа
					in.code[int((unsigned char)str[i])] != IN::I &&
					in.code[int((unsigned char)str[i])] != IN::F &&
					in.code[int((unsigned char)str[i])] != IN::T
					)
				{
					str[i] = in.code[int((unsigned char)str[i])];
				}
			}



			for (int i = 0; i < strlen(str); i++)
			{
				code[iter++] = (unsigned char)str[i];
			}

			code[iter++] = '\n';

			cols = 0;
		}
		code[iter] = '\0';

		in.ignore = ignors;
		in.lines = lines;
		in.text = code;
		in.size = strlen((char*)in.text);

		file.close();
		delete[] str;
		return in;
	}

	void dell_in(
		char* str,
		int index)
	{
		for (int i = index; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}
	}

	void IN::add(
		char startCh,
		char endCh,
		const int code)
	{
		for (char i = startCh; i <= endCh; i++)
		{
			this->code[(unsigned char)i] = code;
		}
	}

	void checkSpaces(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ' && str[i + 1] == ' ')
			{
				dell_in(str, i);
				i--;
			}
		}
	}
}