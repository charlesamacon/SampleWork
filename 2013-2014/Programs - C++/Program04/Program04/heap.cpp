#include "heap.h"
#include <iostream>

using namespace std;

heap::heap(void)
{
}

heap::heap(int *a, int x)
{
	insert(a, x);													// This is much easier than directly calling insert() from main()
}

heap::~heap(void)
{
}

void heap::insert(int *a, int x)
{
	size = x;														// Make sure size is the parameter being passed in
	int i;															// When this function is called recursively, this makes sure size is correct.
	
	for (i = x/2; i >= 1; i--)
	{
		buildHeap(a, i, x);											// Build our heap (or rebuild if being called in the output function)
	}

	output(a);														// Output calls insert again if needed, so this will go on until we're out of numbers or size < i.

	return;
}

void heap::buildHeap(int *heapArray, int i, int n)
{
	int newLoc;																// A new index, essentially. This is where things should go.
	int temp;																// A new temp array

	temp = heapArray[i];

	newLoc = i * 2;															// i should equal x from insert() at this point

	while (newLoc <= n)														// Sort and determine where everything should go.
    {
        if (newLoc < n && heapArray[newLoc+1] > heapArray[newLoc])
		{
            newLoc++;
		}
        if (temp > heapArray[newLoc])										// If it's the largest, it goes at the top.
		{
            break;
		}
        else if (temp <= heapArray[newLoc])
        {
            heapArray[newLoc / 2] = heapArray[newLoc];
            newLoc = newLoc * 2;
        }
    }
    heapArray[newLoc/2] = temp;												// So now we put everything back together
    return;
}

void heap::output(int *a)
{
	cout << "(";
	for (int i = 1; i <= size; i++)
	{
		cout << a[i];
		if (i != size)
		{
			cout << ",";									// If we're not at the last element of the array, print a comma
		}
	}
	cout << ") ";											// Close it out, call it a day, and do it again.

	if (size > 1)											// This is important, and keeps the program from trying to keep reducing forever.
	{
		deleteMax(a);
	}
	else
	{
		cout << endl;										// Or call it a day and start over.
	}

	return;
}

void heap::deleteMax(int *a)
{
		int *temp = NULL;									// Create a new array...
		temp = new int[size];								// That is one smaller than the original array. (EDIT: KEEP IT THE SAME SIZE OR CSE WILL HATE YOU)
		for (int i = 2; i <= size; i++)						// The first element is always the largest, so skip it
		{
			temp[i-1] = a[i];								// Copy the old array to the new array
		}

		a = temp;											// Literally make the old array the new array
		size--;												// Decrease the size of the size variable

		insert(a,size);										// And do it again.
}
