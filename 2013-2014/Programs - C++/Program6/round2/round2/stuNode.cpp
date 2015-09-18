#include "stuNode.h"
#include <iostream>
#include <string>

using namespace std;

stuNode::stuNode()
{
	id = NULL;
}

stuNode::stuNode(int i, string f, string l)
{
	id = i;
	firstName = f;
	lastName = l;
}

stuNode::~stuNode()
{
}

void stuNode::setID(int i)
{
	id = i;
	return;
}

void stuNode::setFirstName(string f)
{
	firstName = f;
	return;
}

void stuNode::setLastName(string l)
{
	lastName = l;
	return;
}

int stuNode::getID()
{
	return id;
}

string stuNode::getFirstName()
{
	return firstName;
}

string stuNode::getLastName()
{
	return lastName;
}

void stuNode::print()
{
	cout << "(" << id << "," << getFirstName() << "," << lastName << ")";
}