// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window
#define DROW1 1
#define SURFACE1 2
#define LIGHT 3
#define DIFFUZE 4
#define ZERKALO 5

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
// ��������
	CMatrix VA,VB,VC,VD;	// ���������� ������ A,B,C,D ��������
	CMatrix PView;          // ���������� ����� ����������
	CRect RS,RW;            // ������� � ������� � ������� ����������� - int
	int IsData,Rezult,IsRotateX,IsRotateY,IsRotateZ;
	double fx,fy,fz,dfi,dT,f0;      // ��� �������� ������ ���� X, Y, Z
// �����������
	POINT **MasPOINT;
	int Nx,Ny;
	CRectD RD;
	pfunc2 pF;
//  �����
	double Radius;
	CMatrix PSourceLight;
	double Ks;
	COLORREF Color;
	int TypeModel;
					 
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
	afx_msg void OnDrowpyramidDrow1();
	afx_msg void OnDrowpyramidDrow2();
	afx_msg void OnDrowpyramidDrow3();
	afx_msg void OnDrowpyramidDrow4();
	afx_msg void OnRotatepyramidRotate();
	afx_msg void OnRotatepyramidRotate32778();
	afx_msg void OnRotatepyramidRotate32779();
	afx_msg void OnAnimatepyramidAnimatex();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnAnimatepyramidAnimatey();
	afx_msg void OnAnimatepyramidAnimatez();
	afx_msg void OnMyfuncMyfunc1();
	afx_msg void OnDestroy();
	afx_msg void OnMyfuncMyfunc2();
public:
  afx_msg void OnMyfuncMyfunc3();
public:
  afx_msg void OnLightSphere();
public:
  afx_msg void OnLightSpheres();
public:
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

