#include "./implementation/header.h"

int main()
{
	// std::vector<covexHull_point> n = { {1,2}, {2,3}, {6,3}, {2,2},{1,3}, {2,4} };
	// std::vector<covexHull_point> convex_hull = convexHull(n);

	// for (auto& p : convex_hull) {
	// 	std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
	// }



	// create graph
	Graph *myGraph = new Graph();

	for (int i = 'A'; i <= 'Z'; ++i)
	{
		char vertex = static_cast<char>(i);
		myGraph->addVertex(string(1, vertex));
	}

	for (char vertex = 'A'; vertex <= 'Z'; ++vertex)
	{
		string v = string(1, vertex);
		for (char other = 'A'; other <= 'Z'; ++other)
		{
			if (vertex != other)
			{
				string o = string(1, other);
				myGraph->addEdge(v, o);
			}
		}
	}

	cout << "Graph vertices and edges:" << endl;
	myGraph->printGraph();

	cout << "\nDepth First Traversal starting from vertex 'A':" << endl;
	myGraph->DFS("A");

	cout << "\nBreadth First Traversal starting from vertex 'A':" << endl;
	myGraph->BFS("A");

	return 0;
}
