#include "stdafx.h"
#include "Serealizer.h"

using namespace std;
int indexNumIn(char arr[]);

void main()
{
	setlocale(LC_ALL, "ru");
	Serealizer serealizer;
	char shortVal[50];
	short Short;
	char unsignedVal[30];
	unsigned short Unsigned;
	
	
	cout << "¬ведите значение short: ";
	cin.getline(shortVal, 50);
	
	cout << "¬ведите значение unsigned short: ";
	cin.getline(unsignedVal, 30);
	
	Short = atol(shortVal + indexNumIn(shortVal)); //преобразование строки в число

	Unsigned = strtoul(unsignedVal + indexNumIn(unsignedVal), NULL, 10); //преобразование строки в число

	cout << Short << " " << Unsigned << endl;

	serealizer.Serialize(Short, Unsigned);
}

int indexNumIn(char arr[]) 
{
	int i = 0;
	for (; i < strlen(arr); i++)
	{
		if (
			(arr[i] >= '0' && arr[i] <= '9') ||
			arr[i] == '-' || arr[i] == '+'
			)
		{
			return i;
		}
	}
	return -1;
}