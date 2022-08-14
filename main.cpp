#include <iostream>
#include <string>
#include "Students.h"

using namespace std;

int Menu() // Меню
{
	cout << "\t1) Вывести всех студентов" << endl;
	cout << "\t2) Вывести всех студентов по убыванию среднего балла" << endl;
	cout << "\t3) Вывести только отличников и хорошистов"  << endl;
	cout << "\t0) Выход" << endl << endl;
	int choice;
	cout << "Выберите действие\n";
	cin >> choice;
	return choice;
}

Students* CreateStudents() // Создание студентов
{
	static Students stud[5];
	stud[0].Set("Турин И.В.", "МТ6-33Б");
	stud[1].Set("Иванов У.Т.", "РК8-13Б");
	stud[2].Set("Перов Н.Л.", "СМ3-15");
	stud[3].Set("Липов А.А.", "ИУ7-31Б");
	stud[4].Set("Урин Т.В.", "РТ5-55");
	int g1[5] = { 5,4,4,3,5 };
	int g2[5] = { 5,5,5,5,5 };
	int g3[5] = { 5,4,4,2,5 };
	int g4[5] = { 3,3,4,5,4 };
	int g5[5] = { 4,3,4,3,4 };
	stud[0].SetGrades(g1);
	stud[1].SetGrades(g2);
	stud[2].SetGrades(g3);
	stud[3].SetGrades(g4);
	stud[4].SetGrades(g5);
	return stud;
}

double* FindAverage(Students* stud, int n) // Нахождение среднего балла
{
	double ave = 0.0;
	static double average[5] = { 0,0,0,0,0 };
	for (int i = 0; i < 5; i++)
	{
		int* arr = stud[i].GetGrades();
		ave = static_cast<double>((arr[0]) + arr[1] + arr[2] + arr[3] + arr[4]) / 5;
		average[i] = ave;
	}
    return average;
}

void Sort(Students stud[5]) // Сортировка пузырьком 
{
	double* average = FindAverage(stud, 5);
	string t1;
	string t2;
	double p;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (average[j] < average[j + 1])
			{
				p = average[j];
				average[j] = average[j + 1];
				average[j + 1] = p;
				t1 = stud[j].GetName();
				t2 = stud[j].GetGroup();
				stud[j].Set(stud[j + 1].GetName(), stud[j + 1].GetGroup());
				stud[j + 1].Set(t1, t2);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << stud[i].GetName() << "\t" << stud[i].GetGroup() << "\t\t" << average[i] << endl << endl;
	}
}

void Print(Students stud[5]) // Вывод всех студентов
{
	double* average = FindAverage(stud, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << stud[i].GetName() << "\t" << stud[i].GetGroup() << "\t\t" << average[i] << endl << endl;
	}
}

void PrintSmart(Students stud[5]) // Вывод отличников и хорошистов
{
	double* average = FindAverage(stud, 5);
	for (int i = 0; i < 5; i++)
	{
		int k = 0;
		int* gr = stud[i].GetGrades();
		for (int j = 0; j < 5; j++)
		{
			if (gr[j] == 3 || gr[j] == 2)
			{
				k++;
			}
		}
		if (k == 0)
		{
			cout << stud[i].GetName() << "\t" << stud[i].GetGroup() << "\t\t" << average[i] << endl << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Students* students = CreateStudents();
	while (true)
	{
		switch (Menu())
		{
		case 1:
			Print(students);
			break;
		case 2:
			Sort(students);
			break;
		case 3:
			PrintSmart(students);
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}