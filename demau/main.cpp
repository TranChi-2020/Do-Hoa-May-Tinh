#include <iostream>
#include<cmath>
using namespace std;

struct TOADO {
   int x, y;
};

float triangleArea(TOADO A, TOADO B, TOADO C) 
{         
   return fabs(A.x * B.y - A.y * B.x + B.x * C.y - B.y * C.x + C.x * A.y - C.y * A.x);
}

bool isInside(TOADO A, TOADO B, TOADO C, TOADO P) 
{     //tim dien tich tam giac p1, p2, p3
   float area = triangleArea (A, B, C);          //dien tich tam giac ABC
   float area1 = triangleArea (P, B, C);         //khu vuc PBC
   float area2 = triangleArea (A, P, C);         //khu vuc APC
   float area3 = triangleArea (A, B, P);        //khu vuc ABP

   return (area == area1 + area2 + area3);        
}
 
int main() 
{
   TOADO A = {0, 0}, B={20, 0}, C={10, 30};
   TOADO P = {10, 15};
   if (isInside(A, B, C, P) == true)
      cout << endl << "Diem P nam trong tam giac ABC";
   else
      cout << endl << "Diem P nam ngoai tam giac ABC";
    return 0;
}
