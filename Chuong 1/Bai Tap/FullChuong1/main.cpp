#include<bits/stdc++.h>
#include <stdio.h>
#include<graphics.h>
#include <conio.h>
#include <math.h>

#define mau1 15
#define mau2 8
#define maumn 7
#define XTop 200
#define YTop 100
#define Dy 32
#define Dx 250
using namespace std;
struct Dinh {
    int x, y;
//Dinh(int a,int b)
//{
//	x=a;b=y;
//}
};
int SoDong;
float a, b, c, d, e, min, max, minn, maxx;
int p;

void KhoiTaoDohoa() {
    int gd = 0, gm;
    initwindow(800, 400);
}

void put8pixel(int xc, int yc, int x, int y, int color) {
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel(y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}

void drawCircleMidpoint(int xc, int yc, int r, int color) {
    int x = 0;
    int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color);
    while (x < y) {
        if (f < 0) f += (x << 1) + 3;
        else {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, color);
    }
}


void VeDaGiac(Dinh d[], int n, int x0, int y0, int R, int color) {
    float g = 3.14 * 2 / n, g1 = 0;
    for (int i = 0; i < n; i++) {
        d[i].x = x0 + R * cos(g1);
        d[i].y = y0 + R * sin(g1);
        g1 += g;
    }
    setcolor(WHITE);
    moveto(d[0].x, d[0].y);
    for (int i = 1; i < n; i++) {
        lineto(d[i].x, d[i].y);
    }
    lineto(d[0].x, d[0].y);
}


/*int Delta3(Dinh a,Dinh b, Dinh c){
int kq=a.x*b.y+a.y*c.x+b.x*c.y-c.x*b.y-b.x*a.y-c.y*a.x;
if(kq<0)return -1;
if(kq>0) return 1;
return 0;
}*/

int round(float x) {
    if (x > 0) return int(x + 0.5);
    else return int(x - 0.5);
}

void plot(int xc, int yc, int x, int y, int color) {
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
}

void elipMidpoint(int xc, int yc, int a, int b, int color) {
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a * a;
    b2 = b * b;
    fx = 0;
    fy = 2 * a2 * y;
    plot(xc, yc, x, y, color);
    p = (b2 - (a2 * b) + (0.25 * a2));//p=b2 - a2*b +a2/4
    while (fx < fy) {
        x++;
        fx += 2 * b2;
        delay(50);
        if (p < 0) {
            p += b2 * (2 * x + 3);//p=p + b2*(2x +3)
        } else {
            y--;
            p += b2 * (2 * x + 3) + a2 * (2 - 2 * y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2 * a2;
        }
        plot(xc, yc, x, y, color);
    }
    p = (b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);
    //
    while (y > 0) {
        y--;
        fy -= 2 * a2;
        delay(50);
        if (p >= 0) {
            p += a2 * (3 - 2 * y); //p=p +a2(3-2y)
        } else {
            x++;
            fx += 2 * b2;
            p += b2 * (2 * x + 2) + a2 * (3 - 2 * y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        plot(xc, yc, x, y, color);
    }
}

struct point {
    int x, y, angle;

    point(int _x = 0, int _y = 0, int _angle = 0) {
        x = _x;
        y = _y;
        angle = _angle;
    }

    void draw(int color, int delays) {
        putpixel(x, y, color);
        delay(delays);
    }
};

int angle(int x, int y) {
    return (int) (atan((float) y / x) * 180 / 3, 14);
}

void calculate(int xcenter, int ycenter, int radius, point a[], int &n) {
    int x, y;
    float p = 3 - 2 * radius;
    point b[400];
    y = 0;
    x = radius;
    n = 0;

    while (y <= x) {
        b[n++] = point(x, y, angle(x, y));
        if (p < 0) p = p + 2 * (2 * y + 3);
        else {
            p = p + 4 * (1 - x) + 2 * (2 * y + 3);
            x = x - 1;
        }
        y = y + 1;
    }
    b[n++] = point(x, y, 90 - angle(x, y));

    for (int k = 0; k < n; k++) {
        a[k] = point(xcenter + b[k].x, ycenter - b[k].y, b[k].angle);
        a[2 * n - 1 - k] = point(xcenter + b[k].y, ycenter - b[k].x, 90 - b[k].angle);
        a[2 * n + k] = point(xcenter - b[k].y, ycenter - b[k].x, 90 + b[k].angle);
        a[4 * n - 1 - k] = point(xcenter - b[k].x, ycenter - b[k].y, 180 - b[k].angle);
        a[4 * n + k] = point(xcenter - b[k].x, ycenter + b[k].y, 180 + b[k].angle);
        a[6 * n - 1 - k] = point(xcenter - b[k].y, ycenter + b[k].x, 270 - b[k].angle);
        a[6 * n + k] = point(xcenter + b[k].y, ycenter + b[k].x, 270 + b[k].angle);
        a[8 * n - 1 - k] = point(xcenter + b[k].x, ycenter + b[k].y, 360 - b[k].angle);
    }
    n = 8 * n;
}

void Arc(int xcenter, int ycenter, int radius, int startang, int endang, int color, int delays = 0) {
    point a[1000];
    int n, k;
    calculate(xcenter, ycenter, radius, a, n);

    if (startang >= 360) {
        startang %= 360;
        endang %= 360;
    }
    if (endang > 360) {
        endang %= 360;
        for (k = 0; k < n; k++)
            if (startang <= a[k].angle && a[k].angle <= 360) a[k].draw(color, delays);
        for (k = 0; k < n; k++)
            if (a[k].angle <= endang) a[k].draw(color, delays);
    } else
        for (k = 0; k < n; k++)
            if (startang <= a[k].angle && a[k].angle <= endang) a[k].draw(color, delays);
}

void Baitap0() {
    cleardevice();
    Arc(getmaxx() / 2, getmaxy() / 2, 80, 45, 180, 11, 5);
    getch();
}

void Baitap1() {
    cleardevice();
    Arc(getmaxx() / 2, getmaxy() / 2, 80, 45, 380, 11, 5);
    getch();

}

void Baitap2() {
    cleardevice();
//	initwindow(640,480);
    Dinh d[100];
    setcolor(GREEN);
    circle(getmaxx() / 2, getmaxy() / 2, 100);
    VeDaGiac(d, 7, getmaxx() / 2, getmaxy() / 2, 100, WHITE);
//	XetLoiLom(d,4);
    getch();
}

void Baitap3() {
    cleardevice();
    Dinh A, B, C;
    A.x = 100;
    A.y = 100;
    B.x = 150;
    B.y = 250;
    C.x = 280;
    C.y = 180;
    float a = B.x - A.x, b = B.y - A.y, c = C.x - B.x, d = C.y - B.y,
            e = B.x * B.x + B.y * B.y, f = A.x * A.x + A.y * A.y, h = C.x - A.x, i = C.y - A.y,
            g = C.x * C.x + C.y * C.y;
    float x = (-(a * (g - e)) + c * (e - f)) / (2 * (b * c - a * d));
    float y;
    if (a == 0) y = (g - f - 2 * x * i) / (2 * h);
    else y = (e - f - 2 * x * b) / (2 * a);
    float r = sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
    line(A.x, A.y, B.x, B.y);
    line(C.x, C.y, B.x, B.y);
    line(A.x, A.y, C.x, C.y);
    drawCircleMidpoint(round(y), round(x), round(r), mau1);
//	Sleep(3000);
    getch();
}

void Baitap4() {
    cleardevice();
    //   drawCircleBresenham(200,200,100);
    Dinh A, B, C;
    A.x = 100;
    A.y = 100;
    B.x = 150;
    B.y = 250;
    C.x = 280;
    C.y = 180;
    float a = B.x - A.x, b = B.y - A.y, c = C.x - B.x, d = C.y - B.y,
            e = B.x * B.x + B.y * B.y, f = A.x * A.x + A.y * A.y, h = C.x - A.x, i = C.y - A.y,
            g = C.x * C.x + C.y * C.y;
    float x = (-(a * (g - e)) + c * (e - f)) / (2 * (b * c - a * d));
    float y;
    if (a == 0) y = (g - f - 2 * x * i) / (2 * h);
    else y = (e - f - 2 * x * b) / (2 * a);
    float r = sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
    line(A.x, A.y, B.x, B.y);
    line(C.x, C.y, B.x, B.y);
    line(A.x, A.y, C.x, C.y);

    getch();
}

float f2(float x) {
    return (a * x * x + b * x + c);
}

void vedothi2(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    cleardevice();
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(15);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f2(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f2(x) * k);
        lineto(x2, y2);
    }
}

void Baitap5() {
    cleardevice();
    a = 1;
    b = 2;
    c = 3;
    // elipMidpoint(getmaxx()/2, getmaxy()/2,150,80,15);
    minn = -10;
    maxx = 10;
    vedothi2(minn, maxx);
    getch();
}

float f(float x) {
    return (a * x * x * x + b * x * x + c * x + d);
}

void vedothi(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    cleardevice();
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(15);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f(x) * k);
        lineto(x2, y2);
    }
}

void Baitap6() {
    cleardevice();
    a = 4;
    b = 2;
    c = 3;
    d = 5;
    minn = -10;
    maxx = 10;
    vedothi(minn, maxx);
    getch();
}

float f4(float x) {
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}

void vedothi4(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    cleardevice();
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(15);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f4(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f4(x) * k);
        lineto(x2, y2);
    }
}

void Baitap7() {
    cleardevice();
    a = 1;
    b = 1;
    c = -2;
    d = 0;
    e = -3;
    minn = -10;
    maxx = 10;
    vedothi4(minn, maxx);
    getch();
}

float f5(float x) {
    return (a * x + b) / (c * x + d);
}

void vedothi5(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    cleardevice();
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(15);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f5(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f5(x) * k);
        if ((x2 == (int) (-(d / c) * k + x0))) {
            moveto(x2, y2);
            continue;
        }
        //	if(y2==(int)((a/c)*k+y0))
        //	{
        //		moveto(x2,y2);
        //		continue;
        //	}
        lineto(x2, y2);
    }
}

void Baitap8() {
    cleardevice();
    a = 1;
    b = 1;
    c = -2;
    d = 4;
    minn = -d / c - 15;
    maxx = -d / c + 15;
    vedothi5(minn, maxx);
    getch();
}

float f6(float x) {
    return (a * x * x + b * x + c) / (d * x + e);
}

void vedothi6(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 80;
    dx = 0.0001;
    cleardevice();
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(15);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f6(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f6(x) * k);
        if ((x2 == (int) (-(e / d) * k + x0))) {
            moveto(x2, y2);
            continue;
        }
        lineto(x2, y2);
    }
}

void Baitap9() {
    cleardevice();
    a = 1;
    b = 2;
    c = 5;
    d = 1;
    e = 4;
    minn = -15;
    maxx = 10;
    vedothi6(minn, maxx);
    getch();
}

float fy(float y) {
    return (y * y) / 2 * p;
}

void vedothip(float min, float max) {
    int x0, y0, x1, y1, x2, y2;
    float y, dy, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = 100;
    dy = 0.0001;
    setcolor(12);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    y = min;
    setcolor(15);
    x1 = x0 + round(fy(y) * k);
    y1 = y0 - round(y * k);
    moveto(x1, y1);
    while (y < max) {
        y = y + dy;
        x2 = x0 + round(fy(y) * k);
        y2 = y0 - round(y * k);
        lineto(x2, y2);
    }
}

void Baitap10() {
    cleardevice();
    p = 2;
    vedothip(-10, 10);
    getch();
}

void Baitap11() {
    cleardevice();
    a = 1;
    b = 2;
    int kk = (100 / a);
    a = a * kk;
    b = b * kk;
    //ellipse(300,300,a,b);
    getch();
}

float f11(float x) {
    return sqrt(((x * x / a * a) + 1) / (b * b));
}

float f22(float x) {
    return -sqrt(((x * x / a * a) + 1) / (b * b));
}

void vedothi11(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    setcolor(15);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = minn;
    setcolor(1);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f11(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f11(x) * k);
        lineto(x2, y2);
    }
}

void vedothi22(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float x, dx, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxx() / 30;
    dx = 0.0001;
    setcolor(15);
    x = minn;
    setcolor(1);
    x1 = x0 + round(x * k);
    y1 = y0 - round(f22(x) * k);
    moveto(x1, y1);
    while (x < maxx) {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(f22(x) * k);
        lineto(x2, y2);
    }
}


float f33(float y) {
    return sqrt(((y * y / b * b) + 1) / (a * a));
}

void vedothi33(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float y, dy, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxy() / 30;
    dy = 0.0001;
    setcolor(15);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    y = minn;
    setcolor(1);
    y1 = y0 + round(y * k);
    x1 = x0 - round(f33(y) * k);
    moveto(x1, y1);
    while (y < maxx) {
        y = y + dy;
        y2 = y0 + round(y * k);
        x2 = x0 - round(f33(y) * k);
        lineto(x2, y2);
    }
}

float f44(float y) {
    return -sqrt(((y * y / b * b) + 1) / (a * a));
}

void vedothi44(float minn, float maxx) {
    int x0, y0, x1, y1, x2, y2;
    float y, dy, k;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float) getmaxy() / 30;
    dy = 0.0001;
    setcolor(15);
    y = minn;
    setcolor(1);
    y1 = y0 + round(y * k);
    x1 = x0 - round(f44(y) * k);
    moveto(x1, y1);
    while (y < maxx) {
        y = y + dy;
        y2 = y0 + round(y * k);
        x2 = x0 - round(f44(y) * k);
        lineto(x2, y2);
    }
}

void Baitap13() {
    cleardevice();
    a = 1;
    b = 2;
    vedothi11(-10, 10);
    vedothi22(-10, 10);
    getch();
}

void Baitap12() {
    cleardevice();
    a = 1;
    b = 2;
    vedothi33(-10, 10);
    vedothi44(-10, 10);
    getch();
}

void Box(int x1, int y1, int x2, int y2, int MauVienTren, int MauVienDuoi, int MauNen) {
    x2 = x2 + 70;
    setfillstyle(1, MauNen);
    bar(x1 - 110, y1 - 80, x2, y2 - 80);
    setcolor(MauVienTren);
    for (int i = 0; i <= 1; i++) {
        moveto(x1 - i - 110, y2 + i - 80);
        lineto(x1 - i - 110, y1 - i - 80);
        lineto(x2 + i, y1 - i - 80);
    }

    setcolor(MauVienDuoi);
    for (int i = 0; i <= 1; i++) {
        moveto(x2 + i, y1 - i - 80);
        lineto(x2 + i, y2 + i - 80);
        lineto(x1 - i - 110, y2 + i - 80);
    }
}

void Ve_menu(int Xdau, int Ydau, int DeltaX, int DeltaY, int chon, int SoDong, char *DongMN[]) {
    setbkcolor(0);
    cleardevice();
    for (int i = 0; i < SoDong; i++) {
        if (i == chon) Box(Xdau, Ydau + i * DeltaY + 6, Xdau + DeltaX, Ydau + i * DeltaY + DeltaY, mau2, mau1, maumn);
        else Box(Xdau, Ydau + i * DeltaY + 6, Xdau + DeltaX, Ydau + i * DeltaY + DeltaY, mau1, mau2, maumn);
        outtextxy(Xdau + 20 - 110, Ydau + 10 + i * DeltaY - 80, DongMN[i]);
    }
}

int main() {

    char ch, *st[20];
    st[0] = "Ve cung tron";
    st[1] = "Ve cung elip";
    st[2] = "Da giac deu noi tiep duong tron";
    st[3] = "Hinh tron qua 3 diem A,B,C";
    st[4] = "Cung tron qua 3 diem A,B,C";
    st[5] = "dt ax^2+bx+c";
    st[6] = "dt ax^3+bx^2+cx+d";
    st[7] = "dt ax^4+bx^3+cx^2+dx+e";
    st[8] = "dt (ax+b)/(cx+d)";
    st[9] = "dt (ax^2+bx+c)/(dx+ex)";
    st[10] = "dt y^2=2*p*x";
    st[11] = "dt (x^2/a^2)+(y^2/b^2)=1";
    st[12] = "dt (x^2/a^2)-(y^2/b^2)=1";
    st[13] = "dt (x^2/a^2)-(y^2/b^2)=-1";
    int x0 = 25, y0 = 5, chon = 0, luuchon, sodong = 14, ok = FALSE;
    KhoiTaoDohoa();
    settextstyle(0, 0, 2);
//  Ve_menu(x0,y0,chon,sodong,st);
    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
    do {
        ch = getch(); //Nhan mot phim
        switch (ch) {
            case 72: //phim len
                luuchon = chon;
                chon--;
                if (chon < 0) chon = sodong - 1;
                Box(XTop, YTop + luuchon * Dy + 6, XTop + Dx, YTop + luuchon * Dy + Dy, mau1, mau2, maumn);
                outtextxy(XTop + 20 - 100, YTop + 10 + luuchon * Dy - 80, st[luuchon]);
                Box(XTop, YTop + chon * Dy + 6, XTop + Dx, YTop + chon * Dy + Dy, mau2, mau1, maumn);
                outtextxy(XTop + 20 - 110, YTop + 10 + chon * Dy - 80, st[chon]);
                break;
            case 80://phim xuong
                luuchon = chon;
                chon++;
                if (chon == sodong) chon = 0;
                Box(XTop, YTop + luuchon * Dy + 6, XTop + Dx, YTop + luuchon * Dy + Dy, mau1, mau2, maumn);
                outtextxy(XTop + 20 - 110, YTop + 10 + luuchon * Dy - 80, st[luuchon]);
                Box(XTop, YTop + chon * Dy + 6, XTop + Dx, YTop + chon * Dy + Dy, mau2, mau1, maumn);
                outtextxy(XTop + 20 - 110, YTop + 10 + chon * Dy - 80, st[chon]);
                break;
            case 13: //phim ENTER
                ok = TRUE;
                break;
        }
        if (ok == TRUE) //Neu phim ENTER duoc nhan
        {
            switch (chon) {
                case 0:
                    Baitap0();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 1:
                    Baitap1();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 2:
                    Baitap2();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 3:
                    Baitap3();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 4:
                    Baitap4();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 5:
                    Baitap5();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 6:
                    Baitap6();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 7:
                    Baitap7();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 8:
                    Baitap8();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 9:
                    Baitap9();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 10:
                    Baitap10();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 11:
                    Baitap11();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 12:
                    Baitap12();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 13:
                    Baitap13();
                    Ve_menu(XTop, YTop, Dx, Dy, chon, sodong, st);
                    break;
                case 14:
                    exit(0);
            }
            ok = FALSE; //tra lai trang thai ENTER chua duoc nhan
        }
    } while (ch != 27);//Nhan phim ESC de thoat khoi chuong trinh
}



