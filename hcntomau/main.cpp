#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
void hcn(int x1, int y1, int x2, int y2)
{
    moveto(x1,y1); //con tro do hoa toi (x1,y1)
    lineto(x2,y1);
    lineto(x2,y2);
    lineto(x1,y2);
    lineto(x1,y1);
}
int main()
{
    initwindow(800,600);
    int x=100,y=100;
    int x1=200, y1=200, x2=700, y2=500;

    //quet tu tren xuong
    hcn(x1,y1,x2,y2);
    for(int y=y1;y<=y2;y++)
    {
        for(int x=x1;x<=x2;x++)
        putpixel(x,y,10);
    }


    //hien mau
    setcolor(10);
    for(int y=y1;y<=y2;y++)
    {
        line(x1,y,x2,y);
    }


    setcolor(10);
    for(int y=y1;y<=(y1+y2)/2;y++)
    {
        line(x1+1,y,x2-1,y);
    }


    setcolor(10);
    for(int y=(y1+y2)/2+1;y<=y2-1;y++)
    {
        line(x1+1,y,x2-1,y);
    }

    setcolor(10);
    while(y1<=y2)
    {
        x1++;
        x2--;
        y1++;
        y2--;
        hcn(x1,y1,x2,y2);
    }
    getch();
    return 0;
}
