#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

bool DEBUG = false;

CLinkedList::CLinkedList(void)
{
	listSize = 0;
	pHead = NULL;
	pLast = NULL;
	pIndex = NULL;
}


CLinkedList::~CLinkedList(void)
{
}

void CLinkedList::addNode(int data)
{
	if (DEBUG == true)
	{
		cout << "ENTERING ADDNODE" << endl;
	}

	CNode * temp = new CNode(data, NULL, NULL);									// Create a new node

	if (DEBUG == true)
	{
		cout << "NODE CREATED" << endl;
	}

	pHead = temp;																// The new node should be the head
	pIndex = temp;																// ...the index...
	pLast = temp;																// ...and the last
	temp->pNext = NULL;															// It should also not point to anything
	temp->pPrev = NULL;
	listSize++;																	// Increase listSize so this whole thing works

	if (DEBUG == true)
	{
		cout << "LISTSIZE: " << listSize << endl;
		cout << "NODE DATA: " << temp->getData() << endl;
		cout << temp << endl;
	}
}

void CLinkedList::addNodeLeft(int data)
{
	if (DEBUG == true)
		cout << "ENTERING ADDNODE LEFT" << endl;

	if (pHead == NULL)
	{
		if (DEBUG == true)
			cout << "pHEAD NULL" << endl;
		addNode(data);
	}
	else
	{
		if (DEBUG == true)
			cout << "pHEAD NOT NULL" << endl;

		if (pIndex == pHead)													// If Index is the Head
		{
			if (DEBUG == true)
				cout << "pINDEX == pHEAD" << endl;	

			if (pLast == pHead)													// If Head is also the last
			{
				if (DEBUG == true)
					cout << "pLAST == pHEAD" << endl;

				CNode * temp1 = new CNode(data, NULL, pHead);					// Create node from data

				if (DEBUG == true)
					cout << "NODE CREATED" << endl;

				pLast = pHead;													// Last is old Head
				pHead = temp1;													// New head is new Node
				pIndex = pHead;													// Index is new Head

				if (DEBUG == true)
				{
					cout << pHead->getData() << endl;
					cout << pLast->getData() << endl;
				}

				listSize++;														// Increase listSize.

				if (DEBUG == true)
				{
					pHead->output();											// TEST to make sure output is in correct order.
					cout << "LISTSIZE: " << listSize << endl;
					cout << "INDEX: " << pIndex->getData() << endl;
				}
			}
			else
			{
				if (DEBUG == true)
					cout << "DOES THIS EVER GET USED?" << endl;					// Yes, when pointer is at head, but head != tail

				CNode * temp1 = new CNode(data, NULL, pHead);					// But not the last in the list

				if (DEBUG == true)
					cout << "NODE CREATED" << endl;								// Create node from data

				pHead = temp1;													// New head is new Node
				pIndex = pHead;													// Index is new head

				listSize++;														// Increase listSize.

				if (DEBUG == true)
				{
					pHead->output();											// TEST to make sure output is in correct order.
					cout << "LISTSIZE: " << listSize << endl;
					cout << "INDEX: " << pIndex->getData() << endl;
				}
			}
		}
		else
		{
																				//ADD NODE TO LEFT OF pINDEX
																				//GET ADDRESS TO THE RIGHT OF MODE

																				// OK, Index is not the head at this point so Index has a value for right and left

			if (DEBUG == true)
				cout << "ATTEMPTING TO ADD AFTER MOVING INDEX" << endl;
			CNode *temp1 = new CNode(data, pIndex->pPrev, pIndex);
			CNode *left = pIndex->pPrev;

			left->pNext = temp1;							
			pIndex->pPrev = temp1;

			if (DEBUG == true)
				pHead->output();

			listSize++;
		}
	}

	moveIndexRight(false);	// MAKE IT WORK BY FORCE

	return;
}

void CLinkedList::addNodeRight(int data)
{
	if (DEBUG == true)
		cout << "ENTERING ADDNODE RIGHT" << endl;

	if (pHead == NULL)
	{
		if (DEBUG == true)
			cout << "pHEAD NULL" << endl;

		addNode(data);
	}
	else
	{
		if (DEBUG == true)
			cout << "pHEAD NOT NULL" << endl;

		if (pIndex == pLast)													// If index is the last
		{
			if (pLast == pHead)													// And the first of the list
			{
				if (DEBUG == true)
					cout << "pLast == pHead" << endl;

				CNode * temp1 = new CNode(data, pLast, NULL);

				if (DEBUG == true)
					cout << "NODE CREATED" << endl;

				pLast = temp1;
				pIndex = pLast;

				if (DEBUG == true)
				{
					cout << pHead->getData() << endl;
					cout << pHead->pNext << endl;
					cout << temp1 << endl;
					cout << pLast->getData() << endl;

					pHead->output();
					cout << "LISTSIZE: " << listSize << endl;
					cout << "INDEX: " << pIndex->getData() << endl;
				}

				listSize++;
			}
			else																// But not the first of the list
			{
				CNode * temp1 = new CNode(data, pLast, NULL);

				if (DEBUG == true)
					cout << "NODE CREATED" << endl;

				pLast = temp1;
				pIndex = pLast;

				listSize++;

				if (DEBUG == true)
				{
					pHead->output();
					cout << "LISTSIZE: " << listSize << endl;
					cout << "INDEX: " << pIndex->getData() << endl;
				}
			}
		}
		else
		{
			if (DEBUG == true)
				cout << "ATTEMPTING TO ADD AFTER MOVING INDEX" << endl;

			CNode *temp1 = new CNode(data, pIndex, pIndex->pNext);
			CNode *right = pIndex->pNext;

			right->pPrev = temp1;
			pIndex->pNext = temp1;

			if (DEBUG == true)
				pHead->output();

			listSize++;

		}
	}

	moveIndexLeft(false);														// [RANT]
																				// This hack brought to you by the letters 'W', 'T' and 'F'.
																				// There's no particularly good reason to do this (as it should)
																				// already be handled earlier, but it NEVER WORKS AND THROWS ERRORS.
																				// Which is why we MAKE IT WORK BY PURE FORCE.
																				// [END RANT]
	return;
}

void CLinkedList::moveIndexRight(bool x)
{
	if (listSize > 0)
	{
		if (pIndex->pNext != NULL)
		{
			CNode *temp = pIndex->pNext;

			if (DEBUG == true)													// Debug strings make code ugly.
			{
				cout << temp->pPrev << endl;
				cout << temp->pNext << endl;
				cout << temp->nData << endl;
			}

			temp->pPrev = pIndex;												// Move index to the right...
			pIndex = temp;

			if (x == true)
				cout << pIndex->getData() << endl;
		}
		else
		{
			if (x == true)
				cout << "Error: End of list." << endl;
		}
	}
	else
	{
		cout << "Error: List empty." << endl;
	}
	return;
}

void CLinkedList::moveIndexLeft(bool x)
{
	if (listSize > 0)
	{
		if (pIndex->pPrev != NULL)
		{
			CNode *temp = pIndex->pPrev;

			if (DEBUG == true)
			{
				cout << temp->pPrev << endl;
				cout << temp->pNext << endl;
				cout << temp->nData << endl;
			}

			temp->pNext = pIndex;												// Move index to the left...
			pIndex = temp;

			if (x == true)														// Blah blah blah...don't pass an argument to this function. THIS WORKS BETTER.
				cout << pIndex->getData() << endl;								// NOW I CAN USE THIS FUNCTION IN DIFFERENT CONTEXTS.
		}
		else
		{
			if (x == true)
				cout << "Error: End of list." << endl;
		}
	}
	else
	{
		cout << "List empty" << endl;
	}
	return;
}

void CLinkedList::removeNode()													// NOTE: This is not necessary for the assignment, but I did it anyway.
{																				// This function is not fully implemented because, again, it is not
	if(listSize > 0)															// needed for the assignment, but it is partially implemented because I
	{																			// made it through the majority of the function before realizing that
		CNode * right = pIndex->pNext;											// I didn't need it. It is not used in the final project, but is left
		CNode * left = pIndex->pPrev;											// here in case I need to use it (and finish it) later.

		if (listSize > 1)
		{
			if (right != NULL)
			{
				right->pPrev = left;
			}
			else
			{
				// Do nothing?
			}
			if (left != NULL)
			{
				left->pNext = right;
			}
			else
			{
				left->pNext = NULL;
			}
			
			if (right != NULL)
			{
				pIndex = right;
			}
			else
			{
				pIndex = left;
			}
			pHead->output();
		}
		else
		{
			pHead = NULL;
			cout << "Error: Head is NULL." << endl;
		}
		
		listSize--;
	}
	else
	{
		cout << "Error: Cannot remove from an empty list." << endl;
	}

	return;
}

bool CLinkedList::searchNode(int data)
{
	if (listSize > 0)
	{
		return pHead->search(data);												// These functions are easy when they're already done recursively
	}																			// in the node class.
	else
	{
		cout << "Error: Cannot search an empty list." << endl;
		return false;
	}
}

void CLinkedList::printList()
{
	if (listSize > 0)
	{
		pHead->output();														// This one is works exactly the same way. Recursive functions are fun.
	}
	else
	{
		cout << "Error: List is empty" << endl;
	}

	return;
}