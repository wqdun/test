#include <iostream>
#include <vector>

class Node {
public:
    Node(int a)
        : data(a) {}
    Node()
        : Node(0) {}
// private:
    friend std::ostream & operator<<(std::ostream &os, const Node &n) {
        os << n.data;
        return os;
    }

private:
    int data = 0;
public:
    Node *next = nullptr;
};

void PrintNode(Node * const _pNode) {
    Node *pNode = _pNode;
    while (pNode) {
        std::cout << *pNode << "\t";
        pNode = pNode->next;
    }
    std::cout << "\n";
    return;
}

Node *ReverseNode(Node * const _pNode) {
    Node *pPrevious = nullptr;
    Node *pNode = _pNode;
    while (pNode) {
        Node *pNext = pNode->next;

        pNode->next = pPrevious;
        pPrevious = pNode;

        pNode = pNext;
    }

    return pPrevious;
}

Node *ReverseNode_(Node *pList) {
    Node *pPrevious = nullptr;

    while (pList) {
        Node *pNext = pList->next;

        pList->next = pPrevious;
        pPrevious = pList;

        pList = pNext;
    }

    return pPrevious;
}

Node *ReverseNode__(Node *pList) {
    Node *p = pList;

    Node *prev_ = nullptr;
    while (p) {
        Node *next = p->next;

        p->next = prev_;

        prev_ = p;
        p = next;
    }

    return prev_;
}

void TestNode() {
    Node n1;
    Node n2(1);
    std::cout << n1 << "\t" << n2 << "\n";

    std::vector<int> arr {1, 2, 3, 2, -1, 0};
    Node * const pRoot = new Node(arr[0]);
    Node *pNode = pRoot;
    for (size_t i = 1; i < arr.size(); ++i) {
        pNode->next = new Node(arr[i]);
        pNode = pNode->next;
    }
    (void) PrintNode(pRoot);

    Node *newRoot = ReverseNode_(pRoot);
    (void) PrintNode(newRoot);

    return;
}


int main(int argc, char const *argv[]) {
    TestNode();
    return 0;
}
