#pragma once
#define PARM_IN L"-in:" // ���� ��� ����� ��������� ����
#define PARM_OUT L"-out:" // ���� ��� ����� ���������� ����
#define PARM_LOG L"-log:" // ���� ��� ����� �������
#define PARM_MAX_SIZE 300 // ������������ ����� ������ ��������� 
#define PARM_OUT_DEFAULT_EXT L".out" // ���������� ����� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log" // ���������� ����� ���������� ���� �� ���������

namespace Parm // ��������� ������� ���������� 
{
	struct PARM // ������� ���������	
	{
		wchar_t in[PARM_MAX_SIZE]; // -in: ��� ����� ��������� ����
		wchar_t out[PARM_MAX_SIZE]; // -out: ��� ����� ���������� ����
		wchar_t log[PARM_MAX_SIZE]; // -log: ��� ����� ���������
	};

											// int _tmain(int argc, _TCHAR* argv[])
	PARM getparm(int argc, wchar_t* argv[]); // ������������ struct PARM �� ������ ���������� ������� main
};

