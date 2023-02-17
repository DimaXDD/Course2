#include "stdafx.h"

using namespace std;

namespace Out {
	OUT getout(wchar_t outfile[]) {

		OUT out;
		out.stream = new std::ofstream;
		out.stream->open(outfile);
		if (!out.stream->is_open())
		{
			throw ERROR_THROW(112);
		}
		wcscpy_s(out.outfile, outfile);

		return out;
	}
	void WriteOut(In::IN in, wchar_t out[]) {
		ofstream fout(out);
		fout << in.text;
		fout.close();
	}
	void WriteError(OUT out, Error::ERROR error) {

		*out.stream << "--- Ошибки --- " << endl;
		*out.stream << "Ошибка " << error.id << ":" << error.message << endl;

		if (error.inext.line != -1)
		{
			*out.stream << "Строка " << error.inext.line << " Символ: " << error.inext.col << endl << endl;
		}
	}
	// закрывает поток
	void Close(OUT out) {
		out.stream->close();
		delete out.stream;
	}
}