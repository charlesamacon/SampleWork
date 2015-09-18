/******************
Name: Charles Alan Macon
Course: CSCE 3110
Assignment: Programming Assignment 1 - Starter Program
Due Date: Saturday, June 20, 2015
******************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int arr[10][10];		// Global variables are "bad", but so so fun.

ifstream myfile ("program1input.dat");

void input();			// Forward declaration, because reasons.
void output();

int main()
{
	input();
	output();

	return 0;
}

void input()
{
	string line;
	string inputArr[10];
	int i = 0;

	while (getline(myfile, line))				// While we have input....
	{
		int j = 0;
		stringstream ssin(line);

		while (ssin.good() && j < 10)
		{
			ssin >> inputArr[j];			// ...save input in string array
			j++;
		}

		for (int k = 0; k < 10; k++)
		{
			arr[i][k] = atoi(inputArr[k].c_str());	// Convert to int
		}
		i++;										// Move to next i index
	}


	return;
}

void output()
{
	// Not sure if we're supposed to output to console or to a file,
	// So we'll do both.

	ofstream outFile("output.txt");						//Create file "output.txt"
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(3) << arr[i][j] << " ";		// Output to console
			outFile << setw(3) << arr[i][j] << " ";		// Output to file
		}
		outFile << endl;
		cout << endl;
	}

	return;
	// Simple enough.
}