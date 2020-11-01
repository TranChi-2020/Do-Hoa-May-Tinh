//Chuong trinh tao Menu POPUP che do GRAPHICS
//Copy right by Pham Anh Phuong
#include <graphics.h>
#include <conio.h>
#include <cmath>

#define mau1 15
#define mau2 8
#define maumn 7
#define XTop 200
#define YTop 100
#define Dy 32
#define Dx 250

int SoDong;
float a, b, c, d, e, min, max;
void KhoiTaoDohoa()
{
    int gd = 0, gm;
    initgraph(&gd, &gm, "");
}

struct point
{
    int x, y, angle;
    point(int _x = 0, int _y = 0, int _angle = 0)
    {
        x = _x;
        y = _y;
        angle = _angle;
    }

    void draw(int color)
    {
        putpixel(x, y, color);
    }
};

struct toaDo2D
{
    int x;
    int y;
};

toaDo2D findCenter(toaDo2D A, toaDo2D B, toaDo2D C)
{
    toaDo2D center;
    float ab = (float)(B.y - A.y) / (float)(B.x - A.x);
    float bc = (float)(C.y - B.y) / (float)(C.x - B.x);
    center.x = (ab * bc * (A.y - C.y) + bc * (A.x + B.x) - ab * (B.x + C.x)) / (2 * (bc - ab));
    center.y = -1 * (center.x - (A.x + B.x) / 2) / ab + (A.y + B.y) / 2;
    return center;
}

toaDo2D findCenter(toaDo2D p[], int n)
{
    int sumX = 0;
    int sumY = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += p[i].x;
        sumY += p[i].y;
    }
    toaDo2D center;
    center.x = sumX / n;
    center.y = sumY / n;
    return center;
}

int findRadius(toaDo2D center, toaDo2D A)
{
    float radius = sqrt((center.x - A.x) * (center.x - A.x) + (center.y - A.y) * (center.y - A.y));
    return round(radius);
}

int findRadius(int n, float a)
{
    float radius = a / (2 * sin(3.14 / n));
    return round(radius);
}

void DrawPoly(toaDo2D P[], int n, int xc, int yc, int R)
{
    for (int i = 0; i < n - 1; i++)
    {
        line(P[i].x, P[i].y, P[i + 1].x, P[i + 1].y);
    }
    line(P[n - 1].x, P[n - 1].y, P[0].x, P[0].y);
    setcolor(BLUE);
    circle(xc, yc, R);
}

int angle(int x, int y)
{
    return (int)(atan((float)y / x) * 180 / 3.14);
}

void calculate(int x0, int y0, int r, point a[], int &n)
{
    int x, y;
    float p = 3 - 2 * r;
    point b[400];
    y = 0;
    x = r;
    n = 0;

    while (y <= x)
    {
        b[n++] = point(x, y, angle(x, y));
        if (p < 0)
            p = p + 2 * (2 * y + 3);
        else
        {
            p = p + 4 * (1 - x) + 2 * (2 * y + 3);
            x = x - 1;
        }
        y = y + 1;
    }
    b[n++] = point(x, y, 90 - angle(x, y));

    for (int k = 0; k < n; k++)
    {
        a[k] = point(x0 + b[k].x, y0 - b[k].y, b[k].angle);
        a[2 * n - 1 - k] = point(x0 + b[k].y, y0 - b[k].x, 90 - b[k].angle);
        a[2 * n + k] = point(x0 - b[k].y, y0 - b[k].x, 90 + b[k].angle);
        a[4 * n - 1 - k] = point(x0 - b[k].x, y0 - b[k].y, 180 - b[k].angle);
        a[4 * n + k] = point(x0 - b[k].x, y0 + b[k].y, 180 + b[k].angle);
        a[6 * n - 1 - k] = point(x0 - b[k].y, y0 + b[k].x, 270 - b[k].angle);
        a[6 * n + k] = point(x0 + b[k].y, y0 + b[k].x, 270 + b[k].angle);
        a[8 * n - 1 - k] = point(x0 + b[k].x, y0 + b[k].y, 360 - b[k].angle);
    }
    n = 8 * n;
}

float X(float a, int r)
{

    return r * cos(a * M_PI / 180);
}

float Y(float a, int r)
{

    return r * sin(a * M_PI / 180);
}

void Sector(int x0, int y0, int g1, int g2, int Rx, int Ry)
{

    int x1, y1, x2, y2;
    float x, dx, k;
    dx = 6;
    x = g1;
    setcolor(14);
    x1 = x0 + round(X(x, Rx));
    y1 = y0 - round(Y(x, Ry));
    moveto(x1, y1);

    while (x < g2)
    {

        x += dx;
        x2 = x0 + round(X(x, Rx));
        y2 = y0 - round(Y(x, Ry));
        lineto(x2, y2);
    }
}
void arc(int x0, int y0, int g1, int g2, int r, int color)
{
    point a[1000];
    int n, k;
    calculate(x0, y0, r, a, n);

    if (g1 >= 360)
    {
        g1 %= 360;
        g2 %= 360;
    }
    if (g2 > 360)
    {
        g2 %= 360;
        for (k = 0; k < n; k++)
            if (g1 <= a[k].angle && a[k].angle <= 360)
                a[k].draw(color);
        for (k = 0; k < n; k++)
            if (a[k].angle <= g2)
                a[k].draw(color);
    }
    else
        for (k = 0; k < n; k++)
            if (g1 <= a[k].angle && a[k].angle <= g2)
                a[k].draw(color);
}

void ve4diem(int xc, int yc, int x, int y, int color);
void elipMidpoint(int xc, int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a * a;
    b2 = b * b;
    fx = 0;
    fy = 2 * a2 * y;
    ve4diem(xc, yc, x, y, color);
    p = round(b2 - (a2 * b) + (0.25 * a2));

    while (fx < fy)
    {

        x++;
        fx += 2 * b2;
        if (p < 0)
        {
            p += b2 * (2 * x + 3);
        }
        else
        {
            y--;
            p += b2 * (2 * x + 3) + a2 * (2 - 2 * y);
            fy -= 2 * a2;
        }

        ve4diem(xc, yc, x, y, color);
    }

    p = round(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);

    while (y > 0)
    {

        y--;
        fy -= 2 * a2;
        if (p >= 0)
        {
            p += a2 * (3 - 2 * y);
        }
        else
        {
            x++;
            fx += 2 * b2;
            p += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
        }
        ve4diem(xc, yc, x, y, color);
    }
}

void ve4diem(int xc, int yc, int x, int y, int color)
{
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
}
void Baitap0()
{
    cleardevice();
    toaDo2D P[10000];
    //test
    P[0].x = 150;
    P[0].y = 100;
    P[1].x = 107;
    P[1].y = 175;
    P[2].x = 193;
    P[2].y = 175;
    float a = sqrt((P[1].x - P[0].x) * (P[1].x - P[0].x) + (P[1].y - P[0].y) * (P[1].y - P[0].y)); // do dai 1 canh
    toaDo2D center = findCenter(P, 3);                                                             // tim tam
    int radius = findRadius(3, a);                                                                 // tim ban kinh
    DrawPoly(P, 3, center.x, center.y, radius);                                                    // ve
    getch();
}

void Baitap1()
{
    cleardevice();
    toaDo2D A, B, C;
    A.x = 100;
    A.y = 200;
    B.x = 240;
    B.y = 330;
    C.x = 200;
    C.y = 120;
    toaDo2D center = findCenter(A, B, C);
    int radius = findRadius(center, A);
    setcolor(BLUE);
    circle(center.x, center.y, radius);
    putpixel(A.x, A.y, WHITE);
    putpixel(B.x, B.y, WHITE);
    putpixel(C.x, C.y, WHITE);
    getch();
}
void Baitap2()
{
    cleardevice();
    arc(getmaxx() / 2, getmaxy() / 2, 30, 360, 60, WHITE); // ve cung tron tu 30do den 360 do ban kinh bang 60;
    getch();
}
void Baitap3()
{
    cleardevice();
    int Min = 0;
    int Max = 180;
    int x0 = 120, y0 = 120, r = 100;
    Sector(x0, y0, Min, Max, 50, 20);
    getch();
}
void Baitap4()
{
    cleardevice();
    toaDo2D A, B, C;
    A.x = 257;
    A.y = 80;
    B.x = 300;
    B.y = 151;
    C.x = 375;
    C.y = 93;
    putpixel(A.x, A.y, BLUE);
    putpixel(B.x, B.y, BLUE);
    putpixel(C.x, C.y, BLUE);
    arc(getmaxx() / 2, getmaxy() / 5, 168, 360, 60, 14);
    getch();
}
void Baitap5()
{
    cleardevice();
    elipMidpoint(getmaxx() / 2, getmaxy() / 2, 160, 80, YELLOW); // ve cung tron tu 30do den 360 do ban kinh bang 60;
    getch();
}

float bai9_1(float x)
{
    return (a * x * x + b * x + c);
}

float bai9_2(float x)
{
    return (a * x * x * x + b * x * x + c * x + d);
}

float bai9_3(float x)
{
    return (a * x * x * x * x + b * x * x * x + c * x * x + d * x + e);
}

float bai9_4(float x)
{
    return ((a * x + b) / (c * x + d));
}

float bai9_5(float x)
{
    return ((a * x * x + b * x + c) / (d * x + e));
}
float goiHam(int i, float x)
{
    switch (i)
    {
    case 0:
        return bai9_1(x);

    case 1:
        return bai9_2(x);

    case 2:
        return bai9_3(x);

    case 3:
        return bai9_4(x);

    case 4:
        return bai9_5(x);
    }
}

void vedothi(float min, float max, int i)
{
    float x, dx, k;
    int x0, y0, x1, y1, x2, y2;
    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;
    k = (float)getmaxx() / 50;
    dx = 0.001;
    setcolor(WHITE);
    line(0, y0, 2 * x0, y0);
    line(x0, 0, x0, 2 * y0);
    x = min;
    x1 = x0 + round(x * k);
    y1 = y0 - round(goiHam(i, x) * k);
    moveto(x1, y1);
    while (x < max)
    {
        x = x + dx;
        x2 = x0 + round(x * k);
        y2 = y0 - round(goiHam(i, x) * k);
        setcolor(BLUE);
        lineto(x2, y2);
    }
    delay(10);
}

void Baitap9_1(int i)
{
    cleardevice();
    min = -10;
    max = 10;
    a = 1;
    b = -3;
    c = -1;
    vedothi(min, max, i);
    getch();
}

void Baitap9_2(int i)
{
    cleardevice();
    min = -10;
    max = 10;
    a = 1;
    b = -3;
    c = -1;
    d = 2;
    vedothi(min, max, i);
    getch();
}

void Baitap9_3(int i)
{
    cleardevice();
    min = -10;
    max = 10;
    a = 1;
    b = -3;
    c = -1;
    d = 2;
    e = -2;
    vedothi(min, max, i);
    getch();
}

void Baitap9_4(int i)
{
    cleardevice();
    min = -10;
    max = 10;
    a = 1;
    b = -3;
    c = -1;
    d = 2;
    vedothi(min, max, i);
    getch();
}

void Baitap9_5(int i)
{
    cleardevice();
    min = -10;
    max = 10;
    a = 1;
    b = -3;
    c = -1;
    d = 2;
    e = -2;
    vedothi(min, max, i);
    getch();
}

void Box(int x1, int y1, int x2, int y2, int MauVienTren, int MauVienDuoi, int MauNen)
{
    setfillstyle(1, MauNen);
    bar(x1, y1, x2, y2);
    setcolor(MauVienTren);
    for (int i = 0; i <= 1; i++)
    {
        moveto(x1 - i, y2 + i);
        lineto(x1 - i, y1 - i);
        lineto(x2 + i, y1 - i);
    }

    setcolor(MauVienDuoi);
    for (int i = 0; i <= 1; i++)
    {
        moveto(x2 + i, y1 - i);
        lineto(x2 + i, y2 + i);
        lineto(x1 - i, y2 + i);
    }
}

void Ve_menu(int Xdau, int Ydau, int DeltaX, int DeltaY, int chon1, int SoDong, char *DongMN[])
{
    setbkcolor(0);
    cleardevice();
    for (int i = 0; i < SoDong; i++)
    {
        if (i == chon1)
            Box(Xdau, Ydau + i * DeltaY + 6, Xdau + DeltaX, Ydau + i * DeltaY + DeltaY, mau2, mau1, maumn);
        else
            Box(Xdau, Ydau + i * DeltaY + 6, Xdau + DeltaX, Ydau + i * DeltaY + DeltaY, mau1, mau2, maumn);
        outtextxy(Xdau + 20, Ydau + 15 + i * DeltaY, DongMN[i]);
    }
}

main()
{
    char ch, *st[20];

    st[0] = "DrawPoly";
    st[1] = "Circle3P";
    st[2] = "ARC";
    st[3] = "Sector";
    st[4] = "ARC3P";
    st[5] = "Bai tap 10";
    st[6] = "Bai tap 9";
    char *st2[20];
    st2[0] = "ax^2 + bx + c";
    st2[1] = "ax^3 + bx^2 + cx + d";
    st2[2] = "ax^4 + bx^3 + cx^2+ dx + e";
    st2[3] = "(ax+b)/(cx+d)";
    st2[4] = "(ax^2+bx+c)/(dx+e)";
    st2[5] = "Back";
    int x0 = 25, y0 = 5, chon1 = 0, luuchon1, sodong1 = 7, ok = FALSE;
    KhoiTaoDohoa();
    settextstyle(0, 0, 2);
    //  Ve_menu(x0,y0,chon1,sodong1,st);
    Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);

    int select, sodong2 = 6, chon2 = 0, luuchon2;
    bool oke = false;
    do
    {
        ch = getch(); //Nhan mot phim
        switch (ch)
        {
        case 72: //phim len
            luuchon1 = chon1;
            chon1--;
            if (chon1 < 0)
                chon1 = sodong1 - 1;
            Box(XTop, YTop + luuchon1 * Dy + 6, XTop + Dx, YTop + luuchon1 * Dy + Dy, mau1, mau2, maumn);
            outtextxy(XTop + 20, YTop + 15 + luuchon1 * Dy, st[luuchon1]);
            Box(XTop, YTop + chon1 * Dy + 6, XTop + Dx, YTop + chon1 * Dy + Dy, mau2, mau1, maumn);
            outtextxy(XTop + 20, YTop + 15 + chon1 * Dy, st[chon1]);
            break;
        case 80: //phim xuong
            luuchon1 = chon1;
            chon1++;
            if (chon1 == sodong1)
                chon1 = 0;
            Box(XTop, YTop + luuchon1 * Dy + 6, XTop + Dx, YTop + luuchon1 * Dy + Dy, mau1, mau2, maumn);
            outtextxy(XTop + 20, YTop + 15 + luuchon1 * Dy, st[luuchon1]);
            Box(XTop, YTop + chon1 * Dy + 6, XTop + Dx, YTop + chon1 * Dy + Dy, mau2, mau1, maumn);
            outtextxy(XTop + 20, YTop + 15 + chon1 * Dy, st[chon1]);
            break;
        case 13: //phim ENTER
            ok = TRUE;
            break;
        }
        if (ok == TRUE) //Neu phim ENTER duoc nhan
        {
            switch (chon1)
            {
            case 0:
                Baitap0();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 1:
                Baitap1();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 2:
                Baitap2();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 3:
                Baitap3();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 4:
                Baitap4();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 5:
                Baitap5();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 6:
                cleardevice();
                Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
                do
                {
                    select = getch(); //Nhan mot phim
                    switch (select)
                    {
                    case 72: //phim len
                        luuchon2 = chon2;
                        chon2--;
                        if (chon2 < 0)
                            chon2 = sodong2 - 1;
                        Box(XTop, YTop + luuchon2 * Dy + 6, XTop + Dx, YTop + luuchon2 * Dy + Dy, mau1, mau2, maumn);
                        outtextxy(XTop + 20, YTop + 15 + luuchon2 * Dy, st2[luuchon2]);
                        Box(XTop, YTop + chon2 * Dy + 6, XTop + Dx, YTop + chon2 * Dy + Dy, mau2, mau1, maumn);
                        outtextxy(XTop + 20, YTop + 15 + chon2 * Dy, st2[chon2]);
                        break;
                    case 80: //phim xuong
                        luuchon2 = chon2;
                        chon2++;
                        if (chon2 == sodong2)
                            chon2 = 0;
                        Box(XTop, YTop + luuchon2 * Dy + 6, XTop + Dx, YTop + luuchon2 * Dy + Dy, mau1, mau2, maumn);
                        outtextxy(XTop + 20, YTop + 15 + luuchon2 * Dy, st2[luuchon2]);
                        Box(XTop, YTop + chon2 * Dy + 6, XTop + Dx, YTop + chon2 * Dy + Dy, mau2, mau1, maumn);
                        outtextxy(XTop + 20, YTop + 15 + chon2 * Dy, st2[chon2]);
                        break;
                    case 13: //phim ENTER
                        oke = TRUE;
                        break;
                    }
                    if (oke == TRUE) //Neu phim ENTER duoc nhan
                    {
                        switch (chon2)
                        {
	                        case 0:
	                            Baitap9_1(chon2);
	                            Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
	                            break;
	                        case 1:
	                            Baitap9_2(chon2);
	                            Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
	                            break;
	                        case 2:
	                            Baitap9_3(chon2);
	                            Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
	                            break;
	                        case 3:
	                        {
	                            Baitap9_4(chon2);
	                            Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
	                            break;
	                        }
	                        case 4:
	                        {
	                            Baitap9_5(chon2);
	                            Ve_menu(XTop, YTop, Dx, Dy, chon2, sodong2, st2);
	                            break;
	                        }
	                        case 5:
	                        {
	                            select = 27;
	                            break;
	                        }
                        }
                        oke = FALSE; //tra lai trang thai ENTER chua duoc nhan
                    }
                } while (select != 27); //Nhan phim ESC de thoat khoi chuong trinh
                cleardevice();
                Ve_menu(XTop, YTop, Dx, Dy, chon1, sodong1, st);
                break;
            case 7:
                exit(0);
            }
            ok = FALSE; //tra lai trang thai ENTER chua duoc nhan
        }
    } while (ch != 27); //Nhan phim ESC de thoat khoi chuong trinh
}

