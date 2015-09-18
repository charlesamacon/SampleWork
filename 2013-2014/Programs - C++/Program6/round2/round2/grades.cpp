#include "grades.h"
#include "students.h"
#include <iostream>
#include <string>
#include <algorithm>

extern students st_Students;

using namespace std;

grades::grades()
{
	index = 0;

	for (int i = 0; i < 1000; i++)
	{
		gradeArray[i].id = -1;
	}
}


grades::~grades()
{
}

void grades::addGrade(int i, string c, string g)
{
	bool gradeAdded = false;
	bool duplicateGrade = false;

	// Create a grade object
	grade gr;
	gr.id = i;
	gr.s_course = c;
	gr.s_grade = g;

	// Check for an existing grade for this course
	for (int i = 0; i < 1000; i++)
	{
		if (gradeArray[i].id == gr.id)
		{
			if (gradeArray[i].s_course == gr.s_course)
			{
				duplicateGrade = true;
			}
		}
	}

	// If there isn't a duplicate grade, add this grade to the first open spot
	if (!duplicateGrade)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (gradeArray[i].id == -1 && !gradeAdded)
			{
				gradeArray[i] = gr;
				gradeAdded = true;
			}
		}
	}
	else
	{
		cout << "Duplicate Add Grade for a Student" << endl;
	}

	// Finally, sort the grades.
	sort();
}

void grades::print()
{
	sort();
	bool firstPrint = false;

	for (int i = 0; i < 1000; i++)
	{
		// Print all grades that actually exist
		if (gradeArray[i].id != -1)
		{
			if (firstPrint)
			{
				// Place a dash before every grade but the first
				cout << "-";
			}
			cout << "(" << gradeArray[i].id << "," << gradeArray[i].s_course << "," << gradeArray[i].s_grade << ")";
			firstPrint = true;
		}
	}

	if (!firstPrint)
	{
		cout << "Grade table empty";
	}
}

void grades::sort()
{
	std::sort(gradeArray, gradeArray + 1000);
}

void grades::deleteG(int id)
{
	
	for (int i = 0; i < 1000; i++)
	{
		if (gradeArray[i].id == id)
		{
			gradeArray[i].id = -1;
			gradeArray[i].s_course = "";
			gradeArray[i].s_grade = "";

			// Could probably do some better memory work here, but there's no point.
		}
	}

	sort();
	return;
}