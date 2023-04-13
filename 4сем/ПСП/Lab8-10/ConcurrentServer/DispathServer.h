#pragma once
#include "Global.h"

//����� ������ ������� �� ������� ����� �����������, ���������� �������������, �������������� �������
//�������� ���������� (����� � ��� ���������) � ����� ����������� ����� ������ ListContact(�������� ������ ��������� �
//����������� � ������ AcceptServer).

//������ ��������� �������� �������(� ������� ���������� �������) �� ������� ����������� �� ��������� ������ �������, ���������������� ������� ��
//������������, � ����� ��������� ����� ��������������� ������������ �������(�) ��� �������� ��������������� ���������.
DWORD WINAPI DispathServer(LPVOID pPrm) {
	cout << "DispathServer ��������\n";
	DWORD rc = 0;
	try {
		while (*((TalkersCommand*)pPrm) != EXIT) {//������� ������ �� �����
			try {
				if (WaitForSingleObject(Event, 300) == WAIT_OBJECT_0) {//������� � ���������� ���������

					if (&ClientServiceNumber > (volatile LONG*)0) {
						Contact* client = NULL;
						int libuf = 1;
						char CallBuf[50] = "", SendError[50] = "ErrorInquiry";
						EnterCriticalSection(&scListContact);

						//������ ��������������� ������������� ������ ListContact  (� ������� �������� ��� �������� � �������������� ��������)
						//� ��������� ������, ��������������� �������
						for (ListContact::iterator p = Contacts.begin(); p != Contacts.end(); p++) {
							if (p->type == Contact::ACCEPT)
							{
								client = &(*p);

								//��� ����������� � ������ ���������������, �� �� ������������ ������� (��� ����� ����������  �� ����������� ���������, 
								//���������� � ������� ������) ������� ��������� ������ ��������� ������� (������� ������ ���� ����� �������) � �������
								//������� recv (������ 3.11).
								bool flag = false;
								while (flag == false) {
									if ((libuf = recv(client->s, CallBuf, sizeof(CallBuf), NULL)) == SOCKET_ERROR) {
										switch (WSAGetLastError()) {
											case WSAEWOULDBLOCK: Sleep(100); break;
											default: throw  SetErrorMsgText("Recv:", WSAGetLastError());
										}
									}
									else flag = true;
								}

								if (flag == true) {//if Rand, Echo or Time
									string time_error;

									
									client->type = Contact::CONTACT;
									strcpy_s(client->srvname, CallBuf);

									//��������� ������ ����� ����������� ������� AcceptServer
									//��� ������� ����������� ������ EchoSever.����� �� ����� ��������
									//������ �� ��������� ��������, � ������� ����������� �������� ������
									//AcceptServer ����� ���������� ��������������� ��������� ����������.
									// 
									//��������� � ���������� ��������� ����� ����  ������ ����� ������� �������������� 
									//������� (�.�. ���� ������ � ��� ����������� ���������� ����� ������ �������������� �������).
									client->htimer = CreateWaitableTimer(NULL, false, NULL);
									_int64 time = -600000000;
									SetWaitableTimer(client->htimer, (LARGE_INTEGER*)&time, 0, ASWTimer, client, false);
									cout << CallBuf <<  " ������ ������" << endl;
									if ((libuf = send(client->s, CallBuf, sizeof(CallBuf), NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Send:", WSAGetLastError());
									client->hthread = sss(CallBuf, client);
								}
								else {
								//������������� ������, ��������� ���� ������ �� ���������  
								//�������������� ������������� ��������� ��� ������
									if ((libuf = send(client->s, SendError, sizeof(SendError) + 1, NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Send:", WSAGetLastError());
									closesocket(client->s);
									client->sthread = Contact::ABORT;
									CancelWaitableTimer(client->htimer);
									InterlockedIncrement(&Fail);
								}
							}
						}
						LeaveCriticalSection(&scListContact);
					}
					SleepEx(0, true);
				}
				SleepEx(0, true);
			}
			catch (string errorMsgText) {
				std::cout << errorMsgText << endl;
			}
		}
	}
	catch (string errorMsgText) {
		std::cout << errorMsgText << endl;
	}
	catch (...) {
		std::cout << "Error DispathServer" << std::endl;
	}
	cout << "DispathServer ����������\n" << endl;
	ExitThread(rc);
}