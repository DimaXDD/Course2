#include "iostream"
#include "Winsock2.h"
#pragma comment(lib,"WS2_32.lib")
#pragma warning(disable:4996)


using namespace std;

SOCKET sS;

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

bool GetServerByName(char* name, char* call, sockaddr* from, int* len)
{
	hostent* host;
	host = gethostbyname(name); // получение хоста
	cout << inet_ntoa(*(in_addr*)host->h_addr_list[0]);
	SOCKADDR_IN sock;
	sock.sin_addr.s_addr = inet_addr(inet_ntoa((*(in_addr*)host->h_addr_list[0]))); // преобразование айпи
	sock.sin_family = AF_INET;
	sock.sin_port = htons(2000);
	from = (sockaddr*)&sock;
	int l = sizeof(sock);
	len = &l;
	int err = 0;
	char bfrom[50];
	try
	{
		if ((err = sendto(sS, call, strlen(call) + 1, NULL, from, *len)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("send to: ", WSAGetLastError());
		}

		if ((err = recvfrom(sS, bfrom, sizeof(bfrom), NULL, from, len)) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("recvfrom: ", WSAGetLastError());
		}
	}
	catch (const std::exception&)
	{

	}
	cout << name;
	return true;
}


void main()
{
	try
	{
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("wsastartup: ", WSAGetLastError());
		}
		if ((sS = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
		{
			throw SetErrorMsgText("socket create: ", WSAGetLastError());
		}
		SOCKADDR_IN sock;
		int len = sizeof(sock);
		char name[20] = "Svendell"; // DESKTOP-DDFE5SO (пишем сюда хост, к которому будем делать коннект)
		char call[20] = "Hello";
		if (!GetServerByName(name, call, (sockaddr*)&sock, &len))
		{
			throw SetErrorMsgText("socket create: ", WSAGetLastError());
		}

		if (closesocket(sS) == SOCKET_ERROR)
		{
			throw SetErrorMsgText("socket close: ", WSAGetLastError());
		}
		if (WSACleanup() == SOCKET_ERROR)
		{
			throw SetErrorMsgText("wsa clean up: ", WSAGetLastError());
		}

	}
	catch (const std::exception&)
	{

	}
}