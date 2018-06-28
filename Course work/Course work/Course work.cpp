#include "stdafx.h"
#include "fstream"
#include "main.h"
#include "ctime"
#include "header.h"
#include "iostream"
using namespace std;

void startTheGame();

//fixed size: 60 characters

void main()
{
	char a = '�';
	setlocale(0, "rus");
	system("mode con cols=100 lines=20");
	::SetConsoleTitle(("English-Study Application"));

	while (a == '�'){
		startTheGame();
		ClearScreen();
		beautifulOutput("                                        ������ ������?[�/�]                                         ", 0);
		beautifulOutput("                    ����� ���������� � ���������� �� �������� ����������� �����!                    ", 0);
		moveCursor(50, 1);
		cin >> a;
		if (a != '�'){
			a = '�';
		}
		ClearScreen();
	}
	
	 
}


void startTheGame(){
	system("color F0");
	setXCoord(0);
	setYCoord(0);
	
	int difficulty, typeOfGame;

	beautifulOutput("                    ����� ���������� � ���������� �� �������� ����������� �����!                    ", 0);
	beautifulOutput("                        ���������� �������� �� C++ � �������������� Win32API                        ", 0);
	beautifulOutput("                                  �� ��������, ��� ��� ����������!                                  ", 0);
	beautifulOutput("", 2);
	beautifulOutput("                              �������� ���� �� ���� ������� ����������:                             ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              1. �����                                              ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              2. ������                                             ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              3. ������                                             ", 1);

	moveCursor(50, 1);
	
	cin >> difficulty;
	ClearScreen();

	beautifulOutput("                                �������� ���� �� ���� ������� ����:                                ", 0);
	beautifulOutput("", 2);
	beautifulOutput("                                        1. ������������� ����                                      ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                       2. ���������� ���������                                     ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                      3. ���������� �����������                                    ", 1);
	moveCursor(50, 1);
	cin >> typeOfGame;
	ClearScreen();
	switch (typeOfGame){
	case 1: {wordMatching(difficulty); break; };
	case 2: {fillGap(difficulty); break; };
	case 3: {completeDefinition(difficulty); break; }
	default: {beautifulOutput("                                �� ���������. ���������� ��� ���!                                  ", 0); moveCursor(0, 1);   system("pause");  startTheGame(); }
	}
}

