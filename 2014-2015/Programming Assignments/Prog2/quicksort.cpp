/********************************
Charles Alan Macon
CSCE 3110
Programming Assignment 2 - QuickSort
Due Date: June 30, 2015
*********************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

//ifstream myfile ("input.txt");			// REMEMBER TO CHANGE THIS BEFORE SUBMITTING
ofstream outfile ("neo_sorted.txt");			// CHANGE THIS TO PROPER OUTPUT FILE
clock_t t;

struct neo
{
	string designationString;
	float impactProbability;
};

void input( neo* a);
void output( neo* a);

//QuickSort
void quicksort(neo a[], int p, int r);
int median(neo a[], int p, int r);
int partition(neo a[], int p, int r);
void swap(neo a[], int i, int j);

int main()
{
	neo neoArray[585];		// Init array
	input(neoArray);		// Get Input
	cout << endl;			
	t = clock();			// Start clock
	quicksort(neoArray, 0, 584);	// Sort
	t = clock() - t;		// Stop clock
	output(neoArray);		// Output again
	cout << endl;
	cout << "Sorting took " << t << " clicks." << endl;
	return 0;
}

void input (neo* a)
{
	string line;
	string exit;
	int i = 0;

	while (getline(cin, line))				// Replace myfile with cin
	{
		stringstream ssin(line);			// Use a stringstream to store values
		float tempNum;

		ssin >> a[i].designationString;
		ssin >> tempNum;
		ssin >> exit;					// In case we can't handle a null terminator

		a[i].impactProbability = tempNum;

		i++;						// Iterate. Easy peasy.
	}
	return;
}

///////////// QUICKSORT /////////////////
void quicksort(neo a[], int p, int r)
{
	int pivot;
	if (p < r)
	{
		pivot = median(a, p, r);		// Choose pivot using median-of-three method
		quicksort(a, p, pivot - 1);		// First half (minus pivot)
		quicksort(a, pivot + 1, r);		// Second half (minus pivot)
	}

	return;
}

// Find the median (different median each recursion)
int median(neo a[], int p, int r)
{
	int middle = (r + p) / 2;				// Median = (low_index + high_index) / 2
	
		if (a[p].impactProbability > a[middle].impactProbability)	//if a[low_index] > a[middle], swap
		{
			//swap p and middle
			swap(a, p, middle);
		}

		if (a[p].impactProbability > a[r].impactProbability)		// low > high, swap
		{
			//swap p and r
			swap(a, p, r);
		}

		if (a[middle].impactProbability > a[r].impactProbability)	// middle > high, swap
		{
			//swap middle and r
			swap(a, middle, r);
		}

	swap(a, middle, r);							// Swap the middle and high spots
	return partition(a, p, r);						// Return the partition index
}

// Partition and return pivot (different for each recursion)
int partition(neo a[], int p, int r)
{
	int left;		// Left Index
	int right;		// Right Index
	neo pivot;		// Copy of pivot object

	left = p;		// Lower Bounds
	right = r;		// Upper Bounds
	pivot = a[p];

	while (left < right)
	{
		while (a[right].impactProbability > pivot.impactProbability)
		{
			right--; // Move closer to the middle
		}

		while ((left < right) && (a[left].impactProbability <= pivot.impactProbability))
		{
			left++; // Move closer to the middle
		}

		if (left < right)
		{
			swap(a, left, right);	// Once we flip, we swap again
		}
	}

	a[p] = a[right];	// Swap the objects (instead of the index)
	a[right] = pivot;

	return right;	// Return index to median which returns to quicksort function.
}

void swap(neo a[], int i, int j)
{
	neo temp = a[i];		// Easy swap. Make a copy of a[i]

	a[i] = a[j]; 			// Assign a[j] to a[i]
	a[j] = temp;			// Assign copy of a[i] to a[j]. Done. Yay.

	return;
}

void output (neo* a)
{
	for (int i = 0; i < 585; i++)
	{
		//cout << fixed << setprecision(12) << a[i].designationString << " " << a[i].impactProbability << endl;
		outfile << fixed << setprecision(12) << a[i].designationString << " " << a[i].impactProbability << endl;
	}
}
