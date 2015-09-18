#pragma once
class CNode
{
	friend class CLinkedList;

private:
	int nData;
	CNode * pNext;
	CNode * pPrev;

public:
	CNode (int data, CNode * prev, CNode * next);
	CNode(void);
	~CNode(void);

	int getData();
	void output();
	bool search(int i);
};

