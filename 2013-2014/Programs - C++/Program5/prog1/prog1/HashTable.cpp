#include "HashTable.h"
#include "Node.h"


HashTable::HashTable()
{
	int i;
	for (i = 0; i < 7; i++)
	{
		//cout << "Creating bucket " << i << endl;

		Node * b = new Node(NULL);
		bucket[i] = b;
	}
}


HashTable::~HashTable()
{
	// DEFAULT DECONSTRUCTOR
}


void HashTable::insert(int data)
{
	bucketIndex = ((data * data) % 7);

	//cout << "Trying to add: " << data << endl;

	if (search(data, true))
	{
		// SHHHH! SEARCH SILENTLY
		cout << "WARNING: duplicate input: " << data << endl;
	}
	else
	{
		if (bucket[bucketIndex]->getValue() == NULL)
		{
			bucket[bucketIndex]->setValue(data);
		}
		else
		{
			// This isn't useful at this point, but I might need
			// to expand upon this later.
			Node * last = new Node();
			last = bucket[bucketIndex]->getLast();

			Node * newNode = new Node(data);
			last->setNext(newNode);
		}
	}
}

void HashTable::print()
{
	int i;

	// There are only 7 buckets, so this is hardcoded. Otherwise, we would
	// just pass this in as a variable.
	for (i = 0; i < 7; i++)
	{
		cout << "(";
		bucket[i]->printNodes();
		cout << ")";
		if (i < 6)
		{
			cout << "-";
		}
		else
		{
			cout << endl;
		}
	}
}

bool HashTable::search(int i, bool s)
{
	int testIndex = ((i * i) % 7);

	// The bool denotes whether or not the search function is silent. Kinda cool.
	return pSearch(i, bucket[testIndex], s);
}

bool HashTable::pSearch(int i, Node *n, bool s)
{
	//cout << "Searching for " << i << endl;
	bool tf;
	if (n != NULL)
	{
		if (i == n->getValue())
		{
			if (!s)
			{
				cout << "True" << endl;
			}
			tf = true;
			return true;
		}
		else if (n->getNext() != NULL)
		{
			Node *ne = n->getNext();
			pSearch(i, ne, s);
		}
		else
		{
			if (!s)
			{
				cout << "False" << endl;
			}
			return false;
		}
	}
	else
	{
		//cout << "Null Found" << endl;
		if (!s)
		{
			cout << "False" << endl;
		}
		return false;
	}
	// For some reason, this negates all the work I've done
	// return false;
}

void HashTable::deleteValue(int i)
{
	int testIndex = ((i * i) % 7);
	
	deleteValue(i, testIndex, bucket[testIndex]);

	return;
}

void HashTable::deleteValue(int i, int index, Node *n)
{
	//cout << "Searching for " << i << endl;
	bool tf;

	if (n != NULL)
	{
		if (i == n->getValue())
		{
			//This should only be seen if the value happens
			//to be the first node.
			Node *next = n->getNext();
			
			bucket[index] = next;
			delete n;
			
		}
		else if (n->getNext() != NULL)
		{
			Node *next = n->getNext();

			if (i == next->getValue())
			{
				// Delete that node, move this nodes' next pointer to the next-next node
				// Sometimes the most elegant solution doesn't work.
				if (next->getNext() != NULL)
				{
					Node *nextNext = next->getNext();
					n->setNext(nextNext);
					delete next;
				}
				else
				{
					n->setNext(NULL);
					delete next;
				}
			}
			else
			{
				// We don't need the bucketIndex anymore
				deleteValue(i, NULL, next);
			}
		}
		else
		{
			cout << "WARNING: Target Value Not Found: " << i << endl;
			return;
		}
	}
}
