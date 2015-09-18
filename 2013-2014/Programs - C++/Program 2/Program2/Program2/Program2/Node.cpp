#include "node.h"
#include <iostream>

using namespace std;

CNode::CNode(int data, CNode * prev, CNode * next)
{
	nData = data;

	if (prev != NULL)							
	{
		pPrev = prev;							
	}
	else
		pPrev = NULL;							

	if (next != NULL)						
	{
		pNext = next;							
	}
	else
		pNext = NULL;							
}


CNode::CNode(void)
{
}


CNode::~CNode(void)
{
}

int CNode::getData()
{
	return nData;
}

void CNode::output()
{
	cout << nData;
	if (pNext != NULL)
	{
		cout << "-";
		pNext->output();
	}
	else
	{
		cout << endl;
	}
	return;
}

bool CNode::search(int i)
{
	if (nData == i)
	{
		cout << "True." << endl;
		return true;
	}
	else if (pNext != NULL)
	{
		//cout << "Number not found, moving to next list item" << endl;
		pNext->search(i);
	}
	else if (pNext == NULL)
	{
		cout << "False." << endl;
	}
	return false;
}