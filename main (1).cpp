#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a,b,c;

    cout<<"nhap vao gia tri A,B,C ="<<endl;
    cin>>a>>b>>c;
    float delta = (b*b) - (4*a*c);
    if(a==0)
    {
       if(b==0)
         {
             if(c==0)
             {
                 cout<<"\nphuong trinh vo so nghiem";
             }
             else
             {
                 cout<<"\nphuong trinh vo nghiem";
             }
         }
        else if(b!=0)
         {
        cout<<"Phuong trinh co nghiem la :"<<-c/b;
         }
    }
    else if(a!=0)
    {

        if(delta<0)
        {
            cout<<"phuong trinh vo nghiem";
        }
        else if(delta=0)
        {
            cout<<"phuong trinh co nghiem kep ="<<-b/2*a;
        }
        else
        {
            cout<<"phuong trinh co hai nghiem phan biet la";
            cout<<"x1: "<<(float)( - b + sqrt(delta))/(2*a)<<"\n";
            cout<<"x2: "<<(float)( - b - sqrt(delta))/(2*a)<<endl;
        }
    }
    return 0;
}
