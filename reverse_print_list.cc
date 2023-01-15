#include <iostream>
#include <vector>
#include <stack>

class ListNode {
public:
    ListNode() {}
    ListNode(int a)
        : data(a) {}

public:
    int data = 0;
    ListNode *next = nullptr;
};

ListNode *CreateList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }

    ListNode *root = new ListNode(arr[0]);
    ListNode *p = root;
    for (size_t i = 1; i < arr.size(); ++i) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }

    return root;
}

void PrintList(ListNode *list) {
    while (list) {
        std::cout << list->data << "\t";
        list = list->next;
    }

    std::cout << "\n";
    return;
}

void ReversePrint(ListNode *list) {
    std::stack<ListNode *> nodes;

    while (list) {
        nodes.push(list);
        list = list->next;
    }

    while (!nodes.empty()) {
        ListNode *p = nodes.top();
        std::cout << p->data << "\t";
        nodes.pop();
    }
    std::cout << "\n";
    return;
}

int main(int argc, char const *argv[]) {
    const std::vector<int> a {1, 2, 3, 4, 5};

    ListNode *list = CreateList(a);
    ReversePrint(list);

    return 0;
}
