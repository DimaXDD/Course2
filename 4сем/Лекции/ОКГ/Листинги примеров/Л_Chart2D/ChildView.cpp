// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Chart2D.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	Index = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_TESTS_MMTEXT, &CChildView::OnTestsMmtext)
	ON_COMMAND(ID_TESTS_MMANIS, &CChildView::OnTestsMmanis)
	ON_COMMAND(ID_TESTS_BEZIER, &CChildView::OnTestsBezier)
	ON_COMMAND(ID_TESTS_MMANIS0, &CChildView::OnTestsMmanis0)
	ON_COMMAND(ID_TESTS_CLEAR, &CChildView::OnTestsClear)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if (Index==1)
	{
		Graph.Draw(dc,1,1);
	}

	if (Index==2)
	{
		Graph.GetRS(RS);		 
		SetMyMode(dc,RS,RW);	      // Устанавливает режим отображения MM_ANISOTROPIC 
		Graph.Draw1(dc,1,1);
		dc.SetMapMode(MM_TEXT);			 // Устанавливает режим отображения MM_TEXT
	}
	if (Index==3)
	{
// Одна линия		
	PenLine.Set(PS_SOLID,0,RGB(0,0,0));	
	Graph.SetPenLine(PenLine);
	Graph.Draw(dc,1,1);
// Вторая линия линия		
	PenLine.Set(PS_SOLID,2,RGB(255,0,0));	
	Graph.SetPenLine(PenLine);
	Graph.DrawBezier(dc,N_Bezier);
	}




	
	// Do not call CWnd::OnPaint() for painting messages
}


////////////////////////////////////////////////////////////
double CChildView::MyF1(double x)
{
	double y=x*sin(x);	
	return y;
}

double CChildView::MyF2(double x)
{
	double y=x*x;	
	return y;
}



////////////////////////////////////////////////////////////




void CChildView::OnTestsMmtext()	// MM_TEXT
{
/*	
	double dx=0.01;
	double xL=-0.1;
	double xH=-xL;
*/
	
	double dx=pi/36;
	double xL=-4*pi;
	double xH=-xL;
	int N=(xH-xL)/dx;
	X.RedimMatrix(N+1);
	Y.RedimMatrix(N+1);
	for(int i=0;i<=N;i++)
	{
		X(i)=xL+i*dx;
		Y(i)=MyF1(X(i));
		//Y(i)=MyF2(X(i));
	}
	PenLine.Set(PS_SOLID,2,RGB(255,0,0));
	PenAxis.Set(PS_SOLID,2,RGB(0,0,255));
	RW.SetRect(100,50,500,450);	
	Graph.SetParams(X,Y,RW);
	Graph.SetPenLine(PenLine);
	Graph.SetPenAxis(PenAxis);
	Index=1;
	this->Invalidate();	
	
}

void CChildView::OnTestsMmanis()	// MM_ANISOTROPIC
{

	
	double xL=-10;
	double xH=-xL;
	//double xH =0;
	double dx=1;
	//double dx=0.1;	//Ломаная!!!
	int N=(xH-xL)/dx;
	X.RedimMatrix(N+1);
	Y.RedimMatrix(N+1);
	for(int i=0;i<=N;i++)
	{
		X(i)=xL+i*dx;
		Y(i)=MyF2(X(i));
	}
	PenLine.Set(PS_SOLID,2,RGB(0,0,255)); //Рисует толстую линию
	PenAxis.Set(PS_SOLID,0,RGB(255,0,0));
	RW.SetRect(100,50,500,450);	
	Graph.SetParams(X,Y,RW);
	Graph.SetPenLine(PenLine);
	Graph.SetPenAxis(PenAxis);
	Index=2;
	this->Invalidate();	
}

void CChildView::OnTestsBezier()	// BEZIER
{	
	double dt=pi/4;
	int N=9;
	X.RedimMatrix(N);
	Y.RedimMatrix(N);
	//*
	for(int i=0;i<N;i++)
	{	
		X(i)=i*dt;
		Y(i)=sin(i*dt);
	}
	//*/


	/*
	X(0)=0;		X(1)=1;		X(2)=2;		X(3)=3;
	Y(0)=0;		Y(1)=1;		Y(2)=1;		Y(3)=0;

	X(4)=4;		X(5)=5;		X(6)=6;		
	Y(4)=-1;	Y(5)=-1;	Y(6)=0;		
*/

	N_Bezier=50;
	RW.SetRect(100,50,500,350);	
	Graph.SetParams(X,Y,RW);	
	Index=3;
	this->Invalidate();	
	


}


void CChildView::OnTestsMmanis0()
{
	// TODO: добавьте свой код обработчика команд
	
	double xL = -10;
	double xH = -xL;
	double dx = 1;
	int N = (xH - xL) / dx;
	X.RedimMatrix(N + 1);
	Y.RedimMatrix(N + 1);
	for (int i = 0; i <= N; i++)
	{
		X(i) = xL + i*dx;
		Y(i) = MyF2(X(i));
	}
	PenLine.Set(PS_SOLID, 0, RGB(0, 0, 255)); //Толщина линии = 0
	PenAxis.Set(PS_SOLID, 0, RGB(255, 0, 0));
	RW.SetRect(100, 50, 500, 450);
	Graph.SetParams(X, Y, RW);
	Graph.SetPenLine(PenLine);
	Graph.SetPenAxis(PenAxis);
	Index = 2;
	this->Invalidate();

}


void CChildView::OnTestsClear()
{
	// TODO: добавьте свой код обработчика команд
	Index = 0;
	this->Invalidate();
}
