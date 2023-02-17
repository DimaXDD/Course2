#pragma once
#include <cstddef>

namespace FST
{
	struct RELATION      // ребро:символ -> веришан графа переходов КА
	{
		char symbol;        // символ перехода
		short nnode;		// номер смежной вершины
		RELATION
		(
			char c = 0x00,		//символ перехода
			short ns = NULL		// новое состояние
		);
	};

	struct NODE			// вершина графа переходов
	{
		short n_relation;		//количество инцидентных ребер
		RELATION* relations;	// инцидентные ребра
		NODE();
		NODE
		(
			short n,	// количество инциндентных ребер
			RELATION rel, ...		// список ребер
		);
	};

	struct FST			// недетерминированный конечный автомат
	{
		char* string;		// цепочка(строкаб завешатся 0х00
		short position;		// текущая позиция в цепочке
		short nstates;		//количество состояний автомата
		NODE* nodes;		// граф переходов: [0] - начальное состояние, [nstate - 1] - конечное
		short* rstates;		// возможные состояния автомата на данной позиции
		FST
		(
			char* s,		//цпочка (строкаб завершается 0х00)
			short ns,		// кооличетсво состояний автомата
			NODE n, ...		// список состояний (граф переходов)
		);
		FST(char* str, short nst, NODE* nd, ...);
	};

	bool execute		//выполнить распознавание цепочки
	(
		FST& fst		//недетерминированный конечный автомат
	);

}
