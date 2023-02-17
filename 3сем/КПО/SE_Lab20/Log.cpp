#include "Log.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string>

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log;
		std::ofstream* stream = new std::ofstream(logfile);
		if (!stream->is_open())
		{
			throw ERROR_THROW(112);
		}
		else
		{
			wcscpy_s(log.logfile, logfile);
			log.stream = stream;
		}
		return log;
	}
	void WriteLine(LOG log, char* c, ...)
	{
		char** el = &c;
		char* str = *el;
		while (strlen(str) != 0)
		{
			el += 1;
			*(log.stream) << str;
			str = *el;
		}
	}
	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t** el = &c;
		wchar_t* wStr = *el;
		char chStr[MAX_LEN_LINE];
		while (wcslen(wStr) != 0)
		{
			wcstombs_s(0, chStr, wStr, MAX_LEN_LINE); // перевод из wchar_t в char
			el += 1;
			wStr = *el;
			*(log.stream) << chStr;
		}
	}
	void WriteLog(LOG log)
	{
		string(*check)(int num) = [](int num)
		{
			return ((num >= 0 && num <= 9) ? ("0" + std::to_string(num)) : std::to_string(num));
		};
		short day;
		short month;
		short year;
		short second;
		short minute;
		short hour;
		string head;
		head = "\n---- Протокол ------";

		struct tm u;
		char* f;

		const time_t timer = time(NULL);
		localtime_s(&u, &timer);

		day = u.tm_mday;
		month = u.tm_mon;
		year = u.tm_year;
		second = u.tm_sec;
		minute = u.tm_min;
		hour = u.tm_hour;

		head +=
			check(day) + "." + check(month + 1) + "." + "20" + std::to_string(year % 100) + " " +
			check(hour) + ":" + check(minute) + ":" + check(second) + " --------\n";

		*(log.stream) << head;
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char out[PARM_MAX_SIZE];
		char in[PARM_MAX_SIZE];
		char Log[PARM_MAX_SIZE];

		wcstombs_s(0, in, parm.in, PARM_MAX_SIZE);
		wcstombs_s(0, out, parm.out, PARM_MAX_SIZE);
		wcstombs_s(0, Log, parm.log, PARM_MAX_SIZE);

		string head = "---- Параметры --------------\n";
		*(log.stream) << PARM_IN << "\t" << in << endl
			<< PARM_OUT << "\t" << out << endl
			<< PARM_LOG << "\t" << Log << endl;
	}
	void WriteIn(LOG log, In::IN in)
	{
		string head = "---- Исходные данные --------\n";
		*(log.stream) << head <<
			"Количество символов:\t\t" << in.size << endl <<
			"Проигнорировано:\t\t" << in.ignore << endl <<
			"Количество строк:\t\t" << in.lines << endl;
	}
	void WriteError(LOG log, Error::ERROR e)
	{
		if (e.inext.line != -1)
		{
			*(log.stream)
				<< "Ошибка: " << e.id << " : " << e.message << std::endl
				<< "Строка: " << e.inext.line << "  Символ: " << e.inext.col << std::endl;
		}
		else
		{
			*(log.stream) << "Ошибка: " << e.id << " : " << e.message << std::endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
}