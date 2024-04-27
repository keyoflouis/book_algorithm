
#include"header.h"
int main() {
	//Graph* myGraph = new Graph();

	//for (int i = 'A'; i <= 'H'; ++i)
	//{
	//	char vertex = static_cast<char>(i);
	//	myGraph->addVertex(string(1, vertex));
	//}

	//// bool addEdge_v1_to_v2(string vertex1,string vertex2)
	//myGraph->addEdge_v1_to_v2("A", "B");
	//myGraph->addEdge_v1_to_v2("B", "C");
	//myGraph->addEdge_v1_to_v2("C", "D");
	//myGraph->addEdge_v1_to_v2("D", "E");
	//myGraph->addEdge_v1_to_v2("E", "F");

	//myGraph->addEdge_v1_to_v2("A", "C");
	//myGraph->addEdge_v1_to_v2("B", "D");
	//myGraph->addEdge_v1_to_v2("C", "E");
	//myGraph->addEdge_v1_to_v2("D", "F");
	//myGraph->addEdge_v1_to_v2("E", "G");
	//myGraph->addEdge_v1_to_v2("F", "G");
	//myGraph->addEdge_v1_to_v2("H", "B");

	//cout << "Graph vertices and edges:" << endl;
	//myGraph->printGraph();

	//cout << "\nheap version DFS" << endl;
	//myGraph->DFS_stack("A");

	//cout << endl;
	//list<string> result = myGraph->topologicalSort();
	//for (auto& i : result)
	//	cout << i << " ";
	//cout << endl;

	//return 0;


	int n = 4; // Example for n = 4
	johnsonTrotter(n);
	return 0;

}