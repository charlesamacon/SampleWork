#include <iostream>
#include <sstream>
#include "tuple.h"
#include "Table.h"

using namespace std;

int main()
{
	int quit = 0;
	Table t_Students;
	Table t_Grades;


	while (quit == 0)
	{
		string input;
		string textInput;
		string textInput2;
		string textInput3;
		string textInput4;
		int numericInput = NULL;

		stringstream ss;

		cout << "tables> ";
		getline(cin, input);

		ss << input;
		ss >> textInput >> textInput2 >> numericInput >> textInput3 >> textInput4;

		quit = 1;
	}
}