#include <conio.h>
#include <iostream>
#include <math.h>
#include <graphics.h>
#define Step 5;
using namespace std;
void thietlapdohoa(){
	int gd = 0, gm;
	initgraph(&gd,&gm,"d:\\TC\\bgi");
}
void vehinh (int x0, int y0){
	rectangle (x0, y0, x0 + 50, y0 + 30);
}
 main (){
	int x0, y0;
	char ch;
	thietlapdohoa();
	x0 = getmaxx()/2;
	y0 = getmaxy()/2;
	setwritemode(XOR_PUT);
	vehinh (x0, y0);
	do { ch = getch ();
	switch (ch){
		case 75 : //phim 
		   vehinh (x0, y0);
		      x0 -= Step;
		      vehinh (x0, y0);
		      break;
	    case 77: 
	        vehinh (x0, y0);
	          x0 += Step;
	          vehinh (x0,y0);
	          break;
	    case 72: 
		    vehinh (x0, y0);
			  y0 -= Step;
			  vehinh (x0, y0);
			  break;
	    case 80:
		    vehinh (x0,y0);
			  y0 += Step;
			  vehinh (x0, y0);
			  break;      
	}
		
	} 
	while(ch!= 27);
	closegraph ();
}
