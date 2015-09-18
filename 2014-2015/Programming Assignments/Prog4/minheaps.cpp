/*********************************
Charles Alan Macon
CSCE 3110
Programming Assignment 4 - Heaps and Stuff
Due Date: July 31, 2015
*********************************/


#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

//ifstream myfile ("input");		// This needs to be changed to cin

class Heap
{
	private:
		int size;
		int currentSize;
		int capacity;
		vector<int> heapArray;
		
	public:
		Heap();
		~Heap();
		bool isEmpty();
		int findMin();
		void insert(int a);
		int parent(int child);
		void change(int a, int x);
		void buildHeap(int i);
		void deleteMin();
		void output(int n);
		int left(int i);
		int right(int i);
		void heapup(int i);
		void heapdown(int i);
};

Heap::Heap()
{
	capacity = 0;
	heapArray.resize(capacity);
}

Heap::~Heap()
{
	// We're not using this, so it's empty
}

void Heap::insert(int a)
{
	//cout << "INSERTING" << endl;

	heapArray.push_back(a);						// Might as well treat it like a heap
	//cout << "Building Heap..." << endl;
	heapup(heapArray.size() - 1);				
	
	return;
}

int Heap::parent(int child)
{
	// Find Parent of a given child
	int p = (child - 1) / 2;
	if (child == 0)
		return -1;
	else
		return p;
}

void Heap::buildHeap(int i)
{
	// This function is the same as heapup, but I've given it a different name
	// for abstraction purposes. It helps me visualize the process better
	if (i >= 0 && parent(i) >= 0 && heapArray[parent(i)] > heapArray[i])
	{
		int temp = heapArray[i];
		heapArray[i] = heapArray[parent(i)];
		heapArray[parent(i)] = temp;
		buildHeap(parent(i));
	}
}

int Heap::left(int i)
{
	// Return the index of the left node
	int l = 2 * i + 1;
	if (l < heapArray.size())
	{
		return l;
	}
	else
		return -1;
}

int Heap::right(int i)
{
	// Return the index of the right now
	int r = 2 * i + 2;
	if (r < heapArray.size())
	{
		return r;
	}
	else
		return -1;
}

void Heap::output(int n)
{
	// Recursive postorder output.
	if (n >= 0 && n <= heapArray.size())
	{
		output(left(n));
		output(right(n));
		cout << heapArray[n] << " ";
	}
	
}

void Heap::change(int a, int x)
{
	//cout << "CHANGING" << endl;
	vector <int>::iterator it = heapArray.begin();
	int i = 0;
	
	// Here, we have to keep track of the value of a given "node" and 
	// it's proper location within the array. As such, we have an iterator
	// and an iterating integer. Fun times had by all.
	while (it != heapArray.end())
	{
		if (*it == a)
		{
			heapArray[i] = x;		// Change every instance of a to x.
		}
		it++;
		i++;
	}
	return;
}

void Heap::deleteMin()
{
	// Find the min (always at the beginning), pop it back, rebuild the heap.
	heapArray[0] = heapArray.at(heapArray.size() - 1);
	heapArray.pop_back();
	heapdown(0);
	
	return;
}

bool Heap::isEmpty()
{
	// We might not need this, but it's good for completion.
	if (heapArray.size() == 0)
		return true;
	else
		return false;
}

void Heap::heapup(int i)
{
	// Again, same as buildHeap, but used at different times. Swap if necessary.
	if (i >= 0 && parent(i) >= 0 && heapArray[parent(i)] > heapArray[i])
	{
		int temp = heapArray[i];
		heapArray[i] = heapArray[parent(i)];
		heapArray[parent(i)] = temp;
		heapup(parent(i));
	}
}

void Heap::heapdown(int i)
{
	// Get the children of the given index
	int child = left(i);
	int child1 = right(i);
	
	// If needed, left and right should be equal
	if (child >= 0 && child1 >=0 && heapArray[child] > heapArray[child1])
	{
		child = child1;
	}
	
	if (child > 0)
	{
		// Swap, as usual.
		int temp = heapArray[i];
		heapArray[i] = heapArray[child];
		heapArray[child] = temp;
		heapdown(child);
	}
}


int main()
{
	string line;
	string command;
	
	stringstream tokenizer;			// Stringstreams are awesome in so many ways
	
	Heap newHeap;						// Create the heap for use later.
	
	while (getline(cin, line))		// Replace "myfile" with cin
	{
		stringstream ssin(line);		// Stringstreams can be used for fun and profit
		int tempNum1;
		int tempNum2;
		
		ssin >> command;				// Store Command
		if (command == "P")
		{
			// Print
			//cout << "Print\n";
			newHeap.output(0);			// Output starting at min node. POSTORDER
			cout << endl;
		}
		else if (command == "D")
		{
			// Delete Min
			//cout << "Delete\n";
			newHeap.deleteMin();		// Delete the min and bubble down.
		}
		else if (command == "C")
		{
			// Change Values
			// get next two ints and change
			ssin >> tempNum1;
			ssin >> tempNum2;
			//cout << "Change\n";
			//cout << tempNum1 << " " << tempNum2 << endl;
			newHeap.change(tempNum1, tempNum2);
		}
		else if (command == "I")
		{
			// Insert next node
			ssin >> tempNum1;
			//cout << "Insert\n";
			//cout << tempNum1 << endl;
			newHeap.insert(tempNum1);
		}
	}
	
	return 0;
}