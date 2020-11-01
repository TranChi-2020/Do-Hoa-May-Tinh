
int psx,psy,pw,ph;
int border[100][100];
void initboarder(){
            for(int j=psy;j<ph+psy;j++){border[psx][j]=1;}
            for(int j=psy;j<ph+psy;j++){border[pw+psx][j]=1;}
            for(int i=psx;i<pw+psx;i++){border[i][psy]=1;}
            for(int i=psx;i<pw+psx+1;i++){border[i][ph+psy]=1;}

            for(int j=10;j<14;j++){border[psx][j]=0;}

            for(int j=0;j<100;j++){
                for(int i=0;i<100;i++){
                    if(border[i][j]==1){gotoxy(i,j);cout<<"0";}
                }
            }

}
int checkbord(int x, int y){
    int r=0;
if(border[x][y]==1){r=1;}else{r=0;}
return r;
}
int checkfrt(int x, int y){
    int r=0;
    if((fx==x)&(fy==y)){r=1;}
    return r;
}

int checkbody(int xx,int yy){
        int put=0;
        int s=pt.size();
        for(int i=0;i<s;i++){
            if((pt[i].x==xx)&(pt[i].y==yy)){put=1;}
        }
      return put;
    }

int bplay=1;
void checkColl(){
    int s=pt.size();
    temp=pt[s-1];
    if(border[temp.x-pw][temp.y]==1){
        bplay=0;
    }
    if(temp.y < psy | temp.y > psy+ph){
        bplay=0;
    }
}


/////////////////////////////////////
void play()
{
int sy=4,sx=4,w=35,h=16;
psx=sx;
psy=sy;
pw=w;
ph=h;

greet();
initboarder();
	while (bplay) {
	/*	b = getch();
		if(b=='a'){d=2;}else if(b=='d'){d=0;}else if(b=='w'){d=1;}else if(b=='s'){d=3;} */

            processvector();
            checkColl();
            ////////////////////////////////////////////////////////////////////////////////////////////
                    for(int j=sy+1;j<h+sy;j++){
            for(int i=sx+w;i<2*w+sx;i++){
                gotoxy(i-w,j);
                if(1== checkbody(i,j) )
                    {cout<<"0";}
                else if(checkfrt(i,j)==1){cout<<"0";}
                else if(checkbord(i-w,j)==1){cout<<"0";}
                //else if(checkColl(i,j)){gameover();}
                else {cout<<" ";}
                                    }
                                }
            /////////////////////////////////////////////////////////////////////////////////////////////

	}

	system("cls");
	gotoxy(8,6);
	cout<<"GAME OVER!";
		Sleep(2500);
	ShellExecute( NULL, TEXT( "open" ), TEXT( "https://www.youtube.com/channel/UCAWvEudCuekhTEeewjuaDng/" ), NULL, NULL, 0 );
	cin>>bplay;

}
//////////////////////////////////////

