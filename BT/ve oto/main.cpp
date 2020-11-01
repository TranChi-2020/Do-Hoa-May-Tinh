#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

/***** VE DUONG THANG ****/

// Ve duong doc (// 0y)

void Line_OY(int y1, int y2, int x,int c){
  for(int y=y1;y<=y2;y++)
   putpixel(x,y,c);
 }

// Ve duong ngang (// 0x)
void Line_OX(int x1, int x2, int y,int c){
for(int x=x1;x<=x2;x++)
   putpixel(x,y,c);
}

// Bresenham_Line
void Bre_Line(int x1, int y1, int x2, int y2, int c)
{
   int x, y, dx, dy,p,const1,const2;
   y = y1;
  dx = x2 - x1;
  dy = y1 - y2;
  p = 2*dy - dx;
  const1 = 2*dy;
  const2 = 2*(dy-dx);
  for (x=x1; x<=x2; x++) {
   putpixel(x, y, c);
   if (p<0)
     p += const1; // p=p + 2dy
   else {
     p +=const2; //p=p+2dy-2dx
     y--;
  }
 }
}

// ve duong than voi Midpoint
void Mid_line(int x1, int y1, int x2, int y2, int c)
{
  int x, y, dx, dy,d;
  y = y1;
  dx = x2 - x1;
  dy = y2 - y1;
  d= dy - dx/2;
  for (x=x1; x<=x2; x++)
  {
    putpixel(x, y, c);
    if (d <= 0)
      d = d + dy;
    else
   {
      y ++;
      d = d + dy - dx;
   }
 }
}

/***** VE DUONG TRON ****/

// ham pc
void pc(int xc,int yc, int x, int y, int c){
 putpixel(xc + x, yc + y, c);
 putpixel(xc - x, yc - y, c);
 putpixel(xc -y, yc +x, c);
 putpixel(xc +y, yc -x, c);
}

// Ve duong tron voi Bresenham
void Bresenham_Circle(int xc, int yc, int r, int c)
{
  int x, y, p;
  x = 0;
  y = r;
  p = 3 - 2 * r;
  pc(xc,yc, r,0,c); //ve 4 diem dac biet
  while (x < y){
   if (p < 0)
     p += 4 * x + 6;
   else{
     p += 4 * (x-y) + 10;
     y--;
   }
   x++;
   pc(xc,yc, x,y,c);
   pc(xc,yc, y,x,c);
 }
 pc(xc,yc, y,y,c); // ve 4 diem phan giac x=y
}

// Ve duong tron voi MidPoint
void Mid_circle(int xc, int yc, int r, int c)
{
  int x, y, d;
  x = 0;
  y = r;
  d = 1- r;
  pc(xc,yc, r,0,c); //ve 4 diem dac biet
  while (x <= y)
  {
    pc(xc,yc, x,y,c);
    pc(xc,yc, y,x,c);
    if (d< 0)
       d +=2 * x + 3;
    else
   {
      d += 2 * (x-y) + 5;
      y--;
   }
   x++;
 }
 pc(xc,yc, y,y,c); // ve 4 diem phan giac x=y
}

/*****************************/
// ham main

int main(){
int driver=DETECT, mode;
initgraph(&driver,&mode,"C:\\TC\\BGI"); // Ban co the thay doi Path tuy vao may cua ban

// AB
Line_OX(10,90,40,4);

// FE
Line_OX(30,70,20,4);

// DC
Line_OX(80,90,30,4);

// AG
Line_OY(30,40,10,4);

// BC
Line_OY(30,40,90,4);

// O1
Bresenham_Circle(30,40, 10,5);

//O2
Mid_circle(60, 40,10, 5);

// Kinh sau (GF)
Bre_Line(10,30,30,20,4) ;

// Kinh truoc (DE)
Mid_line(70,20, 80, 30,4) ;

getch();
}
