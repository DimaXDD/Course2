// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();
	//double dx,dy;	// ���� ��� ������ �������� f(x,y) �� x � y 
	double r,fi,q; // ����������� ���������� ����� ���������� � ���
	//CRectD SRect;	// ������� �������� ������� f(x,y) � ��� 
	//CRect  WRect;	// ������� � ���� ��� ���������
	CRect WRect;
	int Index;	// ��������� ��� OnPaint
	CPlot3D  Graph1,Graph2,Graph3;	// ���������� �������� ���� CPlot3D


// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCPlot3DDef();
	afx_msg void OnCplot3dFunc1();
	afx_msg void OnCplot3dFunc2();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

