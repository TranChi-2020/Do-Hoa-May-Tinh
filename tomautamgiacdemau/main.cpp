#include<iostream>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<cmath>

using namespace std;

struct ToaDo{
	int x;
	int y;
};

ToaDo A,B,C;

void inputToaDo(){
	cout<<"Nhap vao toa do diem A(x,y): ";
	cin >> A.x >> A.y;
	
	cout<<"Nhap vao toa do diem B(x,y): ";
	cin >> B.x >> B.y;
	
	cout<<"Nhap vao toa do diem C(x,y): ";
	cin >> C.x >> C.y;
}

float area(ToaDo A, ToaDo B, ToaDo C){
	float S = (abs((B.x*A.y-A.x*B.y)+(C.x*B.y-B.x*C.y)+(A.x*C.y-C.x*A.y)))/2;
	return S;
}

bool check(ToaDo P, ToaDo A, ToaDo B,ToaDo C){
	float sumArea = round(area(P,A,B)+ area(P,B,C)+area(P,A,C));
	float S = round(area(A,B,C));
	if(sumArea == S) return true;
	else return false;
}



void veTamGiac(ToaDo A, ToaDo B, ToaDo C){
	line(A.x,A.y,B.x,B.y);
	line(B.x,B.y,C.x,C.y);
	line(C.x,C.y,A.x,A.y);
}

int MIN(int a,int b){
	return a<b? a: b;
}

int MAX(int a, int b){
	return a>b? a : b;
}

void toMau(int minX, int maxX, int minY, int maxY){
	for(int x = minX; x<=maxX;x++){
		for(int y = minY; y <= maxY;y++){
			ToaDo P;
			P.x = x;
			P.y = y;
			if(check(P,A,B,C)){
				putpixel(x,y,BLUE);
			}
			
		}
	}
}
int main(){
	int gd,gm;
	inputToaDo();
	int minX = MIN(MIN(A.x,B.x),C.x);
	int maxX = MAX(MAX(A.x,B.x),C.x);
	int minY = MIN(MIN(A.y,B.y),C.y);
	int maxY = MAX(MAX(A.y,B.y),C.y);
	initgraph(&gd,&gm,"C://TC//BGI");
	veTamGiac(A,B,C);
	toMau(minX,maxX,minY,maxY);
	getch();
	closegraph();
	return 0;
	
}
