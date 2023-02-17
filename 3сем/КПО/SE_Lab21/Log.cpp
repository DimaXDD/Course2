#include "stdafx.h"

namespace Log
{
	LOG getlog(wchar_t logfile[]) // Запись в структуру лог
	{
		LOG log;
		log.stream = new std::ofstream;
		log.stream->open(logfile);
		if (!log.stream->is_open())
		{
			throw ERROR_THROW(112);
		}
		wcscpy_s(log.logfile, logfile);
		return log;

	}// запись в структуру LOG

	void WriteLine(LOG log, char* c, ...)//конкатенация строк
	{
		char** pc = &c;
		char l[1024] = "";
		while (*pc != "")
		{
			strcat_s(l, *pc);
			pc++;
		}
		*log.stream << l;
	}// вывести в протокол конкатенацию строк
	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t** pc = &c;
		char l[1024] = "";
		char f[1024] = "";
		while (*pc != L"")
		{
			wcstombs_s(0, l, *pc, IN_MAX_LEN_TEXT);
			strcat_s(f, l);
			pc++;
		}
		*log.stream << f;
	}
	void WriteLog(LOG log)
	{
		char date[100];
		tm local;
		time_t currentTime;
		currentTime = time(NULL);
		localtime_s(&local, &currentTime);
		strftime(date, 100, "%d.%m.%Y %H:%M:%S", &local);
		*log.stream << "—----- Протокол —- Дата: " << date << "-----------------------------------------" << std::endl;
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char change[20];
		*log.stream << "-—---- Параметры----------- " << std::endl;
		wcstombs_s(0, change, parm.log, IN_MAX_LEN_TEXT);
		*log.stream << "-log:" << change << std::endl;
		wcstombs_s(0, change, parm.out, IN_MAX_LEN_TEXT);
		*log.stream << "-out:" << change << std::endl;
		wcstombs_s(0, change, parm.in, IN_MAX_LEN_TEXT);
		*log.stream << "-in:" << change << std::endl;
	}
	void WriteIn(LOG log, In::IN in)
	{
		*log.stream << "-—---- Исходные данные----------- " << std::endl;
		*log.stream << in.text << std::endl;
		*log.stream << "Количество символов: " << in.size << std::endl;
		*log.stream << "Проигнорировано: " << in.ignor << std::endl;
		*log.stream << "Количество строк: " << in.lines << std::endl;
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (log.stream->is_open())
		{
			*log.stream << "Ошибка: " << error.id << ": " << error.message << " строка " << error.inext.line << ", позиция " << error.inext.col << std::endl;
		}
		else
		{
			std::cout << "Ошибка: " << error.id << ": " << error.message << " строка " << error.inext.line << ", позиция " << error.inext.col << std::endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
};