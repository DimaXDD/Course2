#pragma once
#define PARM_IN "-in:"
#define PARM_OUT "-out:"
#define PARM_LOG "-log:"
#define PARM_MAX_SIZE 300
#define PARM_OUT_DEFAULT_EXT L".out"
#define PARM_LOG_DEFAULT_EXT L".log"

void wcscpy_s(wchar_t* a1, wchar_t* a2);
void strcpy_s(char* a1, const char* a2);
void translate(char*, wchar_t*, short i = 0);

namespace Parm
{
	struct PARM
	{
		wchar_t in[PARM_MAX_SIZE];  // -in ��� ����� � �������� �����
		wchar_t out[PARM_MAX_SIZE]; // -out ��� ����� ���������� ����
		wchar_t log[PARM_MAX_SIZE] = L"program.log"; // -log ��� ����� ���������
	};

	PARM getparm(int argc, _TCHAR* argv[]); // ������������ struct PARM �� ������ ���������� ������� main
}