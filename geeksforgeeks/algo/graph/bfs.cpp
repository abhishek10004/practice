// http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
	int no_vertices;
	vector<int> * vertices;
public:
	Graph(int v) : no_vertices(v), vertices(new vector<int>[v]) {}
	void addEdge(int src, int dest);
	void printGraph();
	void bfs(int src);
};

void Graph::addEdge(int src, int dest)
{
	vertices[src].insert(vertices[src].begin(), dest);
}

void Graph::printGraph()
{
	for(int i=0;i<no_vertices;i++)
		for(int j=0;j<vertices[i].size();j++)
			cout << "Edge from vertex " << i << " to vertex " << vertices[i][j] << endl;
}

void Graph::bfs(int src)
{
	bool isVisited[no_vertices];
	for(int i=0;i<no_vertices;i++)
		isVisited[i] = false;
	queue<int> vertices_queue;
	vertices_queue.push(src);
	while(!vertices_queue.empty())
	{
		int vertex = vertices_queue.front();
		vertices_queue.pop();
		if(isVisited[vertex])
			continue;
		isVisited[vertex] = true;
		cout << "The vertex is " << vertex << endl;
		// visit the neighbours and put them in queue
		for(int i=0;i<vertices[vertex].size();i++)
			vertices_queue.push(vertices[vertex][i]);
	}
}

int main()
{
	int v = 5;
	Graph g(v);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 0);
	g.addEdge(3, 3);
	g.bfs(2);
	return 0;
}
