#pragma once
#include "Winsock2.h"
#pragma comment(lib, "WS2_32.lib") 
#include <string>

using namespace std;

string  GetErrorMsgText(int code);
string  SetErrorMsgText(string msgText, int code);
string  SetPipeError(string msgText, int code);