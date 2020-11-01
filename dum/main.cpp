#include <iostream>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
void khung(int x1,int y1,int x2,int y2,int sleep)
{
    int i;
    for(i=floor((x1+x2)/2)+1;i>x1;i--)
    {
	gotoxy(i,y2);
	cout<<"\315";
	gotoxy(x1+x2-i,y2);
	cout<<"\315";
	delay(sleep);
    }
    gotoxy(x1,y2);
    cout<<"\310";
    gotoxy(x2,y2);
    cout<<"\274";
    delay(sleep);
    for(i=y2-1;i>y1;i--)
    {
	gotoxy(x1,i);
	cout<<"\272";
	gotoxy(x2,i);
	cout<<"\272";
	delay(sleep);
    }
    gotoxy(x1,y1);
    cout<<"\311";
    gotoxy(x2,y1);
    cout<<"\273";
    delay(sleep);
    for(i=x2-1;i>=(x1+x2)/2;i--)
    {
	gotoxy(i,y1);
	cout<<"\315";
	gotoxy(x1+x2-i,y1);
	cout<<"\315";
	delay(sleep);
    }
}

/*void AutoSnake(int x,int y,int *pk,int *pc,int *pd)
{
    int i,j;
    for(i=-1;i<=1;i++)
    {
	for(j=-1;j<=1;j++)
	{
	    if(B[x+i][y+j]==0&A[x+i][y+j]==0)
	    {
		B[x+i][y+j]=1;
		AutoSnake(x,y,*pk,*pc,*pd);
	    }
	}
    }
}*/

int main()
{
    const MinX=5,MaxX=30,MinY=5,MaxY=30; //pham vi di chuyen cua con ran
    int A[MaxX-MinX+1][MaxY-MinY+1]; //mang 2 chieu - neenf tangr cuar thuaatj toans
    int n=5; //do dai cua ran
    int x=8,y=8,x1=7,y1=8,x2=6,y2=8; //cac toa do cua dau ran
    int Tx=8,Ty=8; //toa do muc tieu
    int i,j; //hai bien dung trong lenh for de xu li hinh anh chuyen dong
    char ch; //xac dinh dieu kien thoat chuong trinh
    int than=205; //mang ma ASCII cua ky tu dung de ve ran
    int k,c,d; //giup ran tim duong
    int B[MaxX-MinX+1][MaxY-MinY+1];
    int *pk=&k,*pc=&c,*pd=&d; //cac bien con tro
    textmode(C4350);
    //clrscr();
    khung(MinX-1,MinY-1,MaxX+1,MaxY+1,25);
    for(i=0;i<=(MaxX-MinX);i++)
    {
	for(j=0;j<=(MaxY-MinY);j++)
	{
	    A[i][j]=0;
	}
    }
    A[x1][y1]=n;
    srand(time(NULL));
    do
    {
	//tao thoi gian che va ghi thong so
	gotoxy(2,2);
	cout<<n<<" "<<Tx<<" "<<Ty<<" "<<x<<" "<<y<<"       ";
	delay(25);

	//khoi tao muc tieu
	if((Tx==x)&(Ty==y))
	{
	    do
	    {
		Tx=rand()%(MaxX-MinX-1);
		Ty=rand()%(MaxY-MinY-1);
	    }while(A[Tx][Ty]!=0);
	    n++; //tang do dai ran
	}
	gotoxy(Tx+MinX,Ty+MinY);
	cout<<"x";

	//xu li hinh anh chuyen dong
	for(i=0;i<=(MaxX-MinX);i++)
	{
	    for(j=0;j<=(MaxY-MinY);j++)
	    {
		if(A[i][j]!=0)
		{
		    A[i][j]--;
		    if(A[i][j]==0)
		    {
			gotoxy(i+MinX,j+MinY);
			cout<<" ";
		    }
		}
	    }
	}

	//phan tich ky tu dung de ve ran
	if(x==x1&x1==x2){than=186;}
	if(y==y1&y1==y2){than=205;}
	if(x2==x1&y1==y&(y2==y1+1||(y2==0&y1==MaxY-MinY))&(x1==x-1||(x1==MaxX-MinX&x==0)))
	    {than=201;}
	if(y2==y1&x1==x&(x2==x1+1||(x2==0&x1==MaxX-MinX))&(y1==y-1||(y1==MaxY-MinY&y==0)))
	    {than=201;}
	if(y2==y1&x1==x&(x2==x1+1||(x2==0&x1==MaxX-MinX))&(y1==y+1||(y1==0&y==MaxY-MinY)))
	    {than=200;}
	if(x2==x1&y1==y&(y2==y1-1||(y2==MaxY-MinY&y1==0))&(x1==x-1||(x1==MaxX-MinX&x==0)))
	    {than=200;}
	if(y2==y1&x1==x&(x2==x1-1||(x2==MaxX-MinX&x1==0))&(y1==y-1||(y1==MaxY-MinY&y==0)))
	    {than=187;}
	if(x2==x1&y1==y&(y2==y1+1||(y2==0&y1==MaxY-MinY))&(x1==x+1||(x1==0&x==MaxX-MinX)))
	    {than=187;}
	if(y2==y1&x1==x&(x2==x1-1||(x2==MaxX-MinX&x1==0))&(y1==y+1||(y1==0&y==MaxX-MinX)))
	    {than=188;}
	if(x2==x1&y1==y&(y2==y1-1||(y2==MaxY-MinY&y1==0))&(x1==x+1||(x1==0&x==MaxX-MinX)))
	    {than=188;}
	x2=x1;
	y2=y1;
	x1=x;
	y1=y;

	/*ran tu di chuyen
	for(i=0;i<=(MaxX-MinX);i++)
	{
	    for(j=0;j<=(MaxY-MinY);j++)
	    {
		B[i][j]=0;
	    }
	} /*/


	//xu li chuyen dong
	if(x==Tx)
	{
	    if(y<Ty){y++;}
	    if(y>Ty){y--;}
	}
	else
	{
	    if(x>Tx){x--;}
	    if(x<Tx){x++;}
	}

	//xu li khi ran tu dam vao chinh no
	if(A[x][y]!=0)
	{
	    x=x1;
	    y=y1;
	    if(y==Ty)
	    {
		if(x<Tx){x++;}
		if(x>Tx){x--;}
	    }
	    else
	    {
		if(y>Ty){y--;}
		if(y<Ty){y++;}
	    }
	}
	if(A[x][y]!=0)
	{
	    x=x1; y=y1;
	    x++;
	}
	if(A[x][y]!=0)
	{
	    x=x1; y=y1;
	    x--;
	}
	if(A[x][y]!=0)
	{
	    x=x1; y=y1;
	    y++;
	}
	if(A[x][y]!=0)
	{
	    x=x1; y=y1;
	    y--;
	}

	//xu li khi ran di qua pham vi
	if(x<0){x=MaxX-MinX;}
	if(x>MaxX-MinX){x=0;}
	if(y<0){y=MaxY-MinY;}
	if(y>MaxY-MinY){y=0;}

	//ve ran
	A[x1][y1]=n;
	gotoxy(x2+MinX,y2+MinY);
	cout<<char(than);

	//dieu kien thoat
	if(kbhit())
	{
	    ch=getch();
	}

    }while(ch!=27);
}
