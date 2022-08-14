#include "Students.h"
#include <iostream>
#include <string>

using namespace std;

string Students::GetName()
{
	return name;
}

string Students::GetGroup()
{
	return group;
}

int* Students::GetGrades()
{
	return grades;
}

void Students::Set(string name, string group)
{
	this->name = name;
	this->group = group;
}

void Students::SetGrades(int grades[5])
{
	for (int i = 0; i < 5; i++)
	{
		this->grades[i] = grades[i];
	}
}