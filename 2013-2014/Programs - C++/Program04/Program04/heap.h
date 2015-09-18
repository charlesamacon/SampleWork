#pragma once
class heap
{
private:
	int size;
public:
	heap(void);
	heap(int *a, int x);
	~heap(void);
	void insert(int *a, int x);
	void buildHeap(int *a, int i, int n);
	void deleteMax(int *a);
	void output(int *a);
};

