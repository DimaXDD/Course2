#include "Serealizer.h"
#include "stdafx.h"

void Serealizer::Serialize(short shortVal, unsigned short unsignedVal)
{
	ofstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		//запись в файл
		file.write(reinterpret_cast<char*>(&shortVal), sizeof(short));
		file.write(reinterpret_cast<char*>(&unsignedVal), sizeof(unsigned short)); 
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}