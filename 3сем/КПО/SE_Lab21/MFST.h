#pragma once
#include "GRB.h"
#include "LT.h"
#include <stack>
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
typedef std::stack<short> MFSTSTSTACK;		///стек автомата

namespace MFST
{
	struct MfstState			//Состояние автомата (для сохранения)
	{
		short lenta_position;	///позиция на ленте
		short nrule;
		short nrulechain;		///№ тек. цепочки, тек. правила
		MFSTSTSTACK st;			///стек автомата
		MfstState();
		MfstState(
			short pposition,	///позиция на ленте
			MFSTSTSTACK pst,	///стек автомата
			short pnrulechain	///№ текущей цепочки, тек. правила
		);
		MfstState(
			short pposition,
			MFSTSTSTACK pst,
			short pnrule,
			short pnrulechain
		);
	};

	struct Mfst					//Магазинный автомат
	{
		enum RC_STEP {			///код возврата ф-и step
			NS_OK,				///0 (найдено правило и цепочка, цеп. записана в стек)
			NS_NORULE,			///1 (не найдено правило (ошибка в грамматике)) 
			NS_NORULECHAIN,		///2 (не найдена подходящая цепочка правила (ошибка в исх. коде)
			NS_ERROR,			///3 (неизвестный нетерминал)
			TS_OK,				///4 (тек. символ ленты == вершине стека, продвинулась лента, pop стека)
			TS_NOK,				///5 (тек. символ ленты != вершине стека, восстановлено состояние)
			LENTA_END,			///6 (тек. позиция ленты >= lenta_size)
			SURPRISE
		};			///7 (неожиданный код возврата (ошибка в step)

		struct MfstDiagnosis		//Диагностика
		{
			short lenta_position;	///позиция на ленте
			RC_STEP rc_step;		///код завершения шага
			short nrule;			///номер правила
			short nrule_chain;		///номер цепочки правила
			MfstDiagnosis();
			MfstDiagnosis(
				short plenta_position,
				RC_STEP prc_step,
				short pnrule,
				short pnrule_chain);
		}diagnosis[MFST_DIAGN_NUMBER];	///последние самые глубокие сообщения

		GRBALPHABET* lenta;		///перекодированная (TS/NS) лента (из LEX)
		short lenta_position;	///тек. позиция на ленте
		short nrule;			///номер тек. правила
		short nrulechain;		///номер тек. цепочки, тек. правила
		short lenta_size;		///размер ленты
		GRB::Greibach grebach;	///граматика Грейбах
		LT::LexTable lex;		///рез. работы ЛА
		MFSTSTSTACK st;			///стек автомата
		std::stack<MfstState> storestate;	///стек для сохранения состояний
		Mfst();
		Mfst(
			LT::LexTable plex,
			GRB::Greibach pgrebach);

		char* getCSt		///получить содержимое стека
		(
			char* buf
		);
		char* getCLenta		///лента: n символов с pos
		(
			char* buf,
			short pos,
			short n = 25
		);
		char* getDiagnosis	///получ. n-ую строку диагностики или 0x00
		(
			short n,
			char* buf
		);
		bool savestate();	///сохранить состояние автомата
		bool reststate();	///восст. состояние автомата
		bool push_chain		///поместить цепочку правила в стек
		(
			GRB::Rule::Chain chain	///цепочка правила
		);
		RC_STEP step();		///выполнить шаг автомата
		bool start();		///запустить автомат
		bool savediagnosis
		(
			RC_STEP pprc_step	///код завершения шага
		);
		void printrules();	///вывести последовательность правил


		struct Deducation	///вывод
		{
			short size;				///кол-во шагов в выводе
			short* nrules;			///номера правил грамматики
			short* nrulechains;		///номера цепочек правил грамматики (nrules)
			Deducation() {
				size = 0;
				nrules = 0;
				nrulechains = 0;
			};
		}deducation;
		bool savededucation();		///сохранить дерево вывода
	};
}