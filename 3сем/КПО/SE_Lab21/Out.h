#pragma once
#include "In.h"
#include "Parm.h"
#include "Error.h"

namespace Out	// –абота с протоколом
{
	struct OUT // протокол
	{
		wchar_t outfile[PARM_MAX_SIZE]; // им€ файла протокола
		std::ofstream* stream;	// выходной поток протокола
	};

	static const OUT INITOUT{ L"", NULL };// структура дл€ начальной инициализации OUT
	OUT getout(wchar_t outfile[]);// сформировать структуру OUT
	void WriteIn(OUT out, In::IN in);
	void WriteError(OUT out, Error::ERROR error);
	void close(OUT out);
};