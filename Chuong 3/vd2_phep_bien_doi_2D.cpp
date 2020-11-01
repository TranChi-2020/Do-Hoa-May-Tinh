#include <conio.h>
#include <math.h>
#include <graphics.h>
#define PI 3.1416
struct ToaDo {
	float x, y;
	float k;
};


int round (float x){
	if (x>0) return int (x+0.5);
	else return int (x-0.5);
}
void thietlapdohoa (){
	int mh = 0, mode = 0; 
	initgraph (&mh, &mode, "d:\\TC\\bgi");
}
void vetruc (int x0, int y0){
	line (0, y0 , 2*x0,y0);
	line (x0, 0, x0, 2*x0);
}
void vehinh (ToaDo p1, ToaDo p2, ToaDo p3, int x0, int y0, int k){
	line (x0+round(p1.x*k), y0- round(p1.y*k),
	       x0+round(p2.x*k), y0-round(p2.y*k));
	line (x0+round(p2.x*k), y0- round(p2.y*k),
	       x0+round(p3.x*k), y0-round(p3.y*k));
	line (x0+round(p3.x*k), y0- round(p3.y*k),
	       x0+round(p1.x*k), y0-round(p1.y*k));
}
void QuayDiem (ToaDo p, float alpha, ToaDo &pmoi){
	pmoi.x = p.x*cos(alpha) - p.y*sin(alpha);
	pmoi.y = p.x*sin(alpha) + p.y*cos(alpha);
}
void QuayHinh (ToaDo p1, ToaDo p2, ToaDo p3, float alpha, ToaDo &p1moi, ToaDo &p2moi, ToaDo &p3moi){
	QuayDiem (p1, alpha, p1moi);
	QuayDiem (p2, alpha, p2moi);
	QuayDiem (p3, alpha, p3moi);
}
 main (){
 	int x0, y0;
 	float k;
	float goc, alpha;
	char ch;
	ToaDo p, pp, ppp, p1, p2, p3;
	thietlapdohoa ();
	k = getmaxy () / 30;
	x0 = getmaxx () / 2;
	y0 = getmaxy () / 2;
	vetruc (x0, y0);
	p.x = 5; p.y = 3; pp.x = 2;pp.y = 6; ppp.x = 6; ppp.y = -4;
	p1 = p; p2 = pp; p3 = ppp;
	goc = PI/180 ; alpha = 0;
	setwritemode (XOR_PUT);
	vehinh (p1, p2, p3,x0,y0,k);
	do {
		ch = getch ();
		switch (ch)
		{
			case 75:
				vehinh (p1, p2,p3,x0,y0,k);
				  alpha = alpha + goc;
				  
		    QuayHinh(p,pp,ppp,alpha,p1,p2,p3);
		           vehinh (p1, p2,p3,x0,y0,k);
		           break;
		    case 77:
				vehinh (p1, p2,p3,x0,y0,k);
				  alpha = alpha - goc;
				  
		    QuayHinh(p,pp,ppp,alpha,p1,p2,p3);
		           vehinh (p1, p2,p3,x0,y0,k);
		           break;
		}
	} while (ch!=27);
	closegraph ();
}
