// Charles Alan Macon - Ripple_carry.cpp
// Due Date - 06/15/2014
//
// Description: This program allows the user to add two binary numbers together
//				using the ripple-carry method.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>
#include <sstream>
#include "adder.h"

using namespace std;

const bool DEBUG = false;					// If set to "true", all debug output will be enabled.
bool CSE = false;							// In visual studio or on CSE Machine?
int base = 2;								// The base we'll be using. This will change based on user input.

bool inputIsGoodString (string str);		// Check the string for proper input
bool inputIsGoodDigit (string str);			// Check the string for binary (or base 6) digits
void numberAdder ();						// Add stuff

int main()
{
	if (DEBUG == false)						// Failsafe to ensure that all CSE Machine code is turned on if debug is off
	{
		CSE = true;						
	}

	//int i;									// Container for input
	int input = 0;

	while(input == 0)
	{
		cout << "1. ADD BASE2" << endl;			// MENU OPTION 1
		cout << "2. ADD BASE6" << endl;			// MENU OPTION 2
		cout << "3. QUIT" << endl;				// MENU OPTION 3
		cout << "Please enter the number for the option you would like: " << endl;
		cout << "ripple_carry> ";
		string i;
		cin >> i;								// Input for input

		if (i=="1" || i=="2")
		{
			while(i=="1" || i=="2")
			{
				if (i=="1")
				{
					// Base 2 addition.
					base = 2;
					cout << endl;
					cout << "Please enter the command 'add' followed by two binary numbers." << endl;
				}
				else
				{
					// Base 6 addition.
					base = 6;
					cout << endl;
					cout << "Please enter the command 'add' followed by two base 6 numbers." << endl;
				}
				
				if (DEBUG == true)
				{
					cout << base << endl;		// Display base we're working with
				}
				
				numberAdder();
				if (CSE == true)				// On CSE Machine?
				{
					cout << "Press any key to continue: ";
					cin.ignore().get();
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
				}
				else							// Or at home?
				{
					cout << "WARNING: CSE is false. Set to true." << endl;
					CSE = true;
					//system("PAUSE");
					//system("CLS");
				}

				break;
			}
		}
		else if (i == "3")
		{
			input = 1;
		}
		else
		{
			cout << "ERROR: Command not recognized. Please enter the appropriate menu option number.\n" << endl;
		}

		i = "0";
	}

	return 0;
}

void numberAdder()
{
	string input = "";
	string textInput;
	string numericInput1;
	string numericInput2;
	stringstream tokenizer2000;				//The Tokenizer 2000 (TM)

	cout << "ripple_carry>";
	cin.ignore();
	getline (cin,input);
	
	tokenizer2000 << input;												// Stream input into Tokenizer and tokenize
	tokenizer2000 >> textInput >> numericInput1 >> numericInput2;		// This >> is >> magic

	if (DEBUG == true)
	{
		cout << textInput << endl;			// Check to make sure each
		cout << numericInput1 << endl;		// part of the input was
		cout << numericInput2 << endl;		// appropriately tokenized
	}

	if (inputIsGoodString(textInput))
	{
		if (inputIsGoodDigit(numericInput1))
		{
			if (inputIsGoodDigit(numericInput2))
			{
				Adder adder(numericInput1, numericInput2);		// Create Adder object
				if(base == 2)
				{
					adder.printAdderBase2();					// If base 2, add in base 2
				}
				else
				{
					adder.printAdderBase6();					// If base 6, add in base 6
				}
			}
			else
				cout << "ERROR: Second Number Invalid" << endl;	// It's all errors from this point forth
		}
		else
			cout << "ERROR: First Number Invalid" << endl;		// Bad numbers
	}
	else
	{
		cout << "ERROR: Command Not recognized" << endl;		// Bad commands
	}

	return;
}

bool inputIsGoodString(string str)
{
	if (DEBUG == true)
	{
		cout << "Entering inputIsGoodString" << endl;
	}
	if(str != "add")											// If input is anything but "add", fail out
		return false;
	return true;
}

bool inputIsGoodDigit(string str)
{
	if (DEBUG == true)
	{
		cout << "Entering inputIsGoodDigit" << endl;
	}

	int i = 0;

	if (str == "")
	{
		cout << "ERROR: You must enter a number." << endl;
		return false;
	}

	while (str[i])
	{
		if (str[i] == '-')
		{
			cout << "ERROR: Negative numbers are not supported" << endl;
			return false;
		}


		if (isdigit(str[i]))							// Check to verify character is a digit.
		{
			if (DEBUG == true)
			{
				cout << "Character is a digit" << endl;
			}

			if (base == 2)									// Check if base == 2
			{
				if (str[i] == '0' || str[i] == '1')			// If it is, check to see if it is a binary digit.
				{
					if (DEBUG == true)
					{
						cout << "Digit is binary" << endl;
						cout << str[i] << endl;
					}
				}
				else
				{
					cout << "ERROR: Digit is not binary" << endl;
					return false;
				}
			}
			else if (base == 6)																									// Check if base == 6
			{
				if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5')			// If it is, check to see if it is base 6.
				{
					if (DEBUG == true)
					{
						cout << "Digit is base 6" << endl;
					}
				}
				else
				{
					cout << "ERROR: Digit is not base 6" << endl;
					return false;
				}
			}
		}
		else
		{
			if (DEBUG == true)
			{
				cout << "ERROR: Character is not a digit" << endl;
			}
			return false;								// Return false if not
		}
		i++;
	}

	if (i > 6)
	{
		cout << "ERROR: Number not be longer than 6 digits" << endl;
		return false;
	}

	return true;										// If all is good, return true
}