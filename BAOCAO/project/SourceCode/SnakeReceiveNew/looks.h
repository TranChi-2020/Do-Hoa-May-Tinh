/*
#include <iostream>

#include "windows.h"
#include "conio.h"
using namespace std;
*/

void gotoxy(int x, int y);
//  HWND WINAPI GetConsoleWindow(void);
// define _WIN32_WINNT as 0x0500
// headers Wincon.h ( Windows.h )
///////////////////////////////////////
//BOOL WINAPI SetWindowPos(HWND hwnd,HWND insurtAfter,int x,int y,int cx, int cy, UINT uflags);
//                                ,HWND_TOP,        ,new pos   , new width n h, 0X4000,2000,0020,0080,0010...


void resize(int x,int y,int w,int h)
{
    HWND hand = GetConsoleWindow();
    SetConsoleTitle("Chat Program");
    SetWindowPos(hand,HWND_TOP,x,y,w, h, 0X2000);

}
const WORD colors[] = {0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};

	HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
//input console colors
void incol(){
    SetConsoleTextAttribute( hstdin, 0x0C );
}
/////////////input colors end//////////////////////

/////////////output console colors
	void blue(){
//blue
	//SetConsoleTextAttribute( hstdout, 0x01 );
	SetConsoleTextAttribute( hstdout, 0x09 );
	}
	void green(){
//green
	//SetConsoleTextAttribute( hstdout, 0x02 );
	SetConsoleTextAttribute( hstdout, 0x0A );
	}
	void red(){
//red
	//SetConsoleTextAttribute( hstdout, 0x04 );
	SetConsoleTextAttribute( hstdout, 0x0C );
	}
	void yellow(){
//yellow============
	//SetConsoleTextAttribute( hstdout, 6 );
	SetConsoleTextAttribute( hstdout, 14 );
	}
	void pink(){
//purple,pink,magenta
	//SetConsoleTextAttribute( hstdout, 0x05 );
	SetConsoleTextAttribute( hstdout, 0x0D );
	}
	void cyan(){
//aqua,cyan===============
	//SetConsoleTextAttribute( hstdout, 3 );
	SetConsoleTextAttribute( hstdout, 11 );
	}
	void white(){
//aqua,cyan===============
	//SetConsoleTextAttribute( hstdout, 3 );
	SetConsoleTextAttribute( hstdout, 15 );
	}
/////////////output console colors end
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////////////////////
void removescroll(int n){
    //SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
//    HWND x = GetConsoleWindow();
//    ShowScrollBar(x, SB_BOTH, FALSE);
    //////////////////////////////////
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    COORD NewSBSize;
    int Status;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hOut, &SBInfo);
    NewSBSize.X = SBInfo.dwSize.X - 0;
    NewSBSize.Y = SBInfo.dwSize.Y - n;

    Status = SetConsoleScreenBufferSize(hOut, NewSBSize);
    if (Status == 0)
    {
        Status = GetLastError();
        cout << "SetConsoleScreenBufferSize() failed! Reason : " << Status << endl;
        exit(Status);
    }

    GetConsoleScreenBufferInfo(hOut, &SBInfo);
/*
    cout << "Screen Buffer Size : ";
    cout << SBInfo.dwSize.X << " x ";
    cout << SBInfo.dwSize.Y << endl;
*/
}
