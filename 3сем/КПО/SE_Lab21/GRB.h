#pragma once
#include "Error.h"
typedef short GRBALPHABET;		///������� �������� ���������� ��������� > 0, ����������� < 0

namespace GRB
{
	//������� � ���������� �������
	struct Rule
	{
		///������. ������ ������� � ���� A->xxx|yyy|....
		GRBALPHABET nn;		///���������� (����� ������ �������) < 0
		int iderror;		///��� ������ � Error
		short size;			///���-�� ������� - ������ ������ �������


		//������������� ������� - ������ ������� �������
		struct Chain
		{
			short size;						///����� �������
			GRBALPHABET* nt;				///������� ���������� (>0) � ����������� (<0)
			Chain() {
				size = 0;
				nt = 0;
			};
			Chain(
				short psize,				///���-�� �������� � �������
				GRBALPHABET s, ...			///������� (�������� ��� ����������)
			);
			char* getCChain(char* b);		///�������� ������-������� � ���������� ���� ��� �����������

			//������, ������. ASCI-������� � GRBALPHABET-������� (� � �)
			static GRBALPHABET T(char t) {
				return GRBALPHABET(t);		///��������
			};
			static GRBALPHABET N(char n) {
				return -GRBALPHABET(n);		///����������
			};

			//������, ������. ���. �� GRBALPHABET-������ � ��� �
			static bool isT(GRBALPHABET s) {
				return s > 0;				///��������?
			};
			static bool isN(GRBALPHABET s) {
				return !isT(s);				///����������?
			}

			//�����, ������. �������� GRBALPHABET-������ � ASCI-������
			static char alphabet_to_char(GRBALPHABET s) {
				return isT(s) ? char(s) : char(-s); ///������ ������� - ������ ������ �������
			};
		}*chains;

		Rule() {				///�-��
			nn = 0x00;
			size = 0;
		}
		Rule(
			GRBALPHABET pnn,	///���������� (<0)
			int iderror,		///���� ��������� ����������� (Error)
			short psize,		///���-�� ������� - ������ ������ �������
			Chain c, ...		///��-�� ������� - ������ ������ �������
		);
		char* getCRule			///�������� ������� � ���� N->������� (��� ����������)
		(
			char* b,			///�����
			short nchain		///� ������� (������ �����) � �������
		);
		short getNextChain(	///�������� ����. �� j �������, ������� �� ����� ��� -1
			GRBALPHABET t,			///������ ������ �������
			Rule::Chain& pchain,	///������������ �������
			short j					///� �������
		);
	};


	struct Greibach				//���������� �������
	{
		short size;				///���-�� ������
		GRBALPHABET startN;		///��������� ������
		GRBALPHABET stbottomT;	///��� ����� (��������� ������� � ��)
		Rule* rules;			///��-�� ������
		Greibach() {		///�-� ��� �����
			short size = 0;
			startN = 0;
			stbottomT = 0;
			rules = 0;
		};
		Greibach(
			GRBALPHABET pstartN,	///��������� ������
			GRBALPHABET pstbottomT,	///��� �����
			short psize,			///���-�� ������
			Rule r, ...				///�������
		);
		short getRule(			///�������� � ������� ��� -1
			GRBALPHABET pnn,	///����� ������ �������
			Rule& prule			///������������ ������� ����������
		);
		Rule getRule(short n);	///�������� ������� �� ������
	};
	Greibach getGreibach();		///�������� ����������
};