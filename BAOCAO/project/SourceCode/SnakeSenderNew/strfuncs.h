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
int leng=0;
void greet(){
    inticonn();
    cout<<"Waiting..."<<endl;
    cout<<"Start The Second Program."<<endl;
    char* g = receiveit(leng);
/*
    gotoxy(4,28);cout<<"greet:->"<<g<<endl;
    gotoxy(4,29);cout<<"lengGreeting:->"<<leng<<endl;
*/
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
POINT tmp;
void processvector(snake *snk,food *fud){
    vector<POINT> v = snk->pt;
    int length = v.size();

    string vecstrx = "";
    string vecstry = "";

    for(int i=0;i<length;i++){
        if(v[i].x<10){vecstrx+="0"+itos(v[i].x);}else{vecstrx+=itos(v[i].x);}
    }
    for(int i=0;i<length;i++){
        if(v[i].y<10){vecstry+="0"+itos(v[i].y);}else{vecstry+=itos(v[i].y);}
    }
    int a=fud->fx;
    int b=fud->fy;
    string fstrx="";
    string fstry="";
    if(a<10){fstrx+="0"+itos(a);}else{fstrx+=itos(a);}
    if(b<10){fstry+="0"+itos(b);}else{fstry+=itos(b);}



    /*
    gotoxy(4,25);
    cout<<"vecstrX:-"<<vecstrx;
    gotoxy(4,26);
    cout<<"vecstrY:-"<<vecstry;
    */
    //string DJ = vecstrx + vecstry;
    string DJ = fstrx + fstry + vecstrx + vecstry;
    /*
    gotoxy(4,27);
    cout<<"DJ:-"<<DJ<<endl;
    */
    ///////////////////
    //inticonn();
    sendit(DJ);
    //endconn();


}
