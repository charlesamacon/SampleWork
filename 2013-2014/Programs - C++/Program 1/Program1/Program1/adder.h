//adder.h
#ifndef ADDER_H
#define ADDER_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Adder
{
	private:
		string parameter1;
		string parameter2;
		char carry;

	public:
		Adder(string parameter1, string parameter2);
		void printAdderBase2();
		void printAdderBase6();

};

#endif