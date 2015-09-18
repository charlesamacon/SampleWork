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

struct node				// Nice and simple
{
	int key;
	node * parent;
	node * left;
	node * right;
};

class BST
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
		return findLargestChild(n->right);		// Recursively find largest child
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
		return findSmallestChild(n->left);		// Recursively find smallest child
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

void BST::del_nodeB()
{
	node *largestInTL;
	node *smallestinTR;
	node *tempRoot;
	
	if (root != NULL)
	{
		if (root->left != NULL && root->right != NULL)
		{
			cout << endl;
			//cout << "Entering Delete" << endl;
			tempRoot = root;
			largestInTL = findLargestChild(root->left);			// Basically we do double the work as we did in A
			smallestinTR = findSmallestChild(root->right);		// by finding the largest of the left and the smallest
			
			int tLDistance = root->key - largestInTL->key;		// of the right. Then we compare them.
			int tRDistance = smallestinTR->key - root->key;
			
			if (tLDistance < tRDistance)
			{
				//cout << "Left" << endl;
				root = NULL;						// Same method used in A.
				root = new node;
				root->key = largestInTL->key;
				root->left = tempRoot->left;
				root->right = tempRoot->right;
				largestInTL->key = -1;				// Lazy Deletion. Node still exists, but doesn't "count"
			}
			else
			{
				//cout << "Right" << endl;
				// smallestinTR becomes root
				root = NULL;						// Same as above, but on the other side.
				root = new node;
				root->key = smallestinTR->key;
				root->left = tempRoot->left;
				root->right = tempRoot->right;
				smallestinTR->key = -1;				// Lazy Deletion. Node still exists, but doesn't "count"
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
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->key = k;
	}
	return;
}

void BST::insert(int k, node *n)
{
	if (k < n->key)
	{
		if (n->left != NULL)
		{
			insert(k, n->left);
		}
		else
		{
			n->left = new node;
			n->left->left = NULL;
			n->left->right = NULL;
			n->left->key = k;
			n->left->parent = n;

		}

	}
	else if (k >= n->key)
	{
		if (n->right != NULL)
		{
			insert(k, n->right);
		}
		else
		{
			n->right = new node;
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
	return search(k, root);
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
	
	clock_t t;	
	srand (time(NULL));
	
	for (int i = 0; i < 100; i++)
	{
		if (i == 0)
		{
			bst.insert(500);
		}
		else
		{
			int r = rand() % 999 + 1;
			bst.insert(r);			// Populate tree with a bunch of random numbers
		}

	}
	
	cout << "\nPrinting Original Tree:" << endl;
	bst.print_tree();
	cout << endl;
	t = clock();
	bst.del_nodeB();						// Using Strategy B here.
	t = clock() - t;
	cout << "Printing New Tree:" << endl;
	bst.print_tree();
	
	cout << "\n\nOperation took " << t << " clicks" << endl;
	
	return 0;
}
