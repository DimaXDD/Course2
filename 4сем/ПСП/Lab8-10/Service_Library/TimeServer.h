#pragma once
#include "Global.h"

//����������� ������ ���������� ������������������  time � ����������  ��������� ��������� ���� � ������� ���������� ���������� � �������: dd.mm.yyyy/hh:mm:ss.
//������� ���������� ������: ����� ����� ������������������ ��������, �������� ��   time.     
DWORD WINAPI TimeServer(LPVOID lParam) {
	
	DWORD rc = 0;		// ��� ��������
	Contact* client = (Contact*)lParam;
	
	QueueUserAPC(ASStartMessage, client->hAcceptServer, (DWORD)client);	// ������ � ������� ��������� � ������ ������������
	try {
		client->sthread = Contact::WORK;
		int  bytes = 1;
		char ibuf[50], obuf[50] = "Close: finish;", Time[50] = "Time";
		// ��������� ������ �� ������
		while (client->TimerOff == false) {
			if ((bytes = recv(client->s, ibuf, sizeof(ibuf), NULL)) == SOCKET_ERROR) {	// ��������� ������
				switch (WSAGetLastError()) {
				case WSAEWOULDBLOCK: Sleep(100); break;
				default: throw  SetErrorMsgText("Recv:", WSAGetLastError());
				}
			}
			else {
				if (strcmp(ibuf, "Time") == 0) {
					if (client->TimerOff != false) {// ��������� ����� ������������ �������
						break;
					}
					SYSTEMTIME stt;
					GetLocalTime(&stt);
					sprintf_s(ibuf, "%s %d.%d.%d/%d:%02d:%d", Time, stt.wDay, stt.wMonth, stt.wYear, stt.wHour, stt.wMinute, stt.wSecond);
					if ((send(client->s, ibuf, sizeof(ibuf), NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());// ���������� �������
				}
				else break;
			}
		}


		if (client->TimerOff == false) {
			
			CancelWaitableTimer(client->htimer);// ��������� ������
			if ((send(client->s, obuf, sizeof(obuf) + 1, NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());
			
			client->sthread = Contact::FINISH;// ������ ����� �������� ����������
			QueueUserAPC(ASFinishMessage, client->hAcceptServer, (DWORD)client);
		}
	}
	catch (string errorMsgText) {
		std::cout << errorMsgText << std::endl;
		CancelWaitableTimer(client->htimer);
		client->sthread = Contact::ABORT;
	}
	ExitThread(rc);	// ��������� �����
}