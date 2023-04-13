#define _CRT_SECURE_NO_WARNINGS

#include "Global.h"
#include "AcceptServer.h"
#include "DispathServer.h"
#include "GarbageCleaner.h"
#include "ConsolePipe.h"
#include "ResponseServer.h"
#include "tchar.h"


int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");

	try {

		if (argc > 1) {
			int tmp = atoi(argv[1]);
			if (tmp >= 0 && tmp <= 65535) {
				port = atoi(argv[1]);
				cout << "����� TCP-����: " << port << endl;
			}
			else {
				cout << "����� �������� TCP-����" << endl;
			}
		}
		else {
			cout << "������������ TCP ���� �� ���������: " << port << endl;
		}

		if (argc > 2) {
			int tmp = atoi(argv[2]);
			if (tmp >= 0 && tmp <= 65535) {
				uport = atoi(argv[2]);
				cout << "����� UDP-����: " << uport << endl;
			}
			else {
				cout << "����� �������� UDP-����" << endl;
			}
		}
		else {
			cout << "������������ UDP ���� �� ���������: " << uport << endl;
		}

		if (argc > 3) { //3 �������� - ��� ����������
			dllname = argv[3];
		}

		if (argc > 4) {
			npname = argv[4];
			cout << "������ ��� ������������ ������: " << npname << endl;
		}
		else cout << "������������ ��� ������������ ������ �� ���������: " << npname << endl;

		if (argc > 5) {
			ucall = argv[5];
			cout << "����� ��������:   " << ucall << endl;
		}
			cout << "������������ �������� �� ���������: " << ucall << endl;
		srand((unsigned)time(NULL));

		volatile TalkersCommand  cmd = START;

		InitializeCriticalSection(&scListContact);


		st1 = LoadLibrary(dllname);
		sss = (HANDLE(*)(char*, LPVOID))GetProcAddress(st1, "SSS");
		if (st1 == NULL) cout << "������ ��� �������� DLL" << endl;
		else cout << "��������� DLL " << dllname << endl << endl;


		hAcceptServer = CreateThread(NULL, NULL, AcceptServer, (LPVOID)&cmd, NULL, NULL);            //main
		HANDLE hDispathServer = CreateThread(NULL, NULL, DispathServer, (LPVOID)&cmd, NULL, NULL);

		HANDLE hConsolePipe = CreateThread(NULL, NULL, ConsolePipe, (LPVOID)&cmd, NULL, NULL);       //main - ������ ������������ ������
		HANDLE hGarbageCleaner = CreateThread(NULL, NULL, GarbageCleaner, (LPVOID)&cmd, NULL, NULL); //main


		HANDLE hResponseServer = CreateThread(NULL, NULL, ResponseServer, (LPVOID)&cmd, NULL, NULL);
			
		SetThreadPriority(hAcceptServer, THREAD_PRIORITY_HIGHEST);			//����� �������� ������ ����������� ��������
		SetThreadPriority(hGarbageCleaner, THREAD_PRIORITY_BELOW_NORMAL);	//���������� (� ������� ������)
		SetThreadPriority(hConsolePipe, THREAD_PRIORITY_NORMAL);

		SetThreadPriority(hResponseServer, THREAD_PRIORITY_ABOVE_NORMAL);
		SetThreadPriority(hDispathServer, THREAD_PRIORITY_NORMAL);

		WaitForSingleObject(hAcceptServer, INFINITE);
		WaitForSingleObject(hDispathServer, INFINITE);
		WaitForSingleObject(hConsolePipe, INFINITE);
		WaitForSingleObject(hGarbageCleaner, INFINITE);
		WaitForSingleObject(hResponseServer, INFINITE);

		CloseHandle(hAcceptServer);
		CloseHandle(hDispathServer);
		CloseHandle(hGarbageCleaner);
		CloseHandle(hConsolePipe);
		CloseHandle(hResponseServer);

		DeleteCriticalSection(&scListContact);

		FreeLibrary(st1);
	}
	catch (...) {
		cout << "error" << endl;
	}

	system("pause");
	return 0;
}