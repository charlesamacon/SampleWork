/******************************************
Charles Alan Macon
CSCE 3110
Programming Assignment 5 - Breadth First Search
Due Date: August 7,  2015

Output:
The program returns each edge (in order individually).
If we're using the input from the original assignment, output should be:

The Graph Is Connected
1 3 4 2
Edge List:
----------
{ 1 - 3 }
{ 1 - 4 }
{ 1 - 2 }
{ 2 - 4 }
{ 2 - 3 }
{ 3 - 4 }
******************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>

using namespace std;

//ifstream myfile("input.txt");						// This needs to be commented out and all references changed to cin

struct edge
{
	int vertex1;
	int vertex2;
};

class Graph
{
private:
	int verts;										// How many verticies are we working with?
	list<int> *adjacencyLists;
	edge vertlist[1000];							// This is our list of edges, regardless of what it is actually called
public:
	Graph(int verts);
	void addToVertList(int v1, int v2);				// Add to list
	bool checkInVertList(int v1, int v2);			// Check to see if an edge already exists in list (undirected, so no "duplicates")
	void printVertList();							// Print the list of edges
	void setActualVerts(int v);						// We initialize int verts to a high value, but this is the ACTUAL value, as determined in main()
	void createEdge(int v1, int v2);				// Create an edge
	void traverseGraph(int root);					// Output the graph
	bool isBroken(int root);						// Same as traverseGraph(), except there's no output. It just looks to see if we can access every vertex.
};

Graph::Graph(int verts)
{
	this->verts = verts;							// Must be a high value to allow for a lot of numbers, if desired.
	adjacencyLists = new list<int>[verts];

	for (int i = 0; i < 1000; i++)
	{
		vertlist[i].vertex1 = -1;					// We can initialize these values in the struct on my machine at home
		vertlist[i].vertex2 = -1;					// but the CSE machine won't let me. This is my workaround.
	}
}

bool Graph::checkInVertList(int v1, int v2)
{
	// Run through the list of edges to see if this edge already exists.
	// Remember, this is undirected, so { X, Y } is the same as { Y, X }
	for (int i = 0; i < 1000; i++)
	{
		if (vertlist[i].vertex1 != -1)
		{
			if ((vertlist[i].vertex1 == v1 && vertlist[i].vertex2 == v2) || (vertlist[i].vertex2 == v1 && vertlist[i].vertex1 == v2))
			{
				return false;						// If the edge already exists...we return...false. I should have thought this through better, but it works, at least.
			}
		}
	}

	return true;
}

void Graph::addToVertList(int v1, int v2)
{
	if (checkInVertList(v1, v2))					// Confusing, I know. Returns true if edge is NOT in list already.
	{
		// add to vert list
		for (int i = 0; i < 1000; i++)
		{
			if (vertlist[i].vertex1 == -1)
			{
				vertlist[i].vertex1 = v1;
				vertlist[i].vertex2 = v2;
				return;
			}
		}
	}
	else
	{
		return;										// If it already exists, don't add and continue on our way.
	}
}

void Graph::createEdge(int v1, int v2)
{
	adjacencyLists[v1].push_back(v2);				// Much easier when we're dealing with an actual <list>
	//cout << "Edge Created" << endl;
	addToVertList(v1, v2);
	return;
}

void Graph::setActualVerts(int v)
{
	verts = v;										// Update # of verts.
	return;
}

bool Graph::isBroken(int root)
{
	// Traversing Graph
	bool *visited = new bool[verts];
	for (int i = 0; i < verts; i++)
	{
		visited[i] = false;
	}

	list<int> queue;

	visited[root] = true;
	queue.push_back(root);

	list<int>::iterator i;

	while (!queue.empty())
	{
		root = queue.front();
		//cout << root << " ";
		queue.pop_front();

		for (i = adjacencyLists[root].begin(); i != adjacencyLists[root].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	for (int i = 1; i < verts; i++)	// Have to start at 1 because reasons. (0 don't count, yo)
	{
		// Basically, what we're doing here is checking to see if we're able to get to each vertex in the graph.
		// If we aren't, then the graph is disconnected and we exit.
		if (visited[i] == false)
		{
			cout << "The Graph Is Disconnected" << endl;
			return false;	// Um...if it IS broken...return false.
		}
	}
	cout << "The Graph Is Connected" << endl;
	return true;
}

void Graph::traverseGraph(int root)
{
	// Traversing Graph
	// This function is exactly the same as the function above, except this outputs the entire tree.
	bool *visited = new bool[verts];
	for (int i = 0; i < verts; i++)
	{
		visited[i] = false;
	}

	list<int> queue;

	visited[root] = true;
	queue.push_back(root);

	list<int>::iterator i;

	while (!queue.empty())
	{
		root = queue.front();

		if (root != 0 && root != -1)
		{
			cout << root << " ";
		}
		queue.pop_front();

		for (i = adjacencyLists[root].begin(); i != adjacencyLists[root].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	return;
}

void Graph::printVertList()
{
	// To print everything in its proper order, we need to have to iterators going, which has O(n^2)
	// The inner loop will only print the values that match that of the outer loop. So we're basically taking it a layer at a time.
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (vertlist[j].vertex1 != -1 && vertlist[j].vertex2 != -1 && vertlist[j].vertex1 != 0 && vertlist[j].vertex2 != 0)
			{
				if (i == vertlist[j].vertex1)
					cout << "{ " << vertlist[j].vertex1 << " - " << vertlist[j].vertex2 << " }" << endl;
			}
		}
	}
}

int main()
{
	string line;

	int graphSize = 1001;										// Allow for a LOT of values

	Graph newGraph(graphSize);									// Basically, what we're doing is allocating room for a lot of values, but then ignoring the room we don't need.
	int largest = 0;											// So, we need to keep track of the largest vertex that comes our way.

	while (getline(cin, line))
	{
		
		stringstream ssin(line);								// Hey, our old friend, the stringstream. Useful and effective.
		int command;											// The first character of input
		int tempNum[1000] = { 0 };

		ssin >> command;
		if (command > largest)
		{
			largest = command;									// If this input is larger than the largest value so far, we update the value.
		}

		// This block allows us to accept a vertex that is adjacent to a large number of other vertices
		for (int i = 0; i < 1000; i++)
		{
			int x = ssin.peek();	

			if (x == EOF)										// Check to make sure that there's something to add.
			{
				break;
			}
			else
			{
				ssin >> tempNum[i];
				newGraph.createEdge(command, tempNum[i]);		// If there is something to add, we create a new edge (and add it to our list of edges)
			}
		}
	}

	
	newGraph.setActualVerts(largest + 1);						// Set the upper limit to the ACTUAL number of verts.
	if (newGraph.isBroken(1))									// Check to see if we're broken or not. 
	{
		newGraph.traverseGraph(1);								//If not, we'll continue through the thing. All this line does is output the entire tree. Not necessary, but nice to see that it's working correctly.
		cout << "\nEdge List: " << endl;
		cout << "----------" << endl;							// Formatting to make it pretty
		newGraph.printVertList();								// Print the list in breadth first format
	}
	//system("PAUSE");											// For Windows OS only
	return 0;
}