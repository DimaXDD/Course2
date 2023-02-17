#pragma once

#include "In.h"
#include "Parm.h"
#include "Error.h"

namespace Out	// Работа с протоколом
{
	struct OUT // протокол
	{
		wchar_t outfile[PARM_MAX_SIZE]; // имя файла протокола
		std::ofstream* stream;	// выходной поток протокола
	};

	static const OUT INITLOG{ L"", NULL };// структура для начальной инициализации LOG
	OUT getout(wchar_t outfile[]);// сформировать структуру LOG
	void WriteOut(In::IN in, wchar_t out[]); // создание Out файла и вывод обработанного текста
	void WriteError(OUT out, Error::ERROR error);
	void Close(OUT out);
};