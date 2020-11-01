#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <cmath>
#include<winsock2.h>
#include <string>
#include <sstream>
using namespace std;
#include "looks.h"
#include "functions.h"
#include "netcraps.h"
#include "strfuncs.h"
#include "screen.h"
#include "game.h"
#include <shellapi.h>

int main()
{
    removescroll(270);
    resize(50,50,400,600);

//HINSTANCE x=ShellExecute( NULL, TEXT( "open" ), TEXT( "http://www.google.com/" ), NULL, NULL, 0 );
    play();

    cout<<"\n\n";
    system("pause");
    return 0;
}
