#include "tree.h"
#include <iostream>

using namespace std;


tree::tree(void)
{
	root = NULL;												// When we create the tree, we want root to be NULL, or it's all for naught.
	dipSwitch = 1;												// Set dipswitch to 1 for later use.
}


tree::~tree(void)
{
}

void tree::addNode(int value)
{
	if (root != NULL)
	{
		insert(value, root);									// If root has something in it, go to the private function
	}
	else
	{
		root = new node;										// Otherwise create a root node.
		root->setValue(value);
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->directionFromParent = NULL;
	}
}

int tree::height()
{
	return height(root);										// Access the private function
}

int tree::height(node *leaf)
{
	if (leaf == NULL)
	{
		return 0;
	}

	int leftHeight = height(leaf->left);
	int rightHeight = height(leaf->right);

	if (leftHeight > rightHeight)								// If the left is height than the right
	{
		return leftHeight + 1;									// Return leftHeight + 1 (to account for the first layer kind of being a '0'
	}
	else
	{
		return rightHeight + 1;									// Otherwise return the rightHeight
	}
}

void tree::output()
{
	output(root);
	cout << endl;
	dipSwitch = 1;												// Reset dipSwitch for next time
	return;
}

void tree::output(node *leaf)
{
	if(leaf != NULL)
	{
		if (leaf->left != NULL)
		{
			output(leaf->left);
			dipSwitch = 0;										// Maybe not the best way...
		}
		
		if (dipSwitch == 0)										// ...but it works like a dream
		{
			cout << "-";										// This method keeps the dash from printing before the first number
		}
		
		cout << leaf->getValue();
		dipSwitch = 0;											// You know, I love well documented code. I love the practice of it.
		
		if (leaf->right != NULL)								// It makes it a lot easier when I'm finishing an assignment.
		{
			output(leaf->right);								// All I have to do is make sure the comments are properly aligned.
			dipSwitch = 0;
		}
	}
	else
	{
		cout << "Error: Tree is empty." << endl;
	}
}

bool tree::search(int value)
{
	return search(value, root);
}

bool tree::search(int value, node *leaf)
{
	//cout << "Searching for value: " << value << endl;
	if (leaf != NULL)
	{
		if (value == leaf->getValue())							// Simple, if value == current leaf
		{
			cout << "True" << endl;								// Return true
			return true;					
		}
		else if (value > leaf->getValue())						// OTherwise figure out if it's less than or greater than and search again.
		{
			//cout << "Value not found - Searching Right" << endl;
			return search(value, leaf->right);
		}
		else
		{
			//cout << "Value not found - Searching Left" << endl;
			return search(value, leaf->left);
		}
	}

	cout << "False" << endl;
	return false;
}

void tree::insert(int value, node *leaf)
{
	//cout << "Adding " << value << endl;

	if (leaf == NULL)
	{
		cout << "BAD HAPPENED" << endl;							// Honestly, this should never happen
	}

	//cout << "Attempting to get leaf value" << endl;
	//cout << leaf->getValue() << endl;

	if (value < leaf->getValue())
	{
		if(leaf->left != NULL)
		{
			//cout << "Recursion - Left" << endl;
			insert(value, leaf->left);							// If there's another node to the left, keep going
		}
		else
		{
			//cout << "Adding new leaf - Left" << endl;
			leaf->left = new node;								// Else, don't
			leaf->left->setValue(value);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = leaf;
			leaf->left->directionFromParent = 1;				// 1 for left.
		}
	}
	else if (value >= leaf->getValue())
	{
		if(leaf->right != NULL)
		{
			//cout << "Recursion - Right" << endl;
			insert(value, leaf->right);							// If there's another node to the right, keep going
		}
		else
		{
			//cout << "Adding new node - Right" << endl;
			leaf->right = new node;								// Else, don't.
			leaf->right->setValue(value);
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = leaf;
			leaf->right->directionFromParent = 2;				// 2 for right
		}
	}
	
	return;
}

bool tree::deleteNode(int value)
{
	if (root == NULL)
	{
		cout << "Error: Tree Is Empty." << endl;
		return false;											// If there's nothing in the tree, DON'T DELETE IT
	}
	else
	{
		if (root->getValue() == value)
		{
			node temp;
			temp.setValue(0);
			temp.left = root;

			node *deletedNode = root->deleteNode(value, &temp);
			root = temp.left;

			if (deletedNode != NULL)
			{
				delete deletedNode;								// This is much easier this way. Without temp nodes this was a serious pain.
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			node *deletedNode = root->deleteNode(value, NULL);
			
			if (deletedNode != NULL)
			{
				delete deletedNode;								// Went on for hundreds of lines, too.
				return true;
			}
			else
			{
				cout << "Error: Value does not exist in tree. Cannot Delete." << endl;
				return false;
			}
		}
	}
	cout << "Error: Value does not exist in tree. Cannot Delete." << endl;
	return false;												// It was beautiful, but didn't do anything...
}

void tree::reverseTree()
{
	if (root != NULL)
	{
		reverseTree(*root);
	}
	return;
}

void tree::reverseTree(node root)					// I DON'T UNDERSTAND WHY THIS DOESN'T WORK...
{
	node *temp = root.left;							// Make temp node the left node
	root.left = root.right;							// Make left node the right node
	root.right = temp;								// Make the right node the temp node
	
	if(root.left != NULL)
	{
		reverseTree(*root.left);					// If left is not null, keep going
	}
	if(root.right != NULL)
	{
		reverseTree(*root.right);					// If right is not null, keep going
	}
}