
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


	//int n = 4; 
	//johnsonTrotter(n);
	//return 0;

	/*int n;
	std::cout << "Enter the number of bits for Gray codes: ";
	std::cin >> n;

	std::vector<std::string> grayCodes = BRGC(n);

	std::cout << "The " << n << "-bit Gray codes are:\n";
	for (const std::string& code : grayCodes) {
		std::cout << code << std::endl;
	}

	return 0;*/

	// vector<coin> coins;
	// for (int i = 0; i < 11; i++) {
	// 	coin c;
	// 	c.value = 1;
	// 	c.index = i;
	// 	coins.push_back(c);
	// }
	// coins[5].value = 0;

	// int fakeCoinIndex = fakeIndex(coins);
	// cout << "fake:" << fakeCoinIndex << endl;

	// return 0;

	// int n = 4;
	// int m = 5;
	// cout << "x = "<< n <<" y =" << m<<" x * y = "<<mult(n,m) << endl;

	std::list<int> people = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	josephus(people, 3);
	std::cout << "The last person standing is: " << people.front() << std::endl;
	return 0;

}