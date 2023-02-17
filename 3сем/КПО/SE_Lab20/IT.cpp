#include "IT.h"
#include "stdafx.h"

namespace IT
{
	IdTable Create(int size)
	{
		if (size > TI_MAXSIZE)
		{
			throw ERROR_THROW(116);
		}

		IdTable idtable;

		idtable.maxsize = size;
		idtable.size = 0;
		idtable.table = new Entry[size];

		return idtable;
	}

	void Add(
		IdTable& idtable,
		Entry entry)
	{
		if (idtable.size >= idtable.maxsize)
		{
			throw ERROR_THROW(117);
		}

		idtable.table[idtable.size] = entry;
		idtable.size++;
	}

	Entry GetEntry(
		IdTable& idtable,
		int n)
	{
		if (
			n >= idtable.maxsize ||
			n < 0)
		{
			throw ERROR_THROW(118);
		}

		return idtable.table[n];
	}

	int IsId(
		IdTable& idtable,
		char id[ID_MAXSIZE])
	{
		for (int i = 0; i < idtable.size; i++)
		{
			if (strcmp(idtable.table[i].id, id) == 0)
			{
				return i;
			}
		}

		return TI_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete[] idtable.table;
		idtable.size = 0;
		idtable.maxsize = 0;
	}
}