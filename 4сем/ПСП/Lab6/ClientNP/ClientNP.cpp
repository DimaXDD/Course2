#include <iostream>
#include <Winsock2.h>
#include <string>
#include <Windows.h>

#pragma comment (lib, "WS2_32.lib")
#pragma warning(disable:4996)

// Локальный формат имени канала
#define PIPE_NAME L"\\\\.\\pipe\\Tube"	// где: точка (.) - обозначает локальный компьютер;
										// pipe - фиксированное слово;
										// xxxxx - имя канала

// Сетевой формат имени канала
#define PIPE_NAME_LAN L"\\\\SERVER\\pipe\\Tube"
#define STOP "STOP"

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
	case 2: msgText = "Неудачное завершение"; break;
	case ERROR_INVALID_PARAMETER: msgText = "Значение параметра pimax превосходит величину  PIPE_UNLMITED_INSTANCES"; break;
	case ERROR_NO_DATA: msgText = "The pipe is being closed"; break;
	case ERROR_PIPE_CONNECTED: msgText = "There is a process on other end of the pipe"; break;
	case ERROR_PIPE_LISTENING: msgText = "Waiting for a process to open the other end of the pipe"; break;
	case ERROR_CALL_NOT_IMPLEMENTED: msgText = "This function is not supported on this system"; break;
	default: msgText = "**ERROR**"; break;
	}

	return msgText;
}

string SetPipeError(string msgText, int code)
{
	return msgText + GetErrorMsgText(code) + "\n\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HANDLE cH; // дескриптор канала
	DWORD lp;
	char buf[50];

	try
	{
		// 1 блок
		// для передачи в локальной сети: на сервере оставьте такой же локальный PIPE_NAME, 
		// а на клиента замените на его PIPE_NAME_LAN и введите в него имя своего серверного компа
		if ((cH = CreateFile(
			PIPE_NAME, // Имя канала
			GENERIC_READ | GENERIC_WRITE, // Чтение и запись
			0, // Совместное чтение и запись
			NULL, // аттрибуты безопасности
			OPEN_EXISTING, //  открытие существующего канала
			NULL, // флаги и атрибуты
			NULL)) == INVALID_HANDLE_VALUE) // доп флаги
		{
			throw SetPipeError("CreateFile: ", GetLastError());
		}

		int countOfMessages;
		cout << "Введите кол-во сообщений: ";
		cin >> countOfMessages;

		for (int i = 1; i < countOfMessages; ++i)
		{
			string obuf = "Hello from ClientNP " + to_string(i);
			
			// 2 блок
			if (!WriteFile(cH, obuf.c_str(), sizeof(obuf), &lp, NULL))
			{
				throw SetPipeError("WriteFile: ", GetLastError());
			}

			// 3 блок
			if (!ReadFile(cH, buf, sizeof(buf), &lp, NULL))
			{
				throw SetPipeError("ReadFile: ", GetLastError());
			}

			cout << "[OK] Sent message: " << buf << endl;
		}

		if (!WriteFile(cH, STOP, sizeof(STOP), &lp, NULL))
		{
			throw SetPipeError("WriteFile: ", GetLastError());
		}

		// 4 блок
		if (!CloseHandle(cH))
		{
			throw SetPipeError("Close: ", GetLastError());
		}
	}
	catch (string ErrorPipeText)
	{
		cout << "\nError in ClientNP " << ErrorPipeText;
	}
}