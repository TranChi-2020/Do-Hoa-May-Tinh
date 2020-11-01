//////////////////////////////string to int converter
int stoi(string Text)
{
int sresult;//number which will contain the result
stringstream sconvert(Text); // stringstream used for the conversion initialized with the contents of Text
sconvert >> sresult; //give the value to Result using the characters in the string
return sresult;
}
/////////////////////////////////////////////////////
//////////////////////////////int to string converter
string itos(int Number)
{
string Result;//string which will contain the result
stringstream convert; // stringstream used for the conversion
convert << Number;//add the value of Number to the characters in the stream
Result = convert.str();//set Result to the content of the stream
return Result;
}
///////////////////////////////////////////////////////////////net part end////////////////////////////////
void greet(){
    inticonn();
    sendit("hey");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* data=NULL;
int length=0;
string dt,dx,dy;
string ft,sfx,sfy;
int fx,fy;
int m;

vector<POINT> pt;
POINT temp;

void processvector(){
//inticonn();
data = receiveit(length);
//endconn();
data[length]=0x0;
/*
//system("cls");
gotoxy(4,4);
cout<<"data:"<<data;   cout<<endl;
gotoxy(4,5);
cout<<"length:"<<length;   cout<<endl;
*/
string tmp=data;
ft=tmp.substr(0,4);
//gotoxy(4,1);cout<<"ft="<<ft;
sfx=ft.substr(0,2);
sfy=ft.substr(2);
//gotoxy(4,1);cout<<"sfx="<<sfx;cout<<" - ";cout<<"sfy="<<sfy;
fx=stoi(sfx);
fy=stoi(sfy);

dt=tmp.substr(4);
m=(length-4)/2;
dx=dt.substr(0,m);
dy=dt.substr(m);
/* gotoxy(11,5);
cout<<"m="<<m;
gotoxy(4,6);
cout<<"dx="<<dx;
gotoxy(4,7);
cout<<"dy="<<dy;  */
string x,y;
int ind=0;
//gotoxy(4,9);
int nnn=pt.size();
for(int i=0;i<nnn;i++){
    pt.erase(pt.begin()+0);
}
for(int i=0;i<m/2;i++){
    x=dx.substr(0,2);
    y=dy.substr(0,2);

    dx=dx.substr(2);
    dy=dy.substr(2);
    //cout<<x<<" , "<<y<<endl;

    temp.x=stoi(x);
    temp.y=stoi(y);
    pt.push_back(temp);
}


}




