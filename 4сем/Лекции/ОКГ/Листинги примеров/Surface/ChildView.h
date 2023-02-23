// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();
	//double dx,dy;	// Шаги для расчет значений f(x,y) по x и y 
	double r,fi,q; // Сферические координаты точки наблюдения в МСК
	//CRectD SRect;	// Область изменеия функции f(x,y) в МСК 
	//CRect  WRect;	// Область в окне для рисования
	CRect WRect;
	int Index;	// Индикатор для OnPaint
	CPlot3D  Graph1,Graph2,Graph3;	// Объявление объектов типа CPlot3D


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

