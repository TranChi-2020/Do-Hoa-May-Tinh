void tomauHTCB(int xa, int xb, int xc, int xd, int ymin, int ymax, int mt)
{
         int xm1, xm2;
         float m1=(float)(ymax-ymin)/(xd-xa);
         float m2=(float)(ymax-ymin)/(xc-xb);
         int color=getcolor();
         setcolor(mt);
     for (int y=ymin; y<=ymax; y++)
   {
     xm1=(int)((1/m1)*(y-ymin)+xa+0.5);
     xm2=(int)((1/m2)*(y-ymin)+xb+0.5);
     line(xm1,y,xm2,y);
   }
    setcolor(color);
  
}
