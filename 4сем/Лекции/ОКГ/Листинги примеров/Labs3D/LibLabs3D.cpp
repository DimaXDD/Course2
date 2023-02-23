#include "stdafx.h"
void DrawPyramid(CDC& dc,CMatrix& VA,CMatrix& VB,CMatrix& VC,CMatrix& VD,CMatrix& PView)
// ������ �������� ��� �������� ��������� ����� 
// � ������ MM_ANISOTROPIC - ��� ������������ ��������� ���������
// � ������� ������ ������� ����� � ��������� ������ ������ ���� �����������
// dc - ������ �� ����� CDC MFC
// D - ������� ��������
// ABC - ��������� ��������
// VA,VB,VC - ���������� ������ A,B,C � ������� ������� ���������
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))

{
	double r=PView(0);
	double fi=PView(1);
	double q=PView(2);
	CMatrix MV=CreateViewCoord(r,fi,q);

	CMatrix Ve=MV*VA; // ���������� ������� � � ������� �����������
	int ax=(int)Ve(0);
	int ay=(int)Ve(1);

	Ve=MV*VB;         // ���������� ������� B � ������� �����������
	int bx=(int)Ve(0);
	int by=(int)Ve(1);

	Ve=MV*VC;         // ���������� ������� C � ������� �����������
	int cx=(int)Ve(0);
	int cy=(int)Ve(1);

	Ve=MV*VD;         // ���������� ������� D � ������� �����������
	int dx=(int)Ve(0);
	int dy=(int)Ve(1);

	CPen MyPen1,MyPen2;
	MyPen1.CreatePen(PS_SOLID,0, RGB(0,0,255)); 
	CPen* pOldPen= dc.SelectObject(&MyPen1);
	
	
	dc.MoveTo(ax,ay);	 // ����� A 	
	dc.LineTo(bx,by);  // ����� AB
	dc.LineTo(cx,cy);  // ����� BC
	dc.LineTo(ax,ay);  // ����� CA


	MyPen2.CreatePen(PS_SOLID,0, RGB(255,0,0)); 
	dc.SelectObject(&MyPen2);

	dc.LineTo(dx,dy);  // ����� AD
	dc.LineTo(bx,by);  // ����� DB
	dc.MoveTo(dx,dy);	 // ����� D
	dc.LineTo(cx,cy);  // ����� DC

	dc.SelectObject(pOldPen);

}

void DrawPyramid1(CDC& dc,CMatrix& VA,CMatrix& VB,CMatrix& VC,CMatrix& VD,CMatrix& PView)
// ������ �������� � ��������� ��������� ����� 
// � ������ MM_ANISOTROPIC - ��� ������������ ��������� ���������
// � ������� ������ ������� ����� � ��������� ������ ������ ���� �����������
// dc - ������ �� ����� CDC MFC
// D - ������� ��������
// ABC - ��������� ��������
// VA,VB,VC - ���������� ������ A,B,C � ������� ������� ���������
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
{
// ��������� ��������� ���������� ������� ����� ����������
	double r=PView(0);
	double fi=PView(1);						// �������
	double q=PView(2);						// �������
	double fi_rad=(fi/180.0)*pi;	// ������� fi � �������
	double q_rad=(q/180.0)*pi;		// ������� q � �������
	double zv=r*cos(q_rad);
	double xv=r*sin(q_rad)*cos(fi_rad);
	double yv=r*sin(q_rad)*sin(fi_rad);
	CMatrix VR(3);
	VR(0)=xv;  VR(1)=yv;     VR(2)=zv;
//----------���������� ������ � ������� ����������� -----------------------
	POINT A,B,C,D;
	CMatrix MV=CreateViewCoord(r,fi,q);	// ������� ��������� � ������� ������� ���������
	CMatrix Ve=MV*VA; // ���������� ������� � � ������� �����������
	A.x=(int)Ve(0);
	A.y=(int)Ve(1);

	Ve=MV*VB;         // ���������� ������� B � ������� �����������
	B.x=(int)Ve(0);
	B.y=(int)Ve(1);

	Ve=MV*VC;         // ���������� ������� C � ������� �����������
	C.x=(int)Ve(0);
	C.y=(int)Ve(1);

	Ve=MV*VD;         // ���������� ������� D � ������� �����������
	D.x=(int)Ve(0);
	D.y=(int)Ve(1);
//-----------------------------------------------------------------

	CMatrix AD=VD-VA;                 // ������ AD - ������ 4
	CMatrix AC=VC-VA;                 // ������ AC - ������ 4
	CMatrix AB=VB-VA;                 // ������ AB - ������ 4
	CMatrix BD=VD-VB;                 // ������ BD - ������ 4
	CMatrix BC=VC-VB;                 // ������ BC - ������ 4
	//-- ������� ��������� ������� �� ��������
	AD.RedimData(3);
	AC.RedimData(3);
	AB.RedimData(3);
	BD.RedimData(3);
	BC.RedimData(3);

	//double VR1[]={VR(0),VR(1),VR(2)};	//#############################################

	CMatrix VN=VectorMult(AC,AD);			// ������ �������(!)������� � ����� ACD

	//double VN1[]={VN(0),VN(1),VN(2)};	//#############################################

	double sm=ScalarMult(VN,VR);      // ��������� ������������ ������� ������� � ����� �
																		// � ������� ����� ����������
	if(!(sm<0)) // ����� ACD ������ - ������ ����� 
	{		
		POINT ACD[]={A,C,D,A};
		dc.Polyline(ACD,4);
	}

	VN=VectorMult(AD,AB);		  	// ������ �������(!)������� � ����� ADB
	sm=ScalarMult(VN,VR);       // ��������� ������������ ������� ������� � ����� �
														  // � ������� ����� ����������
	if(!(sm<0)) // ����� ADB ������ - ������ ����� 
	{		
		POINT ADB[]={A,B,D,A};
		dc.Polyline(ADB,4);
	}

	VN=VectorMult(AB,AC);		  	// ������ �������(!)������� � ����� ABC
	sm=ScalarMult(VN,VR);       // ��������� ������������ ������� ������� � ����� �
													  	// � ������� ����� ����������
	if(!(sm<0)) // ����� ABC ������ - ������ ����� 
	{		
		POINT ABC[]={A,B,C,A};
		dc.Polyline(ABC,4);
	}

	VN=VectorMult(BD,BC);		  	// ������ �������(!)������� � ����� BDC
	sm=ScalarMult(VN,VR);       // ��������� ������������ ������� ������� � ����� �
													  	// � ������� ����� ����������
	if(!(sm<0)) // ����� BDC ������ - ������ ����� 
	{		
		POINT BDC[]={B,D,C,B};
		dc.Polyline(BDC,4);
	}

}
double MyFunction2(double x,double y)
{
	/*
		double b=1,c=1;
		double r=sqrt(x*x+y*y);
		double z=cos(b*r)/(1+c*r);
		return z;
	*/	
		double z,q=10;
		double r=sqrt(x*x+y*y);
		if(r<0.00001) z=1;
		else z=sin(r)/r;
		return q*z;
}

double MyFunction1(double x,double y)
{
		double x0=10,y0=-5;
		double z=(x-x0)*(x-x0)+(y-y0)*(y-y0)-3;
		return z;
}

double MyFunction3(double x,double y)
{
		double x0=0,y0=0;
		double z=(x-x0)*(x-x0)-(y-y0)*(y-y0);
		return z;
}

////////////////////// ���� ////////////////////////////////////////////////////////////

void DrawLightSphere(CDC& dc,double Radius,CMatrix& PView,CMatrix& PSourceLight,CRect RW,
					 COLORREF Color,int Index)

// ������ ����� � ������ ������������
// Radius - ������ �����
// PView - ���������� ����� ���������� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// PSourceLight - ���������� ��������� ����� � ������� ����������� ������� ���������
// (r,fi(����.), q(����.))
// RW - ������� � ���� ��� ����������� ����
// Color - ���� ��������� �����
// Index=0 -  ������������ ������ ��������� ����� :cos(e)
// Index=1 -  ���������� ������ ��������� ����� :[cos(a)]^n

{
  BYTE red=GetRValue(Color);
  BYTE green=GetGValue(Color);
  BYTE blue=GetBValue(Color);

  CMatrix VSphere(3),VSphereNorm(3),PV(4);  // V0(3)
  COLORREF Col;
  double df=0.5;                            // ��� �� �������,�������
  double dq=0.5;                            // �������	
  double kLight;
  VSphere(0)=Radius;	                    // ������ �����
  CMatrix VR=SphereToCart(PView);       	// ��������� ���������� ����� ����������
  CMatrix VS=SphereToCart(PSourceLight);	// ��������� ���������� ��������� �����
  CRectD  RV(-Radius,Radius,Radius,-Radius); // ������� � ������� ����������� � ��������� XY
                                            // ��� ����������� �������� ����
  CMatrix MW=SpaceToWindow(RV,RW);		    // ������� (3 �� 3)��������� � ������� �������
											// ���������
  CMatrix MV=CreateViewCoord(PView(0),PView(1),PView(2));	//�������(4 �� 4) ���������  
									                        // � ������� ������� ���������	

//------ �������� �� ������ �����  ---------------------------------------
  for(double fi=0;fi<360.0;fi+=df)			// ������
	for(double q=0;q<=180.0;q+=dq)			// q= 90 - ���� �����
	{
	  VSphere(1)=fi;  // ������� (������),VSphere(0)==Radius 
	  VSphere(2)=q;	  // ������	
	  CMatrix VCart=SphereToCart(VSphere);	// ��������� ���������� ����� �����  
	  VSphereNorm=VCart;				    // ������ ������� � ����������� �����!
	  CMatrix  VK=VR-VSphereNorm;       // ����������� �� ����� ���������� ������������
                                        // ������� � ����� �������	
	  double cos_RN=CosV1V2(VK,VSphereNorm); // ������� ���� ����� �������� ����� ���������� R
									         // � �������� ������� N � ����� �����
	  if(cos_RN>0)	  // ���� ����� ������ �����������...
		{ //=====
		  PV(0)=VCart(0);
		  PV(1)=VCart(1);
		  PV(2)=VCart(2);
		  PV(3)=1;
		  PV=MV*PV;        // ���������� ����� � ������� ������� ���������
		  VCart(0)=PV(0);  // Xv
		  VCart(1)=PV(1);  // Yv
		  VCart(2)=1;
		  VCart=MW*VCart;  // ������� ���������� ������� ����� �����		  
		  CMatrix  VP=VS-VSphereNorm;  // ����������� �� �������� ����� ������������
                                       // ������� � ����� �������	
		  double cos_PN=CosV1V2(VP,VSphereNorm); // ������� ���� ������� ���� ( ����� VP � 
		                                         // �������� VSphereNor
		  if(cos_PN>0)	// ���� ����� ����� ����������...
			{
			  if(Index==0) // ������������ ������ ���������
				{
				  kLight=cos_PN*cos_RN;
				}
			  if(Index==1) // ���������� ������ ���������
				{
				  double xx=2*ModVec(VP)*cos_PN/ModVec(VSphereNorm);
				  CMatrix RX=VSphereNorm*xx-VP; //���������� ���
				  double cos_A=CosV1V2(RX,VR);  // ������� ���� ����� ���������� ����� � 
		                                        // �������� ����������
				  if(cos_A>0)kLight=cos_A*cos_A*cos_A*cos_A; //(cos^4)
				  else kLight=0;			  
				}
			  /*Col=RGB(kLight*255,kLight*255,kLight*255);*/
		      Col=RGB(kLight*red,kLight*green,kLight*blue);
			  dc.SetPixel((int)VCart(0),(int)VCart(1),Col);
			}
		  else
			{
			  Col=RGB(0,0,0);
			  dc.SetPixel((int)VCart(0),(int)VCart(1),Col);
			}
		} //===========
//-----------------------------------------------------------------------
	}
}




