#include "stdafx.h"
#include "In.h"
#include "Error.h"
namespace In
{
	IN getin(wchar_t infile[])
	{
		int lines = 0;
		int cols = 1;
		int ignors = 0;
		int iter = 0;
		unsigned char* str = new unsigned char[MAX_LEN_LINE];
		unsigned char code;
		IN in;
		in.size = 0;
		std::fstream file(infile, std::fstream::in);

		// если невозможео открыть файл
		if (!file) throw ERROR_THROW(110)
		else
		{
			while (iter < IN_MAX_LEN_TEXT)
			{
				code = file.get();

				if (file.eof()) {
					str[iter] = '\0';
					lines++;
					break;
				}
				if (code == IN_CODE_ENDL)
				{
					str[iter] = '|';
					iter++;
					lines++;
					cols = 1;
					continue;
				}
				if (in.code[code] == in.T)
				{
					str[iter] = code;
					iter++;
					cols++;
					continue;
				}
				if (in.code[code] == in.I) { ignors++; continue; }

				if (in.code[code] == in.F) {
					lines++;
					throw ERROR_THROW_IN(111, lines, cols)
				}

				str[iter] = in.code[code];
				iter++;
			}

			in.lines = lines;
			in.ignore = ignors;
			in.size = iter;
			in.text = str;

			return in;
		}
	}

	void dell_in(char* str, int index)
	{
		for (int i = index; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}
	}
}