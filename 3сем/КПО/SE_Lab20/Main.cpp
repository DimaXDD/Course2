#include "stdafx.h"
#include "Analize.h"
#include <array>
#include <map>
using namespace fst;

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	Log::LOG log = Log::INITLOG; // инициализация лога
	Parm::PARM parm; // инициализация параметров

	log = Log::getlog();

	
		parm = Parm::getparm(argc, argv); // получение параметро
		Log::Close(log);

		log = Log::getlog(parm.log); // получение лога
		In::IN in = In::getin(parm.in); // получение входных данных

		LT::LexTable lextable = LT::Create(in.size); // создание таблицы лексем
		IT::IdTable idtable = IT::Create(in.size); // создание таблицы идентификаторов
		IT::Entry func;
		
		strcpy_s(func.id, "substr");
		func.iddatatype = IT::STR;
		func.idxfirstLE = LT_TI_NULLIDX;
		func.idtype = IT::F;
		
		IT::Add(idtable, func);
		
		strcpy_s(func.id, "strlen");	
		func.iddatatype = IT::INT;
		IT::Add(idtable, func);

		LexAnalize(in, lextable, idtable); // лексический анализ
		char* lexs = new char[lextable.size];
		
		for (ushort i = 0; i < lextable.size; i++)
		{
			lexs[i] = lextable.table[i].lexema;
		}
		lexs[lextable.size] = '\0';

		Log::WriteLog(log); // запись в лог
		Log::WriteParm(log, parm); // запись процесса проверки параметров
		Log::WriteIn(log, in); // запись процесса обработки входных данных
		Log::Close(log); // закрытие лога

		Out::OUT out(parm.out);
		out.Write(lexs);
		
		cout << Check::check(parm.out);
		
		// вывод таблицы лексем


		
		//cout << "Таблица лексем:" << endl;
		//
		//for (ushort i = 0; i < lextable.size; i++)
		//{
		//	cout << "lexema: " << lextable.table[i].lexema << "\t\t\t";
		//	cout << "sn: " << lextable.table[i].sn << "\t\t\t";
		//	cout << "idxTI: " << lextable.table[i].idxTI << "\t\t\t";
		//	cout << endl;
		//}
		//
		//// вывод таблицы идентификаторов
		//
		//cout << "\n\nТаблица идентификаторов:" << endl;
		//
		//for (ushort i = 0; i < idtable.size; i++)
		//{
		//	cout << "id: " << idtable.table[i].id << "\t\t\t";
		//	cout << "iddatatype: " << idtable.table[i].iddatatype << "\t\t\t";
		//	cout << "idxfirstLE: " << idtable.table[i].idxfirstLE << "\t\t\t";
		//	cout << "idtype: " << idtable.table[i].idtype << "\t\t\t";
		//	
		//	if (idtable.table[i].iddatatype == IT::INT)
		//	{
		//		cout << "value: " << idtable.table[i].value.vint << "\t\t\t";
		//	}
		//	else
		//	{
		//		cout << "value: " << idtable.table[i].value.vstr->str << "\t\t\t";
		//	}
		//	
		//	cout << endl;
		//}
	
		//std::cout << "Ошибка: " << e.id << " : " << e.message << std::endl; // вывод ошибки
		//if (e.inext.line != -1)
		//{
		//	std::cout << "Строка: " << e.inext.line << "  Символ: " << e.inext.col << std::endl;
		//}
		//Log::WriteError(log, e); // запись ошибки в лог
		//Log::Close(log); // закрытие лога
	
	return 0;
}