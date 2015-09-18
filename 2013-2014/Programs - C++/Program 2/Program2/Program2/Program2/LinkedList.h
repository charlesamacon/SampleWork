#pragma once

#include "Node.h"

class CLinkedList
{
private:
	CNode * pHead;
	CNode * pIndex;
	CNode * pLast;
	int listSize;

public:
	CLinkedList(void);
	~CLinkedList(void);
	void addNode (int data);
	void addNodeLeft (int data);
	void addNodeRight (int data);
	void removeNode ();
	void moveIndexLeft(bool x);
	void moveIndexRight(bool x);
	bool searchNode (int data);
	void printList();
};

