#include "Check.h"
#include <map>
#include <array>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
using namespace fst;

namespace Check
{
	bool check(wchar_t* path)
	{

		// Проверка инициализации

		FST init(
			(char*)"dti=ivivfi(l,l,fi(i,i));",
			13,
			NODE(1, RELATION('d', 1)), // 0
			NODE(1, RELATION('t', 2)), // 1
			NODE(2, RELATION('i', 3), RELATION('i', 11)), // 2
			NODE(1, RELATION('=', 4)), // 3

			NODE(4, RELATION('(', 4), RELATION('i', 5), RELATION('l', 5), RELATION('f', 6)), // 4
			NODE(3, RELATION(')', 5), RELATION(';', 12), RELATION('v', 4)), // 5

			NODE(1, RELATION('i', 7)), // 6
			NODE(2, RELATION('(', 8), RELATION('(', 10)), // 7
			NODE(5, RELATION('i', 9), RELATION('f', 6), RELATION('l', 9), RELATION('i', 10), RELATION('l', 10)), // 8
			NODE(1, RELATION(',', 8)), // 9
			NODE(2, RELATION(')', 9), RELATION(')', 5)), // 10

			NODE(1, RELATION(';', 12)), // 11

			NODE() // 12
		);

		FST initFunc(
			(char*)"tfi(ti,ti,ti){dti;dti=ivfi(fi())vl;rl;};",
			26,
			NODE(1, RELATION('t', 1)), // 0
			NODE(1, RELATION('f', 2)), // 1
			NODE(1, RELATION('i', 3)), // 2
			NODE(2, RELATION('(', 4), RELATION('(', 7)), // 3
			NODE(1, RELATION('t', 5)), // 4
			NODE(2, RELATION('i', 6), RELATION('i', 7)), // 5
			NODE(1, RELATION(',', 4)), // 6
			NODE(1, RELATION(')', 8)), // 7

			//////////////////////////////////////////////
			NODE(1, RELATION('{', 9)), // 8
			NODE(4, RELATION('d', 10), RELATION('i', 12), RELATION('r', 21), RELATION('p', 13)), // 9
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(1, RELATION('t', 11)), // 10
			NODE(2, RELATION('i', 12), RELATION('f', 15)), // 11
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(2, RELATION(';', 9), RELATION('=', 13)), // 12
			NODE(4, RELATION('l', 14), RELATION('i', 14), RELATION('(', 13), RELATION('f', 15)), // 13
			NODE(3, RELATION(')', 14), RELATION(';', 9), RELATION('v', 13)), // 14
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(1, RELATION('i', 16)), // 15
			NODE(2, RELATION('(', 17), RELATION('(', 19)), // 16
			NODE(5, RELATION('i', 18), RELATION('l', 18), RELATION('f', 15), RELATION('i', 19), RELATION('l', 19)), // 17
			NODE(1, RELATION(',', 17)), // 18
			NODE(4, RELATION(')', 20), RELATION(')', 14), RELATION(')', 18), RELATION(')', 19)), // 19
			NODE(1, RELATION(';', 9)), // 20
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(2, RELATION('l', 22), RELATION('i', 22)), // 21
			NODE(1, RELATION(';', 23)), // 22
			NODE(1, RELATION('}', 24)), // 23
			NODE(1, RELATION(';', 25)), // 24
			NODE() // 25
			//////////////////////////////////////////////
		);

		FST _main(
			(char*)"m{dti;dti=l;dti;dti;dti;dti;i=l;i=l;i=l;i=l;i=fi(i,i);i=fi(i,i);pl;pi;pi;pfi(i);rl;};",
			19,
			NODE(1, RELATION('m', 1)), // 0

			//////////////////////////////////////////////
			NODE(1, RELATION('{', 2)), // 1
			NODE(4, RELATION('d', 3), RELATION('i', 5), RELATION('r', 14), RELATION('p', 6)), // 2
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(1, RELATION('t', 4)), // 3
			NODE(2, RELATION('i', 5), RELATION('f', 8)), // 4
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(2, RELATION(';', 2), RELATION('=', 6)), // 5
			NODE(4, RELATION('l', 7), RELATION('i', 7), RELATION('(', 6), RELATION('f', 8)), // 6
			NODE(3, RELATION(')', 7), RELATION(';', 2), RELATION('v', 6)), // 7
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(1, RELATION('i', 9)), // 8
			NODE(2, RELATION('(', 10), RELATION('(', 12)), // 9
			NODE(5, RELATION('i', 11), RELATION('l', 11), RELATION('f', 8), RELATION('i', 12), RELATION('l', 12)), // 10
			NODE(1, RELATION(',', 10)), // 11
			NODE(4, RELATION(')', 13), RELATION(')', 7), RELATION(')', 11), RELATION(')', 12)), // 12
			NODE(1, RELATION(';', 2)), // 13
			//////////////////////////////////////////////

			//////////////////////////////////////////////
			NODE(2, RELATION('l', 15), RELATION('i', 15)), // 14
			NODE(1, RELATION(';', 16)), // 15
			NODE(1, RELATION('}', 17)), // 16
			NODE(1, RELATION(';', 18)), // 17
			NODE() // 18
			//////////////////////////////////////////////
		);
		
		ifstream file(path);
		char* str = new char[255];
		char* str2 = new char[4022];

		while (!file.eof())
		{
			file.getline(str, 255);

			str += 3;
			
			switch (str[0])
			{
			case 'd':
				init.string = str;

				if (!execute(init))
				{
					return false;
				}

				break;
			case 't':
				strcpy_s(str2, str);

				while (str[0] != '}')
				{
					file.getline(str, 255);
					str += 3;
					
					strcat_s(str2, 255, str);

					if (file.eof() && str[0] != '}')
					{
						return false;
					}
				}
				initFunc.string = str2;
				
				if (!execute(initFunc))
				{
					return false;
				}
				
				break;
			case 'm':
				strcpy_s(str2, str);

				while (str[0] != '}')
				{
					file.getline(str, 255);
					str += 3;

					strcat_s(str2, 255, str);

					if (file.eof() && str[0] != '}')
					{
						return false;
					}
				}
				_main.string = str2;

				if (!execute(_main))
				{
					return false;
				}
				break;
			case '\n':
				break;
			}
		}
		
		delete[] str2;
		file.close();
		
		return true;
	}
}