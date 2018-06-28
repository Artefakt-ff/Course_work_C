#include "stdafx.h"
#include "iostream"
#include "main.h"
#include "fstream"
#include "ctime"
using namespace std;

const int easyTasks = 2;
const int mediumTasks = 2;
const int hardTasks = 2;



class TaskSlava{
public:
	TaskSlava(){}
	TaskSlava(int d){
		difficulty = d;
		getFilename();
	}
	~TaskSlava(){}
	void outputTask(){
		try{
			ifstream fout(filename);
			char t[200];
			fout.getline(var1, 20);
			fout.getline(var2, 20);
			fout.getline(var3, 20);
			fout.getline(answer, 20);
			fout.getline(t, 100);
			beautifulOutput(t, 0);
			beautifulOutput(var1, 1);
			beautifulOutput(var2, 1);
			beautifulOutput(var3, 1);
			
			fout.close();
		}
		catch (fstream::failure e){
			beautifulOutput("                                        Задание недоступно.                                       ", 0);
		}
	}
	bool checkAnswer(){
		beautifulOutput("Введите ваш ответ:", 0);
		moveCursor(19, -1);
		cin >> temp;
		if ((int)temp == (int)answer+20){
			return true;
		}
		return false;
	}
private:
	int difficulty;
	char filename[50], var1[20], var2[20], var3[20], answer[20], temp[20];
	void getFilename(){
		int num;
		if (difficulty == 1){
			num = rand() % easyTasks;
			sprintf(filename, "slava/fillGap_easy/%d.txt", num);
		}
		else if (difficulty == 2){
			num = rand() % mediumTasks;
			sprintf(filename, "slava/fillGap_medium/%d.txt", num);
		}
		else {
			num = rand() % hardTasks;
			sprintf(filename, "slava/fillGap_hard/%d.txt", num);
		}
	}
};
void fillGap(int difficulty){
	srand(time(0));
	setlocale(0, "rus");
	beautifulOutput("                           Напишите цифру, соответствующую верному слову                            ", 0);
	int rightAnswers = 0, i, numberOfTasks = difficulty * 2;
	TaskSlava *arr = new TaskSlava[numberOfTasks];
	for (i = 0; i < numberOfTasks; i++){
		arr[i] = TaskSlava(difficulty);
	}

	for (i = 0; i < numberOfTasks; i++){
		arr[i].outputTask();
		if (arr[i].checkAnswer() == true){
			rightAnswers++;
		}
		ClearScreen();
	}
	outputResult(rightAnswers, numberOfTasks);
};
