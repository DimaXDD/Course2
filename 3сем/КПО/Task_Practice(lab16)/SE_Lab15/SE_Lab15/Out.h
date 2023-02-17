#pragma once

#include "In.h"
#include "Parm.h"
#include "Error.h"

namespace Out	// ������ � ����������
{
	struct OUT // ��������
	{
		wchar_t outfile[PARM_MAX_SIZE]; // ��� ����� ���������
		std::ofstream* stream;	// �������� ����� ���������
	};

	static const OUT INITLOG{ L"", NULL };// ��������� ��� ��������� ������������� LOG
	OUT getout(wchar_t outfile[]);// ������������ ��������� LOG
	void WriteOut(In::IN in, wchar_t out[]); // �������� Out ����� � ����� ������������� ������
	void WriteError(OUT out, Error::ERROR error);
	void Close(OUT out);
};