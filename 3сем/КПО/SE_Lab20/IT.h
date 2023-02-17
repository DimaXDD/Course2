#pragma once

#define ID_MAXSIZE 20 // ������������ ���������� �������� � ��������������
#define TI_MAXSIZE 4096 // ������������ ���������� ������� � ������� ���������������
#define TI_INT_DEFAULT 0x00000000 // �������� �� ��������� ��� ���� integer
#define TT_STR_DEFAULT 0x00 // �������� �� ��������� ��� ���� string
#define TI_NULLIDX (ushort)0xffffffff // ��� �������� � ������� ���������������
#define TI_STR_MAXSIZE 255 

namespace IT
{
	enum IDDATATYPE // ���� ������ ���������������
	{
		INT = 1,
		STR = 2
	};

	enum IDTYPE // ���� ���������������
	{
		V = 1, // ����������
		F = 2, // �������
		P = 3, // ��������
		L = 4, // �������
	};

	struct Entry // ������ � ������� ���������������
	{
		int idxfirstLE; // ������ ������ ������ � ������� ������
		char id[ID_MAXSIZE]; // �������������
		IDDATATYPE iddatatype; // ��� ������ ��������������
		IDTYPE idtype; // ��� ��������������

		union
		{
			int vint; // �������� ��� ���� integer

			struct
			{
				char len; // ���������� �������� � string
				char str[TI_STR_MAXSIZE - 1]; // ������� string

			} vstr[TI_STR_MAXSIZE]; // �������� ��� ���� string

		} value;
	};

	struct IdTable // ��������� ������� ���������������
	{
		int maxsize; // ������������ ���������� ������� � ������� ��������������� < TI_MAXSIZE
		int size; // ������� ������ ������� ��������������� < maxsize
		Entry* table; // ������ ����� ������� ���������������
	};

	IdTable Create(int size); // �������� ������� ���������������

	void Add( // ���������� ������ � ������� ���������������
		IdTable& idtable, // ������� ���������������
		Entry entry // ������ ������� ���������������
	);

	Entry GetEntry( // ��������� ������ �� ������� ���������������
		IdTable& idtable, // ������� ���������������
		int n // ����� ������ � ������� ���������������
	);

	int IsId( // ����� �������������� � ������� ��������������� ������� ������ ��� TI_NULLIDX
		IdTable& idtable, // ������� ���������������
		char id[ID_MAXSIZE] // �������������
	);

	void Delete(IdTable& idtable); // �������� ������� ���������������
}