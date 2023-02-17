#include "stdafx.h"

namespace Log
{
	LOG getlog(wchar_t logfile[]) // ������ � ��������� ���
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

	}// ������ � ��������� LOG

	void WriteLine(LOG log, char* c, ...)//������������ �����
	{
		char** pc = &c;
		char l[1024] = "";
		while (*pc != "")
		{
			strcat_s(l, *pc);
			pc++;
		}
		*log.stream << l;
	}// ������� � �������� ������������ �����
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
		*log.stream << "�----- �������� �- ����: " << date << "-----------------------------------------" << std::endl;
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		char change[20];
		*log.stream << "-�---- ���������----------- " << std::endl;
		wcstombs_s(0, change, parm.log, IN_MAX_LEN_TEXT);
		*log.stream << "-log:" << change << std::endl;
		wcstombs_s(0, change, parm.out, IN_MAX_LEN_TEXT);
		*log.stream << "-out:" << change << std::endl;
		wcstombs_s(0, change, parm.in, IN_MAX_LEN_TEXT);
		*log.stream << "-in:" << change << std::endl;
	}
	void WriteIn(LOG log, In::IN in)
	{
		*log.stream << "-�---- �������� ������----------- " << std::endl;
		*log.stream << in.text << std::endl;
		*log.stream << "���������� ��������: " << in.size << std::endl;
		*log.stream << "���������������: " << in.ignor << std::endl;
		*log.stream << "���������� �����: " << in.lines << std::endl;
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (log.stream->is_open())
		{
			*log.stream << "������: " << error.id << ": " << error.message << " ������ " << error.inext.line << ", ������� " << error.inext.col << std::endl;
		}
		else
		{
			std::cout << "������: " << error.id << ": " << error.message << " ������ " << error.inext.line << ", ������� " << error.inext.col << std::endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
};