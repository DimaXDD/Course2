#pragma once

#define LEXEMA_FIXSIZE 1	//фиксированный размер лексем
#define LT_MAXSIZE 4096		//макс количество строк в таблице
#define LT_TI_NULLIDX 0xffffffff	//нет элемента “»
#define LEX_INTEGER		't'	//лексема дл€ integer
#define LEX_STRING		't'	//лексема дл€ string
#define LEX_LITERAL		'l'	//лексема дл€ литерала
#define LEX_ID			'i'	//лексема дл€ идентификатора
#define LEX_FUNCTION	'f'	//лексема дл€ function
#define LEX_MAINFUNC	'm'	//лексема дл€ main
#define LEX_DECLARE		'd'	//лексема дл€ declare
#define LEX_RETURN		'r'	//return
#define LEX_PRINT		'p'	//print
#define LEX_SEMICOLON	';'	//;
#define LEX_COMMA		','	//,
#define LEX_LEFTBRACE	'{'	//{
#define LEX_RIGHTBRACE  '}'	//}
#define LEX_LEFTHESIS	'('	//(
#define LEX_RIGHTHESIS	')'	//)
#define LEX_PLUS		'v'	//+
#define LEX_MINUS		'v'	//-
#define LEX_MULTIPLICATION		'v'	//*
#define LEX_DIRSLASH	'v'	// /
#define LEX_EQUAL			'='	//=


namespace LT
{
	struct  Entry
	{
		char lexema[LEXEMA_FIXSIZE];
		int sn;
		int idxTI;
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);

	void Add(LexTable& lextable, Entry entry);

	Entry GetEntry(LexTable& lextable, int n);

	void Delete(LexTable& lextable);

};