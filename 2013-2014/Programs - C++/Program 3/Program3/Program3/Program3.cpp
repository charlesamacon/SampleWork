// Charles Alan Macon
// Program 3: BST

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "tree.h"
#include "node.h"

using namespace std;

bool isInputValid(string i);
void doInput(string i);
void doInput(string i, int x);
tree tree;												// This returns an error in VS for no reason. Code still compiles. Confused.

int main()
{
	//tree tree;
	int quit = 0;

	while (quit == 0)
	{
		string input = "";
		string textInput;
		int numericInput = NULL;
		stringstream tokenizer4000;

		cout << "bst> ";
		getline (cin,input);

		tokenizer4000 << input;
		tokenizer4000 >> textInput >> numericInput;

		if(isInputValid(textInput))
		{
			if(numericInput != NULL)
			{
				if (textInput == "add" || textInput == "delete" || textInput == "search")
				{
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
					doInput(textInput);
				}
			}
			else if(textInput == "quit")
			{
				quit = 1;
				break;
			}
			else
			{
				cout << "Error: Invalid Command" << endl;						// In case one slips by...
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

bool isInputValid(string i)
{
	if (i == "add" || i == "delete" || i == "search" || i == "inorder" || i == "height" || i == "quit" || i == "reverse")
	{
		return true;
	}
	else
		return false;
}

void doInput(string i)
{
	if (i == "inorder")
	{
		tree.output();
	}
	else if (i == "height")
	{
		cout << tree.height() << endl;
	}
	else if (i == "reverse")
	{
		tree.reverseTree();
	}
	else
	{
		cout << "Error: Unknown command." << endl;
	}
	return;
}

void doInput(string i, int x)
{
	if (i == "add")
	{
		tree.addNode(x);
	}
	else if (i == "delete")
	{
		tree.deleteNode(x);
	}
	else if (i == "search")
	{
		tree.search(x);
	}
	else
	{
		cout << "Error: Unknown command." << endl;
	}
	return;
}