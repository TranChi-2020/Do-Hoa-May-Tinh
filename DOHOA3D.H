#ifndef DoHoa3D_h
#define DoHoa3D_h
#define khoang 5
#include<math.h>
struct ToaDo3D
{
	float x,y,z;
};
struct ToaDo2D
{
	int x,y;
} ;
enum PhepChieu{PhoiCanh,SongSong};
float R,theta,phi,D;
float aux1,aux2,aux3,aux4 ;
float aux5,aux6,aux7,aux8 ;
char  ch;
ToaDo2D PC,PE;
ToaDo3D Obs;
PhepChieu pc;
float Xproj,Yproj;

void ThietLapDoHoa()
{
	int gd=0,gm;
	initgraph(&gd,&gm,"");
}

void KhoiTaoPhepChieu()
{
   float th,ph;
   th = M_PI*theta/180;
   ph = M_PI*phi/180;
   aux1 = sin(th);
   aux2 = sin(ph);
   aux3 = cos(th);
   aux4 = cos(ph);
   aux5 = aux3*aux2;
   aux6 = aux1*aux2;
   aux7 = aux3*aux4;
   aux8 = aux1*aux4;
   PC.x = getmaxx()/ 2;
   PC.y = getmaxy()/ 2;
}

void  Chieu(ToaDo3D P)
{
   Obs.x = -P.x*aux1 + P.y*aux3 ;
   Obs.y = -P.x*aux5 - P.y*aux6 + P.z*aux4  ;
   if( pc== PhoiCanh)
   {
       Obs.z =-P.x*aux7 - P.y*aux8 - P.z*aux2 + R ;
       Xproj = D*Obs.x/Obs.z;
       Yproj = D*Obs.y/Obs.z;
   }
   else
   {
	  Xproj = D*Obs.x;
	  Yproj = D*Obs.y;
   }
}

void VeDen(ToaDo3D P)
{
   Chieu(P);
   PE.x = PC.x + ceil(Xproj);
   PE.y = PC.y - ceil(Yproj);
   lineto (PE.x,PE.y);
}

void DiDen(ToaDo3D P)
{
   Chieu(P);
   PE.x = PC.x + ceil(Xproj);
   PE.y = PC.y - ceil(Yproj);
   moveto (PE.x,PE.y);
}

void TrucToaDo()
{
 ToaDo3D OO,XX,YY,ZZ;

   setcolor(LIGHTRED);
   OO.x=0;     OO.y=0;     OO.z=0;
   XX.x=2;     XX.y=0;     XX.z=0;
   YY.x=0;     YY.y=2;     YY.z=0;
   ZZ.x=0;     ZZ.y=0;     ZZ.z=2;
   DiDen(OO);VeDen(XX); outtextxy(PE.x+2,PE.y,"X");
   DiDen(OO);VeDen(YY); outtextxy(PE.x+2,PE.y,"Y");
   DiDen(OO);VeDen(ZZ); outtextxy(PE.x+2,PE.y,"Z");
}

void DieuKhienQuay()
{
    ch=getch();
   if( ch ==0 )
	ch = getch();
   cleardevice();
   switch(ch)
   {
     case 72 : phi = phi + khoang;
     break;
     case 80 : phi = phi - khoang;
     break;
     case 75 : theta = theta + khoang;
     break;
     case 77 : theta = theta - khoang;
   }
}
#endif
