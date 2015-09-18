// Charles Alan Macon
// CSCE 2110.001 - Fall 2014
// Program 2 - Tables

#include <iostream>
#include <sstream>
#include "grades.h"
#include "students.h"
#include "stuNode.h"

//#include "tuple.h"
//#include "Table.h"

using namespace std;

// Globals
students st_Students;
grades gt_Grades;

int main()
{
	int quit = 0;

	while (quit == 0)
	{
		string input;
		string textInput;
		string textInput2;
		string textInput3 = "";
		string textInput4 = "";
		string textInput5 = "";
		int numericInput = -1;

		stringstream ss;

		cout << "tables> ";
		getline(cin, input);

		ss << input;
		ss >> textInput >> textInput2 >> numericInput >> textInput3 >> textInput4 >> textInput5;

		if (textInput == "students")
		{
			if (textInput2 == "add")
			{
				if (numericInput != -1 && textInput3 != "" && textInput4 != "")
				{
					stuNode *s = new stuNode(numericInput, textInput3, textInput4);
					st_Students.addStudent(s);
				}
				else
				{
					cout << "Error: Student Must Have A Name" << endl;
				}
			}
			else if (textInput2 == "delete")
			{
				if (numericInput != -1)
				{
					st_Students.deleteS(numericInput);
				}
				else
				{
					cout << "Error: Must Include Student ID Number" << endl;
				}
			}
			else if (textInput2 == "display")
			{
				st_Students.print();
				cout << endl;
			}
			else
			{
				cout << "Error: Unrecognized Student Command" << endl;
			}
		}
		else if (textInput == "grades")
		{
			if (textInput2 == "add")
			{
				if (numericInput != -1 && textInput3 != "" && textInput4 != "")
				{
					if (textInput5 != "")
					{
						cout << "Error: Cannot Add Multiple Grades At Once" << endl;
					}
					else
					{
						gt_Grades.addGrade(numericInput, textInput3, textInput4);
					}
				}
				else
				{
					cout << "Error: Must Include Course And Grade" << endl;
				}
			}
			else if (textInput2 == "delete")
			{
				if (numericInput != -1)
				{
					gt_Grades.deleteG(numericInput);
				}
				else
				{
					cout << "Error: Must Include Student ID Number" << endl;
				}
			}
			else if (textInput2 == "display")
			{
				gt_Grades.print();
				cout << endl;
			}
			else
			{
				cout << "Error: Unrecognized Grade Command" << endl;
			}
		}
		else if (textInput == "quit")
		{
			quit = 1;
		}
		else
		{
			cout << "Error: Unrecognized Command" << endl;
		}

		//quit = 1;
	}

	// THIS WORKS
	//stuNode *s = new stuNode(5, "alan", "macon");
	//st_Students.studentTable[0] = s;
	//st_Students.studentTable[0]->print();
	//cout << endl;

	/*for (int i = 0; i < 4; i++)
	{
		// ADD STUDENTS
		stuNode *s = new stuNode(i, "ALAN", "MACON");
		st_Students.addStudent(s);

		graNode *g = new graNode(i, "COMPUTER", "A");
		gt_Grades.addGrade(g);
	}

	// PRINT STUDENTS
	st_Students.print();
	cout << endl;

	// PRINT GRADES
	gt_Grades.print();
	cout << endl;

	// PRINT SPECIFIC GRADE
	gt_Grades.print(2);
	cout << endl;

	// DELETE STUDENTS
	st_Students.deleteS(2);
	st_Students.print();	
	cout << endl;

	gt_Grades.print(2);
	cout << endl;*/

	// BEGIN SAMPLE INPUT

	//students add 123 josh smith
	/*stuNode *s = new stuNode(123, "josh", "smith");
	st_Students.addStudent(s);

	//students add 111 jim jones
	stuNode *q = new stuNode(111, "jim", "jones");
	st_Students.addStudent(q);

	gt_Grades.addGrade(123, "computers", "A");
	gt_Grades.addGrade(123, "biology", "C");
	gt_Grades.addGrade(123, "chemistry", "B");
	//grades display
	gt_Grades.print();
	// These should also be sorted by class name, somehow.
	cout << endl;

	//students display
	st_Students.print();
	cout << endl;

	//students delete 123
	st_Students.deleteS(123);

	//grades display
	gt_Grades.print();
	cout << endl;

	//students delete 111
	st_Students.deleteS(111);

	//students display
	st_Students.print();
	cout << endl;

	// END SAMPLE INPUT
	system("PAUSE");*/
}