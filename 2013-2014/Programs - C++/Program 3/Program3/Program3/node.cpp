#include "node.h"
#include <iostream>

using namespace std;

node::node(void)
{
}


node::~node(void)
{
}

int node::getValue()
{
	return value;
}

void node::setValue(int v)
{
	value = v;
	return;
}

node node::getLeft()
{
	return *left;
}

node node::getRight()
{
	return *right;
}

node* node::deleteNode(int value, node *parent)
{
	if (value < this->value)
	{
		if (left != NULL)															// Find the node
		{
			return left->deleteNode(value, this);									// Recursion!
		}
		else
		{
			return NULL;
		}
	}
	else if (value > this->value)
	{
		if (right != NULL)															// Find the node
		{
			return right->deleteNode(value, this);
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		if (left != NULL && right != NULL)											// If it has childrenn...
		{
			this -> value = right->minimum();
			return right->deleteNode(this->value, this);
		}
		else if (parent->left == this)
		{
			if (left != NULL)
			{
				parent->left = left;
			}
			else
			{
				parent->left = right;
			}
			return this;
		}
		else if (parent->right == this)												// Makes total sense
		{
			if (left != NULL)
			{
				parent->right = left;
			}
			else
			{
				parent->right = right;
			}
			return this;
		}
	}
}

int node::minimum()
{
	if (left == NULL)																// Quick and easy way of getting the minimum value.
		return value;
	else
		return left->minimum();
}