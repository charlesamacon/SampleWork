#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

bool isValidString(string s);

int main()
{
	int fail = 0;
	
	string input = "";
	string textInput;
	
	stringstream tokenizer;			// Stringstreams are awesome in so many ways
	
	int arraySize = 500;
	
	return 0;
}

bool isValidString(string s)
{
	if (s == "P" || s == "D" || s == "C" || s == "I")
	{
		return true;
	}
	else
	{
		return false;
	}
}

