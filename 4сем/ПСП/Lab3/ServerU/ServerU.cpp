#include <iostream>
#include <string>
#include "Winsock2.h"                // заголовок  WS2_32.dll

using namespace std;

#pragma comment(lib, "WS2_32.lib")   // экспорт  WS2_32.dll
#pragma warning(disable:4996)

using namespace std;

string  GetErrorMsgText(int code)    // cформировать текст ошибки 
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
};

string SetErrorMsgText(string msgText, int code)
{
	return msgText + GetErrorMsgText(code);
}

int main()
{
	SOCKET  sS;
	WSADATA wsaData;
	try
	{
		// 1.
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			throw  SetErrorMsgText("Startup:", WSAGetLastError());

		// 2.
		if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
			throw  SetErrorMsgText("socket:", WSAGetLastError());

		SOCKADDR_IN serv;
		serv.sin_family = AF_INET;
		serv.sin_port = htons(2000);
		serv.sin_addr.s_addr = inet_addr("127.0.0.1"); // указываем сюда айпи сервера

		if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
			throw  SetErrorMsgText("bind:", WSAGetLastError());

		// 3.
		SOCKADDR_IN clnt;
		clnt.sin_family = AF_INET;
		clnt.sin_port = htons(2000);
		clnt.sin_addr.s_addr = inet_addr("127.0.0.1"); // указываем сюда айпи клиента
		memset(&clnt, 0, sizeof(clnt));
		int lc = sizeof(clnt);
		char ibuf[50];
		int  lb = 0;

		// =======================  TASK 7  =======================
		int i = 0;
		while (true)
		{
			int lcInt = sizeof(clnt);
			int time = clock();
			while (true)
			{
				if (lb = recvfrom(sS, ibuf, sizeof(ibuf), NULL, (sockaddr*)&clnt, &lc) == SOCKET_ERROR)
					break;

				cout << ibuf << " " << i << "\n";
				i++;

				if (!strcmp(ibuf, "CLOSE"))
					break;
				if ((lb = sendto(sS, ibuf, strlen(ibuf) + 1, NULL, (sockaddr*)&clnt, sizeof(clnt))) == SOCKET_ERROR)
					break;
			}
			i = 0;
			cout << "\nProgram was running for " << time << " ticks or " << ((float)time) / CLOCKS_PER_SEC << " seconds.\n\n";
		}

		// 5.
		if (closesocket(sS) == SOCKET_ERROR)
			throw  SetErrorMsgText("closesocket:", WSAGetLastError());
		if (WSACleanup() == SOCKET_ERROR)
			throw SetErrorMsgText("Cleanup:", WSAGetLastError());
	}
	catch (string errorMsgText)
	{
		cout << endl << "WSAGetLastError: " << errorMsgText;
	}
	return 0;
}