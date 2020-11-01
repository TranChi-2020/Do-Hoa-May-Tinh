#include <iostream>
#include <windows.h>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <tchar.h>
#include <strsafe.h>
#include <wincon.h>
#include <vector>
#include <stdio.h>
#include <cwchar>
#include <math.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setWindowAndTitle(int size) {
	TCHAR szOldTitle[MAX_PATH];
	TCHAR szNewTitle[MAX_PATH];
	// Save current console title.
	if( GetConsoleTitle(szOldTitle, MAX_PATH) )
	{
		// Build new console title string.
		StringCchPrintf(szNewTitle, MAX_PATH, TEXT("CHUONG TRINH DO HOA"), szOldTitle);
		SetConsoleTitle(szNewTitle);
	}
	
	//Full screen
	COORD Coord;
	CONSOLE_FONT_INFOEX cfi;
	
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &Coord);
}

void setTextColor(int color, string text) {
	//Set color
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	SetConsoleTextAttribute(hConsole, WHITE);
}

void endAlgorithm() {
	moveto(10, 10);
	setbkcolor(YELLOW);
	setcolor(RED);
	outtext("");
	settextstyle(EUROPEAN_FONT, 0, 2);
	outtext("Chuong trinh da thuc hien thanh cong! Nhan mot phim bat ky de dung.");
	setbkcolor(BLACK);
	
	setTextColor(BLUE, "Nhan mot phim bat ky de dung: ");
	system("pause");
	
	closegraph();
}

// EDIT: Thiet lap thuat toan
// NEW: Them thuat toan duoi day

class DDA {
	private:
		string name;

	public:
		#define Round(a) int(a + 0.00005)

		string getName() {
			name = "DDA";
			return name;
		}
		
		int color = GREEN;
		
		void dtDDA(int x1, int y1, int x2, int y2) {
			int x = x1;
			float y = y1;
			float m = float(y2 - y1)/(x2 - x1);
			putpixel(x, Round(y), color);
			for(int i = x1; i < x2; i++) {
				x++;
				y += m;
				putpixel(x, Round(y), color);
				delay(0);
			}
		}
		
		void init() {
		   	int color;
		   	struct arccoordstype a, b;
			initwindow(1280, 720);
			dtDDA(100, 100, 1000, 600);
		}
};

class Bresenham {	
	private:
		string name;
	
	public:
		#define DELAY 10	
		string getName() {
			name = "Line Bresenham";
			return name;
		}
		
		int color = BLUE;
		void dtBres(int x1, int y1, int x2, int y2) {
			int Dx, Dy, p, Const1, Const2;
			int x, y;
			Dx = x2 - x1;
			Dy = y2 - y1;
			p = 2*Dy - Dx;
			Const1 = 2*Dy;
			Const2 = 2*(Dy - Dx);
			x = x1;
			y = y1;
			putpixel(x, y, color);
			for(int i = x1; i < x2; i++) {
				if(p < 0)
					p += Const1;
				else {
					p += Const2;
					y++;
				}
				x++;
				putpixel(x, y, color);
				delay(3);
			}
			
		}
		void init(){
			int x, y, color;
			struct arccoordstype a, b;
		   	initwindow(1280, 720);
			dtBres(100, 100, 1000, 600);
		}
};

class MidPoint {
	private:
		string name;
	public:
		
		string getName() {
			name = "Circle Midpoint";
			return name;
		}
		
		int color = GREEN;
		void put8Pixel(int x, int y) {
			putpixel(x, y, color);
			putpixel(y, x, color);
			putpixel(y, -x, color);
			putpixel(x, -y, color);
			putpixel(-x, -y, color);
			putpixel(-y, -x, color);
			putpixel(-x, y, color);
			putpixel(-y, x, color);
		}
		void htMidPoint(int x0, int y0, int R) { 
			int x, y, p;
			x = 0;
			y = R;
			put8Pixel(x,y);
			p = 1 - R;
			while (x < y) {
				if (p < 0) p += 2*x + 3;
				else {
					p += 2*(x - y) + 5;
					y--;
				}
				x++;
				put8Pixel(x + x0, y + y0);
				put8Pixel(x + x0, -y + y0);
				put8Pixel(-x + x0, y + y0);
				put8Pixel(-x + x0, -y + y0);
				delay(0);
			}
		}
		void init() {
			int x, y, color;
			struct arccoordstype a, b;
			initwindow(1280, 720);
			htMidPoint(300, 300, 250);
		}
};

class ScanLine {
	private:
		string name;
	
	public:
		#define MAXVERTEX 20
		#define MAXEDGE 20
		#define TRUE 1
		#define FALSE 0
		string getName() {
			name = "scan-line fill (to color theo dong quet)";
			return name;
		}
		
		typedef struct {
			int x;
			int y;
		} point;
		
		typedef struct {
			int NumVertex; //so dinh			
			point aVertex[MAXVERTEX];
		} POLYGON; //DA GIAC
		
		typedef struct {
			int NumPt;
			float xPt[MAXEDGE];
		} XINTERSECT; //DIEM GIAO
		
		typedef struct {
			int yMin; //Tung do nho cua 2 dinh cua 1 canh
			float xIntersect; //hoanh do giao diem cua canh va dong quet
			float dxPerScan; //=1/m (m la he so goc)
			int DeltaY; //khoang cach tu dong quet den tung do lon  nhat cua canh
		} EDGE;
		
		typedef struct {
			int NumEdge;
			EDGE aEdge[MAXEDGE];
		} EDGELIST;
		
		/*cac canh sap xep theo thu tu giam dan cua yMin (yMin la gia tri lon nhat cua 2 dinh 1canh)
		xu li luon truong hop dong quet di ngang qua dinh ma tai do chi tinh 1 diem giao*/
		void PutEdgeInList(EDGELIST &EdgeList, point p1, point p2, int NextY) {//dat 1canh vao danh sach canh
			EDGE EdgeTmp;
			EdgeTmp.dxPerScan = float(p2.x - p1.x)/(p2.y - p1.y); //1/m
			if(p1.y < p2.y) {
				/* truong hop dong quet di qua giao diem cua 2 canh co huong y cung tang */
				if(p2.y < NextY) {
					p2.y--;
					p2.x -= EdgeTmp.dxPerScan;
				}
				EdgeTmp.yMin = p1.y;
				EdgeTmp.xIntersect = p1.x;
				EdgeTmp.DeltaY = abs(p2.y - p1.y) + 1;
			}
			else {
				/* truong hop dong quet di qua giao diem cua 2 canh co huong y cung giam */
				if(p2.y > NextY) {
					p2.y++;
					p2.x += EdgeTmp.dxPerScan;
				}
				EdgeTmp.yMin = p2.y;
				EdgeTmp.xIntersect = p2.x;
				EdgeTmp.DeltaY = abs(p2.y - p1.y) + 1;
			}
			
			//xac dinh vi tri chen
			int j = EdgeList.NumEdge;
			while((j > 0) && (EdgeList.aEdge[j - 1].yMin > EdgeTmp.yMin)) {
				EdgeList.aEdge[j] = EdgeList.aEdge[j - 1];
				j--;
			}
			
			//tien hanh chen dinh moi vao canh
			EdgeList.NumEdge++;
			EdgeList.aEdge[j] = EdgeTmp;
		}
		
		/* Tim dinh ke tiep sao cho khong nam tren cung duong thang voi dinh dang xet */
		int FindNextY(POLYGON P, int id) {
			int j = (id + 1) % P.NumVertex;
			while((j < P.NumVertex) && (P.aVertex[id].y == P.aVertex[j].y))
				j++;
			if(j < P.NumVertex)
				return(P.aVertex[j].y);
			return 0;
		}
		
		//tao danh sasch cac canh tu da giac da cho
		void MakeSortedEdge(POLYGON P, EDGELIST &EdgeList, int &TopScan, int &BottomScan) {
			TopScan = BottomScan = P.aVertex[0].y;
			EdgeList.NumEdge = 0;
			for(int i = 0; i < P.NumVertex; i++) {
				//truong hop canh k phai la canh nam ngang
				if(P.aVertex[i].y != P.aVertex[i + 1].y)
					PutEdgeInList(EdgeList, P.aVertex[i], P.aVertex[i + 1], FindNextY(P, i + 1));
				if(P.aVertex[i + 1].y > TopScan)
					TopScan = P.aVertex[i + 1].y;
			}
			BottomScan = EdgeList.aEdge[0].yMin;
		}
		
		//cap nhat lai 2 con tro FirstId, LastId cho biet danh sach cac canh active (cac canh giao voi dong quet hien hanh)
		void UpdateActiveEdgeList(EDGELIST EdgeList, int yScan, int &FirstId, int &LastId) {
			while((FirstId < EdgeList.NumEdge - 1) && (EdgeList.aEdge[FirstId].DeltaY == 0))
				FirstId++;
			while((LastId < EdgeList.NumEdge - 1) && (EdgeList.aEdge[LastId].yMin <= yScan))
				LastId++;
		}
		
		void SortOnX(XINTERSECT & aIntersectPt) {
			for(int i = 0; i < aIntersectPt.NumPt - 1; i++) {
				int Min = i, t;
				for(int j = i + 1; j < aIntersectPt.NumPt; j++)
					if(aIntersectPt.xPt[j] < aIntersectPt.xPt[Min])
						Min = j;
					t = aIntersectPt.xPt[Min];
					aIntersectPt.xPt[Min] = aIntersectPt.xPt[i];
					aIntersectPt.xPt[i] = t;
			}
		}
		
		/* tim hoanh do giao diem cua cac canh cua da giac voi dong quet yScan.
			Sau khi tim xong sap xep theo chieu tang dan x*/
		void FindXIntersection(EDGELIST EdgeList, XINTERSECT &aIntersectPt, int FirstId, int LastId) {
			aIntersectPt.NumPt = 0;
			for(int i = FirstId; i <= LastId; i++) {
				if(EdgeList.aEdge[i].DeltaY > 0) {
						aIntersectPt.xPt[aIntersectPt.NumPt] = EdgeList.aEdge[i].xIntersect;
						aIntersectPt.NumPt++;
				}
			}
			SortOnX(aIntersectPt);
		}
		void FillLine(XINTERSECT aIntersectPt, int yScan) {
			for(int i = 0; i < aIntersectPt.NumPt; i+= 2)
				line(Round(aIntersectPt.xPt[i]), yScan, Round(aIntersectPt.xPt[i + 1]), yScan);
		}
		void UpdateEdgeList(EDGELIST &EdgeList, int FirstId, int LastId) {
			for(int i = FirstId; i <= LastId; i++) {
				if(EdgeList.aEdge[i].DeltaY > 0) {
					EdgeList.aEdge[i].DeltaY--;
					EdgeList.aEdge[i].xIntersect += EdgeList.aEdge[i].dxPerScan;
				}
			}
		}
		void ScanLineFill(POLYGON P) {
			EDGELIST EdgeList;
			XINTERSECT aIntersectPt;
			int TopScan, BottomScan, FirstId, LastId;
			MakeSortedEdge(P, EdgeList, TopScan, BottomScan);
			FirstId = LastId = 0;
			for(int i = BottomScan; i <= TopScan; i++) {
				// cap nhat lai danh sach cac canh active -cac canh cat dong quet i
				UpdateActiveEdgeList(EdgeList, i, FirstId, LastId);
				
				/* tim cac hoanh do giao diem voi dong quet voi cac canh
				va sap xep cac giao diem do truc tiep tren EdgeList*/
				FindXIntersection(EdgeList, aIntersectPt, FirstId, LastId);
				FillLine(aIntersectPt, i);
				UpdateEdgeList(EdgeList, FirstId, LastId);
				delay(0);
			}
		}
		void init()  {
			int x, y, color;
			struct arccoordstype a, b;
			
			initwindow(1280, 720);
			
			POLYGON p; 
			setcolor(BLUE); 
			p.NumVertex = 4 - 1; 
			
			//A
			p.aVertex[0].x = 200; 
			p.aVertex[0].y = 100; 
			
			//B
			p.aVertex[1].x = 100; 
			p.aVertex[1].y = 600; 
			
			//C
			p.aVertex[2].x = 1000; 
			p.aVertex[2].y = 600;
			
			//D
			p.aVertex[3].x = 900; 
			p.aVertex[3].y = 100;
			
			ScanLineFill(p);
		}
};

class BoundaryFill {
	private:
		string name;
	public:
	
		string getName() {
			name = "Boundary Fill (To color dua theo duong bien)";
			return name;
		}
		
		void floodFill(int x, int y, int f, int b)
		{
			if (getpixel(x, y) != f && getpixel(x, y) != b)
			{
			    putpixel(x ,y , f);
				floodFill(x - 1, y, f, b);
				floodFill(x, y + 1, f, b);
				floodFill(x + 1, y, f, b);
				floodFill(x, y - 1, f, b);
			}
		}
			 	
		void init()
		{
			initwindow(1280, 720);
			
			circle(300, 300, 118);
			floodFill(300, 300, 14, 15);
		}
};

class LineMidpoint {
	private:
		string name;
	public:
	
		string getName() {
			name = "Line Midpoint";
			return name;
		}
		
		void dtMid(int x1, int y1, int x2, int y2, int c) { 
			int x, y, dx, dy,d; 
			y = y1; 
			dx = x2 - x1; 
			dy = y2 - y1; 
			d= dy - dx/2; 
			for (x=x1; x<=x2; x++){ 
				putpixel(x, y, c);
				delay(0); 
				
				if (d <= 0) d = d + dy; 
				else { 
					y ++; 
				    d = d + dy - dx; 
				}
			}
		}
		
		void init() {
			initwindow(1280, 720);
			dtMid(100, 100, 1000, 600, LIGHTGREEN);
		}
};

class BresenhamCircle {
	
	private:
		string name;
	public:
	
		string getName() {
			name = "Circle Midpoint";
			return name;
		}
		
		int color = GREEN;
		void put8Pixel(int x, int y) {
			putpixel(x, y, color);
			putpixel(y, x, color);
			putpixel(y, -x, color);
			putpixel(x,-y,color);
			putpixel(-x, -y, color);
			putpixel(-y, -x, color);
			putpixel(-y,x,color);
			putpixel(-x, y, color);
		}
		void htBres(int x0, int y0, int r) {
			int x=0;
			int y=r;
			int p=3-2*r;
			put8Pixel(x,y);
			while(x < y) {
				if(p < 0) p = p + 4*x + 6;
				else {
					p = p + 4*(x-y) + 10;
					y--;
				}
				x++;
				put8Pixel(x+x0,y+y0);
				put8Pixel(x+x0,-y+y0);
				put8Pixel(-x+x0,y+y0);
				put8Pixel(-x+x0,-y+y0);
				delay(0);
			}
		}
		void init() {
			initwindow(1280, 720);
			htBres(300, 300, 250);
		}
};

class TiLe {
	private:
		string name;
	public:
	
		string getName() {
			name = "Phep ti le";
			return name;
		}
		
		typedef struct {
			int x;
			int y;
		} point;
		void draw(point &p1, point &p2, point &p3) {
			line(p1.x, p1.y, p2.x, p2.y);
			line(p1.x, p1.y, p3.x, p3.y);
			line(p2.x ,p2.y, p3.x, p3.y);
		}
		point scale(point p1, float hsx, float hsy) {
			point p;
			p.x = p1.x*hsx;
			p.y = p1.y*hsy;
			return p;
		}
		void init() {
			initwindow(1280, 720);
			
			point p1, p2, p3, A, B, C;
			float kc;

			p1.x = 600;
			p1.y = 50;
			p2.x = 350;
			p2.y = 300;
			p3.x = 800;
			p3.y = 300;
			setcolor(YELLOW);
			draw(p1, p2, p3);
			
			delay(1000);
			//Ti le
			A=scale(p1, 1, 2);
			B=scale(p2, 1, 2);
			C=scale(p3, 1, 2);
			setcolor(BLUE);
			draw(A, B, C);
		}
};

class TinhTien {
	private:
		string name;
	public:
	
		string getName() {
			name = "Phep tinh tien";
			return name;
		}
		
		typedef struct {
			int x;
			int y;
		}point;
		
		void draw(point &p1 ,point & p2, point & p3) {
			line(p1.x, p1.y, p2.x, p2.y);
			line(p1.x, p1.y, p3.x, p3.y);
			line(p2.x ,p2.y, p3.x, p3.y);
		}
		
		point tinhTien(point p1, float kcx, float kcy) {
			point p;
			p.x = p1.x+kcx;
			p.y = p1.y+kcy;
			return p;
		}
		
		void init() {
		initwindow(1280, 720);
		
		// Tam giac ban dau
		point p1, p2, p3, A, B, C;
		float kc;
		p1.x = 300;
		p1.y = 50;
		p2.x = 50;
		p2.y = 300;
		p3.x = 500;
		p3.y = 300;
		setcolor(GREEN);
		draw(p1, p2, p3);
		
		delay(1000);
		
		// Tam giac duoc tinh tien
		A = tinhTien(p1, 400, 200);
		B = tinhTien(p2, 400, 200);
		C = tinhTien(p3, 400, 200);
		setcolor(YELLOW);
		draw(A, B, C);
	}
};

class Quay {
	private:
		string name;
	public:
	
		string getName() {
			name = "Phep quay";
			return name;
		}
		
		void TriAngle(int x1,int y1,int x2,int y2,int x3,int y3) {
		   line(x1,y1,x2,y2);
		   line(x2,y2,x3,y3);
		   line(x3,y3,x1,y1);
		}
		void Rotate(int x1,int y1,int x2,int y2,int x3,int y3) {
		    int x,y,a1,b1,a2,b2,a3,b3,p=x2,q=y2;
		    float Angle = 60;
		    
		    Angle=(Angle*3.14)/180;
		    a1=p+(x1-p)*cos(Angle)-(y1-q)*sin(Angle);
		    b1=q+(x1-p)*sin(Angle)+(y1-q)*cos(Angle);
		    a2=p+(x2-p)*cos(Angle)-(y2-q)*sin(Angle);
		    b2=q+(x2-p)*sin(Angle)+(y2-q)*cos(Angle);
		    a3=p+(x3-p)*cos(Angle)-(y3-q)*sin(Angle);
		    b3=q+(x3-p)*sin(Angle)+(y3-q)*cos(Angle);
		    TriAngle(a1,b1,a2,b2,a3,b3);
		}
		void init() {
			
			initwindow(1280, 720);
			
		    int x1 = 500, y1 = 50, x2 = 300, y2 = 250, x3 = 700, y3 = 250;
		    
		    TriAngle(x1,y1,x2,y2,x3,y3);
		    
		    delay(1000);
		    
		    cleardevice();
		    
		    Rotate(x1,y1,x2,y2,x3,y3);
		    
		    setcolor(BLUE);
		    TriAngle(x1,y1,x2,y2,x3,y3);
		}
};

class CohenSutherland {
	private:
		string name;
	public:
	
		string getName() {
			name = "Cohen - Sutherland";
			return name;
		}
		
		void cohen(int x1,int y1,int x2,int y2,int xa, int ya, int xb,int yb) {
			int a[4],b[4],i,kthuc=0;
			while(kthuc==0) { 
		    	delay(10);
		    	a[1]=a[2]=a[3]=a[4]=0; 
		    	if(xa<x1) a[1]=1; 
		    	if(xa>x2) a[2]=1; 
		    	if(ya<y1) a[3]=1; 
		    	if(ya>y2) a[4]=1;
		    	b[1]=b[2]=b[3]=b[4]=0; 
		    	if(xb<x1) b[1]=2; 
		    	if(xb>x2) b[2]=2; 
		    	if(yb<y1) b[3]=2; 
		    	if(yb>y2) b[4]=2;
		    	int ktra=0;
		    	for(i=1;i<=4;i++) { 
				    if( (a[i]==1) || (b[i]==1) ) ktra=1; 
				}
				if(ktra==0) {
			     setcolor(10);
			     line(xa,ya,xb,yb);
			     kthuc=1;
			 	}
				else {
			       int ktra1=1;
			    	for(i=1;i<=4;i++) {
				    	if( (a[i]==1) && (b[i]==1) ) ktra1=0;
					}
			    	if(ktra1==0) {kthuc=1;}
					else {
				    	if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0) {
					    	for(i=1;i<=4;i++) {
						   		int tg1=a[i];a[i]=b[i];b[i]=tg1;
							}
							int tg2=xa;xa=xb;xb=tg2;
							int tg3=ya;ya=yb;yb=tg3;
						} 
				    	if(a[1]==1) {
					    	ya=(yb-ya)*(x1-xa)/(xb-xa)+ya; 
					    	xa=x1; //cout<<xa<<" "<<ya<<endl; 
						}
						if(a[2]==1) {
							ya=(yb-ya)*(x2-xa)/(xb-xa)+ya; 
							xa=x2;  
						}
				   		if(a[3]==1) { 
							xa=(xb-xa)*(y1-ya)/(yb-ya)+xa; 
							ya=y1; 
						}
				   		if(a[4]==1) {
							xa=(xb-xa)*(y2-ya)/(yb-ya)+xa; 
					   		ya=y2; 
						} 
					} 
				}
			} 
		}
		void init() {
			initwindow(1280, 720);
		   
			setcolor(GREEN);
			rectangle(100, 100, 600, 600);
			setcolor(YELLOW);
			cohen(100, 100, 600, 600, 150, 100, 300, 300);
		}
};

class LiangBarsky {	
	private:
		string name;

	public:
		#define ROUND(a)((int)(a+0.5))
		string getName() {
			name = "Liang - Barsky";
			return name;
		}
		
		int cliptest(float p,float q,float *u1,float *u2) {
		    float r;
		    int retval=1;
		    if(p<0.0) {
		    	r=q/p;
		        if(r>*u2)
		        retval=0;
		        if(r>*u1)
		            *u1=r;
		    }
		    else if(p>0.0) {
		    	r=q/p;
		        if(r<*u1) retval=0;
		        if(r<*u2) *u2=r;
		    }
		    else if(q<0.0)
		        retval=0;
		        return(retval);
		}
		void clipline(int minx,int miny,int maxx,int maxy,int x1,int y1,int x2,int y2) {
		    float u1=0.0,u2=1.0,dx=x2-x1,dy;
		    if(cliptest(-dx,x1-minx,&u1,&u2))
		    if(cliptest(dx,maxx-x1,&u1,&u2)) {
		    	dy=y2-y1;
		        if(cliptest(-dy,y1-miny,&u1,&u2))
		            if(cliptest(dy,maxy-y1,&u1,&u2)) {
		                if(u2<1.0) {
		                    x2=x1+u2*dx;
		                    y2=y1+u2*dy;
		                }
		                if(u1>0.0) {
		                    x1+=u1*dx;
		                    y1+=u1*dy;
		                }
		                line(x1,y1,x2,y2);
		            }
		    }
		}
		void init() {
            
            int x1 = 50, y1 = 50, x2 = 1000, y2 = 600,
				minx = 100, miny = 100, maxx = 600, maxy = 600;
            
			initwindow(1280, 720);
            
            // Cac bo phan ban dau
            setcolor(BLUE);
            line(x1,y1,x2,y2);
            rectangle(minx,maxy,maxx,miny);
            
			delay(1000);
			
			// Phan view nhin thay
            setcolor(YELLOW);
            clipline(minx,miny,maxx,maxy,x1,y1,x2,y2);
            rectangle(minx,maxy,maxx,miny);
		}
};

class SutherlandHodgeman {
	private:
		string name;

	public:

		#define round(a) ((int)(a+0.5))
		
		string getName() {
			name = "Sutherland - Hodgeman";
			
			return name;
		}
		
		int k;
		float xmin = 50, ymin = 50, xmax = 600, ymax = 600, arr[20], m;
		void clipl(float x1,float y1,float x2,float y2) {
			
			if(x2-x1)
			m=(y2-y1)/(x2-x1);
			if(x1>=xmin && x2>=xmin) {
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(x1<xmin && x2>=xmin) {
				arr[k]=xmin;
				arr[k+1]=y1+m*(xmin-x1);
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(x1>=xmin  && x2<xmin) {
				arr[k]=xmin;
				arr[k+1]=y1+m*(xmin-x1);
				k+=2;
			}
		}
		
		void clipt(float x1,float y1,float x2,float y2) {
			if(y2-y1)
			m=(x2-x1)/(y2-y1);
			if(y1<=ymax && y2<=ymax) {
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(y1>ymax && y2<=ymax) {
				arr[k]=x1+m*(ymax-y1);
				arr[k+1]=ymax;
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(y1<=ymax  && y2>ymax) {
				arr[k]=x1+m*(ymax-y1);
				arr[k+1]=ymax;
				k+=2;
			}
		}
		
		void clipr(float x1,float y1,float x2,float y2) {
			if(x2-x1)
			m=(y2-y1)/(x2-x1);
			if(x1<=xmax && x2<=xmax) {
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(x1>xmax && x2<=xmax)	{
				arr[k]=xmax;
				arr[k+1]=y1+m*(xmax-x1);
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(x1<=xmax  && x2>xmax) {
				arr[k]=xmax;
				arr[k+1]=y1+m*(xmax-x1);
				k+=2;
			}
		}
		
		void clipb(float x1,float y1,float x2,float y2) {
			if(y2-y1)
			m=(x2-x1)/(y2-y1);
			if(y1>=ymin && y2>=ymin) {
				arr[k]=x2;
				arr[k+1]=y2;
				k+=2;
			}
			if(y1<ymin && y2>=ymin) {
				arr[k]=x1+m*(ymin-y1);
				arr[k+1]=ymin;
				arr[k+2]=x2;
				arr[k+3]=y2;
				k+=4;
			}
			if(y1>=ymin  && y2<ymin) {
				arr[k]=x1+m*(ymin-y1);
				arr[k+1]=ymin;
				k+=2;
			}
		}
		
		void init() {
			int n = 3, poly[20], i;
			float xi, yi, xf, yf, polyy[] = {100, 550, 500, 100, 1000, 550};
			
			initwindow(1280, 720);
			
			polyy[i] = polyy[0];
			polyy[i + 1] = polyy[1];
			
			for(i=0; i < 2*n+2 ; i++) {
				poly[i] = round(polyy[i]);
			}
			
			rectangle(xmin, ymax, xmax, ymin);
			fillpoly(n, poly);
			
			delay(1000);

			cleardevice();
			
			k = 0;
			for(i=0; i < 2*n; i += 2)
			clipl(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
			n = k/ 2;
			for(i=0; i < k; i++)
			polyy[i] = arr[i];
			polyy[i] = polyy[0];
			polyy[i + 1] = polyy[1];
			
			k=0;
			for(i=0; i < 2*n; i += 2)
			clipt(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
			n = k / 2;
			for(i=0; i < k; i++)
			polyy[i] = arr[i];
			polyy[i] = polyy[0];
			polyy[i + 1] = polyy[1];
			
			k=0;
			for(i=0; i < 2*n; i += 2)
			clipr(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
			n=k/2;
			for(i=0; i < k; i++)
			polyy[i] = arr[i];
			polyy[i] = polyy[0];
			polyy[i + 1] = polyy[1];
			
			k=0;
			for(i=0; i < 2*n; i += 2)
			clipb(polyy[i], polyy[i + 1], polyy[i + 2], polyy[i + 3]);
			for(i = 0; i < k; i++)
			poly[i] = round(arr[i]);
			if(k) fillpoly(k/2,poly);
			
			rectangle(xmin, ymax, xmax, ymin);
			
		}
};

class Bezier {
	private:
		string name;

	public:

		#define NPOINTS 7
		
		string getName() {
			name = "Bezier";
			return name;
		}
		
		struct xycoord {
		  double xcoord, ycoord;
		};
		 
		 /* Tra ve gia tri Factorial cua q (q!) */
		double fact(int q)
		{
		  int f=1, c;
		    for (c=q; c>1; c--)
		      f *= c;
		    return (f);
		}
		 
		double C(int n, int i)
		{
		  return (fact(n) / (fact(i) * fact(n-i)));
		}
		 
		double blend(int i, int n, double u, double binomial)
		{
		  double partial;
		  int j;
		 
		  partial = binomial;
		  for (j=1; j<= i; j++)
		    partial *= u;
		  for (j=1; j<= (n-i); j++)
		    partial *= (1.0 - u);
		  return partial;
		}
		 
		void BezierFcn (double *x, double *y, double u, double coeff[],
		           		int n, struct xycoord p[])
		{
		  int i;
		  double b;
		 
		  *x = *y = 0;
		  for (i=0; i<=n; i++)
		  {
		    b = blend (i, n, u, coeff[i]);
		    *x += (b * p[i].xcoord);
		    *y += (b * p[i].ycoord);
		  }
		}
		 
		void drawBezier(struct xycoord p[], int npts, int segments)
		{
		  int i, oldx, oldy;
		  double u, x, y;
		  double coeff[20];
		 
		  for (i=0; i<npts; i++)
		    coeff[i] = C(npts-1, i);
		 
		  for (i=0; i<=segments; i++)
		  {
		    u = (double) i / segments;
		    BezierFcn(&x, &y, u, coeff, npts - 1, p);
		    if (i==0)
		    {
		      moveto(x, y);
		      oldx = x;
		      oldy = y;
		    }
		    else
		    {
		      lineto(x, y);
		      oldx = x;
		      oldy = y;
		    }
		  }
		}
	
		int init() {
			struct xycoord pt[] = { {300, 500}, {100, 300}, {300, 100},
									{500, 300}, {800, 500}, {1000, 300},
									{800, 100}};
			int order[] = {0, 1, 2, 3, 4, 5, 6};
			initwindow(1280, 720);
			setcolor(LIGHTGREEN);
			
			drawBezier(pt, NPOINTS, 40);
		}
};

///////////////////////////////////

// CAC THUAT TOAN

// NEW: Khai bao thuat toan

DDA dda;
Bresenham bres;
MidPoint midP;
ScanLine scanLine;
BoundaryFill boundaryFill;
LineMidpoint LineMidpoint;
BresenhamCircle circleBresenham;
TiLe tiLe;
TinhTien tinhTien;
Quay quay;
CohenSutherland cohenSutherland;
LiangBarsky liangBarsky;
SutherlandHodgeman sutherlandHodgeman;
Bezier bezier;

///////////////////////////////////

// EDIT: Khoi tao cac thuat toan
void initAlgorithm(string index) {
	SelectAl:
	setTextColor(BLUE, "Chuong trinh so: ");
	cin >> index;
	int i = atoi(index.c_str());
	
	switch (i)
		{
			// Khoi tao cac thuat toan
			// NEW: Khoi tao them thuat toan duoi day
			
			case 1: 
				
				dda.init();
				endAlgorithm();
				break;
				
			case 2:
			 	bres.init();
			 	endAlgorithm();
				break;
				
			case 3:
			 	midP.init();
			 	endAlgorithm();
				break;
				
			case 4:
			 	scanLine.init();
			 	endAlgorithm();
				break;
				
			case 5:
			 	boundaryFill.init();
				endAlgorithm();
				break;
			
			case 6:
				LineMidpoint.init();
				endAlgorithm();
				break;
			
			case 7:
				circleBresenham.init();
				endAlgorithm();
				break;
			
			case 8:
				tiLe.init();
				endAlgorithm();
				break;
				
			case 9:
				tinhTien.init();
				endAlgorithm();
				break;
				
			case 10:
				quay.init();
				endAlgorithm();
				break;
				
			case 11:
				cohenSutherland.init();
				endAlgorithm();
				break;
			
			case 12:
				liangBarsky.init();
				endAlgorithm();
				break;
				
			case 13:
				sutherlandHodgeman.init();
				endAlgorithm();
				break;
				
			case 14:
				bezier.init();
				endAlgorithm();
				break;
			
			///////////////////////////////////
			
			default: 
				setTextColor(LIGHTRED, "Ban da nhap khong chinh xac. Vui long nhap lai!\n\n");
				goto SelectAl;
				break;
		}
}

// EDIT
void algorithms() {
	string index;
	
	setTextColor(BLUE, "\nHay nhap so chuong trinh duoi day: \n\n");
	
	string options =
	
			//NEW: Them thuat toan vao dong hien thi
			
		   + " 1. " + dda.getName() + ".\n"
		   + " 2. " + bres.getName() + ".\n"
		   + " 3. " + midP.getName() + ".\n"
		   + " 4. " + scanLine.getName() + ".\n"
		   + " 5. " + boundaryFill.getName() + ".\n"
		   + " 6. " + LineMidpoint.getName() + ".\n"
		   + " 7. " + circleBresenham.getName() + ".\n"
		   + " 8. " + tiLe.getName() + ".\n"
		   + " 9. " + tinhTien.getName() + ".\n"
		   + "10. " + quay.getName() + ".\n"
		   + "11. " + cohenSutherland.getName() + ".\n"
		   + "12. " + liangBarsky.getName() + ".\n"
		   + "13. " + sutherlandHodgeman.getName() + ".\n"
		   + "14. " + bezier.getName() + ".\n"
		   
		   ///////////////////////////////////
		   
		   + "\n";
	setTextColor(LIGHTBLUE, options);
	
	initAlgorithm(index);
}

char Continue(string con) {
	Continue:
	setTextColor(BLUE, "\nBan co muon tiep tuc? (c: co; k: khong)\n");
	cin >> con;
	char c = con.at(0);
	
	if (c != 'c' && c != 'k')
	{
		setTextColor(RED, "Cau tra loi khong hop le!\n");
		goto Continue;
	}
	return c;
}

void init() {
	
	//Title
	setTextColor(LIGHTRED, "CHUONG TRINH DO HOA\n");
	
	string con = "c";
	char c = con.at(0);
	do
	{
		algorithms();
		
		c = Continue(con);
	}
	while(c == 'c');
	
	setTextColor(YELLOW, "\nGood bye!\n\n");
}

void endProgram() {
	cout << "===========================================" << endl;
	system("pause");
}

int main()
{
	// EDIT: Mo console va dat kich thuoc
	
	setWindowAndTitle(35); // Edit: Chi thay doi doi so
	
	///////////////////////////////////

	init();
	
	// EDIT: Giu console khi chi chay file .exe
	
	//	endProgram(); // Edit: Co the comment.
	
	///////////////////////////////////
	
	return 0;
}
