#include "iostream"
#include "Winsock2.h"

#pragma comment(lib,"WS2_32.lib")
#pragma warning(disable:4996) 

using namespace std;

string GetErrorMsgText(int code)
{
	string msgText;
	switch (code)
	{
	case WSAEINTR: msgText = "Работа функции прервана"; break;
	case WSAEACCES:	msgText = "Разрешение отвергнуто"; break;
	case WSAEFAULT: msgText = "Ошибочный адрес"; break;
	case WSAEINVAL:	msgText = "Ошибка в аргументе";	break;
	case WSAEMFILE:	msgText = "Открыто слишком много файлов"; break;
	case WSAEWOULDBLOCK: msgText = "Ресурс временно недоступен"; break;
	case WSAEINPROGRESS: msgText = "Операция в процессе развития"; break;
	case WSAEALREADY: msgText = "Операция уже выполняется";	break;
	case WSAENOTSOCK: msgText = "Сокет задан неправильно"; break;
	case WSAEDESTADDRREQ: msgText = "Требуется адрес расположения"; break;
	case WSAEMSGSIZE: msgText = "Сообщение слишком длинное"; break;
	case WSAEPROTOTYPE: msgText = "Неправильный тип протокола для сокета"; break;
	case WSAENOPROTOOPT: msgText = "Ошибка в опции протокола"; break;
	case WSAEPROTONOSUPPORT: msgText = "Протокол не поддерживается"; break;
	case WSAESOCKTNOSUPPORT: msgText = "Тип сокета не поддерживается"; break;
	case WSAEOPNOTSUPP: msgText = "Операция не поддерживается"; break;
	case WSAEPFNOSUPPORT: msgText = "Тип протоколов не поддерживается"; break;
	case WSAEAFNOSUPPORT: msgText = "Тип адресов не поддерживается протоколом"; break;
	case WSAEADDRINUSE: msgText = "Адрес уже используется"; break;
	case WSAEADDRNOTAVAIL: msgText = "Запрошенный адрес не может быть использован"; break;
	case WSAENETDOWN: msgText = "Сеть отключена"; break;
	case WSAENETUNREACH: msgText = "Сеть не достижима"; break;
	case WSAENETRESET: msgText = "Сеть разорвала соединение"; break;
	case WSAECONNABORTED: msgText = "Программный отказ связи"; break;
	case WSAECONNRESET: msgText = "Связь не восстановлена"; break;
	case WSAENOBUFS: msgText = "Не хватает памяти для буферов"; break;
	case WSAEISCONN: msgText = "Сокет уже подключен"; break;
	case WSAENOTCONN: msgText = "Сокет не подключен"; break;
	case WSAESHUTDOWN: msgText = "Нельзя выполнить send: сокет завершил работу"; break;
	case WSAETIMEDOUT: msgText = "Закончился отведенный интервал времени"; break;
	case WSAECONNREFUSED: msgText = "Соединение отклонено"; break;
	case WSAEHOSTDOWN: msgText = "Хост в неработоспособном состоянии"; break;
	case WSAEHOSTUNREACH: msgText = "Нет маршрута для хоста"; break;
	case WSAEPROCLIM: msgText = "Слишком много процессов"; break;
	case WSASYSNOTREADY: msgText = "Сеть не доступна"; break;
	case WSAVERNOTSUPPORTED: msgText = "Данная версия недоступна"; break;
	case WSANOTINITIALISED: msgText = "Не выполнена инициализация WS2_32.dll"; break;
	case WSAEDISCON: msgText = "Выполняется отключение"; break;
	case WSATYPE_NOT_FOUND: msgText = "Класс не найден"; break;
	case WSAHOST_NOT_FOUND: msgText = "Хост не найден"; break;
	case WSATRY_AGAIN: msgText = "Неавторизованный хост не найден"; break;
	case WSANO_RECOVERY: msgText = "Неопределенная ошибка"; break;
	case WSANO_DATA: msgText = "Нет записи запрошенного типа"; break;
	case WSASYSCALLFAILURE: msgText = "Аварийное завершение системного вызова"; break;
	default: msgText = "Unknown error"; break;
	}
	return msgText;
}

string SetErrorMsgText(string msgText, int code)
{
	return msgText + GetErrorMsgText(code);
}


SOCKET sS;
SOCKET cS;


bool GetServer(char* call, short port, sockaddr* from, int* flen)
{
	SOCKADDR_IN all;
	all.sin_addr.s_addr = INADDR_BROADCAST;
	all.sin_family = AF_INET;
	all.sin_port = htons(2000);
	from = (sockaddr*)&all;
	int err = 0;

	if ((err = sendto(cS, call, strlen(call) + 1, NULL, from, *flen) == SOCKET_ERROR))
	{
		throw SetErrorMsgText("sendto:", WSAGetLastError());
	}

	if ((err = recvfrom(cS, call, sizeof(call), NULL, from, flen) == SOCKET_ERROR))
	{
		return false;
	}
	cout << call << endl;
	return true;

}
bool GetRequestFromClient(char* name, short port, sockaddr* from, int* flen)
{
	char bfrom[50];
	int err = 0;
	while (true)
	{

		if ((err = recvfrom(sS, bfrom, sizeof(bfrom), NULL, from, flen)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("rexevfrom: ", WSAGetLastError());
		}
		if (strcmp(name, bfrom) == 0)
		{
			return true;
		}
	}

}

bool PutAnswerToClient(char* name, sockaddr* to, int* lto)
{
	int err = 0;
	if ((err = sendto(sS, name, strlen(name) + 1, NULL, to, *lto)) == SOCKET_ERROR)
	{
		throw SetErrorMsgText("sendto: ", WSAGetLastError());
		return false;
	}
	return true;
}


void main()
{
	try
	{

		setlocale(LC_ALL, "rus");
		char name[10] = "Hello";
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
		{
			throw SetErrorMsgText("wsaSartUp: ", WSAGetLastError());
		}
		DWORD timeout = 10;

		if ((cS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
		{
			throw SetErrorMsgText("socket create: ", WSAGetLastError());
		}
		int optval = 1;
		if (setsockopt(cS, SOL_SOCKET, SO_BROADCAST, (char*)&timeout, sizeof(int)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("setsockopt: ", WSAGetLastError());
		}
		if (setsockopt(cS, SOL_SOCKET, SO_RCVTIMEO, (char*)&optval, sizeof(int)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("setsockopt: ", WSAGetLastError());
		}

		SOCKADDR_IN all;
		int allLen = sizeof(all);
		if (GetServer(name, 2000, (sockaddr*)&all, &allLen))
		{
			cout << "В сети есть несколько серверов с позывным " << name << endl;
			return;
		}
		else
		{
			cout << "В сети один сервер с позывным " << name << endl;
		}
		if (closesocket(cS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("close socket: ", WSAGetLastError());
		}

		if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
		{
			throw SetErrorMsgText("creaate socket: ", WSAGetLastError());
		}
		SOCKADDR_IN  serv;
		serv.sin_addr.s_addr = INADDR_ANY;
		serv.sin_family = AF_INET;
		serv.sin_port = htons(2000);

		if (bind(sS, (LPSOCKADDR)&serv, sizeof(serv)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("bind: ", WSAGetLastError());
		}



		SOCKADDR_IN  from;
		memset(&from, 0, sizeof(from));
		int lbfrom = sizeof(from);
		char hostName[20];
		int err = 0;
		hostent* addr;

		if ((err = gethostname(hostName, sizeof(hostName))) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("get host name: ", WSAGetLastError());
		}

		cout << "host name: " << hostName;
		while (true)
		{
			if (!GetRequestFromClient(name, 2000, (sockaddr*)&from, &lbfrom))
			{
				throw SetErrorMsgText("getRequestFromClient: ", WSAGetLastError());
			}

			std::cout << endl << "IP: " << inet_ntoa(from.sin_addr) << "\tport: " << htons(from.sin_port) << endl;
			lbfrom = sizeof(from);

			//addr = gethostbyaddr(inet_ntoa(from.sin_addr), sizeof(inet_ntoa(from.sin_addr)), AF_INET);
			//cout <<"workstation name: " << addr->h_name <<endl;
			//


			if (!PutAnswerToClient(name, (sockaddr*)&from, &lbfrom))
			{
				throw SetErrorMsgText("put answer: ", WSAGetLastError());
			}
		}


		if (closesocket(sS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("close socket: ", WSAGetLastError());
		}
		if (WSACleanup() == SOCKET_ERROR)
		{
			throw SetErrorMsgText("cleanup: ", WSAGetLastError());
		}
	}
	catch (string errorMsgText) {
		cout << endl << "WSAGetLastError: " << errorMsgText;
	}

}