#pragma once
#include "Error.h"
typedef short GRBALPHABET;		///символы алфавита грамматики терминалы > 0, нетерминалы < 0

namespace GRB
{
	//Правило в грамматике Грейбах
	struct Rule
	{
		///предст. одного правила в виде A->xxx|yyy|....
		GRBALPHABET nn;		///нетерминал (левый символ правила) < 0
		int iderror;		///код ошибки в Error
		short size;			///кол-во цепочек - правых частей правила


		//Представление цепочки - правой стороны правила
		struct Chain
		{
			short size;						///длина цепочки
			GRBALPHABET* nt;				///цепочка терминалов (>0) и нетермналов (<0)
			Chain() {
				size = 0;
				nt = 0;
			};
			Chain(
				short psize,				///кол-во символов в цепочке
				GRBALPHABET s, ...			///символы (терминал или нетерминал)
			);
			char* getCChain(char* b);		///получить строку-цепочку в символьном виде для отображения

			//Методы, преобр. ASCI-символы в GRBALPHABET-символы (т и н)
			static GRBALPHABET T(char t) {
				return GRBALPHABET(t);		///терминал
			};
			static GRBALPHABET N(char n) {
				return -GRBALPHABET(n);		///нетерминал
			};

			//Методы, провер. явл. ли GRBALPHABET-символ т или н
			static bool isT(GRBALPHABET s) {
				return s > 0;				///терминал?
			};
			static bool isN(GRBALPHABET s) {
				return !isT(s);				///нетерминал?
			}

			//Метод, преобр. параметр GRBALPHABET-символ в ASCI-символ
			static char alphabet_to_char(GRBALPHABET s) {
				return isT(s) ? char(s) : char(-s); ///массив цепочек - правых частей правила
			};
		}*chains;

		Rule() {				///к-ры
			nn = 0x00;
			size = 0;
		}
		Rule(
			GRBALPHABET pnn,	///нетерминал (<0)
			int iderror,		///иден сообщения диагностики (Error)
			short psize,		///кол-во цепочек - правых частей правила
			Chain c, ...		///мн-во цепочек - правых частей правила
		);
		char* getCRule			///Получить правило в виде N->цепочка (для распечатки)
		(
			char* b,			///буфер
			short nchain		///№ цепочки (правой части) в правиле
		);
		short getNextChain(	///Получить след. за j цепочку, вернуть ее номер или -1
			GRBALPHABET t,			///первый символ цепочки
			Rule::Chain& pchain,	///возвращаемая цепочка
			short j					///№ цепочки
		);
	};


	struct Greibach				//Грамматика Грейбах
	{
		short size;				///кол-во правил
		GRBALPHABET startN;		///стартовый символ
		GRBALPHABET stbottomT;	///дно стека (последняя лексема в ТЛ)
		Rule* rules;			///мн-во правил
		Greibach() {		///к-р без парам
			short size = 0;
			startN = 0;
			stbottomT = 0;
			rules = 0;
		};
		Greibach(
			GRBALPHABET pstartN,	///стартовый символ
			GRBALPHABET pstbottomT,	///дно стека
			short psize,			///кол-во правил
			Rule r, ...				///правила
		);
		short getRule(			///Получить № правила или -1
			GRBALPHABET pnn,	///левый символ правила
			Rule& prule			///возвращаемое правило грамматики
		);
		Rule getRule(short n);	///получить правило по номеру
	};
	Greibach getGreibach();		///получить грамматику
};