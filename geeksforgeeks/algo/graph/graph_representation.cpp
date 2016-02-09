// http://www.geeksforgeeks.org/graph-and-its-representations/

// representation of unweighted directed graph

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	int v;
	vector<int> * array;
public:
	Graph(int v) : v(v), array(new vector<int>[v]) {} // using initializer list in constructor
	void addEdge(int src, int dest);
	void printGraph();
};

void Graph::addEdge(int src, int dest)
{
	array[src].insert(array[src].begin(), dest);
}

void Graph::printGraph()
{
	for(int i=0;i<v;i++)
		for(int j=0;j<array[i].size();j++)
			cout << "Edge from vertex " << i << " to vertex " << array[i][j] << endl;
}

int main(){
	int v = 5;
	//cout << "Enter the number of vertices\n":
	//cin >> v;
	Graph g(v);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(3,2);
	g.printGraph();
	return 0;
}
