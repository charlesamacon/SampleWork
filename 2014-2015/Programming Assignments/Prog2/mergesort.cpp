/********************************
Charles Alan Macon
CSCE 3110
Programming Assignment 2 - MergeSort
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

//ifstream myfile ("input.txt");			// I assume this needs to be commented out and replaced by cin
ofstream outfile ("neo_sorted.txt");		// Change this before submitting
clock_t t;					// Clock_t object for tracking "clicks"

struct neo
{
	string designationString;		// Don't initialize within the struct
	float impactProbability;		// Doesn't work on the CSE Machine
};

void input( neo* a);
void output( neo* a);

//MergeSort
void mergesort( neo a[], int p, int r);
void merge(neo* a, int p, int q, int r);

int main()
{
	neo neoArray[585];
	input(neoArray);			// Input into the array
	t = clock();				// Start the clock
	mergesort(neoArray, 0, 584);		// Perform mergesort
	t = clock() - t;			// Stop the clock
	output(neoArray);			// Output sorted array
	cout << endl;				// Skip a line
	cout << "Sorting took " << t << " clicks." << endl;	// Return number of clicks
	return 0;
}

void input (neo* a)
{
	string line;
	string exit;
	int i = 0;

	while (getline(cin, line))			// Replace myfile with cin
	{
		stringstream ssin(line);		// Stringstreams are fun and easy
		float tempNum;

		ssin >> a[i].designationString;		// Store designation string
		ssin >> tempNum;			// store value in tempnum
		ssin >> exit;				// Just in case we can't handle the null terminator
		a[i].impactProbability = tempNum;	// Store tempnum in struct.impactProbability
		i++;					// Iterate and continue
	}
	return;
}

//////////// MERGESORT ///////////////
void mergesort(neo a[], int p, int r)
{
	//cout << "Entering mergesort.\n";
	
	if (p < r)
	{

		int q = (p + r) / 2;			// Get the middle point
		mergesort(a, p, q);			// Repeat with first half
		mergesort(a, q + 1, r);			// Repeat with second half
		merge(a, p, q, r);			// Merge all the way up.
	}
}

// Merge from bottom up
void merge(neo* a, int p, int q, int r)
{
	int i, j, k;
	neo copy[585];					// Only has to be the size of the full array for the last merge.
							// I could probably get away with dynamically allocating this based
							// on the size of each "chunk", but this is easier for the moment.

	i = p;						// lower bounds
	k = p;						// lower bounds
	j = q + 1; 					// middle point

	while (i <= q && j <= r)
	{
		if (a[i].impactProbability < a[j].impactProbability)	// if the value at the index we're currently
		{							// at is lower than the other index
			copy[k] = a[i];					// copy it over, iterate, and continue
			k++;
			i++;
		}
		else
		{
			copy[k] = a[j];					// otherwise, copy the other value over
			k++;
			j++;
		}
	}

	for (i; i <= q; i++)			//Tidy everything else up by just copying it over
	{
		copy[k] = a[i];
		k++;
	}

	for (j; j <= r; j++)
	{
		copy[k] = a[j];
		k++;
	}

	for (i = p; i < k; i++)
	{
		a[i] = copy[i];						// Copy everything back to the original array
	}
}


void output (neo* a)
{
	for (int i = 0; i < 585; i++)
	{
		outfile << fixed << setprecision(12) << a[i].designationString << " " << a[i].impactProbability << endl;
	}
}
