#pragma once
#include <iostream>
#include <string>

// Without this one line, everything falls apart on the CSE machine.
using namespace std;

struct grade
{
	int id;
	string s_course;
	string s_grade;

	// OVERLOADED < OPERATOR
	bool operator<(const grade& rhs) const
	{
		int sort_by;

		if (id == rhs.id)
		{
			sort_by = 2;
		}
		else
		{
			sort_by = 1;
		}

		if (sort_by == 1) return id < rhs.id;
		
		return s_course < rhs.s_course;
	}
};
class grades
{
private:
	grade gradeArray[1000];
	int index;
public:
	grades();
	~grades();

	void addGrade(int i, string c, string g);
	void print();
	void deleteG(int id);
	void sort();
};

