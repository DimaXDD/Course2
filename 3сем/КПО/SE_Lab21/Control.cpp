#include "stdafx.h"

//int _tmain(int argc, _TCHAR* argv[])
//{
//	
//	setlocale(LC_ALL, "Rus");
//	Log::LOG log = Log::INITLOG;
//	Out::OUT out = Out::INITOUT;
//	Parm::PARM parm = Parm::getparm(argc, argv);
//	try
//	{
//		log = Log::getlog(parm.log);
//		Log::WriteLine(log, (char*)"Тест", (char*)" без ошибок \n", (char*)"");
//		Log::WriteLine(log, (wchar_t*)L"Тест", (wchar_t*)L" без ошибок \n", L"");
//		Log::WriteLog(log);
//		Log::WriteParm(log, parm);
//		In::IN in = In::getin(parm.in);
//		Log::WriteIn(log, in);
//		Log::Close(log);
//		out = Out::getout(parm.out);
//		Out::WriteIn(out, in);
//		LexAnalize::LexAnaliz(parm, in);
//		Out::close(out);
//	}
//	catch (Error::ERROR e) {
//		std::cout << "Ошибка: " << e.id << " : " << e.message << std::endl;
//		std::cout << "Строка: " << e.inext.line << "  Символ: " << e.inext.col << std::endl;
//		Log::WriteError(log, e);
//		Log::Close(log);
//		out = Out::getout(parm.out);
//		Out::WriteError(out,e);
//		Out::close(out);
//	};
//
//	system("pause");
//	return 0;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	Log::LOG log = Log::INITLOG;
	Out::OUT out = Out::INITOUT;
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);
	try
	{

		In::IN in = In::getin(parm.in);
		LexAnalize::LexAnaliz(parm, in);
	}
	catch (Error::ERROR e)
	{
		WriteError(log, e);
	};
	system("pause");
	return 0;
}

