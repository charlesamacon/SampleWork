#pragma once
class Node
{
private:
	int value;
	Node * pNext;
public:
	Node();
	Node(int v);
	~Node();

	void setNext(Node * next);
	Node * getNext();
	Node * getLast();

	void setValue(int v);
	int getValue();

	void printNodes();
	bool searchNodes(int i);
};

