#include "stdafx.h"

namespace IT
{
	IdTable Create(int size)
	{
		if (size > TI_MAXSIZE)
		{
			throw ERROR_THROW(115);
		}
		IdTable* table = new IdTable;
		table->maxsize = size;
		table->size = 0;
		table->table = new Entry[size];
		return *table;
	}

	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size + 1 > idtable.maxsize)
		{
			throw ERROR_THROW(116);
		}
		idtable.table[idtable.size] = entry;
		idtable.size += 1;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		int n = 0;
		bool flag = false;
		
		for (int i = 0; i < idtable.size -1; i++)
		{
			if (idtable.table[i].id == id)
			{
				flag = true;
				n = i;
				break;
			}
		}
		if (flag)
		{
			return n + 1;
		}
		else
		{
			return TI_NULLIDX;
		}
	}

	void DELETE(IdTable& idtable)
	{
		delete[]idtable.table;
	}
};