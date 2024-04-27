#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    bool arrow; // true for left, false for right

    Node(int value) : value(value), arrow(true) {} // Initialize arrow to true (left)
};

void initVec(vector<Node>& sequantial, int n) {
    sequantial.clear(); 
    for (int t = 1; t <= n; ++t) {
        sequantial.push_back(Node(t));
    }
}

int findMaxMobile(vector<Node>& sequantial, bool& haveMobile) {
    int maxMobile = -1;
    int maxIndex = -1;
    for (int i = 0; i < sequantial.size();i++) {
        if((sequantial[i].arrow && i > 0 && sequantial[i].value > sequantial[i - 1].value) ||
            (!sequantial[i].arrow && i < sequantial.size() - 1 && sequantial[i].value > sequantial[i + 1].value))
            if (sequantial[i].value > maxMobile) {
                maxMobile = sequantial[i].value;
                maxIndex = i;
            }
    }

    haveMobile = (maxMobile != -1);
    return maxIndex;
}

void printSequence(const vector<Node>& sequantial) {
    for (const auto& node : sequantial) {
        cout << node.value << " ";
    }
    cout << endl;
}

void reverseDirections(vector<Node>& sequantial, int value) {
    for (auto& node : sequantial) {
        if (node.value > value) {
            node.arrow = !node.arrow;
        }
    }
}

void swapMobile(vector<Node>& sequancial, int& k, bool& haveMobile) {

    int swapIndex = k + (sequancial[k].arrow ? -1 : 1);

    std::swap(sequancial[k], sequancial[swapIndex]);

    reverseDirections(sequancial, sequancial[swapIndex].value);

    k = findMaxMobile(sequancial, haveMobile);
}
void johnsonTrotter(int n) {
    vector<Node> sequantial;
    initVec(sequantial, n);

    bool haveMobile = true;
    int maxMobileIndex = findMaxMobile(sequantial, haveMobile);

    while (haveMobile) {
        printSequence(sequantial); 
        swapMobile(sequantial, maxMobileIndex, haveMobile);
    }
    printSequence(sequantial);

}
