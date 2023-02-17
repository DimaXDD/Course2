#include "Analize.h"
#include <stack>

void LexAnalize(
	In::IN in,
	LT::LexTable& lextable,
	IT::IdTable& idtable)
{
	string text = "";

	for (ushort i = 0; i < strlen((char*)in.text); i++)
	{
		text.push_back(in.text[i]);
	}
	ushort nLine = 1;

	vector<string> words;
	string word = "";
	bool isStrLit = false;

	for (ushort i = 0; i < in.size; i++)
	{
		if (!isStrLit)
		{
			if (!isStopSymb((char)in.text[i]))
			{
				word.push_back((char)in.text[i]);
			}
			else
			{
				if (word != "")
				{
					words.push_back(word);
					word = "";
				}
				if (
					(char)in.text[i] != ' ' &&
					(char)in.text[i] != '\t'
					)
				{
					word.push_back((char)in.text[i]);
					words.push_back(word);
					word = "";
				}

				if ((char)in.text[i] == '\'')
				{
					isStrLit = true;
				}
			}
		}
		else
		{
			if ((char)in.text[i] == '\'')
			{
				words.push_back(word);
				word = "";
				words.push_back("'");
				isStrLit = false;
			}
			else
			{
				word.push_back((char)in.text[i]);
			}
		}
	}

	searchLexsAndIdns(words, lextable, idtable, nLine);
}

bool isStopSymb(char symb)
{
	char stopSymbs[] = " ,;'(){}[]+-*/=\n\t";

	for (ushort i = 0; i < strlen(stopSymbs); i++)
	{
		if (symb == stopSymbs[i])
		{
			return true;
		}
	}

	return false;
}

void searchLexsAndIdns(
	vector<string>& words,
	LT::LexTable& lextable,
	IT::IdTable& idtable,
	ushort& nLine)
{
	// TODO: проверка на скобки
	// TODO: цепочки
	// TODO: более умные ошибки

	string word;
	stack<string> scope;
	
	scope.push("");
	
	LT::Entry lex;
	IT::Entry idn;
	char str[TI_MAXSIZE];

	/*for (auto i : words)
	{
		cout << i << "\n";
	}*/

	for (ushort i = 0; i < words.size(); i++)
	{
		word = words[i];

		if (word == "\n")
		{
			nLine++;
		}

		if (word == "function")
		{
			lex.lexema = LEX_FUNCTION;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "integer")
		{
			lex.lexema = LEX_INTEGER;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "string")
		{
			lex.lexema = LEX_STRING;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "declare")
		{
			lex.lexema = LEX_DECLARE;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "return")
		{
			lex.lexema = LEX_RETURN;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "print")
		{
			lex.lexema = LEX_PRINT;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "main")
		{
			lex.lexema = LEX_MAIN;
			lex.sn = nLine;
			lex.idxTI = -1;
			
			word = "";
			word.push_back(lex.lexema);
			
			scope.push("main");
			
			LT::Add(lextable, lex);
		}
		else if (word == ";")
		{
			lex.lexema = LEX_SEMICOLON;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == ",")
		{
			lex.lexema = LEX_COMMA;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "{")
		{
			lex.lexema = LEX_LEFTBRACE;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "}")
		{
			lex.lexema = LEX_RIGHTBRACE;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
			
			scope.pop();
		}
		else if (word == "(")
		{
			lex.lexema = LEX_LEFTHESIS;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == ")")
		{
			lex.lexema = LEX_RIGHTHESIS;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);

			if (
				(words[i - 3] == "(" ||
				words[i - 3] == ",") &&
				words[i+1] != "\n"
				)
			{
				scope.pop();
			}
		}
		else if (word == "+")
		{
		lex.lexema = 'v'; //LEX_PLUS;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "-")
		{
		lex.lexema = 'v';// LEX_MINUS;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "*")
		{
		lex.lexema = 'v';// LEX_STAR;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "/")
		{
		lex.lexema = 'v';// LEX_DIRSLASH;
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else if (word == "\n")
		{
			if (words[i - 1] != "\n")
			{
				lex.lexema = '\n';
				lex.sn = nLine;
				lex.idxTI = -1;

				word = "";
				word.push_back(lex.lexema);

				LT::Add(lextable, lex);
			}
		}
		else if (word == "=")
		{
			char* _id = new char[TI_MAXSIZE];
			to_pchar(scope.top() + words[i - 1], _id);

			ushort _index = IT::IsId(idtable, _id);

			if (_index == TI_NULLIDX || _index > 5000)
			{
				throw ERROR_THROW_IN(244, nLine, 0);
			}
			
			auto _idx = idtable.table[_index];

			lex.lexema = LEX_ID;
			lex.sn = nLine;
			lex.idxTI = idtable.size;

			LT::Add(lextable, lex);

			delete[] _id;

			lex.lexema = '=';
			lex.sn = nLine;
			lex.idxTI = -1;

			word = "";
			word.push_back(lex.lexema);

			LT::Add(lextable, lex);
		}
		else
		{
			to_pchar(word, str);
			strcpy_s(idn.id, str);

			if (
				words[i - 1] == "function" &&
				words[i - 2] == "integer")
			{
				scope.push(word);
				idn.iddatatype = IT::INT;
				idn.idtype = IT::F;
				idn.idxfirstLE = lextable.size;

				lex.idxTI = idtable.size;
				lex.lexema = LEX_ID;
				lex.sn = nLine;

				if (idn.iddatatype == IT::INT)
				{
					idn.value.vint = 0;
				}
				else
				{
					strcpy_s(idn.value.vstr->str, "");
				}

				LT::Add(lextable, lex);
				IT::Add(idtable, idn);
			}
			else if (
				words[i - 1] == "function" &&
				words[i - 2] == "string"
				)
			{
				scope.push(word);
				idn.iddatatype = IT::STR;
				idn.idtype = IT::F;
				idn.idxfirstLE = lextable.size;

				lex.idxTI = idtable.size;
				lex.lexema = LEX_ID;
				lex.sn = nLine;

				if (idn.iddatatype == IT::INT)
				{
					idn.value.vint = 0;
				}
				else
				{
					strcpy_s(idn.value.vstr->str, "");
				}

				LT::Add(lextable, lex);
				IT::Add(idtable, idn);
			}
			else if (
				(words[i - 1] == "string" || words[i - 1] == "integer")
				&&
				(words[i - 2] == "(" || words[i - 2] == ",")
				)
			{
				idn.iddatatype = (words[i - 1] == "string" ? IT::STR : IT::INT);
				idn.idtype = IT::P;
				idn.idxfirstLE = lextable.size;

				lex.idxTI = idtable.size;
				lex.lexema = LEX_ID;
				lex.sn = nLine;

				word = scope.top() + word;

				to_pchar(word, str);
				strcpy_s(idn.id, str);

				if (idn.iddatatype == IT::INT)
				{
					idn.value.vint = 0;
				}
				else
				{
					strcpy_s(idn.value.vstr->str, "");
				}

				LT::Add(lextable, lex);
				IT::Add(idtable, idn);
			}
			else if (
				words[i - 1] == "string" ||
				words[i - 1] == "integer")
			{
				idn.iddatatype = (words[i - 1] == "string" ? IT::STR : IT::INT);
				idn.idtype = IT::V;
				idn.idxfirstLE = lextable.size;

				word = scope.top() + word;
				to_pchar(word, str);
				strcpy_s(idn.id, str);

				if (words[i +1 ] != "=")
				{
					lex.idxTI = idtable.size;
					lex.lexema = LEX_ID;
					lex.sn = nLine;

					LT::Add(lextable, lex);
				}

				if (idn.iddatatype == IT::INT)
				{
					idn.value.vint = 0;
				}
				else
				{
					strcpy_s(idn.value.vstr->str, "");
				}

				IT::Add(idtable, idn);
			}
			else
			{
				bool _isNum = isProved(word);
				if (
					i - 1 >= 0 &&
					words[i - 1] == "=" &&
					((_isNum && words[i + 1] == ";") || (word == "'" && words[i + 3] == ";"))
					)
				{
					char* _id = new char[TI_STR_MAXSIZE];
					to_pchar(scope.top() + words[i - 2], _id);

					ushort _index = IT::IsId(idtable, _id);
					
					if (_index == TI_NULLIDX)
					{
						throw ERROR_THROW_IN(225, nLine, 0); // переделать
					}

					strcpy_s(idn.id, _id);

					idn.iddatatype = idtable.table[_index].iddatatype;
					idn.idtype = IT::V;
					idn.idxfirstLE = _index;

					lex.lexema = LEX_LITERAL;
					lex.sn = lextable.size;

					LT::Add(lextable, lex);

					if (isProved(word))
					{
						idn.value.vint = stoi(word);
						idtable.table[_index].value.vint = stoi(word);
					}
					else
					{
						to_pchar(words[i + 1], str);
						strcpy_s(idn.value.vstr->str, str);
						idn.value.vstr->len = strlen(str);

						strcpy_s(idtable.table[_index].value.vstr->str, str);
						idtable.table[_index].value.vstr->len = strlen(str);
						i += 2;
					}

					IT::Add(idtable, idn);
					delete[] _id;
				}
				else if (
					words[i + 1] == "(" &&
					regex_match(word.begin(), word.end(), regex(REG_WORD))
					)
				{
					to_pchar(word, str);
					int index = IT::IsId(idtable, str);
					if (
						word != "strlen" && 
						word != "substr" &&
						index > 30000
						)
					{
						
							throw ERROR_THROW_IN(225, nLine, 0); // переделать
					}
					auto _idn = IT::GetEntry(idtable, index);
					
					lex.lexema = LEX_FUNCTION;
					lex.sn = nLine;
					lex.idxTI = idtable.size;

					LT::Add(lextable, lex);
					
					strcpy_s(idn.id, str);
					idn.iddatatype = _idn.iddatatype;
					idn.idtype = IT::F;
					idn.idxfirstLE = index;
					
					IT::Add(idtable, idn);
					
					
					lex.lexema = LEX_ID;
					lex.sn = nLine;
					lex.idxTI = -1;

					LT::Add(lextable, lex);
				}
				else if (
					_isNum || 
					(word == "'" && words[i+2] == "'")
					)
				{
					strcpy_s(idn.id, "noname");
					
					idn.iddatatype = _isNum ? IT::INT : IT::STR;
					idn.idtype = IT::L;
					idn.idxfirstLE = nLine;
					
					if (_isNum)
					{
						idn.value.vint = stoi(word);
					}
					else
					{
						to_pchar(words[i + 1], str);
						strcpy_s(idn.value.vstr->str, str);
						idn.value.vstr->len = words[i + 1].size();

						i += 2;
					}

					lex.lexema = LEX_LITERAL;
					lex.sn = nLine;
					lex.idxTI = idtable.size;

					LT::Add(lextable, lex);
					IT::Add(idtable, idn);
				}
				else if (
					regex_match(word.begin(), word.end(), regex(REG_WORD)) &&
					words[i+1] != "="
					)
				{
					to_pchar(scope.top() + word, str);
					ushort _index = IT::IsId(idtable, str);

					if (_index != TI_NULLIDX)
					{
						auto _idn = idtable.table[_index];
						lex.lexema = LEX_ID;
						lex.sn = nLine;
						lex.idxTI = _index;

						strcpy_s(idn.id, str);
						idn.iddatatype = _idn.iddatatype;
						idn.idtype = _idn.idtype;
						idn.idxfirstLE = _index;

						if (idn.iddatatype == IT::INT)
						{
							idn.value.vint = 0;
						}
						else
						{
							strcpy_s(idn.value.vstr->str, "");
						}

						LT::Add(lextable, lex);
						IT::Add(idtable, idn);
					}
					else
					{
						throw ERROR_THROW_IN(223, nLine, 0); // переделать
					}
				}
			}
		}
	}
}

void to_pchar(string str, char* pchar)
{
	for (ushort i = 0; i < str.size(); i++)
	{
		pchar[i] = str[i];
	}
	pchar[str.size()] = '\0';
}

bool isProved(string num)
{
	if (num == "")
		return false;
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;

				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}
