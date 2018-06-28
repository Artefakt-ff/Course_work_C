#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "main.h"
#include "string"
#include "ctime"
using namespace std;

const int easyTasks = 2;
const int mediumTasks = 2;
const int hardTasks = 2;

class TaskNikita{
public:
	TaskNikita(){}
	TaskNikita(int d){
		difficulty = d;
		getFilename();
	}
	~TaskNikita(){}
	bool checkAnswer(){
		string answer;
		beautifulOutput("Введите ваш ответ:", 1);
		moveCursor(19, -1);
		cin >> answer;
		if (answer == theme){
			return true;
		}
		return false;
	}
	void outputTask(){
		try{
			ifstream fout(filename);
			int i = 0;
			char t[100];
			fout.getline(theme, 50);
			fout.getline(t, 100);
			beautifulOutput(t, 0);
			fout.close();
		}
		catch (fstream::failure e){
			beautifulOutput("                                        Задание недоступно.                                       ", 0);
		}
	}
private:
	char theme[50];
	char filename[50];
	int difficulty;
	void getFilename(){
		int num;
		if (difficulty == 1){
			num = rand() % easyTasks;
			sprintf(filename, "nikita/completeDefinition_easy/%d.txt", num);
		}
		else if (difficulty == 2){
			num = rand() % mediumTasks;
			sprintf(filename, "nikita/completeDefinition_medium/%d.txt", num);
		}
		else {
			num = rand() % hardTasks;
			sprintf(filename, "nikita/completeDefinition_hard/%d.txt", num);
		}
	}
};


void completeDefinition(int difficulty){
	srand(time(0));
	setlocale(0, "rus");
	beautifulOutput("                            Вы выбрали задание на завершение определения.                           ", 0);
	beautifulOutput("                               Напишите подходящее под определение слово                            ", 0);
	beautifulOutput("", 2);
	int rightAnswers = 0, i, numberOfTasks = difficulty*2;
	TaskNikita *arr = new TaskNikita[numberOfTasks];
	for (i = 0; i < numberOfTasks; i++){
		arr[i] = TaskNikita(difficulty);
	}
	for (i = 0; i < numberOfTasks; i++){
		arr[i].outputTask();
		if (arr[i].checkAnswer() == true){
			rightAnswers++;
		}
		beautifulOutput("", 2);
	}
	ClearScreen();
	outputResult(rightAnswers, numberOfTasks);

};