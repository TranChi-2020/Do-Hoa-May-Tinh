#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;

struct ToaDo{
	int x, y;
};

void HoTen(){
	settextstyle(0,0,2);
	setcolor(BLUE);
	outtextxy(getmaxx()- 300, 50,"Tran Liem Chi");
}

void VeHinh(ToaDo A, ToaDo B, ToaDo C, ToaDo D, ToaDo E, ToaDo F){
	line(A.x,A.y,B.x,B.y);
	line(B.x,B.y,C.x,C.y);
	line(C.x,C.y,A.x,A.y);
	line(E.x,E.y,F.x,F.y);
	line(E.x,E.y,D.x,D.y);
	line(A.x,A.y,D.x,D.y);
	line(B.x,B.y,F.x,F.y);
	line(C.x,C.y,E.x,E.y);
}

int main()
{

	initwindow(800, 600);
	HoTen();
	ToaDo A,B,C,D,E,F;
	A.x = 100; 
	A.y = 100; 
	B.x = 200; 
	B.y = 100; 
	C.x = 150; 
	C.y = 150; 
	D.x = 100; 
	D.y = 200; 
	E.x = 150; 
	E.y = 250; 
	F.x = 200; 
	F.y = 200; 
	VeHinh(A,B,C,D,E,F);
	getch();
	closegraph();
}
