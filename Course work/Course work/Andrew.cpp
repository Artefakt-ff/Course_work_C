#include "stdafx.h"
#include "iostream"
#include "main.h"
#include "fstream"
#include "ctime"
using namespace std;

const int easyTasks = 2;
const int mediumTasks = 2;
const int hardTasks = 2;

class TaskAndrew{
public:
	TaskAndrew(){}
	TaskAndrew(int d){
		difficulty = d;
		getFilename();
	}
	~TaskAndrew(){}
	int outputTaskAndrew(){
		int temp, count = 0;
		try{
			ifstream fout(filename);
			fout.getline(var1, 20);
			fout.getline(var2, 20);
			fout.getline(var3, 20);
			fout.getline(ans1, 20);
			fout.getline(ans2, 20);
			fout.getline(ans3, 20);
			for (int i = 0; i < numberOfVariants; i++){
				fout >> correctAnswers[i];
			}
			beautifulOutput("", 2);

			beautifulOutput(var1, 1);
			beautifulOutput(var2, 1);
			beautifulOutput(var3, 1);
			beautifulOutput("", 2);
			beautifulOutput(ans1, 0);
			moveCursor(strlen(ans1)+1, -1);
			cin >> temp;
			if (temp == correctAnswers[0]) count++; 
			beautifulOutput(ans2, 0);
			moveCursor(strlen(ans2) + 1, -1);
			cin >> temp;
			if (temp == correctAnswers[1]) count++;
			beautifulOutput(ans3, 0);
			moveCursor(strlen(ans3) + 1, -1);
			cin >> temp;
			if (temp == correctAnswers[2]) count++;
			fout.close();
			return count;
		}
		catch (fstream::failure e){
			beautifulOutput("                                        Задание недоступно.                                       ", 0);
		}
	}
	bool checkAnswer(){
		return true;
	}
private:
	char temp[20];
	int numberOfVariants = 3, difficulty;
	int correctAnswers[3];
	char filename[50], answer[20], var1[20], var2[20], var3[20], ans1[20], ans2[20], ans3[20];
	void getFilename(){
		int num;
		if (difficulty == 1){
			num = rand() % easyTasks;
			sprintf(filename, "andrew/wordMatching_easy/%d.txt", num);
		}
		else if (difficulty == 2){
			num = rand() % mediumTasks;
			sprintf(filename, "andrew/wordMatching_medium/%d.txt", num);
		}
		else {
			num = rand() % hardTasks;
			sprintf(filename, "andrew/wordMatching_hard/%d.txt", num);
		}
	}
};
void wordMatching(int difficulty){
	srand(time(0));
	setlocale(0, "rus");
	beautifulOutput("                              Вы выбрали задание на сопоставление слов.                             ", 0);
	beautifulOutput("                          Введите цифру, соответствующую правильному ответу                         ", 0);
	int rightAnswers = 0, i, numberOfTasks = difficulty * 2;
	TaskAndrew *arr = new TaskAndrew[numberOfTasks];
	for (i = 0; i < numberOfTasks; i++){
		arr[i] = TaskAndrew(difficulty);
	}
	for (i = 0; i < numberOfTasks; i++){
		beautifulOutput("", 2);
		rightAnswers += arr[i].outputTaskAndrew();
	}
	ClearScreen();
	outputResult(rightAnswers, numberOfTasks*3);
};
