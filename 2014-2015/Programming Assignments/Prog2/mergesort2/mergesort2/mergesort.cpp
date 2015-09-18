#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

ifstream myfile ("input.txt");
clock_t t;

struct neo
{
	string designationString = "BADBADBADBAD";
	float impactProbability = 0;
};

void input( neo* a);
void output( neo* a);

//MergeSort
void mergesort( neo a[], int p, int r);
void merge(neo* a, int p, int q, int r);

//QuickSort
void quicksort(neo a[], int p, int r);
int median(neo a[], int p, int r);
int partition(neo a[], int p, int r);
void swap(neo a[], int i, int j);

int main()
{
	neo neoArray[585];
	input(neoArray);
	output(neoArray);
	system("PAUSE");
	t = clock();
	//mergesort(neoArray, 0, 584);
	quicksort(neoArray, 0, 584);
	t = clock() - t;
	output(neoArray);
	cout << endl;
	cout << "Sorting took " << t << " clicks." << endl;
	system("PAUSE");
	return 0;
}

void input (neo* a)
{
	string line;
	string exit;
	int i = 0;

	while (getline(myfile, line))
	{
		stringstream ssin(line);
		string tempNum;

		ssin >> a[i].designationString;
		ssin >> tempNum;
		ssin >> exit;

		a[i].impactProbability = stof(tempNum);

		i++;
	}
	return;
}

//////////// MERGESORT ///////////////
void mergesort(neo a[], int p, int r)
{
	//cout << "Entering mergesort.\n";
	
	if (p < r)
	{

		int q = (p + r) / 2;
		//cout << p << endl;
		//cout << q << endl;
		//cout << r << endl;
		//cout << "M1" << endl;
		//system("PAUSE");
		mergesort(a, p, q);
		//cout << "M2" << endl;
		//system("PAUSE");
		mergesort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

void merge(neo* a, int p, int q, int r)
{
	//cout << "Entering Merge" << endl;
	int i, j, k;
	neo copy[585];

	i = p;	// low
	k = p;	// low
	j = q + 1; // mid

	while (i <= q && j <= r)
	{
		if (a[i].impactProbability < a[j].impactProbability)
		{
			copy[k] = a[i];
			k++;
			i++;
		}
		else
		{
			copy[k] = a[j];
			k++;
			j++;
		}
	}

	for (i; i <= q; i++)
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
		a[i] = copy[i];
	}
}

///////////// QUICKSORT /////////////////
void quicksort(neo a[], int p, int r)
{
	int pivot;
	if (p < r)
	{
		pivot = median(a, p, r);
		quicksort(a, p, pivot - 1);
		quicksort(a, pivot + 1, r);
	}

	return;
}

int median(neo a[], int p, int r)
{
	int middle = (r + p) / 2;				// Median = (low_index + high_index) / 2
	
		if (a[p].impactProbability > a[middle].impactProbability)
		{
			//swap p and middle
			swap(a, p, middle);
		}

		if (a[p].impactProbability > a[r].impactProbability)
		{
			//swap p and r
			swap(a, p, r);
		}

		if (a[middle].impactProbability > a[r].impactProbability)
		{
			//swap middle and r
			swap(a, middle, r);
		}
	//}

	swap(a, middle, r);
	return partition(a, p, r);
}

int partition(neo a[], int p, int r)
{
	int left;
	int right;
	neo pivot;

	left = p;
	right = r;
	pivot = a[p];

	while (left < right)
	{
		while (a[right].impactProbability > pivot.impactProbability)
		{
			right--;
		}

		while ((left < right) && (a[left].impactProbability <= pivot.impactProbability))
		{
			left++;
		}

		if (left < right)
		{
			swap(a, left, right);
		}
	}

	a[p] = a[right];
	a[right] = pivot;

	return right;
}

void swap(neo a[], int i, int j)
{
	neo temp = a[i];

	a[i] = a[j]; 
	a[j] = temp;

	return;
}

void output (neo* a)
{
	for (int i = 0; i < 585; i++)
	{
		cout << fixed << setprecision(12) << a[i].designationString << " " << a[i].impactProbability << endl;
	}
}