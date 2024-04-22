#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include<queue>
#include <set>
using namespace std;

class covexHull_point
{
public:
	int x, y;
	covexHull_point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator<(const covexHull_point &p) const
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};
vector<covexHull_point> convexHull(vector<covexHull_point> n);







class Graph
{
private:
	unordered_map<string, unordered_set<string>> adjList;

	// recursion version
	void dfs(string vertex, unordered_map<string, bool> &visited)
	{

		visited.insert(pair<string, bool>(vertex, true));
		cout << vertex << " ";

		for (auto i : adjList.at(vertex))
			if (visited.count(i) == 0)
			{
				dfs(i, visited);
			}
	}

	// heap version
	void DFS_heap();

public:
	bool addVertex(string vertex)
	{
		if (adjList.count(vertex) == 0)
		{
			adjList[vertex];
			return true;
		}
		return false;
	}

	void printGraph()
	{
		for (auto [vertex, edges] : adjList)
		{
			cout << vertex << ": [";
			for (auto edge : edges)
			{
				cout << edge << " ";
			}
			cout << "]" << endl;
		}
	}

	bool addEdge(string vertex1, string vertex2)
	{
		if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
		{
			adjList.at(vertex1).insert(vertex2);
			adjList.at(vertex2).insert(vertex1);
			return true;
		}
		return false;
	}

	bool removeEdge(string vertex1, string vertex2)
	{
		if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
		{
			adjList.at(vertex1).erase(vertex2);
			adjList.at(vertex2).erase(vertex1);
			return true;
		}
		return false;
	}

	bool removeVertex(string vertex)
	{
		if (adjList.count(vertex) != 0)
		{
			for (auto i : adjList.at(vertex))
			{
				adjList.at(i).erase(vertex);
			}
			adjList.erase(vertex);
		}
		return false;
	}

	void DFS(string vertex)
	{
		unordered_map<string, bool> visited;
		dfs(vertex, visited);
	}

	void BFS(string vertex)
	{
		unordered_map<string, bool> visited;
		queue<string> q;

		visited[vertex] = true;
		q.push(vertex);

		while (!q.empty())
		{
			string currentVertex = q.front();
			cout << currentVertex << " ";
			q.pop();
			for (auto i : adjList[currentVertex]) {
				if (visited.count(i)==0) {
					q.push(i);
					visited[i] = true;
				}
			}

		}
	}
};