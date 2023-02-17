#include "stdafx.h"
#include "AsmGen.h"

void main()
{
	setlocale(LC_ALL, "ru");
	short shortVal;
	unsigned short unsignedVal;

	Desearealizer des;
	des.Deserialize(&shortVal, &unsignedVal);

	cout << shortVal << " " << unsignedVal << endl;

	AsmGen AG;
	AG.CreateFile(shortVal, unsignedVal);
}