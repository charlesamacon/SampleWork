#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class HashTable
{
private:
	Node * bucket[7];
	int bucketIndex;
	bool pSearch(int i, Node *n, bool s);
	void deleteValue(int data, int index, Node *n);
public:
	HashTable();
	~HashTable();

	void insert(int data);
	void print();
	void deleteValue(int data);
	bool search(int i, bool s);
};

