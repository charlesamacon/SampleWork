#include "students.h"
#include "grades.h"
#include <string>

extern grades gt_Grades;


students::students()
{
	index = 0;
}


students::~students()
{
}

void students::addStudent(stuNode *s)
{
	index = s->getID();

	if (studentTable[index] != NULL)
	{
		cout << "duplicate add student" << endl;
	}
	else
	{
		studentTable[index] = s;
	}
	//index++;
}

void students::print()
{
	bool firstPrint = false;

	// Print them in the order they were added
	//for (int i = 0; i < index; i++)
	//{
	//	studentTable[i]->print();
	//	if ((i + 1) < index)
	//	{
	//		cout << "-";
	//	}
	//}
	//
	//cout << endl;

	// Alternatively, do it this way to "sort" them.
	for (int i = 0; i < 999; i++)
	{
		if (studentTable[i] != NULL)
		{
			if (firstPrint)
			{
				cout << "-";
			}

			studentTable[i]->print();
			firstPrint = true;
		}
	}

	if (!firstPrint)
	{
		cout << "Student table empty";
	}
	return;
}

void students::deleteS(int id)
{
	// Check all values, why not.
	for (int i = 0; i < 999; i++)
	{
		// Should probably make sure that index isn't null before trying to get its value
		if (studentTable[i] != NULL)
		{
			if (studentTable[i]->getID() == id)
			{
				studentTable[i] = NULL;

				// RUN DELETE FUNCTION ON gt_grades
				// gt_Grades should do the same. Eventually, we'll remove all references to a
				// particular ID.

				gt_Grades.deleteG(id);
			}
		}
	}

	return;
}