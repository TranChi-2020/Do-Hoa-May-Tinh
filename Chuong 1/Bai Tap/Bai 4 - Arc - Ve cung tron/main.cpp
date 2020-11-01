#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
	
	int x,y, Angle;
	Point(int x = 0, int y = 0, int Angle = 0) 
  	{
  		
  		this -> x = x; 
		this -> y =  y; 
		this -> Angle =  Angle;
	}
	
  	void Draw(int Color)
    {
    	
        putpixel(x, y, Color);
    }
};
 
int Angle(int x, int y)
{
	
    return (int) (atan((float) y / x) * 180 / M_PI);
}
 
void TinhToan(int x0, int y0, int r, Point a[], int &n)
{
	
    int x,y; 
	float p = 3 - 2*r;
    Point temp[500]; 
	y = 0; 
	x = r; 
	n = 0;
 
    while (y <= x)
    {
    	
        temp[n++] = Point(x, y , Angle(x,y));
        if (p < 0) p = p + 2 * (2*y + 3);
        else
        {
        	
            p = p + 4 * (1-x) + 2 * (2*y + 3);
            x -= 1;
        }
        
        y += 1;
    }
    
    temp[n++] = Point(x, y, 90 - Angle(x,y));
 
    for (int k = 0; k < n; k++)
    {
    	
            a[k]       = Point(x0 + temp[k].x, y0 - temp[k].y, temp[k].Angle);
            a[2*n-1-k] = Point(x0 + temp[k].y, y0 - temp[k].x, 90 - temp[k].Angle);
            a[2*n+k]   = Point(x0 - temp[k].y, y0 - temp[k].x, 90 + temp[k].Angle);
            a[4*n-1-k] = Point(x0 - temp[k].x, y0 - temp[k].y, 180 - temp[k].Angle);
            a[4*n+k]   = Point(x0 - temp[k].x, y0 + temp[k].y, 180 + temp[k].Angle);
            a[6*n-1-k] = Point(x0 - temp[k].y, y0 + temp[k].x, 270 - temp[k].Angle);
            a[6*n+k]   = Point(x0 + temp[k].y, y0 + temp[k].x, 270 + temp[k].Angle);
            a[8*n-1-k] = Point(x0 + temp[k].x, y0 + temp[k].y, 360 - temp[k].Angle);
    }
    
    n = 8*n;
}
void Arc(int x0, int y0, int g1, int g2, int r, int Color)
{
	
    Point a[1000]; int n, k;
    TinhToan(x0, y0, r, a, n);
 
    if (g1 >= 360) {g1 %= 360; g2 %= 360;}
    if (g2 > 360)
    {
    	
        g2 %= 360;
        
        for (k = 0; k < n; k++)
            if (g1 <= a[k].Angle && a[k].Angle <= 360) a[k].Draw(Color);
            
        for (k = 0; k < n; k++)
            if (a[k].Angle <= g2) a[k].Draw(Color);
    }
    else
        for (k = 0; k < n; k++)
           if (g1<=a[k].Angle && a[k].Angle <= g2) a[k].Draw(Color);
}
 
int main()
{
    int g = DETECT,gmode;
    initgraph(&g,&gmode, "");
	Arc(getmaxx()/2,getmaxy()/2,60,360,100,YELLOW);  
    getch();
    closegraph();
    return 0;
}
