#pragma once
#include "stdafx.h"

namespace LexAnalize
{
	struct table
	{
		LT::LexTable lextab;
		IT::IdTable idtab;
	};


	static struct Flags
	{
		bool function_flags = false;
		bool literal_flags = false;
		bool typedata_flags = false;
		bool ident_flags = false;
		bool static_fun_flags = false;
		bool declare_flags = false;
		bool brace_flags = false;
		bool thesis_flags = false;
		bool kavichka_flag = false;
	};
	void paste(int, char);
	char checktype(char[]);
	void LexAnaliz(Parm::PARM parm, In::IN in);
}