#ifndef NODE_H
#define NODE_H

using namespace std;

class node
{
private:
	int value;
	
public:
	node *left;
	node *right;
	node *parent;
	node *deleteNode(int value, node *parent);
	int directionFromParent;

	int getValue();
	void setValue(int v);
	int minimum();

	node getLeft();
	node getRight();

	node(void);
	~node(void);
};

#endif