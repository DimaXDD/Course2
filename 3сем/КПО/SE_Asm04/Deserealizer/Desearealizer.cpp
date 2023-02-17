#include "Desearealizer.h"
#include "stdafx.h"

void Desearealizer::Deserialize(short* valShort, unsigned short* valUnsigned)
{
	ifstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		file.read(reinterpret_cast<char*>(valShort), sizeof(short));
		file.read(reinterpret_cast<char*>(valUnsigned), sizeof(unsigned short));
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}