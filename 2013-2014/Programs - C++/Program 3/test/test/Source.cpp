#include <iostream>

using namespace std;

void a(int x);
void b(int y);
void c(int z);

int main()
{
	c(3);
	return 0;
}

void a(int x)
{
	int y = 0;

	for (int i = x; i > 0; i--)
	{
		for (int j = 10; j > 0; j--)
		{
			cout << "y: " << y << endl;
			cout << "i: " << i << endl;
			cout << endl;
			
			y++;
		}
	}
	return;
}

void b(int y)
{
	for (int i = 10; i < y; i++)
	{
		cout << "y: " << y << endl;
		cout << "i: " << i << endl;
		cout << endl;
		
	}
	return;
}

void c(int z)
{
	int r = 10;
	int s = 0;
	int t = 8;

	for (int i = 0; i < z; i++)
	{
		r++;
		cout << "b(s):";
		b(s);
		cout << endl;
		cout << "r :" << r << endl;
		//cout << y;
	}

	cout << "entering a(t)" << endl;
	a(t);
	cout << "entering b(r)" << endl;
	b(r);
	return;
}