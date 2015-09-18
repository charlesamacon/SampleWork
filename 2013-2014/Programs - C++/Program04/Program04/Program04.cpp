// Charles Alan Macon
// Program 4
// Heaps - Arrays - Other Fun
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "heap.h"

using namespace std;

bool isValidString(string s);

int main()
{
	int fail = 0;
	int quit = 0;

	while (quit == 0)
	{
		string input = "";
		string textInput;

		stringstream tokenizer6000000;								// Silly (but descriptive) variable names help break the monotony

		cout << "heapsort> ";
		getline (cin, input);

		tokenizer6000000 << input;

		int arraySize = NULL;

		tokenizer6000000 >> textInput;								// The first command should be taken from the sstream AND AND CHECKED
		tokenizer6000000 >> arraySize;								// The second command should be taken, and also checked.

		
																	// This next section will dynamically allocate memory...oh god I'm boring myself.
																	// This creates an array with a size of whatever the user tells it to be.
		if (isValidString(textInput))
		{
			if (arraySize != NULL && fail == 0)
			{
				int* a= NULL;
				a = new int[arraySize+1];								// This is kind of cool because it is. Make one larger than arraySize or CSE will hate you.
			
				for (int i = 1; i <= arraySize; i++)					// Basically, this part fills the array with the user input
				{
					int num = NULL;
					tokenizer6000000 >> num;
				
					if (num != NULL || num == 0)
					{
						a[i] = num;
					}
					else
					{
						cout << "Error! Everything past the 'sort' command must be an integer" << endl;
						fail = 1;
						break;
					}
				}
			
				if (fail == 0)
				{
					heap newHeap(a, arraySize);								// Create a new object
					//newHeap.insert(a,arraySize);							Pass the array and its size to the new object (this step can be avoided by writing a new constructor).
					cout << "Please press any key to continue...";
					cin.ignore();
				}
			}
			else
			{
				cout << "Error! You must enter a valid array size." << endl;
			}
			fail = 0;
		}
		else if (textInput == "quit")
		{
			quit = 1;
			break;
		}
		else
		{
			cout << "Error! Unrecognized command!" << endl;
		}
	}

	return 0;
}

bool isValidString(string s)
{
	if (s == "sort")													// Only 'sort' should be accepted.
		return true;
	else
		return false;
}