#include "stdafx.h"

namespace In
{
	IN OutText(IN info);
	IN getin(wchar_t infile[])
	{
		IN infl;
		unsigned char ch = 'a';
		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];
		infl.lines = 1; int position = 0; infl.size = 0; infl.ignor = 0;
		std::ifstream file(infile);
		if (file.fail() == 0)
		{
			ch = file.get();
			while (!file.eof())
			{
				if (ch == ((unsigned char)'\n'))
				{
					position = 0;
					infl.lines++;
				}
				if (infl.code[(int)ch] == IN::T)
				{

					position++;
					text[infl.size] = ch;
					infl.size++;
				}
				else if (infl.code[(int)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, infl.lines, position);
				}
				else if (infl.code[(int)ch] == IN::I)
				{
					infl.ignor++;
				}
				else
				{
					text[infl.size] = infl.code[(int)ch];
					infl.size++;
				}

				ch = file.get();
			}
			text[infl.size] = '\0';//if (file.eof())
			file.close();
			infl.text = text;			
			infl = OutText(infl);
		}
		else
		{
			throw ERROR_THROW(110);
		}
		return infl;
	}

	IN OutText(IN info) {
		IN out;
		unsigned char* buff = new unsigned char[info.size * 3];
		out.text = new unsigned char[info.size * 3];
		int k = 0, pr = 0;
		out.lines = 0;
		bool check = false;
		for (int i = 0; i < info.size; i++)
		{
			if (info.text[i] == '(' || info.text[i] == ')' || info.text[i] == ',' || info.text[i] == '=' || info.text[i] == '+' || info.text[i] == '-'
				|| info.text[i] == '/' || info.text[i] == '*' || info.text[i] == '{' || info.text[i] == '}' || info.text[i] == ';'|| info.text[i] =='\'')
			{
				buff[k++] = ' ';
				buff[k++] = info.text[i];
				buff[k++] = ' ';
			}
			else {
				buff[k] = info.text[i];
				k++;
			}
		}
		buff[k] = '\0';
		for (int i = 0; i <= k; i++)
		{
			if (buff[i] == ' ' || buff[i] == '\0')
			{
				if (!check)
				{
					out.text[pr++] = buff[i];
					check = true;
				}

			}
			else {
				out.text[pr++] = buff[i];
				check = false;
			}
			if (buff[i] == '\n' || buff[i] == '\0')
			{
				out.lines++;
			}

		}
		out.text[pr] = '\0';
		out.size = pr;
		out.ignor = info.ignor;
		return out;
	}

};