// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Labs3D.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	VA.RedimMatrix(4);
	VB.RedimMatrix(4);
	VC.RedimMatrix(4);
	VD.RedimMatrix(4);
	//PView.RedimMatrix(4);
	PView.RedimMatrix(3);
	PSourceLight.RedimMatrix(3);
	//VA(3)=VB(3)=VC(3)=VD(3)=PView(3)=1;
	VA(3)=VB(3)=VC(3)=VD(3)=1;
	IsData=0;
	MasPOINT=NULL;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_DROWPYRAMID_DROW1, &CChildView::OnDrowpyramidDrow1)
	ON_COMMAND(ID_DROWPYRAMID_DROW2, &CChildView::OnDrowpyramidDrow2)
	ON_COMMAND(ID_DROWPYRAMID_DROW3, &CChildView::OnDrowpyramidDrow3)
	ON_COMMAND(ID_DROWPYRAMID_DROW4, &CChildView::OnDrowpyramidDrow4)
	ON_COMMAND(ID_ROTATEPYRAMID_ROTATE, &CChildView::OnRotatepyramidRotate)
	ON_COMMAND(ID_ROTATEPYRAMID_ROTATE32778, &CChildView::OnRotatepyramidRotate32778)
	ON_COMMAND(ID_ROTATEPYRAMID_ROTATE32779, &CChildView::OnRotatepyramidRotate32779)
	ON_COMMAND(ID_ANIMATEPYRAMID_ANIMATEX, &CChildView::OnAnimatepyramidAnimatex)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_ANIMATEPYRAMID_ANIMATEY, &CChildView::OnAnimatepyramidAnimatey)
	ON_COMMAND(ID_ANIMATEPYRAMID_ANIMATEZ, &CChildView::OnAnimatepyramidAnimatez)
	ON_COMMAND(ID_MYFUNC_MYFUNC1, &CChildView::OnMyfuncMyfunc1)
	ON_WM_DESTROY()
	ON_COMMAND(ID_MYFUNC_MYFUNC2, &CChildView::OnMyfuncMyfunc2)
	ON_COMMAND(ID_MYFUNC_MYFUNC3, &CChildView::OnMyfuncMyfunc3)
	ON_COMMAND(ID_LIGHT_SPHERE, &CChildView::OnLightSphere)
	ON_COMMAND(ID_LIGHT_SPHERES, &CChildView::OnLightSpheres)
	ON_WM_KEYDOWN()
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
	if(IsData==DROW1)
	{
		SetMyMode(dc,RS,RW);	      // Устанавливает режим отображения MM_ANISOTROPIC
		dc.Rectangle(RS);
		if(Rezult==IDYES) DrawPyramid(dc,VA,VB,VC,VD,PView);
		if(Rezult==IDNO) DrawPyramid1(dc,VA,VB,VC,VD,PView);
	}	
	if(IsData==SURFACE1)
	{
		dc.Rectangle(RW);
		double f=PView(1);
		double e=PView(2);
		char buf_f[10],buf_e[10];
		_gcvt(f,6,buf_f); 
		_gcvt(e,6,buf_e); 
		CString s1(buf_f),s2(buf_e);
		s1="f= "+s1+"   "+"e= "+s2;
		dc.TextOutA(RW.left+10,RW.top+5,s1);
		DrawSurface(dc,MasPOINT,Nx,Ny);
	}

	if(IsData==LIGHT)
	{
	  dc.Rectangle(RW);
	  DrawLightSphere(dc,Radius,PView,PSourceLight,RW,Color,TypeModel);				 		
	}
}


void CChildView::OnDrowpyramidDrow1()     //Drow1
{
	VA(0)=10;	VA(1)=0;  VA(2)=0;
	VB(0)=0;	VB(1)=0;  VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0;  VD(2)=20;
	PView(0)=10;	PView(1)=-20;	PView(2)=45;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);

	//Rezult=AfxMessageBox("Показывать невидимые грани?", MB_YESNO|MB_ICONQUESTION);		
	IsData=DROW1;
	InvalidateRect(NULL);
}

void CChildView::OnDrowpyramidDrow2()		//Drow2
{
	VA(0)=10;	VA(1)=0; VA(2)=0;
	VB(0)=0;	VB(1)=0; VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0; VD(2)=20;
	PView(0)=40;	PView(1)=0;	PView(2)=90;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);	
}

void CChildView::OnDrowpyramidDrow3()	//Drow3
{
	VA(0)=10;	VA(1)=0; VA(2)=0;
	VB(0)=0;	VB(1)=0; VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0; VD(2)=20;
	PView(0)=40;	PView(1)=90;	PView(2)=90;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);
}

void CChildView::OnDrowpyramidDrow4()	//Drow4
{
	VA(0)=10;	VA(1)=0; VA(2)=0;
	VB(0)=0;	VB(1)=0; VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0; VD(2)=20;
	PView(0)=40;	PView(1)=0;	PView(2)=0;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);
}

void CChildView::OnRotatepyramidRotate()   // Rotate_X
{
	if(IsData==0)
	{
		::AfxMessageBox("Пирамида не нарисована!");
		return;		
	}
	 Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
		fx=45;  // Градусы
		CMatrix MR=CreateRotate3DX(fx);
		VA=MR*VA;
		VB=MR*VB;
		VC=MR*VC;
		VD=MR*VD;
		IsData=DROW1;
		InvalidateRect(NULL);
}

void CChildView::OnRotatepyramidRotate32778()  // Rotate_Y
{	
	if(IsData==0)
	{
		::AfxMessageBox("Пирамида не нарисована!");
		return;	
	}
		Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
		fy=45;  // Градусы
		CMatrix MR=CreateRotate3DY(fy);
		VA=MR*VA;
		VB=MR*VB;
		VC=MR*VC;
		VD=MR*VD;
		IsData=DROW1;
		InvalidateRect(NULL);
}

void CChildView::OnRotatepyramidRotate32779() // Rotate_Z
{
	if(IsData==0)
	{
		::AfxMessageBox("Пирамида не нарисована!");
		return;
		
	}
		Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
		fz=45;  // Градусы
		CMatrix MR=CreateRotate3DZ(fz);
		VA=MR*VA;
		VB=MR*VB;
		VC=MR*VC;
		VD=MR*VD;
		IsData=DROW1;
		InvalidateRect(NULL);
}

void CChildView::OnAnimatepyramidAnimatex()	// AnimateX
{
	VA(0)=10;	VA(1)=0;  VA(2)=0;
	VB(0)=0;	VB(1)=0;  VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0;  VD(2)=20;
	PView(0)=10;	PView(1)=-20;	PView(2)=45;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	IsRotateX=1;
	IsRotateY=0;
	IsRotateZ=0;
	f0=0;
	dfi=0.02;
	dT=100;
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetTimer(1,dT,NULL);
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//KillTimer(1); 
	//CWnd::OnLButtonUp(nFlags, point);
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
		CMatrix MR(4,4);
		f0+=dfi;
		if(IsRotateX==1)MR=CreateRotate3DX(f0);
		if(IsRotateY==1)MR=CreateRotate3DY(f0);
		if(IsRotateZ==1)MR=CreateRotate3DZ(f0);	
		VA=MR*VA;
		VB=MR*VB;
		VC=MR*VC;
		VD=MR*VD;	
		IsData=DROW1;
		InvalidateRect(NULL);
	CWnd::OnTimer(nIDEvent);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	KillTimer(1); 
	CWnd::OnRButtonDown(nFlags, point);
}

void CChildView::OnAnimatepyramidAnimatey()		// AnimateY
{
	VA(0)=10;	VA(1)=0;  VA(2)=0;
	VB(0)=0;	VB(1)=0;  VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0;  VD(2)=20;
	PView(0)=10;	PView(1)=-20;	PView(2)=45;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	IsRotateX=0;
	IsRotateY=1;
	IsRotateZ=0;
	f0=0;
	dfi=0.02;
	dT=100;
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);	
}

void CChildView::OnAnimatepyramidAnimatez()		// AnimateZ
{
	VA(0)=10;	VA(1)=0;  VA(2)=0;
	VB(0)=0;	VB(1)=0;  VB(2)=0;
	VC(0)=0;	VC(1)=10; VC(2)=0;
	VD(0)=0;	VD(1)=0;  VD(2)=20;
	PView(0)=10;	PView(1)=-20;	PView(2)=45;
	RS.SetRect(-20,20,20,-20);
	RW.SetRect(50,50,450,450);
	IsRotateX=0;
	IsRotateY=0;
	IsRotateZ=1;
	f0=0;
	dfi=0.02;
	dT=100;
	Rezult=MessageBox("Показывать невидимые грани?",
			              "Выбор способа отображения",MB_ICONQUESTION|MB_YESNO);
	IsData=DROW1;
	InvalidateRect(NULL);
}

void CChildView::OnMyfuncMyfunc1()
{
	if(MasPOINT!=NULL)
	{
		for(int i=0;i<Nx;i++) delete MasPOINT[i];
		delete MasPOINT;
	}
	pF=MyFunction1;
	//RD.SetRectD(-5,5,5,-5);
	RD.SetRectD(5,0,15,-10);

	RW.SetRect(100,50,500,450);
	PView(0)=20;	PView(1)=300;	PView(2)=80;
	Nx=41;   Ny=41;
	MasPOINT=CreateSurfaceMatrix(pF,RD,Nx,Ny,RW,PView);
	IsData=SURFACE1;
	InvalidateRect(NULL);
}

void CChildView::OnDestroy()
{
	if(MasPOINT!=NULL)
	{
		for(int i=0;i<Nx;i++) delete MasPOINT[i];
		delete MasPOINT;
	}
	CWnd::OnDestroy();
}

void CChildView::OnMyfuncMyfunc2()
{
	if(MasPOINT!=NULL)
	{
		for(int i=0;i<Nx;i++) delete MasPOINT[i];
		delete MasPOINT;
	}
	pF=MyFunction2;
	RD.SetRectD(-20,20,20,-20);
	//RD.SetRectD(-20,20,20,0);
	RW.SetRect(100,50,500,450);
	PView(0)=30;	PView(1)=0;	PView(2)=90;
	Nx=81;   Ny=81;
	MasPOINT=CreateSurfaceMatrix(pF,RD,Nx,Ny,RW,PView);
	IsData=SURFACE1;
	InvalidateRect(NULL);
}

void CChildView::OnMyfuncMyfunc3()	// f(x,y)=(x-x0)^2-(y-y0)^2
{
  if(MasPOINT!=NULL)
	{
		for(int i=0;i<Nx;i++) delete MasPOINT[i];
		delete MasPOINT;
	}
	pF=MyFunction3;
	RD.SetRectD(-10,10,10,-10);
	RW.SetRect(100,50,500,450);
	PView(0)=30;	PView(1)=70;	PView(2)=50;
	Nx=41;   Ny=41;
	MasPOINT=CreateSurfaceMatrix(pF,RD,Nx,Ny,RW,PView);
	IsData=SURFACE1;
	InvalidateRect(NULL);
  }

void CChildView::OnLightSphere()  // Свет|Сфера - диффузионная модель отражения света
{
  RW.SetRect(100,50,300,250);					// Область в окне
  Radius=20;
  PView(0)=100;	PView(1)=0;  PView(2)=60;
  PSourceLight(0)=100;  PSourceLight(1)=0; PSourceLight(2)=0;
  Color=RGB(255,0,0);
  Ks=1.0;
  IsData=LIGHT;
  TypeModel=0;
  InvalidateRect(NULL);
}

void CChildView::OnLightSpheres()// Свет|Сфера - Зеркальная  модель отражения света
{
  RW.SetRect(100,50,300,250);					// Область в окне
  Radius=20;
  PView(0)=100;	PView(1)=0;  PView(2)=60;
  PSourceLight(0)=100;  PSourceLight(1)=0; PSourceLight(2)=0;
  Color=RGB(255,255,0);
  Ks=1.0;
  IsData=LIGHT;
  TypeModel=1;
  InvalidateRect(NULL);
 
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
  // TODO: Add your message handler code here and/or call default
  if(IsData==SURFACE1)
  {
	switch(nChar)
	{
	  case VK_UP:
		{
		  double d=PView(2)-10;
		  if(d>=0)PView(2)=d;
		  break;
		}
	  case VK_DOWN:
		{
		  double d=PView(2)+10;
		  if(d<=180)PView(2)=d;
		  break;
		}
	  case VK_LEFT:
		{
		  double d=PView(1)-10;
		  if(d>=-180)PView(1)=d;
		  else PView(1)=d+360;
		  break;
		}
	  case VK_RIGHT:
		{
		  double d=PView(1)+10;
		  if(d<=180)PView(1)=d;
		  else PView(1)=d-360;
		  break;
		}
	}
	MasPOINT=CreateSurfaceMatrix(pF,RD,Nx,Ny,RW,PView);
	InvalidateRect(NULL);
  }
  CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
