#ifndef LIBGRAPH
#define LIBGRAPH 1
const double pi=3.14159;
//typedef double (*pfunc)(double);	// Указатель на функцию

struct CSizeD
{
  double cx;
  double cy;
};
//-------------------------------------------------------------------------------
struct CRectD 
 { 
  double left; 
  double top; 
  double right; 
  double bottom; 
  CRectD(){left=top=right=bottom=0;};
  CRectD(double l,double t,double r,double b);
  void SetRectD(double l,double t,double r,double b);
  CSizeD SizeD();	// Возвращает размеры(ширина, высота) прямоугольника 
 };

//-------------------------------------------------------------------------------
struct CMyPen 
{
	int PenStyle;				// Стиль пера
	int PenWidth;				// Толщина пера 
	COLORREF PenColor;	// Цвет пера 
	CMyPen(){PenStyle=PS_SOLID;PenWidth=1;PenColor=RGB(0,0,0);};
	void Set(int PS,int PW,COLORREF PC){PenStyle=PS;PenWidth=PW;PenColor=PC;};
};
//-------------------------------------------------------------------------------

CMatrix SpaceToWindow(CRectD& rs,CRect& rw);
// Возвращает матрицу пересчета координат из мировых в оконные
// rs - область в мировых координатах - double
// rw - область в оконных координатах - int

//------------------------------------------------------------------------------
void SetMyMode(CDC& dc,CRectD& RS,CRect& RW);  //MFC
// Устанавливает режим отображения MM_ANISOTROPIC и его параметры
// dc - ссылка на класс CDC MFC
// RS -  область в мировых координатах 
// RW -	 Область в оконных координатах - int  
//------------------------------------------------------------------------------

class CPlot2D
{
	CMatrix X;				// Аргумент
	CMatrix Y;				// Функция
	CMatrix K;				// Матрица пересчета коорднат
	CRect RW;					// Прямоугольник в окне
	CRectD RS;				// Прямоугольник области в МСК
	CMyPen PenLine;   // Перо для линий
	CMyPen PenAxis;   // Перо для осей
 public:
	CPlot2D(){K.RedimMatrix(3,3);};
	void SetParams(CMatrix& XX,CMatrix& YY,CRect& RWX);
	void SetWindowRect(CRect& RWX);	
	void GetWindowCoords(double xs,double ys, int &xw,int &yw);
	void SetPenLine(CMyPen& PLine);	// Перо для рисования графика
	void SetPenAxis(CMyPen& PAxis);	// Перо для осей координат
	void Draw(CDC& dc,int Ind1,int Int2);		// Рисование с самостоятельным пересчетом координат
	void Draw1(CDC& dc,int Ind1,int Int2);		// Рисование с БЕЗ самостоятельного пересчетом координат
	void DrawBezier(CDC& dc,int NT);
	void GetRS(CRectD& RS);					// Возвращает область графика в мировой СК
};


#endif

