#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
  
  int gd = DETECT,gm,errorcode; //yeu cau auto-detection.

  //khoi tao cac bien do hoa va cuc bo
  initgraph (&gd, &gm, ""); //la path cai dat graphics drivers

  //doc ket qua cua trinh khoi tao.
  errorcode = graphresult();

  //khi co mot loi xay ra.
  if (errorcode != grOk)
    {
      cout << "Xay ra loi : \n" << grapherrormsg(errorcode) << endl;
      cout << "Nhan bat ky phim nao de dung : ";
      
      exit(1);
    }

  /*Ve mot hinh chu nhat co LHS vertex tren cung tai (300, 300)
  va RHS vertex duoi cung tai (600, 400)*/
  rectangle(300, 300, 600, 400);
  rectangle(100, 100, 200, 200);
  
  floodfill(120, 120, WHITE);
  getch();
  closegraph();
  return 0;
}
