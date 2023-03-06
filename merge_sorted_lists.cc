#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Node {
public:
    int data = 0;
    Node *next = nullptr;

    Node() {}
    Node(int i)
        : data(i) {}
};

Node *CreateList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node *root = new Node(arr[0]);
    Node *p = root;
    for (size_t i = 1; i < arr.size(); ++i) {
        p->next = new Node(arr[i]);
        p = p->next;
    }

    return root;
}

void PrintList(Node *list) {
    while (list) {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << "\n";
    return;
}

Node *MergeSort(Node *l1, Node *l2) {
    Node *l3 = new Node();

    Node *p = l3;
    while (true) {
        if (l1) {
            if (l2) {
                if (l1->data > l2->data) {
                    p->next = l2;
                    l2 = l2->next;

                    p = p->next;
                }
                else
                if (l1->data == l2->data) {
                    p->next = l1;
                    l1 = l1->next;

                    p = p->next;
                }
                else {
                    p->next = l1;
                    l1 = l1->next;

                    p = p->next;
                }
            }
            else {
                std::cout << "l2 is nullptr\n";
                p->next = l1;
                break;
            }
        }
        else {
            if (l2) {
                std::cout << "l1 is nullptr\n";
                p->next = l2;
                break;
            }
            else {
                std::cout << "l1 = l2 = nullptr\n";
                break;
            }
        }
    }

    return l3->next;
}

Node *MergeListsUsingPrioQueue(Node *l1, Node *l2) {
    std::priority_queue<int> prioQ;

    while (l1) {
        prioQ.push(l1->data);
        l1 = l1->next;
    }
    while (l2) {
        prioQ.push(l2->data);
        l2 = l2->next;
    }
    std::cout << "size: " << prioQ.size() << "\n";

    if (prioQ.empty()) {
        return nullptr;
    }

    Node *l3 = new Node();
    Node *p = l3;
    while (!prioQ.empty()) {
        p->next = new Node(prioQ.top());
        p = p->next;
        prioQ.pop();
    }

    return l3->next;
}


int main(int argc, char const *argv[]) {
    const std::vector<int> a {0, 5, -1, 7};
    Node *l = CreateList(a);
    (void) PrintList(l);

    Node *l1 = CreateList(std::vector<int> {1, 5, 33});
    Node *l2 = CreateList(std::vector<int> {5, 6, 8, 90});

    Node *l3 = MergeSort(l1, l2);
    (void) PrintList(l3);

    l3 = MergeListsUsingPrioQueue(l1, l2);
    (void) PrintList(l3);
    return 0;
}
