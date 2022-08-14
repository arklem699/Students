#pragma once

#include <string>

using namespace std;

class Students
{
public:
	string GetName();
	string GetGroup();
	int* GetGrades();
	void Set(string name, string group);
	void SetGrades(int grades[5]);
private:
	string name;
	string group;
	int grades[5];
};