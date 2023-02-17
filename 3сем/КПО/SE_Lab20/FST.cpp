#include "FST.h"
#include <vector>

namespace fst
{
	RELATION::RELATION(
		char c,
		short nn
	)
	{
		symbol = c;
		nnode = nn;
	};

	NODE::NODE()
	{
		n_relation = 0;
		relations = NULL;
	};

	NODE::NODE(
		short n,
		RELATION rel,
		...
	)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		
		for (short i = 0; i < n; i++)
		{
			relations[i] = p[i];
		}
	};

	FST::FST(
		char* s,
		short ns,
		NODE n,
		...)
	{
		string = s;
		nstates = ns;
		nodes = new NODE[ns];

		NODE* p = &n;

		for (int k = 0; k < ns; k++)
		{
			nodes[k] = p[k];
		}

		position = -1;
	};

	bool execute(FST& fst)
	{
		char* str = fst.string;
		char symb;
		short nRStates = 1;

		fst.rstates = new short[1];
		fst.rstates[0] = 0;

		for (short i = 0; i < strlen(str); i++)
		{
			symb = str[i];
			fst.position++;

			if (isAllowed(symb, fst.rstates, nRStates, fst))
			{
				fst.rstates = setRelState(symb, fst, &nRStates, fst.rstates);

				if (i + 1 == strlen(str) &&
					isLastState(fst.rstates, nRStates, fst.nstates))
				{
					return true;
				}
			}
			else
			{
				return false;
			}
		}

		fst.string = nullptr;
		delete [] fst.rstates;
		
		return false;
	}

	bool isLastState(short* rstates, short length, short countStates)
	{
		for (short i = 0; i < length; i++)
		{
			if (rstates[i] == countStates - 1)
			{
				return true;
			}
		}

		return false;
	}

	bool isAllowed(
		char symb,
		short*& rstates,
		short length,
		FST& fst
	)
	{
		for (short i = 0; i < length; i++)
		{
			for (short j = 0; j < fst.nodes[rstates[i]].n_relation; j++)
			{
				if (symb == fst.nodes[rstates[i]].relations[j].symbol)
				{
					return true;
				}
			}
		}
		return false;
	}

	short* setRelState(
		char symb,
		FST& fst,
		short* pNRStates,
		short* rstates)
	{
		vector<short> vrstates;
		short nRStates = *pNRStates;

		for (short i = 0; i < nRStates; i++)
		{
			for (short j = 0; j < fst.nodes[rstates[i]].n_relation; j++)
			{
				if (fst.nodes[rstates[i]].relations[j].symbol == symb)
				{
					vrstates.push_back(fst.nodes[rstates[i]].relations[j].nnode);
				}
			}
		}

		delete[] rstates;

		auto result = new short[vrstates.size()];
		*pNRStates = vrstates.size();

		for (short i = 0; i < vrstates.size(); i++)
		{
			result[i] = vrstates[i];
		}

		return result;
	}
}