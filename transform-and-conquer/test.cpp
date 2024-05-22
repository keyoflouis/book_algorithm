#include"header.h"

int main() {
    Node* root = NULL;
    root = insertNode(root, 33);
    root = insertNode(root, 13);
    root = insertNode(root, 53);
    root = insertNode(root, 9);
    root = insertNode(root, 21);
    root = insertNode(root, 61);
    root = insertNode(root, 8);
    root = insertNode(root, 11);
    printTree(root, "", true);
    root = deleteNode(root, 13);
    cout << "After deleting " << endl;
    printTree(root, "", true);
}