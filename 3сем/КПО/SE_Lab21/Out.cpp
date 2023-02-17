#include "stdafx.h"

namespace Out
{

	OUT getout(wchar_t outfile[]) // Запись в структуру лог
	{
		OUT out;
		out.stream = new std::ofstream;
		out.stream->open(outfile);
		if (!out.stream->is_open())
		{
			throw ERROR_THROW(112);
		}
		wcscpy_s(out.outfile, outfile);
		return out;

	}// запись в структуру OUT

	void WriteIn(OUT out, In::IN in)
	{
		*out.stream << in.text;
	}

	void WriteError(OUT out, Error::ERROR error)
	{
		*out.stream << "Ошибка: " << error.id << ": " << error.message << " строка " << error.inext.line << ", позиция " << error.inext.col << std::endl;
	}

	void close(OUT out)
	{
		out.stream->close();
	}
}