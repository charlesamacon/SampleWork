// Charles Alan Macon
// CSCE 2110 - Fall 2014
// Programming Assignment 1

// "Open Hash Table"
// "Fun for the whole family."
// "2 Thumbs Up."

// - Additional Error Checking:
//
// - Checks to make sure that given input is what it's supposed to be,
// - otherwise, the program lets the user know that the command given
// - is invalid. The program also checks to make sure that all functions
// - that are supposed to be given an int are ACTUALLY GIVEN AN INT.

#include <iostream>
#include <sstream>
#include "HashTable.h"
#include "Node.h"

using namespace std;

bool isValidInput(string i);
void doInput(string i);
void doInput(string i, int x);
HashTable ht;

int main()
{
	int quit = 0;

	while (quit == 0)
	{
		string input = "";
		string textInput;
		int numericInput = NULL;
		stringstream ss;

		// Boilerplate stuff I've written a million times
		cout << "set> ";
		getline(cin, input);

		ss << input;
		ss >> textInput >> numericInput;

		if (isValidInput(textInput))
		{
			if (numericInput != NULL)
			{
				if (textInput == "add" || textInput == "delete" || textInput == "search")
				{
					// Use this version of doInput(s,i)
					doInput(textInput, numericInput);
				}
				else
				{
					cout << "Error: Invalid Command Combination." << endl;
				}
			}
			else if (numericInput == NULL && textInput != "quit")
			{
				if (textInput == "add" || textInput == "delete" || textInput == "search")
				{
					cout << "Error: Invalid Command Combination." << endl;
				}
				else
				{
					// Or use this version of doInput(s)
					doInput(textInput);
				}
			}
			else if (textInput == "quit")
			{
				// Quit if told to.
				quit = 1;
				break;
				// Groundbreaking.
			}
			else
			{
				// This shouldn't ever be seen, but just in case.
				cout << "Error: Invalid Command" << endl;
			}
		}
		else
		{
			// DO IT AGAIN, BUT CORRECTLY
			cout << "Error: Unrecognized Command!" << endl;
		}

		// The best way I've found to clear cin
		//cout << "Please press any key to continue..." << endl;
		//cin.ignore();
		// Irrevelant at this point, however.
	}
	return 0;
}

bool isValidInput(string i)
{
	if (i == "add" || i == "delete" || i == "search" || i == "show" || i == "quit")
	{
		// If the command given is on this list, continue...
		return true;
	}
	else
	{
		// Otherwise, call the bouncer over...
		return false;
	}
}

void doInput(string i)
{
	if (i == "show")
	{
		ht.print();
	}
	else
	{
		cout << "Error: Unknown command." << endl; // Probably won't ever see this.
	}
	return;
}

void doInput(string i, int x) // OVERLOADED FUNCTIONS ARE FUN
{
	if (i == "add")
	{
		ht.insert(x);
	}
	else if (i == "delete")
	{
		ht.deleteValue(x);
	}
	else if (i == "search")
	{
		ht.search(x, false);	// Verbose searching!
	}
	else
	{
		cout << "Error: Unknown command." << endl; // If you see this, something is seriously wrong
	}
	return;

	// Eventually, I'm just going to combine all of these assignments that will create
	// a binary search tree of hashtables.
}