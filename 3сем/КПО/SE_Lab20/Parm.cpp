#include "stdafx.h"
#include "Parm.h"
#include "Error.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		if (argc == 1) throw ERROR_THROW(100);

		PARM p;
		short cnt = argc - 1;
		char** args = new char* [cnt];
		bool isIN = false,
			isOUT = false,
			isLOG = false;

		for (short i = 0; i < cnt; i++)
		{
			args[i] = new char[PARM_MAX_SIZE];
		}

		for (int i = 0; i < cnt; i++)
		{
			if (strlen(argv[i + 1]) <= PARM_MAX_SIZE)
			{
				strcpy_s(args[i], argv[i + 1]);
			}
			else
			{
				throw ERROR_THROW(104);
			}
		}

		for (short i = 0; i < cnt; i++)
		{
			if (regex_match(args[i], args[i] + strlen(args[i]), regex("-in:([A-Z]|[a-z]|[0-9]|_)*.txt")))
			{
				isIN = true;
				translate(args[i], p.in, 4);
			}
			else if (regex_match(args[i], args[i] + strlen(args[i]), regex("-out:([A-Z]|[a-z]|[0-9]|_)*.txt")))
			{
				isOUT = true;
				translate(args[i], p.out, 5);
			}
			else if (regex_match(args[i], args[i] + strlen(args[i]), regex("-log:([A-Z]|[a-z]|[0-9]|_)*.txt")))
			{
				isLOG = true;
				translate(args[i], p.log, 5);
			}
		}

		if (!isOUT)
		{
			wcscpy_s(p.out, p.in);
			wcscat_s(p.out, L".out");
		}
		if (!isLOG)
		{
			wcscpy_s(p.log, p.in);
			wcscat_s(p.log, L".log");
		}

		for (short i = 0; i < cnt; i++)
		{
			delete[] args[i];
		}
		delete[] args;
		return p;
	}
}

void translate(char* arr, wchar_t* wArr, short i)
{
	for (short j = 0; i < (strlen(arr) + 1); i++, j++)
	{
		wArr[j] = (wchar_t)arr[i];
	}
}

void wcscpy_s(wchar_t* a1, wchar_t* a2)
{
	for (int i = 0; i < (wcslen(a2) + 1); i++)
	{
		a1[i] = a2[i];
	}
}

void strcpy_s(char* a1, const char* a2)
{
	for (int i = 0; i < (strlen(a2) + 1); i++)
	{
		a1[i] = a2[i];
	}
}