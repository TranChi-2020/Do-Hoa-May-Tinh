int netw;
/////////////////////////////////////////////////////////////////
class screen{
  public:
    int sx,sy;
    int w,h;
  screen(int sxx,int syy,int wid,int hgt){
    sx=sxx;
    sy=syy;
    w=wid;
    h=hgt;
    /////////////
    psx=sxx;
    psy=syy;
    pw=wid;
    ph=hgt;
    /////////////////
    netw=2*w;
   }

void start(snake *snk,updaters *mu,food *fud,int *d){
    mu->initboarder();
    fud->newfood();
    bool b=true;
    while(b){
        for(int j=sy-1;j<h+sy;j++){
            for(int i=sx-1;i<w+sx;i++){


                if((1== snk->checkbody(i,j) | fud->checkfood(i,j) | 1==mu->chkborder(i,j) )) //if(i<sx+w)
                    {gotoxy(i,j);cout<<"0";}
                else {gotoxy(i,j);cout<<" ";}
               /* if(mu->checkcoll(snk,i,j)) {
                        b=false;
                } */

                                     }
                                     /*
            for(int i=sx+w;i<2*w+sx;i++){
                 if((1== snk->checkbody(i,j) | fud->checkfood(i,j)  )){}
            }   */
                                }

            //
            snk->tear(sx,sy,w,h);
            mu->movsnk(snk,*d);
            mu->checkeat(snk,fud);
            if(snk->checkcoll()){b=false;}
            processvector(snk,fud);




            //gotoxy(4,24);
            //cout<<"fx="<<fud->fx<<",fy="<<fud->fy<<endl;
            Sleep(80);
            }//while ends

    system("cls");
	gotoxy(8,6);
	cout<<"GAME OVER!";
	Sleep(2500);
	ShellExecute( NULL, TEXT( "open" ), TEXT( "https://www.youtube.com/channel/UCAWvEudCuekhTEeewjuaDng/" ), NULL, NULL, 0 );

	int x;
	cin>>x;
}

void drawboarder(){



}
};



