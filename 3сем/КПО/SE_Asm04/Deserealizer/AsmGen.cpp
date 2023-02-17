#include "AsmGen.h"
#include "stdafx.h"
#include <string>

string Join(string str);

void AsmGen::CreateFile(short Short, unsigned short Ushort16) // 2 байт беззнаковое
{
	ofstream file(ASMFILE);
	string strShort = to_string(Short);
	string strUshort16 = to_string(Ushort16);
	strShort = Join(strShort);
	strUshort16 = Join(strUshort16);

	if (file.is_open())
	{
		file ASMHEADER;

		/*file << "FILESTR	 DB \"" << data.String << "\", 0" << endl << endl;

		file << "FILEINT	 DD " << '0' + data.Int << endl << endl;
		file << "INTSTR		DB \"num: \", 0" << endl;*/

		file << "FILESHORT DD " << strShort << endl;
		file << "SHORTSTR DB \"short:    \", 0" << endl << endl;
		file << "FILEUSHORT16 DD " << strUshort16 << endl;
		file << "USHORT16STR DB \"ushort16:     \", 0" << endl << endl
			<< ".CODE\n" << endl
			<< "main PROC\n" << endl;

		string footer = "";
		string cTypes = "";
		int startI = 8;
		int countShort = to_string(Short).size();

		for (int i = 0; i < countShort; i++)
		{
			footer += "\n\nmov eax, FILESHORT " + cTypes;
			footer += "\n";
			footer += "add eax, 30h\n";
			footer += "mov SHORTSTR +" + to_string(startI++);
			footer += ", al\n";
			cTypes += " + type FILESHORT";
		}

		footer += "invoke MessageBoxA, 0, offset SHORTSTR, ADDR TEXT_MESSAGE, OK\n";

		string cTypesUshort = "";
		startI = 10;

		for (int i = 0; i < to_string(Ushort16).size(); i++)
		{
			footer += "\n\nmov eax, FILEUSHORT16 " + cTypesUshort;
			footer += "\n";
			footer += "add eax, 30h\n";
			footer += "mov USHORT16STR + " + to_string(startI++);
			footer += ", al\n";
			cTypesUshort += " + type FILEUSHORT16";
		}

		footer += "invoke MessageBoxA, 0, offset USHORT16STR, ADDR TEXT_MESSAGE, OK\n";

		footer += "push - 1\n";
		footer += "call ExitProcess\n";
		footer += "main ENDP\n";
		footer += "end main\n";

		file << footer;
	}
	else
	{
		cout << "File not open" << endl;
	}
}

string Join(string str)
{
	string newStr = "";
	for (int i = 0; i < str.size(); i++)
	{
		newStr += str[i];
		if (i + 1 != str.size())
		{
			newStr += ", ";
		}
	}
	return newStr;
}