
///////////////////////////////////////////////////////////////////////
int  border[100][100];
int psx,psy,pw,ph;
class food{
public:
    int fx,fy;
     //void newfood(int sx,int sy,int x,int y){
        //fx = sx + rand()%x;
        //
    //}
    void newfood(){
        //fx[5,38] inclusive, fx[40,73] inclusive
        //fy[5,19] inclusive
        fx=rand()%69+5;
        fy=rand()%15+5;
        //fx=73;fy=7;
        if(fx==40){
                //this->newfood();
                fx=43;
        }
    }
    int checkfood(int x,int y){
        int r=0;
        if(fx==x&fy==y){r=1;}
        return r;
    }
};
///////////////////////////////////////////////////////////////////////////
class snake{
    public:
vector<POINT> pt;
int put,s;
POINT temp;
    snake(){
       addpt(5,5);
       addpt(6,5);
       addpt(7,5);
    }
    int checkbody(int xx,int yy){
        put=0;
        s=pt.size();
        for(int i=0;i<s;i++){
            if((pt[i].x==xx)&(pt[i].y==yy)){put=1;}
        }
      return put;
    }
    int chktip(int xx,int yy){
        put=0;
        s=pt.size();
        temp=pt[s];
    if((temp.x==xx)&(temp.y==yy)){put=1;}
      return put;
    }
    int checkcoll(){
        int r=0;
        s=pt.size();
        temp=pt[s-1];
        if( border[temp.x][temp.y] == 1 ){
                //gotoxy(4,1);cout<<"game over!";
                r=1;
        }
        if(temp.y >= psy+ph | temp.y<= psy ){
            r=1;
        }
        if(temp.x<= psx+1 ){
            r=1;
        }
        return r;
    }
    void tear(int sx,int sy,int w,int h){
        s=pt.size();
        temp=pt[s-1];
        //temp.x=; temp.y=;
        if(temp.x>sx+w*2){temp.x=sx;pt.push_back(temp); delptb();}
        else if(temp.x<sx){temp.x=sx+w*2;pt.push_back(temp); delptb();}

        if(temp.y>sy+h){temp.y=sy;pt.push_back(temp); delptb();}
        else if(temp.y<sy){temp.y=sy+h;pt.push_back(temp); delptb();}

            //gotoxy(4,23);
            //cout<<"temp.x,temp.y:---"<<temp.x<<","<<temp.y<<endl;


    }

    void addpt(int xx,int yy){
        temp.x=xx;temp.y=yy;
        pt.push_back(temp);
    }
    void delptb(){
        pt.erase(pt.begin()+0);
    }
};
///////////////////////////////////////////////////////////////////////////
class updaters{
public:
    int las;
    POINT mpt;
    int vx,vy;
void movsnk(snake* snk,int direction){
        las=snk->pt.size();
        mpt=snk->pt[las-1];
        ////
             if(direction==0){vx=1;vy=0;}
        else if(direction==1){vx=0;vy=-1;}
        else if(direction==2){vx=-1;vy=0;}
        else if(direction==3){vx=0;vy=1;}
        ////
        snk->addpt(mpt.x+vx,mpt.y+vy);
        snk->delptb();
     }
//

void checkeat(snake* snk,food* fud){
        las=snk->pt.size();
        mpt=snk->pt[las-1];
        //if(mpt.x==fud->fx&mpt.y==fud->fy){
        if(fud->checkfood(mpt.x,mpt.y)){
            //snk->addpt(mpt.x+vx,mpt.y+vy);
            snk->addpt(fud->fx+vx,fud->fy+vy);
            fud->newfood();
        }

     }

     //
//////////////////////////////////////////////////////////
///////////file functions start///////////////////////////
void initboarder(){
    for(int j=0;j<100;j++){
        for(int i=0;i<100;i++){
            border[i][j]=0;
        }
    }
            for(int j=psy;j<ph+psy;j++){border[psx][j]=1;}
            for(int j=psy;j<ph+psy;j++){border[pw+psx][j]=1;}
            for(int i=psx;i<pw+psx;i++){border[i][psy]=1;}
            for(int i=psx;i<pw+psx+1;i++){border[i][ph+psy]=1;}

            for(int j=10;j<14;j++){border[pw+psx][j]=0;}


            for(int j=0;j<100;j++){
                for(int i=0;i<100;i++){
                    if(border[i][j]==1){gotoxy(i,j);cout<<"8";}
                }
            }

}
////////////////////////////////////// end of blessit
int chkborder(int i , int j){
    int r=0;
    if(border[i][j]==1) {r=1;}
    //r=border[i][j];

    return r;
}
//////////////////////////////////////////////////


};
