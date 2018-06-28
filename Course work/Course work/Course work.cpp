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
	char a = '¤';
	setlocale(0, "rus");
	system("mode con cols=100 lines=20");
	::SetConsoleTitle(("English-Study Application"));

	while (a == '¤'){
		startTheGame();
		ClearScreen();
		beautifulOutput("                                        Начнем заново?[д/н]                                         ", 0);
		beautifulOutput("                    Добро пожаловать в приложение по изучению английского языка!                    ", 0);
		moveCursor(50, 1);
		cin >> a;
		if (a != '¤'){
			a = 'н';
		}
		ClearScreen();
	}
	
	 
}


void startTheGame(){
	system("color F0");
	setXCoord(0);
	setYCoord(0);
	
	int difficulty, typeOfGame;

	beautifulOutput("                    Добро пожаловать в приложение по изучению английского языка!                    ", 0);
	beautifulOutput("                        Приложение написано на C++ с использованием Win32API                        ", 0);
	beautifulOutput("                                  Мы надеемся, что вам понравится!                                  ", 0);
	beautifulOutput("", 2);
	beautifulOutput("                              Выберите один из трех уровней сложностей:                             ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              1. Легко                                              ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              2. Средне                                             ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                              3. Сложно                                             ", 1);

	moveCursor(50, 1);
	
	cin >> difficulty;
	ClearScreen();

	beautifulOutput("                                Выберите один из трех режимов игры:                                ", 0);
	beautifulOutput("", 2);
	beautifulOutput("                                        1. Сопоставление слов                                      ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                       2. Заполнение пропусков                                     ", 1);
	beautifulOutput("", 2);
	beautifulOutput("                                      3. Завершение определения                                    ", 1);
	moveCursor(50, 1);
	cin >> typeOfGame;
	ClearScreen();
	switch (typeOfGame){
	case 1: {wordMatching(difficulty); break; };
	case 2: {fillGap(difficulty); break; };
	case 3: {completeDefinition(difficulty); break; }
	default: {beautifulOutput("                                Вы промазали. Попробуйте еще раз!                                  ", 0); moveCursor(0, 1);   system("pause");  startTheGame(); }
	}
}

