#include "Out.h"

namespace Out
{
	OUT::OUT(wchar_t* path_to_file)
	{
		this->path_to_file = path_to_file;
	}

	OUT::~OUT()
	{
	}

	void OUT::Write(char* str)
	{
		file.open(path_to_file);
		ushort line = 1;
		file << "0" << line++ << " ";
		if (file.is_open())
		{
			for (ushort i = 0; i < strlen(str); i++)
			{
				file << str[i];
				
				if (str[i] == '\n')
				{
					file << (line < 10 ?  "0" : "") << line++ << " ";
				}
			}
		}
		file.close();
	}
}