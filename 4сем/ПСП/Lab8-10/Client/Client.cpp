#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include "iostream"
#include "Winsock2.h"                
#pragma comment(lib, "WS2_32.lib")   
#include <string>
#include <ctime>
#include "time.h"

using namespace std;

bool SystemMessage(char* ch) {

	bool result = false;
	try {

		char Timeout[50] = "Close: timeout;", Close[50] = "Close: finish;", Abort[50] = "Close: Abort;";
		if (strcmp(ch, Timeout) == 0) result = true;
		else if (strcmp(ch, Abort) == 0) result = true;
		else if (strcmp(ch, Close) == 0) result = true;
	}
	catch (...) {
		cout << "err" << endl;
	}

	return result;
}

string  GetErrorMsgText(int code) {
	string msgText;
	switch (code) {
	case WSAEINTR:                  msgText = "WSAEINTR";               break;    //������ ������� ��������
	case WSAEACCES:                 msgText = "WSAEACCES";              break;    //���������� ����������
	case WSAEFAULT:                 msgText = "WSAEFAULT";              break;    //��������� �����
	case WSAEINVAL:                 msgText = "WSAEINVAL";              break;    //������ � ���������
	case WSAEMFILE:                 msgText = "WSAEMFILE";              break;    //������� ����� ������ �������
	case WSAEWOULDBLOCK:            msgText = "WSAEWOULDBLOCK";         break;    //������ �������� ����������
	case WSAEINPROGRESS:            msgText = "WSAEINPROGRESS";         break;    //�������� � �������� ��������
	case WSAEALREADY:               msgText = "WSAEALREADY";            break;    //�������� ��� �����������
	case WSAENOTSOCK:               msgText = "WSAENOTSOCK";            break;    //����� ����� �����������
	case WSAEDESTADDRREQ:           msgText = "WSAEDESTADDRREQ";        break;    //��������� ����� ������������
	case WSAEMSGSIZE:               msgText = "WSAEMSGSIZE";            break;    //��������� ������� �������
	case WSAEPROTOTYPE:             msgText = "WSAEPROTOTYPE";          break;    //������������ ��� ��������� ��� ������
	case WSAENOPROTOOPT:            msgText = "WSAENOPROTOOPT";         break;    //������ � ����� ���������
	case WSAEPROTONOSUPPORT:        msgText = "WSAEPROTONOSUPPORT";     break;    //�������� �� ��������������
	case WSAESOCKTNOSUPPORT:        msgText = "WSAESOCKTNOSUPPORT";     break;    //��� ������ �� ��������������
	case WSAEOPNOTSUPP:             msgText = "WSAEOPNOTSUPP";          break;    //�������� �� ��������������
	case WSAEPFNOSUPPORT:           msgText = "WSAEPFNOSUPPORT";        break;    //��� ���������� �� ��������������
	case WSAEAFNOSUPPORT:           msgText = "WSAEAFNOSUPPORT";        break;    //��� ������� �� �������������� ����������
	case WSAEADDRINUSE:             msgText = "WSAEADDRINUSE";          break;    //����� ��� ������������
	case WSAEADDRNOTAVAIL:          msgText = "WSAEADDRNOTAVAIL";       break;    //����������� ����� �� ����� ���� �����������
	case WSAENETDOWN:               msgText = "WSAENETDOWN";            break;    //���� ���������
	case WSAENETUNREACH:            msgText = "WSAENETUNREACH";         break;    //���� �� ���������
	case WSAENETRESET:              msgText = "WSAENETRESET";           break;    //���� ��������� ����������
	case WSAECONNABORTED:           msgText = "WSAECONNABORTED";        break;    //����������� ����� �����
	case WSAECONNRESET:             msgText = "WSAECONNRESET";          break;    //����� �������������
	case WSAENOBUFS:                msgText = "WSAENOBUFS";             break;    //�� ������� ������ ��� �������
	case WSAEISCONN:                msgText = "WSAEISCONN";             break;    //����� ��� ���������
	case WSAENOTCONN:               msgText = "WSAENOTCONN";            break;    //����� �� ���������
	case WSAESHUTDOWN:              msgText = "WSAESHUTDOWN";           break;    //������ ��������� send: ����� �������� ������
	case WSAETIMEDOUT:              msgText = "WSAETIMEDOUT";           break;    //���������� ���������� ��������  �������
	case WSAECONNREFUSED:           msgText = "WSAECONNREFUSED";        break;    //���������� ���������
	case WSAEHOSTDOWN:              msgText = "WSAEHOSTDOWN";           break;    //���� � ����������������� ���������
	case WSAEHOSTUNREACH:           msgText = "WSAEHOSTUNREACH";        break;    //��� �������� ��� �����
	case WSAEPROCLIM:               msgText = "WSAEPROCLIM";            break;    //������� ����� ���������
	case WSASYSNOTREADY:            msgText = "WSASYSNOTREADY";         break;    //���� �� ��������
	case WSAVERNOTSUPPORTED:        msgText = "WSAVERNOTSUPPORTED";     break;    //������ ������ ����������
	case WSANOTINITIALISED:         msgText = "WSANOTINITIALISED";      break;    //�� ��������� ������������� WS2_32.DLL
	case WSAEDISCON:                msgText = "WSAEDISCON";             break;    //����������� ����������
	case WSATYPE_NOT_FOUND:         msgText = "WSATYPE_NOT_FOUND";      break;    //����� �� ������
	case WSAHOST_NOT_FOUND:         msgText = "WSAHOST_NOT_FOUND";      break;    //���� �� ������
	case WSATRY_AGAIN:              msgText = "WSATRY_AGAIN";           break;    //������������������ ���� �� ������
	case WSANO_RECOVERY:            msgText = "WSANO_RECOVERY";         break;    //��������������  ������
	case WSANO_DATA:                msgText = "WSANO_DATA";             break;    //��� ������ ������������ ����
	case WSA_INVALID_HANDLE:      msgText = "WSA_INVALID_HANDLE";     break;    //��������� ���������� �������  � �������
	case WSA_INVALID_PARAMETER:   msgText = "WSA_INVALID_PARAMETER";  break;    //���� ��� ����� ���������� � �������
	case WSA_IO_INCOMPLETE:       msgText = "WSA_IO_INCOMPLETE";      break;    //������ �����-������ �� � ���������� ���������
	case WSA_IO_PENDING:          msgText = "WSA_IO_PENDING";         break;    //�������� ���������� �����
	case WSA_NOT_ENOUGH_MEMORY:   msgText = "WSA_NOT_ENOUGH_MEMORY";  break;    //�� ���������� ������
	case WSA_OPERATION_ABORTED:   msgText = "WSA_OPERATION_ABORTED";  break;    //�������� ����������
	case WSASYSCALLFAILURE:         msgText = "WSASYSCALLFAILURE";      break;
	default:                msgText = "***ERROR***";      break;
	};
	return msgText;
}

string  SetErrorMsgText(string msgText, int code) {
	return  msgText + GetErrorMsgText(code);
}

string error = "Error";

string GetError() {
	return error;
}

bool GetServer(char* call, SOCKADDR_IN* from, int* flen, SOCKET* cC, SOCKADDR_IN* all) {
	char ibuf[50], obuf[50];
	int  libuf = 0, lobuf = 0;

	if ((lobuf = sendto(*cC, call, strlen(call) + 1, NULL, (sockaddr*)all, sizeof(*all))) == SOCKET_ERROR) throw  SetErrorMsgText("Sendto:", WSAGetLastError());
	if ((libuf = recvfrom(*cC, ibuf, sizeof(ibuf), NULL, (sockaddr*)from, flen)) == SOCKET_ERROR) {
		if (WSAGetLastError() == WSAETIMEDOUT) return false;
		else throw  SetErrorMsgText("Recv:", WSAGetLastError());
	}
	if (strcmp(call, ibuf) == 0) return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	int port = 0;
	SOCKET  SocketTCP;
	WSADATA wsaData;


	try {
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) throw SetErrorMsgText("Startup:", WSAGetLastError());
		if ((SocketTCP = socket(AF_INET, SOCK_STREAM, NULL)) == INVALID_SOCKET) throw  SetErrorMsgText("Socket:", WSAGetLastError());

		int ch = 0, cCall = 0;

		int max = 100, lobuf = 1, bport = 2000;
		char obuf[50] = "", ibuf[50] = "", Call[50], Name[50], call[50];

		SOCKADDR_IN Server = { 0 };
		Server.sin_family = AF_INET;
		Server.sin_port = htons(port);

		SOCKADDR_IN Server_IN;
		int Flen = sizeof(Server), connectionType = 0;
		cout << "1 - ����������� �� ����� �������" << endl << "2 - ����������� �� ���������" << endl;
		cin >> connectionType;
		if (connectionType == 1) {
			cout << "������� ��� �������: ";
			cin >> Name;
			hostent* s = gethostbyname(Name);
			if (s == NULL) throw "������ �� ������;";
			cout << "���� �������: ";
			cin >> port;
			Server_IN.sin_addr = *(struct in_addr*)s->h_addr_list[0];
		}
		else if (connectionType == 2) {
			cout << "������� �������� �������: ";
			cin >> call;

			SOCKET SocketUDP;
			int optval = 1;
			if ((SocketUDP = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET) throw SetErrorMsgText("Socket:", WSAGetLastError());
			if (setsockopt(SocketUDP, SOL_SOCKET, SO_BROADCAST,(char*)&optval, sizeof(int)) == SOCKET_ERROR) throw SetErrorMsgText("Opt:", WSAGetLastError());

			SOCKADDR_IN all;
			all.sin_family = AF_INET;
			all.sin_port = htons(bport);
			//all.sin_addr.s_addr = inet_addr("127.0.0.1"); //172.20.10.15
			//all.sin_addr.s_addr = inet_addr("172.20.10.15"); //172.20.10.15
			all.sin_addr.s_addr = inet_addr("127.0.0.1"); //172.20.10.15
			SOCKADDR_IN from;

			memset(&from, 0, sizeof(from));
			int lc = sizeof(from);

			bool bsr = GetServer(call, &from, &lc, &SocketUDP, &all);
			if (bsr == false) {
				throw "Server not found;";
			}
			else {
				Server_IN.sin_addr.s_addr = from.sin_addr.s_addr;
				if (closesocket(SocketUDP) == SOCKET_ERROR) throw SetErrorMsgText("Closesocket:", WSAGetLastError());
				cout << "���� �������: ";
				cin >> port;
			}
		}
		else {
			throw "Wrong code";
		}

		Server_IN.sin_family = AF_INET;
		Server_IN.sin_port = htons(port);

		if ((connect(SocketTCP, (sockaddr*)&Server_IN, sizeof(Server_IN))) == SOCKET_ERROR) throw "������ ����������;";

		printf_s("\n ---------- ---------- ---------- ---------- \n");
		cout << endl << "1 - Rand" << endl << "2 - Time" << endl << "3 - Echo" << endl;
		cin >> cCall;
		switch (cCall) {
		case 1:
			strcpy_s(Call, "Rand");
			break;
		case 2:
			strcpy_s(Call, "Time");
			break;
		case 3:
			strcpy_s(Call, "Echo");
			break;
		default:
			if (closesocket(SocketTCP) == SOCKET_ERROR) throw SetErrorMsgText("Closesocket:", WSAGetLastError()); throw "������ �������� ���;";
		}
		printf_s("\n ---------- ---------- ---------- ---------- \n");


		if ((lobuf = send(SocketTCP, Call, sizeof(Call), NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Send:", WSAGetLastError());
		char rCall[50];
		if ((lobuf = recv(SocketTCP, rCall, sizeof(rCall), NULL)) == SOCKET_ERROR) throw SetErrorMsgText("Recv:", WSAGetLastError());

		if (strcmp(Call, rCall) != 0) {
			throw "������ �� ��������";
		}
		else {
			u_long nonblk = 1;
			if (SOCKET_ERROR == ioctlsocket(SocketTCP, FIONBIO, &nonblk)) throw SetErrorMsgText("Ioctlsocket:", WSAGetLastError());
			clock_t StartTime = clock();
			bool rcv = true;

			char command[50];
			cin >> command;

			try {
				while (true) {
					if (rcv) {
						if ((lobuf = send(SocketTCP, command, sizeof(command), NULL)) == SOCKET_ERROR) {
							throw "Error send";
						}
						rcv = false;
					}

					if ((recv(SocketTCP, obuf, sizeof(obuf), NULL)) == SOCKET_ERROR) {
							switch (WSAGetLastError()) {
							case WSAEWOULDBLOCK: Sleep(100); break;
							default: throw  SetErrorMsgText("Recv:", WSAGetLastError());
						}
					}
					else {
						if (SystemMessage(obuf)) {
							printf("������ �������� ����������: %s\n", obuf);
							break;
						}
						else
							printf("���������� ���������:[%s]\n", obuf);		
						rcv = true;
					}
				}
			}
			catch (...) {
				cout << error << endl;
			}
			clock_t FinishTime = clock();
			printf("�����: %lf ���.\n", (double)(FinishTime - StartTime) / CLOCKS_PER_SEC);

		}
		if (closesocket(SocketTCP) == SOCKET_ERROR) throw SetErrorMsgText("Closesocket:", WSAGetLastError());
		if (WSACleanup() == SOCKET_ERROR) throw SetErrorMsgText("Cleanup:", WSAGetLastError());
	}
	catch (char* errorMsgText) {
		cout << errorMsgText << endl;
	}
	catch (...) {
		cout << error << endl;
	}

	system("pause");
	return 0;
}