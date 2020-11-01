#include <graphics.h>
#include <conio.h>
#include <bits/stdc++.h>
#define mau1 15
#define mau2 8
#define maumn 7
#define XTop 200
#define YTop 100
#define Dy 32
#define Dx 250
using namespace std;
int SoDong;
float a,b,c,d,min,max;
void KhoiTaoDohoa() 
{ 
    int gd=0,gm; 
    initgraph(&gd,&gm,""); 
} 
void Baitap0()
{
	cleardevice();
	outtext("Tran Liem Chi");
	getch();
}

// ve
struct ToaDo{
	int x,y;
};

void VietHoTen(){
	settextstyle(0,0,2);
	setcolor(YELLOW);
	outtextxy(getmaxx() - 500, getmaxy()-50, "Tran liem chi");
}


void Baitap1()
{
	cleardevice();
	int gd,gm;
	initgraph(&gd,&gm, "C://TC//BGI");
	VietHoTen();
	setwritemode(XOR_PUT);
	ToaDo A,B,C,D,E,F,G;
	A.x = 100;
	A.y = 200;
	B.x = 200;
	B.y = 200;
	C.x = 200;
	C.y = 100;
	D.x = 100;
	D.y = 100;
	E.x = 250;
	E.y = 150;
	F.x = 250;
	F.y = 50;
	G.x = 150;
	G.y = 50;
	VeHinh(A,B,C,D,E,F,G);
	ToMauBCFE(B,C,F,E);
	DiChuyenABCD(A,B,C,D, E,F,G);
	getch();
}


void Baitap2()
{
	cleardevice();
	
	getch();
}


void Baitap3()
{
	cleardevice();
	getch();
}
void Box(int x1,int y1,int x2,int y2,int MauVienTren,int MauVienDuoi,int MauNen)
{
   setfillstyle(1,MauNen);
   bar(x1,y1,x2,y2);
   setcolor(MauVienTren);
   for(int i=0;i<=1;i++)
   {
       moveto(x1-i,y2+i);
       lineto(x1-i,y1-i);
       lineto(x2+i,y1-i);
   }

   setcolor(MauVienDuoi);
   for(int i=0;i<=1;i++)
   {
      moveto(x2+i,y1-i);
      lineto(x2+i,y2+i);
      lineto(x1-i,y2+i);
   }
}

void Ve_menu(int Xdau,int Ydau,int DeltaX,int DeltaY,int chon,int SoDong, char *DongMN[])
{
	setbkcolor(0);
	cleardevice();
   	for (int i=0;i<SoDong;i++)
	{
       if (i==chon) Box(Xdau,Ydau+i*DeltaY+6,Xdau+DeltaX,Ydau+i*DeltaY+DeltaY,mau2,mau1,maumn);
       else Box(Xdau,Ydau+i*DeltaY+6,Xdau+DeltaX,Ydau+i*DeltaY+DeltaY,mau1,mau2,maumn);
       outtextxy(Xdau+20,Ydau+15+i*DeltaY,DongMN[i]);
	}
}

main()
{
  char ch,*st[20];

  st[0]="Viet ten ";
  st[1]="Ve hinh"; // abcdefg
  st[2]="To mau"; // to mau
  st[3]="Di Chuyen";
  int x0=25,y0=5,chon=0,luuchon,sodong=4,ok=FALSE;
  KhoiTaoDohoa();
  settextstyle(0,0,2);
//  Ve_menu(x0,y0,chon,sodong,st);
  Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
  do
  {
  ch=getch(); //Nhan mot phim
  switch (ch)
	{
		case 72: //phim len
			luuchon=chon;
			chon--;
			if(chon<0) chon=sodong-1;
            Box(XTop,YTop+luuchon*Dy+6,XTop+Dx,YTop+luuchon*Dy+Dy,mau1,mau2,maumn);
            outtextxy(XTop+20,YTop+15+luuchon*Dy,st[luuchon]);
            Box(XTop,YTop+chon*Dy+6,XTop+Dx,YTop+chon*Dy+Dy,mau2,mau1,maumn);
            outtextxy(XTop+20,YTop+15+chon*Dy,st[chon]);
			break;
		case 80://phim xuong
			luuchon=chon;
			chon++;
			if(chon==sodong) chon=0;
            Box(XTop,YTop+luuchon*Dy+6,XTop+Dx,YTop+luuchon*Dy+Dy,mau1,mau2,maumn);
            outtextxy(XTop+20,YTop+15+luuchon*Dy,st[luuchon]);
            Box(XTop,YTop+chon*Dy+6,XTop+Dx,YTop+chon*Dy+Dy,mau2,mau1,maumn);
            outtextxy(XTop+20,YTop+15+chon*Dy,st[chon]);
			break;
		case 13: //phim ENTER
		ok=TRUE; break;
	}
	if (ok==TRUE) //Neu phim ENTER duoc nhan
	{
	  switch (chon)
		{
		 case 0:
			Baitap0();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 1:
			Baitap1();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 2:
			Baitap2();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		case 3:
			Baitap3();
			Ve_menu(XTop,YTop,Dx,Dy,chon,sodong,st);
			break;
		 case 4: exit(0);
		}
	  ok=FALSE; //tra lai trang thai ENTER chua duoc nhan
	}
  }
  while (ch!=27);//Nhan phim ESC de thoat khoi chuong trinh
}
