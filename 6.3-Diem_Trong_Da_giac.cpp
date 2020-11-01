#include<iostream>
#include<cmath>


using namespace std;

struct toado 
{
	int x;
	int y;
};


float dientich ( toado a, toado b, toado c)
{
	return fabs(a.x*b.y -a.y*b.x + b.x*c.y -b.y*c.x + c.x*a.y -c.y*a.x)	;
}

int main()
{
	int n;
	cin >> n ;
	
	toado 	s[n],p;
	for ( int i = 0 ; i < n ; i ++ )
	{
		cin>>s[i].x>>s[i].y;
	}
	
	cin>>p.x>>p.y;
	
	s[n].x = s[0].x;
	s[n].y = s[0].y; 
	
	float s2 = 0 , s1 = 0 ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		s2 = s2 + ( s[i].x*s[i+1].y - s[i].y*s[i+1].x);
		s1 = s1 + dientich(p,s[i],s[i+1]);
	}
	if ( fabs(s2) == fabs(s1) )
		cout<<"true";
	else
		cout<<"false";
	return 0;
}
