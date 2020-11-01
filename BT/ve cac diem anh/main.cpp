#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
int gdriver=DETECT,gmode,errorcode; //yeu cau auto-detection.
int midx,midy,x;
//khoi tao cac bien do hoa va cuc bo
initgraph(&gdriver,&gmode,"d:\\bc3\\bgi");
//doc ket qua cua trinh khoi tao.
errorcode=graphresult();
if(errorcode!=grOk)
//khi co mot loi xay ra.
{
printf("Xay ra loi : %s \n",grapherrormsg(errorcode));
printf("Nhan bat ky phim nao de dung : ");
getch();
exit(1); //Dung chuong trinh do xuat hien loi.
}
for(x=40;x<120;x=x+10)
{
putpixel(x,200,14); //ve mot diem anh tai vi tri(x,200) voi mau vang(14)
getch();
}
}
