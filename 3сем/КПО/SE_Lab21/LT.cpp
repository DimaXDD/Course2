#include "stdafx.h"


namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE)
		{
			throw ERROR_THROW(113);
		}
		LexTable* lexTable = new LexTable;
		lexTable->maxsize = size;
		lexTable->size = 0;
		lexTable->table = new Entry[size];
		return *lexTable;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size + 1 > lextable.maxsize)
		{
			throw ERROR_THROW(114);
		}
		lextable.table[lextable.size] = entry;
		lextable.size += 1;
	}

	Entry GetEntry(LexTable& lextable, int n)
	{
		return lextable.table[n];
	}

	void DElETE(LexTable& lextable)
	{
		delete[]lextable.table;
	}

};