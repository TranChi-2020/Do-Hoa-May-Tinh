#include<graphics.h>
#include <bits/stdc++.h>

using namespace std;

float a, b , c, d, Min, Max;

int round(float x)
{
	
	if(x > 0) return int(x + 0.5);
	else return int(x - 0.5);
}

float X(float a, int r)
{
	
	return r * cos(a * M_PI / 180);
}

float Y(float a,int r)
{
	
	return r * sin(a * M_PI / 180);
}

void Sector(int x0, int y0, int g1, int g2, int Rx,int Ry)
{
	
	int x1, y1, x2, y2;
	float x, dx, k;
	dx = 6;
	x = g1;
	setcolor(14);
	x1 = x0 + round(X(x, Rx));
	y1 = y0 - round(Y(x, Ry));
	moveto(x1, y1);
	
	while(x < g2)
	{
		
		x += dx;
		x2 = x0 + round(X(x, Rx));
		y2 = y0 - round(Y(x, Ry));
		lineto(x2, y2);
	}
}

int main()
{
	
	initwindow(500, 500);
	Min = 0;
	Max = 180;
	int x0 = 200, y0 = 200, r = 100;
	float _min = 0, _max = 180;
	Sector(200,200,0,180,100,50);
	getch();
	closegraph();
	return 0;
} 

