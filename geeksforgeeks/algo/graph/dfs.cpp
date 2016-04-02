#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph{
	int v;
	vector<int> * vertices;
public:
	Graph(int v) : v(v), vertices(new vector<int>[v]) {}
	void addEdge(int u, int v) { vertices[u].insert(vertices[u].begin(), v); }
	void printGraph()
	{
		for(int i=0;i<v;i++)
			for(int j=0;j<vertices[i].size();j++)
				cout << "Edge from vertex " << i << " to vertex " << vertices[i][j] << endl;
	}
	void dfs(int src);
};

// Assuming the graph is connected
void Graph::dfs(int src)
{
	bool isVisited[v];
	for(int i=0;i<v;i++)
		isVisited[i] = false;
	stack<int> s;
	s.push(src);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		if(isVisited[top])
			continue;
		cout << "Visiting vertex " << top << endl;
		isVisited[top]	 = true;
		for(int i=0;i<vertices[top].size();i++)
			s.push(vertices[top][i]);
	}
}

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 0);
	g.addEdge(3, 3);
	g.printGraph();
	g.dfs(0);
	return 0;
}