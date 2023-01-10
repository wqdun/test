#include <iostream>
#include <vector>

class Node {
public:
    Node(int a)
        : data(a) {}
    Node() {}
// private:
    friend std::ostream & operator<<(std::ostream &os, const Node &n) {
        os << n.data;
        return os;
    }

public:
    int data = 0;
public:
    Node *next = nullptr;
};

void PrintNode(Node *pList) {
    while (pList) {
        std::cout << *pList << "\t";
        pList = pList->next;
    }
    std::cout << "\n";
    return;
}

Node *CreateList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node * const pRoot = new Node(arr[0]);
    Node *pNode = pRoot;
    for (size_t i = 1; i < arr.size(); ++i) {
        pNode->next = new Node(arr[i]);
        pNode = pNode->next;
    }
    (void) PrintNode(pRoot);

    return pRoot;
}

Node *RemoveNode(int target, Node *pList) {
    Node *pRoot = pList;
    Node *pPre = pList;
    while (pList) {
        if (target == pList->data) {
            if (pList == pRoot) {
                pPre = pList;
                Node *pNext = pList->next;

                delete pList;
                pList = nullptr;

                pRoot = pNext;
                pList = pNext;
            }
            else {
                Node *pNext = pList->next;

                pPre->next = pNext;

                delete pList;
                pList = nullptr;

                pList = pNext;
            }
        }
        else {
            pPre = pList;
            pList = pList->next;
        }
    }

    return pRoot;
}

Node *RemoveNode_(int target, Node *pList) {
    // find new root
    while (pList) {
        if (pList->data == target) {
            Node *toRemove = pList;

            pList = pList->next;
            delete toRemove;
        }
        else {
            break;
        }
    }

    Node *newRoot = pList;
    Node *pPrevious = pList;
    while (pList) {
        if (pList->data == target) {
            Node *toRemove = pList;

            pPrevious->next = pList->next;
            // pPrevious = pList;
            pList = pList->next;
            delete toRemove;
        }
        else {
            pPrevious = pList;
            pList = pList->next;
        }
    }

    return newRoot;
}

int main(int argc, char const *argv[]) {
    std::vector<int> a {1, 2, 3, 1, 1, 1, 0, 1, -1};
    // a = {1};

    Node *pList = CreateList(a);

    (void) PrintNode(pList);
    // Node *removed = RemoveNode(1, pList);
    Node *removed = RemoveNode_(1, pList);
    std::cout << "removed: " << static_cast<void *>(removed) << ".\n";
    (void) PrintNode(removed);

    return 0;
}
