//#ifndef GAME_H_INCLUDED
//#define GAME_H_INCLUDED
//
//void initGrid(int, int);
//void drawGrid();
//
//#endif

/*
#include "functions.h"
#include "screen.h"
*/
DWORD WINAPI ThreadFn(LPVOID vpParam);
int b,d=0;
/////////////////////////////////////
void play(){
greet();
/////////
    DWORD tid;
	HANDLE hThread = CreateThread(0, 0, ThreadFn, 0, 0, &tid);
/////////
system("cls");
snake mysnk;
updaters myups;
food myfud;
//myfud.newfood();

screen myscrn(4,4,35,16);
myscrn.start(&mysnk,&myups,&myfud,&d);


CloseHandle(hThread);
}
/////////////////////////////////////
DWORD WINAPI ThreadFn(LPVOID vpParam){

	while (1) {
		//b = getch(); if(b=='a'){d=2;}else if(b=='d'){d=0;}else if(b=='w'){d=1;}else if(b=='s'){d=3;}
		for(int i=8;i<=190;i++)
            {
               if(GetAsyncKeyState(i)==-32767){
               if(i==37){d=2;}else if(i==39){d=0;}else if(i==38){d=1;}else if(i==40){d=3;}

               }

            }
	}
	return 0;
}
