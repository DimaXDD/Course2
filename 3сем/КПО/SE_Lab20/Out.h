#pragma once
#include "stdafx.h"

namespace Out
{
	struct OUT
	{
		wchar_t* path_to_file;
		ofstream file;

		OUT(wchar_t* path_to_file);
		~OUT();

		void Write(char* str);
	};
}

