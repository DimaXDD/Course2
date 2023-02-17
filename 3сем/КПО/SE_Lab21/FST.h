#pragma once
#include <cstddef>

namespace FST
{
	struct RELATION      // �����:������ -> ������� ����� ��������� ��
	{
		char symbol;        // ������ ��������
		short nnode;		// ����� ������� �������
		RELATION
		(
			char c = 0x00,		//������ ��������
			short ns = NULL		// ����� ���������
		);
	};

	struct NODE			// ������� ����� ���������
	{
		short n_relation;		//���������� ����������� �����
		RELATION* relations;	// ����������� �����
		NODE();
		NODE
		(
			short n,	// ���������� ������������ �����
			RELATION rel, ...		// ������ �����
		);
	};

	struct FST			// ������������������� �������� �������
	{
		char* string;		// �������(������� ��������� 0�00
		short position;		// ������� ������� � �������
		short nstates;		//���������� ��������� ��������
		NODE* nodes;		// ���� ���������: [0] - ��������� ���������, [nstate - 1] - ��������
		short* rstates;		// ��������� ��������� �������� �� ������ �������
		FST
		(
			char* s,		//������ (������� ����������� 0�00)
			short ns,		// ����������� ��������� ��������
			NODE n, ...		// ������ ��������� (���� ���������)
		);
		FST(char* str, short nst, NODE* nd, ...);
	};

	bool execute		//��������� ������������� �������
	(
		FST& fst		//������������������� �������� �������
	);

}
