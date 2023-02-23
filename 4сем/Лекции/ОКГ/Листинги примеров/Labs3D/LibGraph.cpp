#include "stdafx.h"

CRectD::CRectD(double l,double t,double r,double b)
{
  left=l; 
  top=t; 
  right=r; 
  bottom=b; 
}
//------------------------------------------------------------------------------
void CRectD::SetRectD(double l,double t,double r,double b)
{
  left=l; 
  top=t; 
  right=r; 
  bottom=b; 
}

//------------------------------------------------------------------------------
CSizeD CRectD::SizeD()
{
  CSizeD cz;
  cz.cx=fabs(right-left);	// ������ ������������� �������
  cz.cy=fabs(top-bottom);	// ������ ������������� �������
  return cz;
}

//------------------------------------------------------------------------------

CMatrix SpaceToWindow(CRectD& RS,CRect& RW)	// �����!!!!!
// ������� ���������
// ���������� ������� ��������� ��������� �� ������� � �������
// RS - ������� � ������� ����������� - double
// RW - ������� � ������� ����������� - int
{
	CMatrix M(3,3);
  CSize sz = RW.Size();	 // ������ ������� � ����
  int dwx=sz.cx;	     // ������
  int dwy=sz.cy;	     // ������
  CSizeD szd=RS.SizeD(); // ������ ������� � ������� �����������

  double dsx=szd.cx;    // ������ � ������� �����������
  double dsy=szd.cy;    // ������ � ������� �����������
  
  double kx=(double)dwx/dsx;   // ������� �� x
  double ky=(double)dwy/dsy;   // ������� �� y
		

	M(0,0)=kx;  M(0,1)=0;    M(0,2)=(double)RW.left-kx*RS.left;			// ���������
  M(1,0)=0;   M(1,1)=-ky;  M(1,2)=(double)RW.bottom+ky*RS.bottom;		// ���������
  M(2,0)=0;   M(2,1)=0;    M(2,2)=1;
	return M;
 }



//--------------------------------------------------------------------------------
void DrawPlot(CDC& dc,CRectD& rs,CRect& rw,CMatrix& X,CMatrix& Y)
// ������ ������ � ������ MM_TEXT - ����������� �������� ���������
// dc - ������ �� ����� CDC MFC
// rs - ������������� ������� � ������� �����������
// rw - ������������� ������� � ������� �����������
// X - ������ ������ - ��������
// Y - ������ ������ - �������, Yi=f(Xi) 
{
	int b1=(X.cols()==1)&&(Y.cols()==1);
	int b2=(X.rows()==Y.rows());
	int bb=b1&&b2;
	if(!bb)
	{
		char* error="DrawPlot: ������������ ������� �������� ������";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}
  char ss[100];
  char sY[]="Y", sX[]="X";

	CMatrix V(3),W(3);
	V(2)=1; 
	CMatrix pM=SpaceToWindow(rs,rw);				// ������� ��������� � ������� ���������� -pM
	dc.Rectangle(rw);					   // ����� � ����
  if(rs.left*rs.right<0)									// ��� Y
  {
		V(0)=0-rs.left;
		V(1)=rs.top-rs.bottom;
		W=pM*V;	
		dc.MoveTo((int)W(0),(int)W(1));				// (0,Ymax)

		V(0)=0-rs.left;
		V(1)=rs.bottom-rs.bottom;
		W=pM*V;
		dc.LineTo((int)W(0),(int)W(1));			 // (0,Ymax) - (0,Ymin) -- ��� Y
  }

  if(rs.top*rs.bottom<0)									// ��� X
  {
		V(0)=rs.left-rs.left;
		V(1)=0-rs.bottom;
		W=pM*V;
		dc.MoveTo((int)W(0),(int)W(1));				// (0,Xmin)
		V(0)=rs.right-rs.left;
		V(1)=0-rs.bottom;
		W=pM*V;
		dc.LineTo((int)W(0),(int)W(1));				// (0,Xmin) - (0,Xmax) -- ��� X
  }

  V(0)=X(0)-rs.left;
  V(1)=Y(0)-rs.bottom;
	W=pM*V;
  dc.MoveTo((int)W(0),(int)W(1));        // ��������� ����� ��� ��������� �������
	for(int i=1;i<X.rows();i++)
  {
		V(0)=X(i)-rs.left;
		V(1)=Y(i)-rs.bottom;
		W=pM*V;																// �����  � ������� �����������
		dc.LineTo((int)W(0),(int)W(1));
  }
	//----- ��� ����� ������� ��� ������� ��������� ������� ----------------- 
	 dc.TextOutA(rw.left-15,rw.top,sY,strlen(sY)); 
   dc.TextOutA(rw.left-15,rw.top,sY,strlen(sY)); 
	 dc.TextOutA(rw.right+10,rw.bottom-15,sX,strlen(sX)); 
	 sprintf(ss,"Xmin=%g,    Xmax=%g",rs.left,rs.right);
	 dc.TextOutA(rw.left,rw.bottom+5,ss,strlen(ss)); 
	 sprintf(ss,"Ymin=%g,    Ymax=%g",rs.bottom,rs.top);
	 dc.TextOutA(rw.left,rw.bottom+25,ss,strlen(ss)); 
}

//-----------------------------------------------------------------------

void DrawPlot1(CDC& dc,CRect& IRS,CMatrix& X,CMatrix& Y)
// ������ ������ � ������ MM_ANISOTROPIC - ��� ������������ ��������� ���������
// � ������� ������ ������� ����� � ��������� ������ ������ ���� �����������
// dc - ������ �� ����� CDC MFC
// IRS - ������������� ������� � ������� ����������� - int
// X - ������ ������ - ��������
// Y - ������ ������ - �������, Yi=f(Xi) 
{
	int b1=(X.cols()==1)&&(Y.cols()==1);
	int b2=(X.rows()==Y.rows());
	int bb=b1&&b2;
	if(!bb)
	{
		char* error="DrawPlot: ������������ ������� �������� ������";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}
  dc.Rectangle(IRS);
  
  if((IRS.left<=0)&&(IRS.right>=0))	  	// ��� Y
  {
	dc.MoveTo(0,IRS.top);	                // (0,Ymax)
	dc.LineTo(0,IRS.bottom);              // (0,Ymax) - (0,Ymin) -- ��� Y
  }

   if((IRS.top>=0)&&(IRS.bottom<=0))		// ��� X
  {
	dc.MoveTo(IRS.left,0);		           // (0,Xmin)
	dc.LineTo(IRS.right,0);		           // (0,Xmin) - (0,Xmax) -- ��� X
  }
  dc.MoveTo((int)X(0),(int)Y(0));
  for(int i=1;i<X.rows();i++)	dc.LineTo((int)X(i),(int)Y(i));
}

//------------------------------------------------------------------------------

void SetMyMode(CDC& dc,CRect& RS,CRect& RW)  //MFC
// ������������� ����� ����������� MM_ANISOTROPIC � ��� ���������
// dc - ������ �� ����� CDC MFC
// RS -  ������� � ������� ����������� - int
// RW -	 ������� � ������� ����������� - int  
{
  int dsx=RS.right-RS.left;
  int dsy=RS.top-RS.bottom;
  int xsL=RS.left;
  int ysL=RS.bottom;

  int dwx=RW.right-RW.left;
  int dwy=RW.bottom-RW.top;
  int xwL=RW.left;
  int ywH=RW.bottom;

  dc.SetMapMode(MM_ANISOTROPIC);
  dc.SetWindowExt(dsx,dsy);
  dc.SetViewportExt(dwx,-dwy);
  dc.SetWindowOrg(xsL,ysL);
  dc.SetViewportOrg(xwL,ywH);
}
//------------------------------------------------------------------------------------
CMatrix CreateTranslate2D(double dx, double dy)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X � �� dy �� ��� Y � ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� -dx ��� X � �� -dy �� ��� Y ��� ������������� ��������� ������� 
{
 CMatrix TM(3,3);
 TM(0,0)=1; TM(0,2)=dx;
 TM(1,1)=1;  TM(1,2)=dy;
 TM(2,2)=1;
 return TM;
}

//-------------------------------------------------------------------------------------
CMatrix CreateTranslate3D(double dx, double dy,double dz)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� 
// �� dx �� ��� X, �� dy �� ��� Y,�� dz �� ��� Z � ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� -dx ��� X,�� -dy �� ��� Y, �� -dz �� ��� Z 
// ��� ������������� ��������� ������� 
{
 CMatrix TM(4,4);
 for(int i=0;i<4;i++) TM(i,i)=1;
 TM(0,3)=dx;
 TM(1,3)=dy;
 TM(2,3)=dz;
 return TM;
}



//------------------------------------------------------------------------------------
CMatrix CreateRotate2D(double fi)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� ��������
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
{
 double fg=fmod(fi,360.0);
 double ff=(fg/180.0)*pi; // ������� � �������
 CMatrix RM(3,3);
 RM(0,0)=cos(ff); RM(0,1)=-sin(ff);
 RM(1,0)=sin(ff);  RM(1,1)=cos(ff);
 RM(2,2)=1;
 return RM;
}
//--------------------------------------------------------------------------------

CMatrix CreateRotate3DZ(double fi)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� Z
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� Z �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
{
 double fg=fmod(fi,360.0);
 double ff=(fg/180.0)*pi; // ������� � �������
 CMatrix RM(4,4);
 RM(0,0)=cos(ff); RM(0,1)=-sin(ff);
 RM(1,0)=sin(ff);  RM(1,1)=cos(ff);
 RM(2,2)=1; 
 RM(3,3)=1;
 return RM;
}
//--------------------------------------------------------------------------------
CMatrix CreateRotate3DX(double fi)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� X
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� X �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
{
 double fg=fmod(fi,360.0);
 double ff=(fg/180.0)*pi; // ������� � �������
 CMatrix RM(4,4);
 RM(0,0)=1;
 RM(1,1)=cos(ff); RM(1,2)=-sin(ff); 
 RM(2,1)=sin(ff); RM(2,2)=cos(ff);
 RM(3,3)=1;
 return RM;
}
//--------------------------------------------------------------------------------
CMatrix CreateRotate3DY(double fi)
// ��������� ������� ��� �������������� ��������� ������� ��� ��� �������� ������ ��� Y
// �� ���� fi (��� fi>0 ������ ������� �������)� ������������� ������� ���������
// --- ��� ---
// ��������� ������� ��� �������������� ��������� ������� ��� �������� ������
// ������� ��������� ������ ��� Y �� ���� -fi ��� ������������� ��������� ������� 
// fi - ���� � ��������
{
 double fg=fmod(fi,360.0);
 double ff=(fg/180.0)*pi; // ������� � �������
 CMatrix RM(4,4);
 RM(0,0)=cos(ff); RM(0,2)=sin(ff);
 RM(1,1)=1;
 RM(2,0)=-sin(ff); RM(2,2)=cos(ff); 
 RM(3,3)=1; 
 return RM;
}

//--------------------------------------------------------------------------------
CMatrix VectorMult(CMatrix& V1,CMatrix& V2)
// ��������� ��������� ������������ �������� V1 � V2
{
	
	int b1=(V1.cols()==1)&&(V1.rows()==3);
	int b2=(V2.cols()==1)&&(V2.rows()==3);
	int b=b1&&b2;
	if(!b)
	{
		char* error="VectorMult: ������������ ����������� ��������! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	CMatrix W(3);
	W(0)=V1(1)*V2(2)-V1(2)*V2(1);
	//double x=W(0);
	W(1)=-(V1(0)*V2(2)-V1(2)*V2(0));
	//double y=W(1);
	W(2)=V1(0)*V2(1)-V1(1)*V2(0);
	//double z=W(2);
	return W;
}

//-------------------------------------------------------------------------------
double ScalarMult(CMatrix& V1,CMatrix& V2)
// ��������� ��������� ������������ �������� V1 � V2
{
	
	int b1=(V1.cols()==1)&&(V1.rows()==3);
	int b2=(V2.cols()==1)&&(V2.rows()==3);
	int b=b1&&b2;
	if(!b)
	{
		char* error="ScalarMult: ������������ ����������� ��������! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	double p=V1(0)*V2(0)+V1(1)*V2(1)+V1(2)*V2(2);
	return p;
}
//-------------------------------------------------------------------------
double ModVec(CMatrix& V)
// ��������� ������ ������� V
{
	int b=(V.cols()==1)&&(V.rows()==3);
	if(!b)
	{
		char* error="ModVec: ����������fz ����������� �������! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	double q=sqrt(V(0)*V(0)+V(1)*V(1)+V(2)*V(2));
	return q;
}
//-------------------------------------------------------------------------
double CosV1V2(CMatrix& V1,CMatrix& V2)
// ��������� ������� ���� ����� ��������� V1 � V2
{
	double modV1=ModVec(V1);
	double modV2=ModVec(V2);
	int b=(modV1<1e-7)||(modV2<1e-7);
	if(b)
	{
		char* error="CosV1V2: ������ ������ ��� ����� �������� < 1e-7!";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	int b1=(V1.cols()==1)&&(V1.rows()==3);
	int b2=(V2.cols()==1)&&(V2.rows()==3);
	b=b1&&b2;
	if(!b)
	{
		char* error="CosV1V2: ������������ ����������� ��������! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	double cos_f=ScalarMult(V1,V2)/(modV1*modV2);
	return cos_f;
}


//-------------------------------------------------------------------------
double AngleV1V2(CMatrix& V1,CMatrix& V2)
// ��������� ���� ����� ��������� V1 � V2 � ��������
{
	double modV1=ModVec(V1);
	double modV2=ModVec(V2);
	int b=(modV1<1e-7)||(modV2<1e-7);
	if(!b)
	{
		char* error="AngleV1V2: ������ ������ ��� ����� �������� < 1e-7!";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	int b1=(V1.cols()==1)&&(V1.rows()==3);
	int b2=(V2.cols()==1)&&(V2.rows()==3);
	b=b1&&b2;
	if(!b)
	{
		char* error="AngleV1V2: ������������ ����������� ��������! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}	
	double cos_f=ScalarMult(V1,V2)/(modV1*modV2);
	if(fabs(cos_f)>1)
	{
		char* error="AngleV1V2: ������ cos(f)>1! ";
		MessageBox(NULL,error,"������",MB_ICONSTOP);
    exit(1);
	}
	double f;
	if(cos_f>0)f=acos(cos_f);
	else f=pi-acos(cos_f);
	double fg=(f/pi)*180;
	return fg;
}
//--------------------------------------------------------------------------------
CMatrix CreateViewCoord(double r,double fi,double q)
// ������� ������� ��������� ����� �� ������� ������� ��������� � �������
// (r,fi,q)- ���������� ����� ����������(������ ������� ������� ���������)
// � ������� ����������� ������� ���������( ���� fi � q � ��������)
{
	double fg=fmod(fi,360.0);
  double ff=(fg/180.0)*pi; // ������� � �������
	fg=fmod(q,360.0);
	double qq=(fg/180.0)*pi; // ������� � �������

	CMatrix VM(4,4);
	VM(0,0)=-sin(ff);   VM(0,1)=cos(ff);
	VM(1,0)=-cos(qq)*cos(ff);	VM(1,1)=-cos(qq)*sin(ff);	VM(1,2)=sin(qq);
	VM(2,0)=-sin(qq)*cos(ff);	VM(2,1)=-sin(qq)*sin(ff);	VM(2,2)=-cos(qq); VM(2,3)=r;
	VM(3,3)=1;
	return VM;
}

/////////////////////////////////////////////////////////////////////////////////////////

void MyLine(CDC& dc,int x1,int y1,int x2,int y2,COLORREF crColor)	// MFC
// ��������� ������ ����� crColor ��� ����� (x1,y1) � (x2,y2)
// dc - ������ �� ����� CDC MFC
{//
 int incX,incY;
 int dx=x2-x1;
 int dy=y2-y1;
 if (dx>0)incX=1;
 if (dx==0)incX=0;
 if (dx<0)incX=-1;
 if (dy>0)incY=1;
 if (dy==0)incY=0;
 if (dy<0)incY=-1;
 if(abs(dx)>=abs(dy))
{///
 dc.SetPixel(x1,y1,crColor);
 if((dx==0)&&(dy==0))return;
 double k=((double)dy)/((double)dx);
 if(k<0)k=-k;
 double c=0;
 int y=y1;
 int d=abs(dx);
 int x=x1+incX;
 for(int i=1;i<=d;i++)
   {
    if((c+=k)>0.5)
    {
			c-=1;
			y+=incY;
		}  
   dc.SetPixel(x,y,crColor);
   x+=incX;
   }
 return;
}///

if(abs(dx)<abs(dy))
{///
 double k=((double)dx)/((double)dy);
 if(k<0)k=-k;
 double c=0;
 dc.SetPixel(x1,y1,crColor);
 int x=x1;
 int d=abs(dy);
 int y=y1+incY;
 for(int i=1;i<=d;i++)
   {
    if((c+=k)>0.5)
    {
			c-=1;
			x+=incX;
		}
		dc.SetPixel(x,y,crColor);
		y+=incY;
   }
 return;
}///
}//

//--------------------------------------------------------------------------------------
void MyBezier(CDC& dc,CPoint* MasPoints,int NamberPoints,int NT)
// ������ ������ ����� �� ������ ������� �����
// dc - ������ �� ����� CDC MFC
// MasPoints - ������ ������� �����
// NamberPoints - ����� ����� � ������� MasPoints 
// NT - ����� �������� �� ��������� t
{
 double dt=1.0/NT;
 int m=NamberPoints-1;
 CPoint* R=new CPoint[NamberPoints];
 //MoveToEx(hdc,MasPoints[0].x,MasPoints[0].y,NULL);
 dc.MoveTo(MasPoints[0].x,MasPoints[0].y);
 for (int k=1;k<=NT;k++)
 {//***
  double t=k*dt;	  
  for(int i=0;i<=m;i++)  R[i]=MasPoints[i];
  for(int j=m;j>0;j--)
  {
	  for(int i=0;i<j;i++) 
	  {
		R[i].x=R[i].x+t*(R[i+1].x-R[i].x);
        R[i].y=R[i].y+t*(R[i+1].y-R[i].y);
	  }
  }
  //LineTo(hdc,R[0].x,R[0].y);
	dc.LineTo(R[0].x,R[0].y);
 }//***
}
//------------------------------------------------------------------------------------
void FillCircle(CDC& dc,int x0,int y0,int r)
// ����������� ���������� ������� ������
// dc - ������ �� ����� CDC MFC
// x0,y0 - �������� ���������� ������ ���������� � ������ MM_TEXT
// r - ������ ����������
// dc - ������ �� ����� CDC MFC
{
  int xEnd=(int)((double)r/sqrt(2.0));
  for(int xi=0;xi<=xEnd;xi++)
  {
	double z=(double)(r*r-xi*xi);
	int yi=(int)sqrt(z);
	int x=x0+xi;
	int y=y0+yi;
	dc.MoveTo(x,y);
	x=x0-xi;
	dc.LineTo(x,y);
	x=x0+yi;
	y=y0+xi;
	dc.MoveTo(x,y);
	x=x0-yi;
	dc.LineTo(x,y);
	x=x0+yi;
	y=y0-xi;
	dc.MoveTo(x,y);
	x=x0-yi;
	dc.LineTo(x,y);
	x=x0+xi;
	y=y0-yi;
	dc.MoveTo(x,y);
	x=x0-xi;
	dc.LineTo(x,y);
  }
}
//-----------------------------------------------------------------------------------------
void FillPolygon(CDC& dc,CPoint* PX,int Npoint)
// ����������� �������� ������������� ������� ������
// dc - ������ �� ����� CDC MFC
// PX - ������ ������ ��������������
// NPoint - ����� ����� � ������� ������
{
	int maxY,minY,xk,Ind;
	CPoint P1,P2;
	CPoint* PP=new CPoint[Npoint+1];
	for(int i=0;i<=Npoint;i++)
	{
	  if(i==Npoint)
	  {
		PP[Npoint].x=PX[0].x;
		PP[Npoint].y=PX[0].y;
	  }
	  else
	  {
		PP[i].x=PX[i].x;
		PP[i].y=PX[i].y;
	  }
	}

	maxY=PP[0].y;
	minY=PP[0].y;
	for(int i=1;i<Npoint;i++)
	{
	  if(PP[i].y>maxY) maxY=PP[i].y;
	  if(PP[i].y<minY) minY=PP[i].y;
	}
	for(int yk=maxY;yk>=minY;yk--)
	{
	  P1.x=-1; P1.y=-1;
	  P2.x=-1; P2.y=-1;
	  Ind=0;
	  for(int i=0;i<Npoint;i++)
	  {//***
		
		if(PP[i].y==PP[i+1].y)	// �����������
		{/////
		  if(yk==PP[i].y)
		  {
			dc.MoveTo(PP[i].x,yk);
			dc.LineTo(PP[i+1].x,yk);
		  }
		  continue;
		}/////

		if(PP[i].x==PP[i+1].x)	// ���������
		{/////
		 Ind++;
		 if(Ind==1)
		 {
			P1.x=PP[i].x;
			P1.y=yk;
		 }
		 if(Ind==2)
		  {
			P2.x=PP[i].x;
			P2.y=yk;
		  }
		 if(Ind==3)
		  {
			if(P1==P2)
			{
			  P2.x=PP[i].x;
			  P2.y=yk;
			}
		  }
		  continue;
		}/////
		double q1=(double)(yk-PP[i].y);
		double q2=(double)(PP[i+1].y-PP[i].y);
		double xx=PP[i].x+(q1/q2)*(PP[i+1].x-PP[i].x);
		//int xk=IRound(xx);
		int xL=(PP[i].x<=PP[i+1].x)?PP[i].x:PP[i+1].x;
		int xH=(PP[i].x>=PP[i+1].x)?PP[i].x:PP[i+1].x;
		if(xx<xL) xk=(int)floor(xx);
		else
			if(xx>xH) xk=(int)ceil(xx);
			else xk=IRound(xx);
		if((xk>=xL)&&(xk<=xH))
		{//+++
		Ind++;
		 if(Ind==1)
		 {
			P1.x=xk;
			P1.y=yk;
		 }
		 if(Ind==2)
		  {
			P2.x=xk;
			P2.y=yk;
		  }
		 if(Ind==3)
		  {
			if(P1==P2)
			{
			  P2.x=xk;
			  P2.y=yk;
			}
		  }
	
		}//+++

	  }//***	

	  if(yk<=(maxY-0))
	  {
	  dc.MoveTo(P1.x,P1.y);
	  dc.LineTo(P2.x,P2.y);
	  }
	}
	delete [] PP;
}


POINT** CreateSurfaceMatrix_XXX(pfunc2 MyF,CRectD& RS,int Nx,int Ny,CRect& RW,CMatrix& PView)
// ��������� ������� ��� ����������� ����������� f(x,y) 
// MyF - ������� ���� ���������� f(x,y)
// RS - ������� �� ��������� XY, �� ������� ��������� ������������ �����������
// Nx - ����� ����� �� ��� x
// Ny - ����� ����� �� ��� y
// RW -������� � ����, ��� ������������ �����������
// PView(r,fi,q) - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
{
	double xL,yL,ddx;
	CMatrix RR=SphereToCart(PView);				// ��������� ���������� ����� ����������
	double xv=RR(0);							// x- ���������� ����� ����������
	double yv=RR(1);					    	// y- ���������� ����� ����������
	double zv=RR(2);							// z- ���������� ����� ����������
	double dx=(RS.right-RS.left)/(Nx-1);	// ��� �� x
	double dy=(RS.top-RS.bottom)/(Ny-1);	// ��� �� y

//-- ���������� ��� ��������� ����� ���������� ������������ ��������� ������� RS ---
	double y=RS.bottom+(RS.top-RS.bottom)*(xv-RS.left)/(RS.right-RS.left);
	yL=RS.bottom;
	if(yv<y)
	{
		xL=RS.left;
		ddx=dx;
	}
	else
	{
		xL=RS.right;
		ddx=-dx;
	}
	
//----- ������� ������� �������� zij=f(xi,yj)-------------------------------------
	CMatrix F(Nx,Ny);
	for(int i=0;i<Nx;i++)
	{
		double xi=xL+i*ddx;
		for(int j=0;j<Ny;j++)
		{
				double yj=yL+j*dy;
				double zij=MyF(xi,yj);
				F(i,j)=zij;
		}
	}
//--------------------------------------------------------------------------------

double maxF=F.MaxElement();
double minF=F.MinElement();
double h=maxF-minF;
F=F-minF;											// ������� z_min ������ �� ��� z � ����� z=0

CSizeD SZ=RS.SizeD();
//--- ������� ���������� ������ ������� RS - (x0,y0)
double x0=RS.left+SZ.cx/2;		// x0
double y0=RS.bottom+SZ.cy/2;	// y0
double dxy=sqrt(SZ.cx*SZ.cx+SZ.cy*SZ.cy); // ����� ��������� ������� RS
double dz=sqrt(dxy*dxy+h*h);		// ����� ��������� �������������� � ���������� RS � ������� h

double fxy_rad=atan(SZ.cx/SZ.cy);	// �������
double fz_rad=atan(h/dxy);			// �������
double fi_rad=(PView(1)/180.0)*pi;	// ������ � �������
double q_rad=(PView(2)/180.0)*pi;	//  ���� � �������
//-------------------------------------------------------------------------------------
double Pxy;
if((fi_rad>=0)&&(fi_rad<=(pi/2))) Pxy=dxy*cos(fxy_rad-fi_rad);
if((fi_rad>(pi/2))&&(fi_rad<=pi)) Pxy=-dxy*cos(fxy_rad+fi_rad);
if((fi_rad>pi)&&(fi_rad<=(3*pi/2))) Pxy=-dxy*cos(fxy_rad-fi_rad);
if((fi_rad>(3*pi/2))&&(fi_rad<(2*pi))) Pxy=dxy*cos(fxy_rad+fi_rad);

//-------------------------------------------------------------------------------------

double Pz,dL;
CRectD RV;
if(q_rad<=(pi/2))
{
	Pz=dz*cos(fz_rad-q_rad);
	dL=(dxy/2)*cos(q_rad);
	//RV.SetRectD(-Pxy/2,Pz-dL,Pxy/2,-dL);
}
else 
{
	Pz=-dz*cos(fz_rad+q_rad);
	dL=-(dxy/2)*cos(q_rad);
	//RV.SetRectD(-Pxy/2,Pz-dL,Pxy/2,-dL);
}
RV.SetRectD(-Pxy/2,Pz-dL,Pxy/2,-dL);

//------------------------------------------------------------------------------------

CMatrix MW=SpaceToWindow(RV,RW);		// ������� (3 �� 3)��������� � ������� ������� ���������

CMatrix V(3),V0(3);
V(2)=1;
V0(0)=RV.left;	
V0(1)=RV.bottom;		// V0(2)=0 - � ������������	
//-------------------------------------------------------------------------------------
CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) ��������� � ������� 
														                      		  //������� ��������� 
CMatrix PS(4);	// ����� � ������� ������������
PS(3)=1;																												
//------------------------------------------------------------------------------------
POINT** MasPoints=NULL;
MasPoints=new POINT*[Nx];
for(int i=0;i<Nx;i++) MasPoints[i]=new POINT[Ny];

	for(int i=0;i<Nx;i++)
	{
		double xi=xL+i*ddx-x0;  // �������� � ����� ���������
		PS(0)=xi;
			for(int j=0;j<Ny;j++)
			{
				double yj=yL+j*dy-y0;	// �������� � ����� ���������
				double zij=F(i,j);
				PS(1)=yj;
				PS(2)=zij;
				CMatrix PV=MV*PS;   // ���������� ����� PS � ������� ������� ��������� (4 �� 4)
				V(0)=PV(0); // x
				V(1)=PV(1); // y
				V=V-V0;			// x-xL, y-yL, 1
				V=MW*V;			// ������� ���������� �����
				MasPoints[i][j].x=(int)V(0);
				MasPoints[i][j].y=(int)V(1);
			}
	}
return 	MasPoints;	
}


//-------------------- CreateSurfaceMatrix ----------------------------------------------
POINT** CreateSurfaceMatrix(pfunc2 MyF,CRectD& RS,int Nx,int Ny,CRect& RW,CMatrix& PView)
// ��������� ������� ��� ����������� ����������� f(x,y) 
// MyF - ������� ���� ���������� f(x,y)
// RS - ������� �� ��������� XY, �� ������� ��������� ������������ �����������
// Nx - ����� ����� �� ��� x
// Ny - ����� ����� �� ��� y
// RW -������� � ����, ��� ������������ �����������
// PView(r,fi,q) - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
{
	double xL,yL,ddx;
	CMatrix RR=SphereToCart(PView);				// ��������� ���������� ����� ����������
	double xv=RR(0);							// x- ���������� ����� ����������
	double yv=RR(1);					    	// y- ���������� ����� ����������
	double zv=RR(2);							// z- ���������� ����� ����������
	double dx=(RS.right-RS.left)/(Nx-1);	// ��� �� x
	double dy=(RS.top-RS.bottom)/(Ny-1);	// ��� �� y

//-- ���������� ��� ��������� ����� ���������� ������������ ��������� ������� RS ---
	double y=RS.bottom+(RS.top-RS.bottom)*(xv-RS.left)/(RS.right-RS.left);
	yL=RS.bottom;
	if(yv<y)
	{
		xL=RS.left;
		ddx=dx;
	}
	else
	{
		xL=RS.right;
		ddx=-dx;
	}
	
//----- ������� ������� �������� zij=f(xi,yj)-------------------------------------
	CMatrix F(Nx,Ny);
	for(int i=0;i<Nx;i++)
	{
		double xi=xL+i*ddx;
		for(int j=0;j<Ny;j++)
		{
				double yj=yL+j*dy;
				double zij=MyF(xi,yj);
				F(i,j)=zij;
		}
	}
//--------------------------------------------------------------------------------

CRectD RV;
GetProjection(RS,F,PView,RV);		  // ������� �����������

//------------------------------------------------------------------------------------

CMatrix MW=SpaceToWindow(RV,RW);		// ������� (3 �� 3)��������� � ������� ������� ���������

CMatrix V(3),V0(3);
V(2)=1;
V0(0)=RV.left;	
V0(1)=RV.bottom;		// V0(2)=0 - � ������������	
//-------------------------------------------------------------------------------------
CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) ��������� � ������� 
														                      		  //������� ��������� 
CMatrix PS(4);	// ����� � ������� ������������
PS(3)=1;																												
//------------------------------------------------------------------------------------
POINT** MasPoints=NULL;
MasPoints=new POINT*[Nx];
for(int i=0;i<Nx;i++) MasPoints[i]=new POINT[Ny];

	for(int i=0;i<Nx;i++)
	{
		double xi=xL+i*ddx;  // �������� � ����� ���������
		PS(0)=xi;
			for(int j=0;j<Ny;j++)
			{
				double yj=yL+j*dy;	// �������� � ����� ���������
				double zij=F(i,j);
				PS(1)=yj;
				PS(2)=zij;
				CMatrix PV=MV*PS;   // ���������� ����� PS � ������� ������� ��������� (4 �� 4)
				V(0)=PV(0); // x
				V(1)=PV(1); // y
				V=V-V0;			// x-xL, y-yL, 1
				V=MW*V;			// ������� ���������� �����
				MasPoints[i][j].x=(int)V(0);
				MasPoints[i][j].y=(int)V(1);
			}
	}
return 	MasPoints;	
}
void DrawSurface(CDC& dc,POINT** MasPoints,int Nx,int Ny)
// dc - ������ �� ����� CDC MFC
// MasPoints - ������ ����� ��� ����������� 
// Nx - ����� ����� �� ��� x
// Ny - ����� ����� �� ��� y
{
	POINT pt[4];
	for(int i=0;i<Nx-1;i++)
		for(int j=0;j<Ny-1;j++)
		{
			pt[0].x=MasPoints[i][j].x;
			pt[0].y=MasPoints[i][j].y;

			pt[1].x=MasPoints[i][j+1].x;
			pt[1].y=MasPoints[i][j+1].y;

			pt[2].x=MasPoints[i+1][j+1].x;
			pt[2].y=MasPoints[i+1][j+1].y;

			pt[3].x=MasPoints[i+1][j].x;
			pt[3].y=MasPoints[i+1][j].y;
			dc.Polygon(pt,4);
		}
}

//-----------------------------------------------------------------------------------
CMatrix SphereToCart(CMatrix& PView)
// ����������� ����������� ���������� PView  ����� � ���������
// PView(0) - r
// PView(1) - fi - ������(������ �� ��� X), ����.
// PView(2) - q - ����(�������� ��� Z), ����.
// ���������: R(0)- x, R(1)- y, R(2)- z	
{
	CMatrix R(3);
	double r=PView(0);
	double fi=PView(1);						// �������
	double q=PView(2);						// �������
	double fi_rad=(fi/180.0)*pi;	// ������� fi � �������
	double q_rad=(q/180.0)*pi;		// ������� q � �������
	R(0)=r*sin(q_rad)*cos(fi_rad);	// x- ���������� ����� ����������
	R(1)=r*sin(q_rad)*sin(fi_rad);	// y- ���������� ����� ����������
	R(2)=r*cos(q_rad);							// z- ���������� ����� ����������
	return R;
}

//-------------------------- GetProjection -------------------------------------------

void GetProjection(CRectD& RS,CMatrix& Data,CMatrix& PView,CRectD& PR)
// ��������� ���������� �������� ������������� ������ �������������� �� 
// ��������� XY � ������� ������� ���������
// Data - ������� ������
// RS - ������� �� ��������� XY, �� ������� ��������� ������������ �����������
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// PR - ��������
{
	double Zmax=Data.MaxElement();
	double Zmin=Data.MinElement();
	CMatrix PS(4,4);	// ����� � ������� ������������
	PS(3,0)=1; PS(3,1)=1;	PS(3,2)=1;	PS(3,3)=1;		
	CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4x4) ��������� 
														          										//� ������� ������� ��������� 
	PS(0,0)=RS.left;
	PS(1,0)=RS.top;
	PS(2,0)=Zmax;

	PS(0,1)=RS.left;
	PS(1,1)=RS.bottom;
	PS(2,1)=Zmax;
					
	PS(0,2)=RS.right;
	PS(1,2)=RS.top;
	PS(2,2)=Zmax;

	PS(0,3)=RS.right;
	PS(1,3)=RS.bottom;
	PS(2,3)=Zmax;

	CMatrix Q=MV*PS;      // ���������� ������� ��������� �������������� � ������� ��
	CMatrix V=Q.GetRow(0);		// ������ X - ���������
	double Xmin=V.MinElement();
	double Xmax=V.MaxElement();
	V=Q.GetRow(1);           // ������ Y - ���������
	double Ymax=V.MaxElement();

	PS(2,0)=Zmin;
	PS(2,1)=Zmin;
	PS(2,2)=Zmin;
	PS(2,3)=Zmin;

	Q=MV*PS;                 // ���������� ������ ��������� �������������� � ������� ��
	V=Q.GetRow(1);           // ������ Y - ���������
	double Ymin=V.MinElement();
	PR.SetRectD(Xmin,Ymax,Xmax,Ymin);
}
//-------------------------- IRound --------------------------------------------------
int IRound(double x)
// ��������� ����� x �� �������� ����������
{
double y=x-floor(x);
if (y<0.5) return (int)floor(x);
else return (int)ceil(x);
}












