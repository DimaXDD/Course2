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

//////////////////////////////////////////////////////////////////
	int IsData;		    // ���� ���������� ������ - 1,2,3,4... 
	int dT_Timer;			// �������� ������� ��� �������
	CRect RW;         // ������� � ����
	CRectD RS;				// ������� � ������� �����������
	CSunSystem SunSystem; // ������ (����������� �� ���������)
	
/////////////////////////////////////////////////////////////////

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
	afx_msg void OnLabplanetsPlanets();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
};

