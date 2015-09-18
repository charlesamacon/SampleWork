#pragma once
#include <iostream>
#include <string>

using namespace std;
class stuNode
{
private:
	int id;
	string firstName;
	string lastName;
public:
	stuNode();
	stuNode(int i, string f, string l);
	~stuNode();

	void setID(int i);
	void setFirstName(string f);
	void setLastName(string l);

	int getID();
	string getFirstName();
	string getLastName();

	void print();
};

