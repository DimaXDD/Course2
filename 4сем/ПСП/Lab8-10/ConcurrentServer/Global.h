//Global
#pragma once
#include "locale.h"
#include <iostream>
#include "Winsock2.h"
#pragma comment(lib,"WS2_32.lib")
#include "Windows.h"
#include <string>
#include <list>
#include <time.h>
#include "Error.h"

using std::string;
using std::list;

int port = 2000; //������������ ���� (�������� �� ��������� 2000)
int uport = 2000; //udp-����, ������������ ResponseServer
const char* dllname = "Service_Library"; //�������� ����������� ���������� 
const char* npname = "cpipe"; //��� ������������ ������, ������������ ConsolePipe
const char* ucall = "HELLO";				//�������� �������, ������������ ResponseServer
//int squirt = AS_SQUIRT; //������� ������������ ���������� �������� ������������
HANDLE(*sss)(char*, LPVOID); //����������, ������������ ��� ������� ������� �� dll
HANDLE hAcceptServer; //���������� AcceptServer
HMODULE st1; //���������� dll

HANDLE Event = CreateEvent(NULL, FALSE, FALSE, NULL); //���������� �������


int AS_SQUIRT = 10; //������������ ���������� �������� ������������ define
enum TalkersCommand { START, STOP, EXIT, STATISTICS, WAIT, SHUTDOWN, GETCOMMAND }; //���������� ������� RConsole

//���������� �����������
volatile LONG Accept = 0;  //���������� �����������
volatile LONG Fail = 0;    //��������� �����������
volatile LONG Finished = 0;//����������� ������
volatile LONG ClientServiceNumber = 0;    //���������� � ������� ������


#pragma region  ListContact

CRITICAL_SECTION scListContact; //����������� ������

struct Contact         // ������� ������ �����������       
{
	//��������� ������� �����������
	enum TE {
		EMPTY,              //������ ������� ������ ����������� 
		ACCEPT,             //���������, �� �� �������������
		CONTACT             //������� �������������� �������  
	}    type;

	// ��������� �������������� �������
	enum ST {
		WORK,               //���� ����� ������� � ��������
		ABORT,              //������������� ������ ���������� ����������� 
		TIMEOUT,            //������������� ������ ���������� �� ������� 
		FINISH              //������������� ������ ����������  ��������� 
	}      sthread;

	// ��� �������� ���������� ����������
	SOCKET      s;         //����� ��� ������ ������� � ��������
	SOCKADDR_IN prms;      //���������  ������ 
	int         lprms;     //����� prms 


	HANDLE      hthread;   //���������� ������  EchoServer
	HANDLE      htimer;    //���������� ���������� �������, ������������ ���������� ����� ������ �������������� ��������

	bool        TimerOff;  //����� ������������ �������
	bool        CloseConn;  //����� ���������� ������������

	//���������������� ��������� � ������������� ���� �������������� �������.
	char msg[50];           //��������� 
	char srvname[15];       //��� �������������� ������ 

	HANDLE hAcceptServer;// Handle �������������� ������

	Contact(TE t = EMPTY, const char* namesrv = "") //����������� 
	{
		memset(&prms, 0, sizeof(SOCKADDR_IN));
		lprms = sizeof(SOCKADDR_IN); //������ ������
		type = t;
		strcpy_s(srvname, namesrv);
		msg[0] = 0;
		CloseConn = false;
		TimerOff = false;
	};

	void SetST(ST sth, const char* m = "") {
		sthread = sth;
		strcpy_s(msg, m);
	}
};
typedef list<Contact> ListContact;
ListContact Contacts; // ������ �����������  

#pragma endregion

//����������� ������� ��� ������������ �������
void CALLBACK ASWTimer(LPVOID Lprm, DWORD, DWORD) {

	char obuf[50] = "Close: timeout;";
	Contact* client = (Contact*)Lprm; //����������� ���������� ��������

	EnterCriticalSection(&scListContact); //������ � ����������� ������
	client->TimerOff = true; 	//������ ����� ������������ �������
	client->sthread = Contact::TIMEOUT;
	LeaveCriticalSection(&scListContact); 	//������� �� ����������� ������

	if ((send(client->s, obuf, sizeof(obuf) + 1, NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());

	SYSTEMTIME stt;
	// �������� ������� ����� � ����
	GetLocalTime(&stt);
	// ������� ���������
	printf("%d.%d.%d %d:%02d Timeout ", stt.wDay, stt.wMonth, stt.wYear, stt.wHour, stt.wMinute);
	cout << client->srvname << ";" << endl;
}


void CALLBACK Test(LPVOID Lprm, DWORD, DWORD) {

	char obuf[50] = "Close: Service unavailable;";
	Contact* client = (Contact*)Lprm; //����������� ���������� ��������

	EnterCriticalSection(&scListContact); //������ � ����������� ������
	client->TimerOff = true; 	//������ ����� ������������ �������
	client->sthread = Contact::FINISH;
	LeaveCriticalSection(&scListContact); 	//������� �� ����������� ������

	if ((send(client->s, obuf, sizeof(obuf) + 1, NULL)) == SOCKET_ERROR) throw  SetErrorMsgText("Send:", WSAGetLastError());

	SYSTEMTIME stt;
	// �������� ������� ����� � ����
	GetLocalTime(&stt);
	// ������� ���������
	printf("%d.%d.%d %d:%02d Service unavailable ", stt.wDay, stt.wMonth, stt.wYear, stt.wHour, stt.wMinute);
	cout << client->srvname << ";" << endl;
}

// ����������� ������� ������� �������������� ������
void CALLBACK ASStartMessage(DWORD Lprm) {
	Contact* client = (Contact*)Lprm;
	/*EnterCriticalSection(&scListContact);*/
	// ������ ����� ������������ �������
	char* sn = client->srvname;
	// �������� ����������� ������
	//LeaveCriticalSection(&scListContact);
	// ��������� �������
	SYSTEMTIME stt;
	// �������� ������� ����� � ����
	GetLocalTime(&stt);
	// ������� ���������
	printf("%d.%d.%d %d:%02d ", stt.wDay, stt.wMonth, stt.wYear, stt.wHour, stt.wMinute);
	std::cout << sn << " started;" << std::endl;
}
// ����������� ������� ���������� �������������� ������
void CALLBACK ASFinishMessage(DWORD Lprm) {
	Contact* client = (Contact*)Lprm;
	/*EnterCriticalSection(&scListContact);*/
	// ������ ����� ������������ �������
	char* sn = client->srvname;
	// �������� ����������� ������
	/*LeaveCriticalSection(&scListContact);*/
	// ��������� �������
	SYSTEMTIME stt;
	// �������� ������� ����� � ����
	GetLocalTime(&stt);
	// ������� ���������
	printf("%d.%d.%d %d:%02d ", stt.wDay, stt.wMonth, stt.wYear, stt.wHour, stt.wMinute);
	std::cout << sn << " stoped;" << std::endl;
}