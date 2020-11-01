#include <iostream>
#include<cmath>
using namespace std;

struct Point {
   int x, y;
};

float triangleArea(Point p1, Point p2, Point p3) {         //find area of triangle formed by p1, p2 and p3
   return abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.yp2.y))/2.0);
}

bool isInside(Point p1, Point p2, Point p3, Point p) {     //check whether p is inside or outside
   float area = triangleArea (p1, p2, p3);          //area of triangle ABC
   float area1 = triangleArea (p, p2, p3);         //area of PBC
   float area2 = triangleArea (p1, p, p3);         //area of APC
   float area3 = triangleArea (p1, p2, p);        //area of ABP

   return (area == area1 + area2 + area3);        //when three triangles are forming the whole triangle
}
 
int main() {
   Point p1={0, 0}, p2={20, 0}, p3={10, 30};
   Point p = {10, 15};
   if (isInside(p1, p2, p3, p))
      cout << "Point is inside the triangle.";
   else
      cout << "Point is not inside the triangle";
}
