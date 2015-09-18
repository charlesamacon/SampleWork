#include "node.h"

using namespace std;

class tree
{
private:
	node *root;
	void insert(int value, node *leaf);
	bool search(int value, node *leaf);
	bool isNodeLowest(int value, node *leaf);
	void reverseTree(node root);
	void output(node *leaf);
	int height(node *leaf);

public:
	int dipSwitch;
	int height();
	void addNode(int value);
	bool search(int value);
	bool isNodeLowest(int value);
	bool deleteNode(int value);
	void reverseTree();
	void output();
	tree(void);
	~tree(void);
};

