#include "stdafx.h"
#include "Parm.h"
#include "Error.h"


namespace Parm
{
	//���������: argc � ���������� ����������(int, >= 1),
	//argv � ������ ���������� �� ���� - ������������ ������ ��
	//���������� ����������, (_TCHAR* � ��������� �� ������ wchar_t)

	PARM getparm(int argc, wchar_t* argv[])
	{
		PARM parm;

		// boolean - ���������� ��� ������ -in, -out, -log
		bool in_find = 0, out_find = 0, log_find = 0;
		for (int i = 1; i < argc; i++)
		{ // wcslen - ���������� ����� ������
			if (wcslen(argv[i]) > PARM_MAX_SIZE) { throw ERROR_THROW(104); }

			if (wcsstr(argv[i], PARM_IN))	
			{
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN));
				in_find = 1;
			}
			if (wcsstr(argv[i], PARM_OUT))
			{
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));
				out_find = 1;
			}
			if (wcsstr(argv[i], PARM_LOG))
			{
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));
				log_find = 1;
			}
		}

		// ���� �� ����� -in
		if (!in_find) throw ERROR_THROW(100);

		// -out
		if (!out_find)
		{
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}

		// -log
		if (!log_find)
		{
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}
		return parm;
	}
}