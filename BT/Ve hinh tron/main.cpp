#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{

int gd=DETECT,gm,errorcode; //yeu cau auto-detection.
//khoi tao cac bien do hoa va cuc bo.
initgraph(&gd,&gm,"d:\\bc3\\bgi"); //la path cai dat graphics drivers
//doc ket qua cua trình khoi tao.
errorcode=graphresult();
//neu co mot loi xay ra.
if (errorcode!=grOk)
{
cout << "Xuat hien mot loi: \n" << grapherrormsg(errorcode) << endl;
cout << "Nhan bat ky phim nao de dung lai : ";

exit(1);
}
circle(200,200,50); //ve mot hinh tron co tam (200,200) va ban kinh (50).

circle(300,203,40); //ve mot hinh tron co tam (300,203) va ban kinh (40).

circle(500,303,80); //ve mot hinh tron co tam (500,303) va ban kinh (80).
getch();
closegraph();
return 0;
}
