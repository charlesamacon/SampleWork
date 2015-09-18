#include "adder.h"

Adder::Adder(string parameter1, string parameter2)
{
	this->parameter1 = parameter1;
	this->parameter2 = parameter2;
};

void Adder::printAdderBase2()
{
	const bool DEBUG = false;
	
	if (DEBUG == true)
	{
		cout << "Entering printAdderBase2()" << endl;
	}

	int p1Length = parameter1.size();
	int p2Length = parameter2.size();
	int lengthCheck = 0;
	int n;
	carry = '0';

	if (p1Length >= p2Length)
		n = p1Length;
	else
		n = p2Length;

	char * temp;
	temp = new char[n+1];

	char * newParameter;
	newParameter = new char[n];
	char * goodParameter;
	goodParameter = new char[n];
	
	if (DEBUG == true)										// Debugging output
	{
		cout << p1Length << endl;
		cout << p2Length << endl;
		cout << n << endl;
	}

	if (p1Length < n || p1Length == p2Length)				// This section makes sure that
	{														// both of the parameters are
		int remainder = n - p1Length;						// the same length.
															// If they already are, then the
		for(int i = 0;i < remainder;i++)					// first parameter becomes "newParameter"
		{
			newParameter[i] = '0';
		}

		for (int i = 0; i < p1Length; i++)
		{
			newParameter[(remainder+i)]=parameter1[i];
		}

		for (int i=0; i < p2Length; i++)
		{
			goodParameter[i] = parameter2[i];
		}
	}
	else if (p2Length < n)
	{
		int remainder = n - p2Length;

		for(int i = 0;i < remainder;i++)
		{
			newParameter[i] = '0';
		}

		for (int i = 0; i < p2Length; i++)
		{
			newParameter[(remainder+i)]=parameter2[i];
		}

		for (int i=0; i < p1Length; i++)
		{
			goodParameter[i] = parameter1[i];
		}
	}

	if (DEBUG == true)										// More debugging output to make sure that
	{														// The parameters were properly formatted.
		for (int i=0; i < n; i++)
		{
			cout << newParameter[i];
		}
		cout << endl;
		for (int i=0; i < n; i++)
		{
			cout << goodParameter[i];
		}
		cout << endl;

	//system("PAUSE");										// This command is OS-specific and creates a nice "pause"

	cout << parameter1[p1Length-1] << endl;					// A check of the last digit.
	cout << parameter2[p2Length-1] << endl;					// For debugging purposes only.

	}

	for (int i = n-1; i >= 0; i--)
	{
		char p1 = newParameter[i];
		char p2 = goodParameter[i];
		int int1;
		int int2;
		int intCarry;

		if (p1 == '0')										// If the current digit being looked at is a 0
		{
			int1 = 0;										// The current int1 should be as well
		}
		else
			int1 = 1;										// Or it should be a 1

		if (DEBUG == true)
		{
			cout << "INT1: " << int1 << endl;
		}

		if (p2 == '0')										// Same goes for p2 and int2
			int2 = 0;
		else
			int2 = 1;

		if (DEBUG == true)
		{
			cout << "INT2: " << int2 << endl;
		}

		if (carry == '0')
			intCarry = 0;
		else
			intCarry = 1;

		if (DEBUG == true)
		{
			cout << "CARRY: " << carry << endl;
		}

		// Now for the fun part...
		if (int1+int2+intCarry==3)							// If they all equal 3
		{
			temp[i] = '1';									// Do this...
			carry = '1';
		}
		else if (int1+int2+intCarry==2)						// == 2
		{
			temp[i] = '0';									// Do this!
			carry = '1';
		}
		else if (int1+int2+intCarry==1)						// == 1
		{
			temp[i] = '1';									// See the pattern?
			carry = '0';
		}
		else if (int1+int2+intCarry==0)						// And so on and so forth
		{
			temp[i] = '0';
			carry = '0';
		}
	}

	if (carry == '1')
	{
		for (int i = 0; i <= n-1; i++)
		{
			lengthCheck++;
		}

		lengthCheck++;
	}

	// "But Alan," you might ask, "this will only end up displaying n digits
	// that are in the temp[] array. How do we fix this?"

	if (lengthCheck <= 6)
	{
		if (carry == '1')										// By manually outputting the carry string
		{														// if it isn't a 0, that's how.
			cout << carry;
		}

		if (temp[0] != '0')										// If the first digit (not counting carry) isn't a 0
		{														// continue like normal
			for (int i = 0; i <= n-1; i++)
			{
				cout << temp[i];
			}
		}
		else if (temp[0] == '0' && carry == '0')				// Otherwise, get rid of the zero and display the first "1".
		{
			int oneCnter = 0;
			for (int i = 1; i <= n-1; i++)						
			{	
				if (oneCnter == 0 && temp[i] == '0')
				{			
					// DO NOTHING AND SKIP THIS DIGIT
					// FOR IT IS NOTHING BUT A LEADING 0
				}
				else
				{
					cout << temp[i];
					oneCnter++;
				}
			}
		}
		else													// All other cominations of stuff should just output normally.
		{
			for (int i = 0; i <= n-1; i++)
			{
				cout << temp[i];
			}
		}
	}
	else
	{
		cout << "ERROR: Answer must be less than 7 digits" << endl;
	}

	cout << endl;

	return;
};

void Adder::printAdderBase6()
{
	const bool DEBUG = false;
	
	if (DEBUG == true)
	{
		cout << "Entering printAdderBase6()" << endl;
	}

	int p1Length = parameter1.size();
	int p2Length = parameter2.size();
	int lengthCheck = 0;
	int n;
	carry = '0';

	if (p1Length >= p2Length)
		n = p1Length;
	else
		n = p2Length;

	char * temp;
	temp = new char[n+1];

	char * newParameter;
	newParameter = new char[n];
	char * goodParameter;
	goodParameter = new char[n];
	
	if (DEBUG == true)										// Debugging output
	{
		cout << p1Length << endl;
		cout << p2Length << endl;
		cout << n << endl;
	}

	if (p1Length < n || p1Length == p2Length)				// This section makes sure that
	{														// both of the parameters are
		int remainder = n - p1Length;						// the same length.
															// If they already are, then the
		for(int i = 0;i < remainder;i++)					// first parameter becomes "newParameter"
		{
			newParameter[i] = '0';
		}

		for (int i = 0; i < p1Length; i++)
		{
			newParameter[(remainder+i)]=parameter1[i];
		}

		for (int i=0; i < p2Length; i++)
		{
			goodParameter[i] = parameter2[i];
		}
	}
	else if (p2Length < n)
	{
		int remainder = n - p2Length;

		for(int i = 0;i < remainder;i++)
		{
			newParameter[i] = '0';
		}

		for (int i = 0; i < p2Length; i++)
		{
			newParameter[(remainder+i)]=parameter2[i];
		}

		for (int i=0; i < p1Length; i++)
		{
			goodParameter[i] = parameter1[i];
		}
	}

	if (DEBUG == true)										// More debugging output to make sure that
	{														// The parameters were properly formatted.
		for (int i=0; i < n; i++)
		{
			cout << newParameter[i];
		}
		cout << endl;
		for (int i=0; i < n; i++)
		{
			cout << goodParameter[i];
		}
		cout << endl;

	//system("PAUSE");										// This command is OS-specific and creates a nice "pause"

	cout << parameter1[p1Length-1] << endl;					// A check of the last digit.
	cout << parameter2[p2Length-1] << endl;					// For debugging purposes only.

	}

	for (int i = n-1; i >= 0; i--)
	{
		char p1 = newParameter[i];
		char p2 = goodParameter[i];
		int int1;
		int int2;
		int intCarry;
	
		if (p1 == '0')
			int1 = 0;
		else if (p1 == '1')
			int1 = 1;
		else if (p1 == '2')
			int1 = 2;
		else if (p1 == '3')
			int1 = 3;
		else if (p1 == '4')
			int1 = 4;
		else
			int1 = 5;
		
		if (DEBUG == true)
		{
			cout << "INT1: " << int1 << endl;
		}
		
		if (p2 == '0')
			int2 = 0;
		else if (p2 == '1')
			int2 = 1;
		else if (p2 == '2')
			int2 = 2;
		else if (p2 == '3')
			int2 = 3;
		else if (p2 == '4')
			int2 = 4;
		else
			int2 = 5;
		
		if (DEBUG == true)
		{
			cout << "INT2: " << int2 << endl;
		}
	
		if (carry == '0')
			intCarry = 0;
		else
			intCarry = 1;

		if (DEBUG == true)
		{
			cout << "CARRY: " << carry << endl;
		}

		// Now for the fun part...
		if (int1+int2+intCarry==11)
		{
			temp[i] = '5';
			carry = '1';
		}
		else if (int1+int2+intCarry==10)
		{
			temp[i] = '4';
			carry = '1';
		}
		else if (int1+int2+intCarry==9)
		{
			temp[i] = '3';
			carry = '1';
		}
		else if (int1+int2+intCarry==8)
		{
			temp[i] = '2';
			carry = '1';
		}
		else if (int1+int2+intCarry==7)
		{
			temp[i] = '1';
			carry = '1';
		}
		else if (int1+int2+intCarry==6)
		{
			temp[i] = '0';
			carry = '1';
		}
		else if (int1+int2+intCarry==5)
		{
			temp[i] = '5';
			carry = '0';
		}
		else if (int1+int2+intCarry==4)
		{
			temp[i] = '4';
			carry = '0';
		}
		else if (int1+int2+intCarry==3)
		{
			temp[i] = '3';
			carry = '0';
		}
		else if (int1+int2+intCarry==2)
		{
			temp[i] = '2';
			carry = '0';
		}
		else if (int1+int2+intCarry==1)
		{
			temp[i] = '1';
			carry = '0';
		}
		else
		{
			temp[i] = '0';
			carry = '0';
		}
	}
	
		if (carry == '1')
	{
		for (int i = 0; i <= n-1; i++)
		{
			lengthCheck++;
		}

		lengthCheck++;
	}

	// "But Alan," you might ask, "this will only end up displaying n digits
	// that are in the temp[] array. How do we fix this?"

	if (lengthCheck <= 6)
	{
		if (carry == '1')										// By manually outputting the carry string
		{														// if it isn't a 0, that's how.
			cout << carry;
		}

		if (temp[0] != '0')										// If the first digit (not counting carry) isn't a 0
		{														// continue like normal
			for (int i = 0; i <= n-1; i++)
			{
				cout << temp[i];
			}
		}
		else if (temp[0] == '0' && carry == '0')				// Otherwise, get rid of the zero and display the first "1".
		{
			int oneCnter = 0;
			for (int i = 1; i <= n-1; i++)						
			{	
				if (oneCnter == 0 && temp[i] == '0')
				{			
					// DO NOTHING AND SKIP THIS DIGIT
					// FOR IT IS NOTHING BUT A LEADING 0
				}
				else
				{
					cout << temp[i];
					oneCnter++;
				}
			}
		}
		else													// All other cominations of stuff should just output normally.
		{
			for (int i = 0; i <= n-1; i++)
			{
				cout << temp[i];
			}
		}
	}
	else
	{
		cout << "ERROR: Answer must be less than 7 digits" << endl;
	}

	cout << endl;

	return;
};