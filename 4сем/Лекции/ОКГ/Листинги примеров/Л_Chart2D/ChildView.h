// ChildView.h : interface of the CChildView class
//


#pragma once

// CChildView window


class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	int Index;
	int N_Bezier;
	CMatrix X,Y;
	CRect RW;
	CRectD RS;
	CPlot2D Graph;
	CMyPen PenLine,PenAxis;

// Operations
public:
	double MyF1(double x);
	double MyF2(double x);
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
	afx_msg void OnTestsMmtext();
	afx_msg void OnTestsMmanis();
	afx_msg void OnTestsBezier();
	afx_msg void OnTestsMmanis0();
	afx_msg void OnTestsClear();
};

