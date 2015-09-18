// Charles Alan Macon
// Program #2
// "List"
//
// Directed by: Charles Alan Macon
// An Alan Macon Production.
// Hair and Makeup provided by Alan Macon.
// Stunts by Charles Macon.

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cctype>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

bool checkInput(string i);
void doInput(string i);
void doInput(string i, int x);

CLinkedList linkedList;															// GLOBAL VARIABLES ARE EVIL

int main()
{
	
	int quit = 0;

	while (quit == 0)
	{
		string input = "";
		string textInput;
		int numericInput = NULL;
		stringstream tokenizer3000;												// The Tokenizer 3000 (TM), new and improved

		cout << "list> ";
		getline (cin,input);
		
		tokenizer3000 << input;
		tokenizer3000 >> textInput >> numericInput;

		if (checkInput(textInput))
		{
			if(numericInput != NULL)
			{
				if (textInput == "addleft" || textInput == "addright" || textInput == "search")
				{
					doInput(textInput, numericInput);
				}
				else
				{
					cout << "Error: Invalid Command Combination." << endl;
				}
			}
			else if(numericInput == NULL && textInput != "quit")
			{
				if (textInput == "addleft" || textInput == "addright" || textInput == "search")
				{
					cout << "Error: Invalid Command Combination." << endl;
				}
				else
				{
					doInput(textInput);
				}
			}
			else if (textInput == "quit")
			{
				quit = 1;
				break;
			}
			else
			{
				cout << "Error: Invalid Command" << endl;						// Just in case one slips by.
			}
		}
		else
		{
			cout << "Error: Unrecognized Command!" << endl;
		}
		cout << "Please press any key to continue..." << endl;
		cin.ignore();
	}

	return 0;
}

bool checkInput(string i)
{
	if (i == "addleft" || i == "addright" || i == "left" || i == "right" || i == "print" || i == "search" || i == "quit")
	{
		return true;															// If the string is any of these words, do something
	}
	else
		return false;															// Otherwise, don't.
}

void doInput(string i)
{
	if (i == "left")
	{
		linkedList.moveIndexLeft(true);											// True denotes that we are outputting errors here.
	}																			// A value of "false" would mean that we are calling the function
	else if (i == "right")														// "internally" and should not output the "end of list" error.
	{
		linkedList.moveIndexRight(true);
	}
	else if (i == "print")
	{
		linkedList.printList();
	}
	else
	{
		cout << "Error: Unknown Command." << endl;								// IF YOU SEE THIS, THERE IS A PROBLEM, BUT I DON'T KNOW WHAT IT IS.
	}

	return;
}

void doInput(string i, int x)													// OVERLOADED FUNCTIONS! WOAAAAAAAAH!
{
	if (i == "addleft")
	{
		linkedList.addNodeLeft(x);
	}
	else if (i == "addright")
	{
		linkedList.addNodeRight(x);
	}
	else if (i == "search")
	{
		linkedList.searchNode(x);
	}
	else
	{
		cout << "Error: Unknown Command." << endl;								// BECAUSE YOU SHOULD NEVER SEE THIS. Seeing this error is not logically possible,
	}																			// but I am outputting an error anyway to cover my bases.

	return;
}

// ~Fin~