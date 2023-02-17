#pragma once

#define LEXEMA_FIXSIZE 1   // ������������� ������ �������
#define LT_MAXSIZE  4096 // ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� ������� ����������������
#define REG_WORD "[A-Za-z_]+[A-Za-z0-9_]*" // ���������� ��������� ��� �����

#define LEX_INTEGER 't' // ������� ��� integer
#define LEX_STRING 't' // ������� ��� string
#define LEX_ID 'i' // ������� ��� ��������������
#define LEX_LITERAL 'l' // ������� ��� ��������
#define LEX_FUNCTION 'f' // ������� ��� �������
#define LEX_DECLARE 'd' // ������� ��� declare
#define LEX_RETURN 'r' // ������� ��� return
#define LEX_PRINT 'p' // ������� ��� print
#define LEX_SEMICOLON ';' // ������� ��� ;
#define LEX_COMMA ',' // ������� ��� ,
#define LEX_LEFTBRACE '{' // ������� ��� {
#define LEX_RIGHTBRACE '}' // ������� ��� }
#define LEX_LEFTHESIS '(' // ������� ��� (
#define LEX_RIGHTHESIS ')' // ������� ��� )
#define LEX_PLUS '+' // ������� ��� +
#define LEX_MINUS '-' // ������� ��� -
#define LEX_STAR '*' // ������� ��� *
#define LEX_DIRSLASH '/' // ������� ��� /
#define LEX_MAIN 'm' // ������� ��� main

namespace LT // ������� ������
{
	struct Entry
	{
		char lexema; // �������
		int sn; // ����� ������
		int idxTI; // ������ � ������� ���������������
	};

	struct LexTable
	{
		int maxsize; // ������������ ������ �������
		int size; // ������� ������ �������
		Entry* table; // ������� ������
	};

	LexTable Create( // �������� ������� ������
		int size // ������������ ������ �������
	);

	void Add( // ���������� ������� � �������
		LexTable& lextable, // ������� ������
		Entry entry // �������
	);

	Entry GetEntry( // ��������� ������� �� �������
		LexTable& lextable, // ������� ������
		int n // ����� �������
	);

	void Delete( // �������� ������� ������
		LexTable& lextable // ������� ������
	);

}
