#include <iostream>
#include <string>
#include "Winsock2.h"                // заголовок  WS2_32.dll

using namespace std;

#pragma comment(lib, "WS2_32.lib")   // экспорт  WS2_32.dll
#pragma warning(disable:4996)

using namespace std;

string GetErrorMsgText(int code)
{
	string msgText;
	switch (code)
	{
	case WSAEINTR:
		msgText = "Function interrupted";
		break;
	case WSAEACCES:
		msgText = "Permission denied";
		break;
	case WSAEFAULT:
		msgText = "Wrong address";
		break;
	case WSAEINVAL:
		msgText = "Wrong args";
		break;
	case WSAEMFILE:
		msgText = "Too many files have opened";
		break;
	case WSAEWOULDBLOCK:
		msgText = "Resource temporarily unavailable";
		break;
	case WSAEINPROGRESS:
		msgText = "Operation in progress";
		break;
	case WSAEALREADY:
		msgText = "Operation already in progress";
		break;
	case WSAENOTSOCK:
		msgText = "Wrong socket";
		break;
	case WSAEDESTADDRREQ:
		msgText = "Required adress location";
		break;
	case WSAEMSGSIZE:
		msgText = "Message is too long ";
		break;
	case WSAEPROTOTYPE:
		msgText = "Wrong protocol type to socket";
		break;
	case WSAENOPROTOOPT:
		msgText = "Error in protocol option";
		break;
	case WSAEPROTONOSUPPORT:
		msgText = "Protocol is not supported";
		break;
	case WSAESOCKTNOSUPPORT:
		msgText = "Socket type is not supported";
		break;
	case WSAEOPNOTSUPP:
		msgText = "Operation is not supported";
		break;
	case WSAEPFNOSUPPORT:
		msgText = "Protocol type is not supported";
		break;
	case WSAEAFNOSUPPORT:
		msgText = "Addresses type is not supported by protocol";
		break;
	case WSAEADDRINUSE:
		msgText = "Address is already used";
		break;
	case WSAEADDRNOTAVAIL:
		msgText = "Requested address cannot be used";
		break;
	case WSAENETDOWN:
		msgText = "Network disconnected";
		break;
	case WSAENETUNREACH:
		msgText = "Network is unttainable";
		break;
	case WSAENETRESET:
		msgText = "Network dropped the connection";
		break;
	case WSAECONNABORTED:
		msgText = "Connection aborted";
		break;
	case WSAECONNRESET:
		msgText = "Connection restored";
		break;
	case WSAENOBUFS:
		msgText = "Not enough memory for buffers";
		break;
	case WSAEISCONN:
		msgText = "Socket has already connected";
		break;
	case WSAENOTCONN:
		msgText = "Socket has not connected";
		break;
	case WSAESHUTDOWN:
		msgText = "Send cannot be performed: socket was shutdowned";
		break;
	case WSAETIMEDOUT:
		msgText = "Alloted time interval has ended";
		break;
	case WSAECONNREFUSED:
		msgText = "Connection was rejected";
		break;
	case WSAEHOSTDOWN:
		msgText = "Host was shotdowned";
		break;
	case WSAEHOSTUNREACH:
		msgText = "Has not way for host";
		break;
	case WSAEPROCLIM:
		msgText = "Too many processes";
		break;
	case WSASYSNOTREADY:
		msgText = "Network is unavailable";
		break;
	case WSAVERNOTSUPPORTED:
		msgText = "Version is not supported";
		break;
	case WSANOTINITIALISED:
		msgText = "WS2_32.dll is not initialised";
		break;
	case WSAEDISCON:
		msgText = "Connection in progress";
		break;
	case WSATYPE_NOT_FOUND:
		msgText = "Type is not found";
		break;
	case WSAHOST_NOT_FOUND:
		msgText = "Host is not found";
		break;
	case WSATRY_AGAIN:
		msgText = "Try again";
		break;
	case WSANO_RECOVERY:
		msgText = "Unknown error";
		break;
	case WSANO_DATA:
		msgText = "Has not data type";
		break;
	case WSA_INVALID_HANDLE:
		msgText = "Invalid handle";
		break;
	case WSA_INVALID_PARAMETER:
		msgText = "Invalid one or many parameters";
		break;
	case WSA_IO_INCOMPLETE:
		msgText = "IO object is incomplete";
		break;
	case WSA_IO_PENDING:
		msgText = "Operation will end later";
		break;
	case WSA_NOT_ENOUGH_MEMORY:
		msgText = "Not enough memory";
		break;
	case WSA_OPERATION_ABORTED:
		msgText = "Operation was aborted";
		break;
	case WSAEINVALIDPROCTABLE:
		msgText = "Invalid provider";
		break;
	case WSAEINVALIDPROVIDER:
		msgText = "Error in provider version";
		break;
	case WSAEPROVIDERFAILEDINIT:
		msgText = "Failed provider initialization";
		break;
	case WSASYSCALLFAILURE:
		msgText = "Abnormal termination of a system call";
		break;
	default:
		msgText = "Unknown error";
		break;
	}
	return msgText;
}

string SetErrorMsgText(string msgText, int code)
{
	return msgText + GetErrorMsgText(code);
}

int main()
{
	SOCKET  cC;
	WSADATA wsaData;
	try
	{
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
			throw  SetErrorMsgText("Startup:", WSAGetLastError());


		if ((cC = socket(AF_INET, SOCK_STREAM, NULL)) == INVALID_SOCKET)
			throw  SetErrorMsgText("Socket:", WSAGetLastError());

		SOCKADDR_IN serv;								// параметры  сокета sS
		serv.sin_family = AF_INET;						// используется IP-адресация  
		serv.sin_port = htons(2000);					// порт 2000
		serv.sin_addr.s_addr = inet_addr("192.168.0.106");  // адрес сервера
		// serv.sin_addr.s_addr = inet_addr("192.168.43.99");  // адрес сервера


		if ((connect(cC, (sockaddr*)&serv, sizeof(serv))) == SOCKET_ERROR)
			throw  SetErrorMsgText("Connect:", WSAGetLastError());


		char ibuf[50],                      //буфер ввода 
			obuf[50];                       //буфер вывода
		int  libuf = 0,                     //количество принятых байт
			lobuf = 0,                      //количество отправленных байт
			count = 0;                      //количество иттераций

		cout << "Enter a number of itterations: ", cin >> count;

		char num[10],
			in[50];
		int t = clock();
		do
		{
			char out[50] = "Hello from Client ";
			_itoa(count, num, 10);
			strcat(out, num);
			if ((lobuf = send(cC, out, strlen(out) + 1, NULL)) == SOCKET_ERROR)
				throw  SetErrorMsgText("send:", WSAGetLastError());

			if ((libuf = recv(cC, in, sizeof(in), NULL)) == SOCKET_ERROR)
				throw  SetErrorMsgText("recv:", WSAGetLastError());


		} while (--count);

		cout << "Ticks: " << clock() - t << endl;
		string t55;
		cin >> t55;

		if ((lobuf = send(cC, "", 1, NULL)) == SOCKET_ERROR)
			throw  SetErrorMsgText("Send:", WSAGetLastError());


		if (closesocket(cC) == SOCKET_ERROR)
			throw  SetErrorMsgText("Closesocket:", WSAGetLastError());

		if (WSACleanup() == SOCKET_ERROR)
			throw  SetErrorMsgText("Cleanup:", WSAGetLastError());

	}
	catch (string errorMsgText)
	{
		cout << endl << errorMsgText;
	}
	return 0;
}