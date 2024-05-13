
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void johnsonTrotter(int n);
vector<string> BRGC(int n);



class Graph {
private:
	unordered_map<string, unordered_set<string>>adjList;
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

	bool addEdge_v1_to_v2(string vertex1,string vertex2) {
		if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
		{
			adjList.at(vertex1).insert(vertex2);
			return true;
		}
		return false;
	}

	bool deleteEdge_v1_to_v2(string vertex1, string vertex2) {
		if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
		{
			adjList.at(vertex1).erase(vertex2);
			return true;
		}
		return false;
	}

	bool deleteDirected_vertex(string vertex) {
		if (adjList.count(vertex)!=0) {
			for (auto i : adjList) {
				if (i.second.count(vertex) != 0) {
					i.second.erase(vertex);
				}
			}

		}
		return true;
	}


	void topologicalSortUtil(string node, unordered_map<string, bool>& visited, list<string>& result) {
		visited[node] = true;

		for (auto i : adjList[node]) {
			if (!visited[i])
				topologicalSortUtil(i, visited, result);
		}

		result.push_front(node);
	}

	list<string> topologicalSort() {
		unordered_map<string, bool> visited;
		for (auto& i : adjList)
			visited[i.first] = false;

		list<string> result;
		for (auto& i : adjList) {
			if (!visited[i.first])
				topologicalSortUtil(i.first, visited, result);
		}

		return result;
	}
	

	// stack version dfs
	void DFS_stack(string start) {
		
		unordered_set<string> visited;
		visited.insert(start);
		stack<string> stack;
		stack.push(start);

		while (!stack.empty())
		{
			string currentVertex = stack.top();
			stack.pop();
			cout << currentVertex << " ";

			for (auto i : adjList[currentVertex]) {

				if (visited.count(i)==0) {
					visited.insert(i);
					stack.push(i);
				}
			}
		}
	}

};

class coin {
public:
	int value;
	int index;

	bool operator==(coin x) {
		return x.value == this->value;
	}
	bool operator==(int index) {
		return this->index == index;
	}
	bool operator>(coin x) {
		return x.value < this->value;
	}
	bool operator<(coin x) {
		return x.value > this->value;
	}
	int operator+(int i) {
		return this->value + i;
	}
};
int fakeIndex(vector<coin> coins);
int mult(int n, int m);
void josephus(list<int>& people, int g = 2);
int interpolationSearch(int arr[], int n, int x);