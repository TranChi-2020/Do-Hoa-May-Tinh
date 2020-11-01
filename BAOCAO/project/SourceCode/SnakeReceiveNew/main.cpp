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
#include "netcraps.h"
#include "strfuncs.h"
#include "functions.h"

int main()
{
    removescroll(270);
    resize(490,50,400,600);

    play();
    system("pause");
    return 0;
}
