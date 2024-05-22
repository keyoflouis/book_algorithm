
#include<iostream>
using namespace std;
class Node;
void printTree(Node* root, string indent, bool last);
Node* deleteNode(Node* root, int key);
Node* insertNode(Node* node, int key);