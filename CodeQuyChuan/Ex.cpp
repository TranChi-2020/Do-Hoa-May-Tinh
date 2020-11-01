#include <iostream>
#include <windows.h>
#include <conio.h>
#include <graphics.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <tchar.h>
#include <strsafe.h>
#include <wincon.h>
#include <vector>
#include <stdio.h>
#include <cwchar>
#include <math.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setWindowAndTitle(int size) {
	TCHAR szOldTitle[MAX_PATH];
	TCHAR szNewTitle[MAX_PATH];
	// Save current console title.
	if( GetConsoleTitle(szOldTitle, MAX_PATH) )
	{
		// Build new console title string.
		StringCchPrintf(szNewTitle, MAX_PATH, TEXT("CHUONG TRINH DO HOA"), szOldTitle);
		SetConsoleTitle(szNewTitle);
	}
	
	//Full screen
	COORD Coord;
	CONSOLE_FONT_INFOEX cfi;
	
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &Coord);
}

void setTextColor(int color, string text) {
	//Set color
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	SetConsoleTextAttribute(hConsole, WHITE);
}

void endAlgorithm() {
	moveto(10, 10);
	setbkcolor(YELLOW);
	setcolor(RED);
	outtext("");
	settextstyle(EUROPEAN_FONT, 0, 2);
	outtext("Chuong trinh da thuc hien thanh cong! Nhan mot phim bat ky de dung.");
	setbkcolor(BLACK);
	
	setTextColor(BLUE, "Nhan mot phim bat ky de dung: ");
	system("pause");
	
	closegraph();
}

// EDIT: Thiet lap thuat toan
// NEW: Them thuat toan duoi day

class DDA {
	private:
		string name;
	public:
		#define Round(a) int(a + 0.00005)
		
		string getName() {
			name = "DDA";
			return name;
		}
		
		int color = GREEN;
		
		void dtDDA(int x1, int y1, int x2, int y2) {
			int x = x1;
			float y = y1;
			float m = float(y2 - y1)/(x2 - x1);
			putpixel(x, Round(y), color);
			for(int i = x1; i < x2; i++) {
				x++;
				y += m;
				putpixel(x, Round(y), color);
				delay(0);
			}
		}
		
		void init() {
		   	int color;
		   	struct arccoordstype a, b;
			initwindow(1280, 720);
			dtDDA(100, 100, 1000, 600);
		}
};

///////////////////////////////////

// CAC THUAT TOAN

// NEW: Khai bao thuat toan

DDA dda;

///////////////////////////////////

// EDIT: Khoi tao cac thuat toan
void initAlgorithm(string index) {
	SelectAl:
	setTextColor(BLUE, "Chuong trinh so: ");
	cin >> index;
	int i = atoi(index.c_str());
	
	switch (i)
		{
			// Khoi tao cac thuat toan
			// NEW: Khoi tao them thuat toan duoi day
			
			case 1: 
				
				dda.init();
				endAlgorithm();
				break;
				
			///////////////////////////////////
			
			default: 
				setTextColor(LIGHTRED, "Ban da nhap khong chinh xac. Vui long nhap lai!\n\n");
				goto SelectAl;
				break;
		}
}

// EDIT
void algorithms() {
	string index;
	
	setTextColor(BLUE, "\nHay nhap so chuong trinh duoi day: \n\n");
	
	string options =
	
			//NEW: Them thuat toan vao dong hien thi
			
		   + " 1. " + dda.getName() + ".\n"
		   
		   ///////////////////////////////////
		   
		   + "\n";
	setTextColor(LIGHTBLUE, options);
	
	initAlgorithm(index);
}

char Continue(string con) {
	Continue:
	setTextColor(BLUE, "\nBan co muon tiep tuc? (c: co; k: khong)\n");
	cin >> con;
	char c = con.at(0);
	
	if (c != 'c' && c != 'k')
	{
		setTextColor(RED, "Cau tra loi khong hop le!\n");
		goto Continue;
	}
	return c;
}

void init() {
	//Title
	
	setTextColor(LIGHTRED, "CHUONG TRINH DO HOA\n");
	
	string con = "c";
	char c = con.at(0);
	do
	{
		algorithms();
		
		c = Continue(con);
	}
	while(c == 'c');
	
	setTextColor(YELLOW, "\nGood bye!\n\n");
}

void endProgram() {
	cout << "===========================================" << endl;
	system("pause");
}

int main()
{
	// EDIT: Mo console va dat kich thuoc
	
	setWindowAndTitle(35); // Edit: Chi thay doi doi so
	
	///////////////////////////////////

	init();
	
	// EDIT: Giu console khi chi chay file .exe
	
	//	endProgram(); // Edit: Co the comment.
	
	///////////////////////////////////
	
	return 0;
}
