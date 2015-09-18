#pragma once
#include <iostream>
#include <string>
#include "stuNode.h"
class students
{
private:
	stuNode *studentTable[999];
	int index;
public:
	students();
	~students();

	void addStudent(stuNode *s);
	void print();
	void deleteS(int id);
};

