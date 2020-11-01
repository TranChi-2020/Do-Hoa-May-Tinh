#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

struct ToaDo2D
{
	
	int x;
	int y;
};

void Input(ToaDo2D P[], int n)
{
	
	for(int i = 0; i < n; i++)
	{
		ToaDo2D	b;
		cin >> b.x;
		cin >> b.y;
		P[i] = b;
	}
}

// ve 8 diem
void DrawPoint(int x0, int y0, int x, int y, int Color)
{
	
	putpixel(x0 + x,y0 + y, Color);
	putpixel(x0 - x,y0 + y, Color);
	putpixel(x0 + x,y0 - y, Color);
	putpixel(x0 - x,y0 - y, Color);
	putpixel(x0 + y,y0 + x, Color);
	putpixel(x0 - y,y0 + x, Color);
	putpixel(x0 + y,y0 - x, Color);
	putpixel(x0 - y,y0 - x, Color);	
}

void DrawCircle(int x0, int y0, int R)
{
	
	int x = 0;
	int y = R;
	int P = 3 - 2*R;
	
	while(x <= y)
	{
		
		DrawPoint(x0, y0, x, y, YELLOW);
		
		if(P < 0)
		{
			P = P  + 4*x+6;
		}
		else
		{
			P = P + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

void DrawPoly(ToaDo2D P[], int n, int xc, int yc, int R)
{
	
	for(int i = 0 ;i < n - 1; i++)
	{
		line(P[i].x, P[i].y, P[i+1].x, P[i+1].y);
	}
	line(P[n-1].x, P[n-1].y, P[0].x, P[0].y);
	DrawCircle(xc, yc, R);
}

int Radius(int n, float a){
	float radius = a / (2 * sin (M_PI / n));
	return round(radius);
}

ToaDo2D Center(ToaDo2D p[], int n)
{
	
	int sumX = 0;
	int sumY = 0;
	for(int i = 0 ; i < n ; i++)
	{
		sumX += p[i].x;
		sumY += p[i].y;
	}
	ToaDo2D center;
	center.x = sumX / n;
	center.y = sumY / n;
	return center;
}

int main()
{
	
	int n;
	cin >> n; 
	ToaDo2D P[1000];
	Input(P,n); 
	float a = sqrt((P[1].x - P[0].x)*(P[1].x - P[0].x)+(P[1].y - P[0].y)*(P[1].y - P[0].y)); 
	ToaDo2D center = Center(P,n); 
	int radius = Radius(n,a); 
	int gd,gm;
	initgraph(&gd,&gm,""); 
	DrawPoly(P,n,center.x,center.y,radius);
	getch();
	closegraph();
	return 0;
}

