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

setfillstyle(EMPTY_FILL,0);
/*Lenh tren nghia la ham setfillstyle duoc su dung de
thiet lap fill style cua mot thanh hinh chu nhat 3 chieu duoi dang trong.*/
bar3d(200,200,300,450,10,1);
getch();
closegraph();
}
