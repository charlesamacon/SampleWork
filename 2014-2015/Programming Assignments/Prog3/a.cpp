/************************
Charles Alan Macon
CSCE 3110 - Summer 2015
Program 3 - Binary Search Trees
Due: 07-17-2015
************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node									// Super easy method. Data Structures!
{
	int key;
	node * parent;
	node * left;
	node * right;
};

class BST									// Setting up the class this way keeps me from having too many files
{
	public:
	BST();
	~BST();
	void insert (int k);
	node *search (int k);
	void del_nodeA ();
	node *findLargestChild(node *n);
	node *findSmallestChild(node *n);
	void del_nodeB ();
	void del_nodeC ();
	void del_tree (node *n);
	void print_tree ();

	private:
	void insert (int k, node *n);
	node *search (int k, node *n);
	void print_tree (node *n);
//	void del_tree (node *n);
	node *root;
};

BST::BST()
{
	root = NULL;					// Start with an empty tree.
}

BST::~BST()
{
	del_tree(root);					// Delete the root first and then everything else recursively.
}

void BST::del_tree( node *n)
{
	if (n != NULL)
	{
		del_tree(n->left);			// Recursively delete the left branch
		del_tree(n->right);			// Recursively delete the right branch
		delete n;					// Delete the current node and move back up the tree.
	}
}

node * BST::findLargestChild(node *n)
{
	if (n->right != NULL)
	{
		return findLargestChild(n->right);		// Recursively find the largest child
	}
	else
	{		
		return n;
	}
}

node * BST::findSmallestChild(node *n)
{
	if (n->left != NULL)
	{
		return findSmallestChild(n->left);		// Recursively find the smallest child
	}
	else
	{
		return n;
	}
}

void BST::print_tree()
{
	print_tree(root);
	return;
}

void BST::print_tree(node *n)
{
	// This method traverses the entire tree and SHOULD print every key in order.
	if (n != NULL)
	{
		if (n->left != NULL)
		{
			//cout << "Left" << endl;
			print_tree(n->left);				
		}
		
		if (n->key != -1)
		cout << " " << n->key;

		if (n->right != NULL)
		{
			//cout << "Right" << endl;
			print_tree(n->right);
		}
	}
	return;
}

void BST::del_nodeA()
{
	node *tempRoot;
	node *largestInTL;
	if (root != NULL)	// Make sure tree exists
	{
		cout << endl;
		if (root->left != NULL) // We're dealing with random input, make sure this exists.
		{
			tempRoot = root;
			largestInTL = findLargestChild(root->left);
			
			if (root->key != largestInTL->key)
			{
				root = NULL;						// Nullify root
				root = new node;					
				root->key = largestInTL->key;		// Copy over the key
				root->left = tempRoot->left;		// Change the pointers
				root->right = tempRoot->right;
				largestInTL->key = -1;				// Lazy Deletion. Node still exists, but doesn't "count"
			}
			else
			{
				//cout << "ERROR: Values are equal" << endl;
			}
		}
	}
	return;
}

void BST::insert(int k)
{
	//cout << "Adding value " << k << endl;
	if (root != NULL)
	{
		insert(k, root);			// Move to other insert function with root as the....root....
	}
	else
	{
		root = new node;			// Insert current value as root
		root->left = NULL;			// Set all pointers as null
		root->right = NULL;
		root->parent = NULL;
		root->key = k;
	}
	return;
}

void BST::insert(int k, node *n)
{
	if (k < n->key)						// If given key is smaller than root key
	{
		if (n->left != NULL)
		{
			insert(k, n->left);			// If n->left is not null, keep going
		}
		else
		{
			n->left = new node;			// Create new node
			n->left->left = NULL;
			n->left->right = NULL;
			n->left->key = k;
			n->left->parent = n;

		}

	}
	else if (k >= n->key)				// If given key is larger than root key
	{
		if (n->right != NULL)
		{
			insert(k, n->right);		// Check for children
		}
		else
		{
			n->right = new node;		// Create new node
			n->right->left = NULL;
			n->right->right = NULL;
			n->right->key = k;
			n->right->parent = n;
		}
	}
	return;
}

node * BST::search(int k)
{	
	return search(k, root);				// Not necessary, but I thought I was going to use it.
}

node * BST::search(int k, node * n)
{
	if (n != NULL)
	{
		if (k == n->key)
		{
			//cout << "Found value!" << endl;
			return n;
		}
		else
		{
			if (k < n->key)
			{
				return search(k, n->left);
			}
			else
			{
				return search(k, n->right);
			}
		}
	}
	else
	{
		//cout << "Did not find value" << endl;
		return NULL;
	}
}

int main ()
{
    BST bst;				// Create tree
	
	clock_t t;				// Clock object
	srand (time(NULL));		// Set up random number generation
	
	for (int i = 0; i < 100; i++)
	{
		if (i == 0)
		{
			bst.insert(500);		// Static root.
		}
		else
		{
			int r = rand() % 999 + 1;
			bst.insert(r);			// Populate tree with a bunch of random numbers
		}

	}
	
	cout << "\nPrinting Original Tree:" << endl;
	bst.print_tree();						// Print original Tree
	cout << endl;
	t = clock();							// Start clock
	bst.del_nodeA();						// Delete random node
	t = clock() - t;						// Stop clock
	cout << "Printing New Tree:" << endl;
	bst.print_tree();						// Print new tree.
	
	cout << "\n\nOperation took " << t << " clicks" << endl;
	
	return 0;
}
