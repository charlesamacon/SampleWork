#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
	value = NULL;
	pNext = NULL;
}

Node::Node(int data)
{
	// Basic node is basic.
	setValue(data);
	setNext(NULL);
}

Node::~Node()
{
}

void Node::setValue(int v)
{
	value = v;
}

int Node::getValue()
{
	return value;
}


void Node::setNext(Node * n)
{
	pNext = n;
}

Node * Node::getNext()
{
	if (pNext != NULL)
	{
		return pNext;
	}
	else
	{
		return NULL;
	}
}

Node * Node::getLast()
{
	if (pNext != NULL)
	{
		pNext->getLast();
	}
	else
	{
		return this;
	}
}

void Node::printNodes()
{
	if (value == 0)
	{
		// Print nothing as per assignment.
	}
	else
	{
		cout << value;

		if (pNext != NULL)
		{
			cout << ",";
			pNext->printNodes();
		}
		else
		{
			return;
		}
	}
	return;
}

bool Node::searchNodes(int i)
{
	int x = value;

	if (x != i)
	{
		if (pNext != NULL)
		{
			pNext->searchNodes(i);
		}
	}
	else
		return true;

	return false;
}