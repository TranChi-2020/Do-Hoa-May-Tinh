#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
int gdriver=DETECT,gmode,errorcode; //yeu cau auto-detection.
int midx,midy,x;
//khoi tao cac bien do hoa va cuc bo.
initgraph(&gdriver,&gmode,"d:\\bc3\\bgi");
//doc ket qua cua trình khoi tao.
errorcode=graphresult();
if(errorcode!=grOk)
//neu co mot loi xay ra.
{
printf("Xuat hien mot loi : %s \n",grapherrormsg(errorcode));
printf("Nhan bat ky phim nao de dung lai : ");

exit(1); //Dung chuong trinh do xuat hien loi.
}
/*thay doi background color.*/
for(x=0;x<=15;x++)
{
setbkcolor(x);

}
getch();
closegraph();
return 0;
}
