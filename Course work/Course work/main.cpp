#include "stdafx.h"
#include "windows.h"
#include "iostream"
using namespace std;

void * hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord1;

WORD task = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
WORD answer = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE;
WORD enter = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;


void beautifulOutput(LPCSTR text, int a){
	WORD attributes;
	switch (a){
	case 0: {attributes = task; break; }
	case 1: {attributes = answer; break; }
	default: {attributes = enter;}
	}
	DWORD cWritten;
	char temp[255];
	CharToOem(text, temp);
	WriteConsoleOutputCharacter(hStdout, temp, lstrlen(temp), coord1, &cWritten);
	for (int i = 0; i < lstrlen(temp); i++) {
		coord1.X = i;
		WriteConsoleOutputAttribute(hStdout, &attributes, 1, coord1, &cWritten);
	}
	coord1.Y++;
	coord1.X = 0;
}

void moveCursor(int x, int y){
	coord1.X = x;
	coord1.Y += y;
	SetConsoleCursorPosition(hStdout, coord1);
	coord1.X = 0;
	coord1.Y++;
}
void setXCoord(int x){
	coord1.X = x;
}
void setYCoord(int y){
	coord1.Y = y;
}
void changeXCoord(int x){
	coord1.X += x;
}
void changeYCoord(int y){
	coord1.Y += y;
}

void outputResult(int rightAnswers, int numberOfQuestion){
	beautifulOutput("                                                                                                    ", 0);
	moveCursor(0, 1);
	cout << "Вы правильно сделали " << rightAnswers << " из " << numberOfQuestion << " заданий";
	moveCursor(0, 1);
	cout << "Ваша оценка - " << round((float)rightAnswers / numberOfQuestion * 100) << "%" << endl;
	moveCursor(0, 1);
	beautifulOutput("                                                                                                    ", 0);
	system("pause");
}
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;


	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;
	setYCoord(0);
	setXCoord(0);
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
