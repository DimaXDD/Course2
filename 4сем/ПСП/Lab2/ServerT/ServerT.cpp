#include <iostream>
#include <string>
#include "Winsock2.h"                // заголовок  WS2_32.dll

using namespace std;

#pragma comment(lib, "WS2_32.lib")   // экспорт  WS2_32.dll
#pragma warning(disable:4996)

using namespace std;string  GetErrorMsgText(int code)    // cформировать текст ошибки 
{
	string msgText;
	switch (code)                      // проверка кода возврата  
	{
		case WSAEINTR: msgText = "WSAEINTR"; break;
		case WSAEACCES: msgText = "WSAEACCES"; break;
		case WSAEFAULT: msgText = "WSAEFAULT"; break;
		case WSAEINVAL: msgText = "WSAEINVAL"; break;
		case WSAEMFILE: msgText = "WSAEMFILE"; break;
		case WSAEWOULDBLOCK:msgText = "WSAEWOULDBLOCK"; break;
		case WSAEINPROGRESS:msgText = "WSAEINPROGRESS"; break;
		case WSAENOTSOCK:msgText = "WSAENOCTSOCK"; break;
		case WSAEDESTADDRREQ:msgText = "WSAEDESTADDRREQ"; break;
		case WSAEMSGSIZE:msgText = "WSAEMSGSIZE"; break;
		case WSAEPROTOTYPE:msgText = "WSAEPROTOTYPE"; break;
		case WSAENOPROTOOPT:msgText = "WSAENOPROTOOPT"; break;
		case WSAEPROTONOSUPPORT:msgText = "WSAEPROTONOSUPPORT"; break;
		case WSAESOCKTNOSUPPORT:msgText = "WSAESOCKTNOSUPPORT"; break;
		case WSAEOPNOTSUPP:msgText = "WSAEOPNOTSUPP"; break;
		case WSAEPFNOSUPPORT:msgText = "WSAEPFNOSUPPORT"; break;
		case WSAEAFNOSUPPORT:msgText = "WSAEAFNOSUPPORT"; break;
		case WSAEADDRINUSE:msgText = "WSAEADDRINUSE"; break;
		case WSAEADDRNOTAVAIL:msgText = "WSAEADDRNOTAVAIL"; break;
		case WSAENETDOWN:msgText = "WSAENETDOWN"; break;
		case WSAENETUNREACH:msgText = "WSAENETUNREACH"; break;
		case WSAENETRESET:msgText = "WSAENETRESET"; break;
		case WSAECONNABORTED:msgText = "WSAECONNABORTED"; break;
		case WSAECONNRESET:msgText = "WSAECONNRESET"; break;
		case WSAENOBUFS:msgText = "WSAENOBUFS"; break;
		case WSAEISCONN:msgText = "WSAEISCONN"; break;
		case WSAENOTCONN:msgText = "WSAENOTCONN"; break;
		case WSAESHUTDOWN:msgText = "WSAESHUTDOWN"; break;
		case WSAETIMEDOUT:msgText = "WSAETIMEDOUT"; break;
		case WSAECONNREFUSED:msgText = "WSAECONNREFUSED"; break;
		case WSAEHOSTDOWN:msgText = "WSAEHOSTDOWN"; break;
		case WSAEHOSTUNREACH:msgText = "WSAEHOSTUNREACH"; break;
		case WSAEPROCLIM:msgText = "WSAEPROCLIM"; break;
		case WSASYSNOTREADY:msgText = "WSASYSNOTREADY"; break;
		case WSAVERNOTSUPPORTED:msgText = "WSAVERNOTSUPPORTED"; break;
		case WSANOTINITIALISED:msgText = "WSANOTINITIALISED"; break;
		case WSAEDISCON:msgText = "WSAEDISCON"; break;
		case WSATYPE_NOT_FOUND:msgText = "WSATYPE_NOT_FOUND"; break;
		case WSAHOST_NOT_FOUND:msgText = "WSAHOST_NOT_FOUND"; break;
		case WSATRY_AGAIN:msgText = "WSATRY_AGAIN"; break;
		case WSANO_RECOVERY:msgText = "WSANO_RECOVERY"; break;
		case WSANO_DATA:msgText = "WSANO_DATA"; break;
		case WSA_INVALID_HANDLE:msgText = "WSA_INVALID_HANDLE"; break;
		case WSA_INVALID_PARAMETER:msgText = "WSA_INVALID_PARAMETER"; break;
		case WSA_IO_INCOMPLETE:msgText = "WSA_IO_INCOMPLETE"; break;
		case WSA_IO_PENDING:msgText = "WSA_IO_PENDING"; break;
		case WSA_NOT_ENOUGH_MEMORY:msgText = "WSA_NOT_ENOUGH_MEMORY"; break;
		case WSA_OPERATION_ABORTED:msgText = "WSA_OPERATION_ABORTED"; break;
		case WSAEINVALIDPROCTABLE:msgText = "WSAEINVALIDPROCTABLE"; break;
		case WSAEINVALIDPROVIDER:msgText = "WSAEINVALIDPROVIDER"; break;
		case WSAEPROVIDERFAILEDINIT:msgText = "WSAEPROVIDERFAILEDINIT"; break;
		case WSASYSCALLFAILURE:msgText = "WSASYSCALLFAILURE"; break;
		default: msgText = "***ERROR***"; break;
	};
	return msgText;
};string SetErrorMsgText(string msgText, int code)
{
	return msgText + GetErrorMsgText(code);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	

	SOCKET sS; // дескриптор сокета
	WSADATA wsaData;

	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			throw  SetErrorMsgText("Startup:", WSAGetLastError());

		if ((sS = socket(AF_INET, SOCK_STREAM, NULL)) == INVALID_SOCKET)
			throw  SetErrorMsgText("Socket:", WSAGetLastError());

		int i = 0;
		WSADATA ws;
		SOCKET s;
		SOCKET c;
		char ibuf[50];
		char obuf[50] = "Hello from Client";
		int t;

		if (FAILED(WSAStartup(MAKEWORD(1, 1), &ws)))
			cout << "socket:" << WSAGetLastError() << endl;
		if (INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM, 0)))
			cout << "socket:" << WSAGetLastError() << endl;

		sockaddr_in c_adr;
		sockaddr_in s_adr;
		{
			s_adr.sin_port = htons(2000);
			s_adr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
			s_adr.sin_family = AF_INET;
		}

		if (SOCKET_ERROR == (bind(s, (LPSOCKADDR)&s_adr, sizeof(s_adr))))
			cout << "bind:" << WSAGetLastError() << endl;

		if (SOCKET_ERROR == listen(s, 2))
			cout << "listen:" << WSAGetLastError << endl;


		while (true)
		{
			int lcInt = sizeof(c_adr);
			if (INVALID_SOCKET == (c = accept(s, (sockaddr*)&c_adr, &lcInt)))
				cout << "accept:" << WSAGetLastError() << endl;

			cout << "Client connected." << endl;
			cout << "Client IP:    " << inet_ntoa(c_adr.sin_addr) << endl;
			cout << "Client port:  " << htons(c_adr.sin_port) << "\n\n";

			int time = clock();
			while (true)
			{
				if (SOCKET_ERROR == recv(c, ibuf, sizeof(ibuf), NULL))
					break;

				cout << ibuf << " " << i << "\n";
				i++;

				if (!strcmp(ibuf, "CLOSE")) { break; }

				if (SOCKET_ERROR == send(c, obuf, strlen(obuf) + 1, NULL))
					break;
			}
			i = 0;
			cout << "Client Disconected.\n";
			cout << "Program was running for " << time << " ticks or " << ((float)time) / CLOCKS_PER_SEC << " seconds.\n\n";
		}

		if (closesocket(c) == SOCKET_ERROR)
			throw SetErrorMsgText("closesocket:", WSAGetLastError());

		if (WSACleanup() == SOCKET_ERROR)
			throw SetErrorMsgText("Cleanup:", WSAGetLastError());
	}
	catch (string errorMsgText)
	{
		cout << endl << "WSAGetLastError: " << errorMsgText;
	}
	return 0;
}