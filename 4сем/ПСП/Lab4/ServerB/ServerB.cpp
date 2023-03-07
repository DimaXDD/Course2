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